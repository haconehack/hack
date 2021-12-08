int main(int argc, char *argv[])
{
  char obuf[32];
  
  // 32bytes copied then it's not contains a null terminate than off-by-one could be occured.
  strncpy(obuf, argv[1], sizeof(obuf));
  
  // bug(obug);
  // could be occred a bug.
  
  printf("code: %d\n", c);
}
