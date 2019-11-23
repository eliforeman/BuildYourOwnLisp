#include <stdio.h>


static char input [2048];

int main (int argc, char **argv){
	
	/* prints version # */
	puts("FOX version 0.0.1");
	puts("Press Ctr+c to Exit \n");


	/* infinite loop */
	while(1){

		fputs("fox > ", stdout);

		fgets(input,2048,stdin);

		printf("what you said: %s", input);


	}
	return 0;

}
