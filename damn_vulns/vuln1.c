
#include <stdio.h>

int main(int argc, char **argv)
{
   char vulnbuf[32];
   
   stncpy(vulnbuf, argv[1], 1024);
   printf("%s\n", vulnbuf);
   
   return 0;
}
