/*
 * A simple yuv concatenater.
 *
 * Copyright 2014, Juncheng Ma <majch2011@gmail.com>
 *
 * yuvcat is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * yuvcat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with yuvcat. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdint.h>
using namespace std;


int main(int argc, char* argv[])
{
  const char *prefix = argv[1];
  int from = atoi(argv[2]);
  int to = atoi(argv[3]);
  int width = atoi(argv[4]);
  int height = atoi(argv[5]);

  char infile[1024];
  const char * outfile = argv[6];

  //YUV 4:2:0 Planar as default
  int frame_size = width * height * 3 / 2 * sizeof(uint8_t);
  uint8_t *buf = (uint8_t *)malloc(frame_size);
  if (buf == NULL) {
    fprintf(stderr, "fail to open yuv buffer for %dx%d yuv frame!\n", width, height);
    goto end;
  }

  FILE *in = NULL, *out = NULL;
  if ((out = fopen(outfile, "wb")) == NULL) {
    fprintf(stderr, "fail to open output file %s!\n", outfile);
    goto end;
  }

  for (int i = from; i <= to; ++i) {
    sprintf(infile, "%s%08d.yuv", prefix, i);
    printf("join %s\n", infile);
    in = fopen(infile, "rb");
    if (in == NULL) {
      fprintf(stderr, "fail to open input file %s!\n", infile);
      goto end;
    }

    //read and write
    while (fread(buf, frame_size, 1, in)) {
      fwrite(buf, frame_size, 1, out);
    }

    fclose(in);
  }

  printf("succeed! %d files joint to %s.\n", to - from + 1, outfile);

end:
  fclose(out);

  free(buf);
  buf = NULL;

  //system("pause");
  return EXIT_SUCCESS;
}