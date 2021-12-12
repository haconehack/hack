#include <stdio.h>

int vuln_f(char *str, int len)
{
   // 14 - 15 (-1)
   char vuln_buf[sizeof("Message: Hello") - len];
   char vuln_stack[32];
    
   memcpy(vuln_buf, str, len);
   // buffer underrun trigger!
   system(vuln_stack);
  
   return(0); 
}

int main()
{
  char s[1024];
  int pos = 0;
  
  scanf("%s", &s);
  pos = strchr(s, ':');
  
  vuln_buf(s, pos);
  
  return(0);
}
