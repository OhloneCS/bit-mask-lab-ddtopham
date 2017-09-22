#include <stdio.h>
int main()
{
  const int x = 32, y = 32;   int i, j;
  const int h = 13;
  unsigned char hdr[h];
  FILE *fp1 = fopen("tree.ppm", "rb"); 
  FILE *fp2 = fopen("treemask.ppm", "wb");
  fread(hdr,1,h,fp1);
  fwrite(hdr,1,h,fp2);
  for (j = 0; j < y; ++j)
    for (i = 0; i < x; ++i)
    {
      unsigned char color[3];
	  fread(color,1,3,fp1);
	  if(color[0] != 0xff)
		{ color[0] = 0; color[1] = 0; color[2] = 0; }
      fwrite(color,1,3,fp2);
    }
  fclose(fp1); fclose(fp2);
  return 0;
}
