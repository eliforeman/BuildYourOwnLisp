#include <stdio.h>


int x = 5;


char* helloWorld(char* n){
	puts(n);
	return 0;
}



int main(int argc, char** argv){
	helloWorld("hello");
	for(int i = 0; i < x; i++){
		puts("yeehaw");	
	}
	return 0;
}
