
int main(int argc,char **argv)
{
   int i,j;
   int a,r,g,b;
   FILE *fptr;
   int width,height; /* Assumes 4 byte ints */

   if (argc < 2) {
      fprintf(stderr,"Usage: %s xfilename\n",argv[0]);
      exit(-1);
   }

   /* Attempt to open the file */
   if ((fptr = fopen(argv[1],"r")) == NULL) {
      fprintf(stderr,"Failed to open input file \"%s\"\n",argv[1]);
      exit(-1);
   }

   /* Read the header */
   fread(&width,sizeof(int),1,fptr);
   width = FIX(width);
   fprintf(stderr,"Width: %d\n",width);
   fread(&height,sizeof(int),1,fptr);
   height = FIX(height);
   fprintf(stderr,"Height: %d\n",height);

   /* Read the ARGB for each pixel */
   for (j=0;j<height;j++) {
      for (i=0;i<width;i++) {

         /* Read the current pixel */
         a = fgetc(fptr);
         r = fgetc(fptr);
         g = fgetc(fptr);
         b = fgetc(fptr);
         if (a == EOF || g == EOF || r == EOF || b == EOF) {
            fprintf(stderr,"Unexpected end of file\n");
            exit(-1);
         }

         /* 
            Do something with the pixels
            Write to raw image in this example 
         */
         putchar(r);
         putchar(g);
         putchar(b);
      }
   }

   fclose(fptr);
}

