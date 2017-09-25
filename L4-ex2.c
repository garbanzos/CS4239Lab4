/*
Name: Tan Yi Yan
Matric. no.: A0127051U
Email: yiyan@u.nus.edu
CS4239 Lab 4 Exercise 2
*/

#include <stdlib.h>
#include <stdio.h>

int global[30] = {0};

int main(int argc, char *argv[], char *envp[]) {
	int choice = 1, *p;
	int buffer[10];

	if (argc > 1) choice=atoi(argv[1]);
	printf("choice %d\n", choice);

    switch (choice) {
    case 1:
        // use after free 
		p = malloc(sizeof(int));
		free(p);
		*p = 100;
        break;
    case 2:
        // stack buffer overflow
		buffer[22] = 200;
        break;
    case 3:
        // global buffer overflow
		global[33] = 300;
        break;
    }
    return 0;
}
