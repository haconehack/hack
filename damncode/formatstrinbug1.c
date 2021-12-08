#include <stdio.h>

int main()
{
  char *fbuf;
  
  fbuf = malloc(1024);
  
  scanf("%s", fbuf);
  printf(fbuf);
}
