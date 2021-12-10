/*
  from https://blog.hubeen.kr/293
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vuln_struct{
	int id;
	char name[20];
	void (*clean)(void *);
} VULNED;

void cleanMem(void *mem)
{
	free(mem);
}

void hacksure(){
	system("/bin/sh");
}

int main(int argc, char *argv[])
{
	void *vuln_tst;
	VULNED *vuln = malloc(170);

	fflush(stdin);
	printf("Enter your id number:");
	scanf("%d", &vuln->id);
	fflush(stdin);
	printf(Enter your name:");
	scanf("%s", vuln->name);

	vuln->clean = cleanMem;
	
	if(vuln->id > 400)
	{
		printf("Your id is too big\n");
		vuln->clean(vuln);
	}

	vuln_tst = malloc(170);
	sstrcpy(vuln_tst, argv[1]);

	free(vuln_tst);
	vuln->clean(vuln);

	return 0;
}
