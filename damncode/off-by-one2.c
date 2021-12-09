#include <stdio.h>

int main()
{
char firstname[20];
char lastname[20];
char fullname[40];

fullname[0] = '\0';

// fullname[39] should be having 'NULL' terminate char but 39 having lastname[19] and it's off-by-one bug occured.

strncat(fullname, firstname, 20);
strncat(fullname, lastname, 20);

}
