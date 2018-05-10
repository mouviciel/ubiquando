//
// Copyright 2018 Mouviciel
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "ubiquando.h"

struct option options[] = {
  { "version",        no_argument,       NULL, 'v' },
  { "configuration",  required_argument, NULL, 'c' },
  { 0,0,0,0 }
};


int main(int argc, char * argv[])
{
  int c;
  char * config_file = NULL;

  while ((c=getopt_long(argc,argv,"vc:",options,NULL)) > -1)
  {
    switch (c)
    {
      case 'v': // --version
        printf("%s version %s\n",argv[0],UBIQUANDO_VERSION_STRING);
        goto success;
        break;
      case 'c':
        config_file = strdup(optarg);
        break;
      case '?':
        goto failure;
        break;

    }
  }

  if (!config_file)
  {
    fprintf(stderr,
            "%s: error: configuration file has not been specified\n",
            argv[0]);
    goto failure;
  }
  printf("Configuration File: %s\n",config_file);

failure:
  return 1;

success:
  return 0;
}

// vim: set tw=79 ts=2 sw=2 et ai si nonu syn=c fo+=ro :
