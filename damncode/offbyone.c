int main(int argc, char *argv[])
{
  char obuf[20];
  
  // 16+4(.log) = 20 then no null terminate next calling function can be off-by-one bug.
  sprintf(obuf, "%16s.log", argv[1]);
  
  // bug(obug);
  // could be occred a bug.
  
  printf("code: %d\n", c);
}
