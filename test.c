#include "bmpwriter.h"
void _BMPanalyze(const char *a)
{
   _BMP=(char*)malloc(134);
   FILE *_BMPf=fopen(a,"rb");
   fread(_BMP,134,1,_BMPf);
   int i=0;
   for(i=0;i<134;i++)
     printf("%d: %d\n",i,_BMP[i]);
   free(_BMP);
}
void _BMPbmpdraw()
{
  int i=0,j=0;
  for(;i<_BMPX;i++)
   for(j=0;j<_BMPY;j++)
     putpixel(i+1,j+1,255,140,6);
}
void _BMPbmpdraw2()
{
  int i=0,j=0;
  for(;i<_BMPX;i++)
   for(j=0;j<_BMPY;j++)
     putpixel(i+1,j+1,(i+j)%255,(1000-i-j)%255,i%255);
}
main()
{
   bmpinit(3,4);
   _BMPbmpdraw();
   bmpsave("test.bmp");
   _BMPanalyze("test.bmp");
    bmpinit(317,411);
   _BMPbmpdraw2();
   bmpsave("test2.bmp");
   bmpfree();
}
