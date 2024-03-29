/*
Name: Tan Yi Yan
Matric. no.: A0127051U
Email: yiyan@u.nus.edu
CS4239 Lab 4 Exercise 3
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int choice=1, *p;
	char a[8], b[100], *c, *d, *e;

	if (argc > 1) choice=atoi(argv[1]);
	printf("choice %d\n", choice);

    switch (choice) {
    case 1:
		// uninitialised pointer 
        *p = 111;
		break;
    case 2:
        // out of bounds access inside non-redzone
		a[66] = (char) 222;
        break;
    case 3:
        // undetected use-after-free
		// because large amount of memory was allocated and deallocated between the "free" and use-after-free
		c = malloc(1 << 20);
		free(c);
		d = malloc(1 << 28);
		free(d);
		e = malloc(1 << 20);
		*c = (char) 333;
        break;
    }
    return 0;
}
