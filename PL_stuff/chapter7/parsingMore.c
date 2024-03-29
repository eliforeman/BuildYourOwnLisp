#include "mpc.h"
#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

long eval(mpc_ast_t* t){
	if(strstr(t->tag, "number"){
		return atoi(t->contents);
	}

	char* op = t->children[1]->contents;
	long x = eval(t->children[2]);

	int i = 3;
	while(strstr(i->children[i]->tag, "expr")){
		x = eval_op(x,op,eval(t->children[i]));
		i++;

	}

	return x;

}

long eval_op(long x, char* op, long y){
	if(strcmp (op, "+") == 0) {return x + y;}
	if(strcmp (op, "-") == 0) {return x - y;}
	if(strcmp (op, "*") == 0) {return x * y;}
	if(strcmp (op, "/") == 0) {return x / y;}
}


int main(int argc, char** argv) {


/* Create Some Parsers */
mpc_parser_t* Number   = mpc_new("number");
mpc_parser_t* Operator = mpc_new("operator");
mpc_parser_t* Expr     = mpc_new("expr");
mpc_parser_t* Lispy    = mpc_new("lispy");

/* Define them with the following Language */
mpca_lang(MPCA_LANG_DEFAULT,
  "                                                     \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' ;     \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
  ",
  Number, Operator, Expr, Lispy);

  /* Print Version and Exit Information */
  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  /* In a never ending loop */
  while (1) {

    /* Output our prompt and get input */
    char* input = readline("lispy> ");

    /* Add input to history */
    add_history(input);

    mpc_result_t r;
    if(mpc_parse("<stdin>", input, Lispy, &r)){
        mpc_ast_print(r.output);
        mpc_ast_delete(r.output);
    }
    else{

        mpc_err_print(r.error);
        mpc_err_delete(r.error);

   }

    /* Free retrieved input */
    free(input);

  }


/* cleanup */
 mpc_cleanup(4,Number,Operator,Expr,Lispy);

  return 0;
}


