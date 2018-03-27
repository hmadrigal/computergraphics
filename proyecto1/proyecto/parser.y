%{
#include <stdio.h>
#include <string.h>

#include "universal_data.h"

%}

%token CONSTANT STRING_LITERAL BEGINN WINDOW SCREEN_SIZE
%token COLOR TERRITORY TEXTURE LIMITS END BACK
%token WHITE YELLOW MAGENTA RED CYAN GREEN BLUE BLACK

%union {
	char *str;
	int val;
	double dval;
}

%start init_rule

%%
init_rule :
	window_rule back_rule size_rule territory_list;

window_rule :
	WINDOW CONSTANT CONSTANT CONSTANT CONSTANT {setWindow((double) $<dval>2, (double) $<dval>3, (double) $<dval>4, (double) $<dval>5);};

back_rule:
	BACK CONSTANT CONSTANT CONSTANT {set_background((double) $<val>2/255, (double) $<val>3/255, (double) $<val>4/255);}
	| BACK background_choice
	| BACK STRING_LITERAL {set_background_image($<str>2);};

background_choice :
	WHITE {select_back(WHITE);}
	| YELLOW {select_back(YELLOW);}
	| MAGENTA {select_back(MAGENTA);}
	| RED {select_back(RED);}
	| CYAN {select_back(CYAN);}
	| GREEN {select_back(GREEN);}
	| BLUE {select_back(BLUE);}
	| BLACK {select_back(BLACK);};

size_rule:
	SCREEN_SIZE CONSTANT CONSTANT {set_size($<val>2, $<val>3);};

territory_list :
	teritory_spec
	| territory_list teritory_spec;

teritory_spec :
	BEGINN TERRITORY {start_territory();} color_spec texture_spec limits_spec END TERRITORY;

color_spec :
	COLOR '=' CONSTANT CONSTANT CONSTANT {set_color_map((double) $<val>3/255, (double) $<val>4/255, (double) $<val>5/255);}
	| COLOR '=' color_choice;

color_choice :
	WHITE {select_color(WHITE);}
	| YELLOW {select_color(YELLOW);}
	| MAGENTA {select_color(MAGENTA);}
	| RED {select_color(RED);}
	| CYAN {select_color(CYAN);}
	| GREEN {select_color(GREEN);}
	| BLUE {select_color(BLUE);}
	| BLACK {select_color(BLACK);};

texture_spec :
	TEXTURE '=' STRING_LITERAL {set_texture($<str>3);};

limits_spec :
	BEGINN LIMITS limits_list END LIMITS;

limits_list :
	CONSTANT CONSTANT {addLimit($<dval>1, $<dval>2);}
	| limits_list CONSTANT CONSTANT {addLimit($<dval>2, $<dval>3);};

%%

#define FALSE 0
#define TRUE 1

extern char yytext[];
extern yylineno;
extern FILE *yyin;

yyerror(char *s)
{
	printf("Error en linea %i\n", yylineno);
        fflush(stdout);
	yyerrok;
	exit(0);
}

select_color(int color) {
	switch(color) {
		case WHITE:
			set_color_map((double) 1, (double) 1, (double) 1);
			break;
		case YELLOW:
			set_color_map((double) 1, (double) 1, (double) 0);
			break;
		case MAGENTA:
			set_color_map((double) 1, (double) 0, (double) 1);
			break;
		case RED:
			set_color_map((double) 1, (double) 0, (double) 0);
			break;
		case CYAN:
			set_color_map((double) 0, (double) 1, (double) 1);
			break;
		case GREEN:
			set_color_map((double) 0, (double) 1, (double) 0);
			break;
		case BLUE:
			set_color_map((double) 0, (double) 0, (double) 1);
			break;
		case BLACK:
			set_color_map((double) 0, (double) 0, (double) 0);
			break;
		default:
			printf("Some error has ocurred!!\n");
			break;
	}
}

select_back(int color) {
	switch(color) {
		case WHITE:
			set_background((double) 1, (double) 1, (double) 1);
			break;
		case YELLOW:
			set_background((double) 1, (double) 1, (double) 0);
			break;
		case MAGENTA:
			set_background((double) 1, (double) 0, (double) 1);
			break;
		case RED:
			set_background((double) 1, (double) 0, (double) 0);
			break;
		case CYAN:
			set_background((double) 0, (double) 1, (double) 1);
			break;
		case GREEN:
			set_background((double) 0, (double) 1, (double) 0);
			break;
		case BLUE:
			set_background((double) 0, (double) 0, (double) 1);
			break;
		case BLACK:
			set_background((double) 0, (double) 0, (double) 0);
			break;
		default:
			printf("Some error has ocurred!!\n");
			break;
	}
}
/*
main(int argc, char *argv[]) {
	yyin = fopen((char *)argv[1], "r+");
	if (! yyin) {
		printf("No se pudo abrir\n");
		exit(0);
	}
	yyparse();

	printf("El # de mapas es %i\n", map_count());
}*/

void loadFile(char *file) {
	yyin = fopen(file, "r+");
	if (! yyin) {
		printf("No se pudo abrir\n");
		exit(0);
	}
	yyparse();
}
