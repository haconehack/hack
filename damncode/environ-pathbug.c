#include <stdio.h>

void envvuln_func() {
    // "reportName" is a usercontrolled environment variable. 
    char* rName = getenv("reportName");
    char buf[30];

    strncpy(buf, "/home/www/tmp/", 30);
    // rName(environment) could be used '../../'(related path string) then you can control the unlink path that all you wanted. (bug)
    strncat(buf, rName, 30);

    unlink(buf);
}

int main()
{
	envvuln_func();
}
