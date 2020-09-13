#include "monty.h"

/**
 *
 *
 *
 */
int main(int argc, char **argv)
{
  FILE *fp;

  /* First Check, only run program + file path */
  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }

  /* Second check, open the file*/
  fp = fopen(argv[1], "r");
  if (fp == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  printf("so far so good\n");
  return (0);
}
