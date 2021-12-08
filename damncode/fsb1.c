#include <stdio.h>

int main()
{
  char *fbuf;
  
  fbuf = malloc(1024);
  
  scanf("%s", fbuf);
  // fbuf can be user-supplied format string... and could be occured by an bug.
  printf(fbuf);
}
