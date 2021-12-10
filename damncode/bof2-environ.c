#include <stdio.h>

void envvuln_func() {
    // reportName environment is vulnerable to buffer overflow.
    char* rName = getenv("reportName");
    char buf[30];

    strncpy(buf, "/home/www/tmp/", 30);
    strncat(buf, rName, 30);

    unlink(buf);
}

int main()
{
	envvuln_func();
}
