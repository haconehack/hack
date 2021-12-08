#include <stdio.h>

char *alloca(int alloc_len)
{
   if(alloc_len > 0 && alloc_len <= 1024)
   {
     return malloc(alloc_len);
   }
  else{
    printf("error to fail the malloc of alloca function\n");
    return (char *) -1;
  }
}

int main(int argc, char **argv)
{
  // allocation size is from usersupplied value and it could be 0~1024.
  char damnvulnpointer = alloca(atoi(argv[1]));
  
  // no bounds checking.
  strcpy(damnvulnpointer, argv[2]);
  
  return 0;
}
