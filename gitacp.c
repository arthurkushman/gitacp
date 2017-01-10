#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 4096
#define GIT_BUFF_SIZE 256

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char* argv[])
{
  if (argc != 2) {
    printf("%s%s%s\n", ANSI_COLOR_YELLOW, "Command run example: gitacp '<any comment>'", ANSI_COLOR_RESET);
    exit(1);
  }

  char data[BUFF_SIZE];
  char str[GIT_BUFF_SIZE];

  strcpy(str, "git add --all && git add . && git commit -am '\t*\t");
  strcat(str, argv[1]);
  strcat(str, "' && git push");
  FILE* fp = popen(str, "r");

  while (fgets(data, sizeof(data), fp)) {
    fprintf(stderr, "-%s-%s-%s-\n", ANSI_COLOR_GREEN, data, ANSI_COLOR_RESET);
  }

  if (pclose(fp) < 0) {
    printf("-%s-%s-%s-\n", ANSI_COLOR_RED, "Error: pclose couldn`t close the pipe.", ANSI_COLOR_RESET);
    exit(1);
  }

    return 0;
}
