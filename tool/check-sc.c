
#include <stdio.h>

/*
  
[x90@x90hack]-[~/check-sc]
>>> ./check-sc testcase.c.txt 15
1:
2: // argv1 == vuln length
3: // argv2 == overflow payload
4: int main(int argc, char *argv[]])
5: {
6:
7: char buf[32];
8: unsigned int lena = 0;
9:
10: snprintf(buf, 32, "%s\n", argv[2]);
11: snprintf(buf,lena, "%s\n", argv[1]])
weak code found!
12: snprintf(buf, sizeof(buf)-1, "%s\n", argv[2]);
13: snprintf(buf, atoi(argv[1]), "%s\n", argv[2]);
weak code found!
14:
15: }
[x90@x90hack]-[~/check-sc]
>>>

*/
int klen;
int stop_pr;

char *readlinea(char *orig)
{
  int i = 0;
  char *buf;

   buf = malloc(128);

  memset(buf, 0x0, sizeof(buf));

  for(i = 0; i < 128; i++)
  {
    if(orig[i] == '\n')
      break;

      buf[i] = orig[i];
  }

  klen = strlen(buf);

  if(buf[i] == '\n')
    stop_pr = 1;

  return(buf);
}

int lookup_codesnip(char *orig)
{
  if(strstr(orig, "snprintf(") != NULL){
    // printf("snprintf found!!\n");
    return(1);
  }

  return(0);
}

char *token_test(char *orig)
{
  char *ptr = strstr(orig, ", ");
  char *ptr1 = strstr(orig, ",");
  char *ascii = "0123456789";
  int i = 0;

  ptr += 2;
  ptr1 += 1;

  for(i = 0; i < sizeof(ascii); i++)
  {
    if(ptr[0] == ascii[i] || ptr1[0] == ascii[i])
      return(1);
  }

  return 0;
}

int token_test2(char *orig)
{
  if(strstr(orig, "sizeof(") != NULL)
  {
    return(1);
  }

  return(0);
}

int main(int argc, char *argv[])
{
  FILE *fp;
  char *pp;
  char *orig_pp;
  char *ptr;
  int i = 0;
  int lena = 0;
  char *ptr1 = NULL;
  int tret = 0, tret2 = 0;
  unsigned int wanted_lc = atoi(argv[2]);

  // x90:: if you want to know the line count then below command...
  // $ lc -c [source code filename]

  if(wanted_lc <= 0 || wanted_lc >= 10000)
  {
    fprintf(stderr, "error malloc'd() to failed\n");
    return(-1);
  }

  pp = malloc(128*wanted_lc);

  orig_pp = pp;

  fp = fopen(argv[1], "r");

  fread(pp, 128, 10000, fp);

  ptr = readlinea(pp);
  printf("1: %s\n", ptr);

for(i = 1; i < wanted_lc; i++)
{
  pp = pp + klen + 1;
  ptr = readlinea(pp);
  if(stop_pr != 1)
  {
    printf("%d: %s\n", i+1, ptr);
  }

  if(lookup_codesnip(ptr) == 1)
  {
    tret = token_test(ptr);
    tret2 = token_test2(ptr);

    if(tret == 0 && tret2 == 0)
    {
      printf("weak code found!\n");
    }
  }
}

}
