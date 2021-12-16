#include <stdio.h>

int main(int argc, char **argv)
{
  char vulnbuf[128];
  char buf_a[100];
  char out_buf[512];
  
  memset(buf_a, 0x41, sizeof(buf_a));
  buf_a[sizeof(buf_a)-1] = '\0';
  
  // no bound checking to bug occured.
  sprintf(out_buf, "%s%s", buf_a, argv[1]);
  printf("out buf=%s\n", out_buf);
  
  return 0;
}
