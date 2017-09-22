#include <stdio.h>
int main()
{
  const int x = 96, y = 96;  int i, j;
  FILE *fp = fopen("background.ppm", "wb");
  fprintf(fp, "P6\n%d %d\n255\n", x, y);
  for (j = 0; j < y; ++j)
    for (i = 0; i < x; ++i)
    {
      unsigned char color[3];
      color[0] = 256 - i % 256;  /* red */
      color[1] = j % 256;  /* green */
      color[2] = (i * j) % 256;  /* blue */
      fwrite(color, 1, 3, fp);
    }
  fclose(fp);
  return 0;
}
