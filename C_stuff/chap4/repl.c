#include <stdio.h>
#include <stdlib.h>


/* We are now going to use the c preprocessor to determine if we are compiling on windows or not*/

#ifdef _WIN32
#include <string.h>

static char buffer[2048];


char *readline(char *prompt){
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

void add_history(char **unused){
}




#else
#include <editline/readline.h>
#endif


int main(int argc, char** argv) {

  /* Print Version and Exit Information */
  puts("FOX Version 0.0.0.0.2");
  puts("Press Ctrl+c to Exit\n");

  /* In a never ending loop */
  while (1) {

    /* Output our prompt and get input */
    char* input = readline("FOX> ");

    /* Add input to history */
    add_history(input);

    /* Echo input back to user */
    printf("This is what you put in: %s\n ",input);

    /* Free retrieved input */
    free(input);

  }

  return 0;
}
