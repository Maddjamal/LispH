#include <stdio.h>
#include <stdlib.h>


/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>


static char buffer[2048];


/* Fake readline function */
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}


#else
#include <editline/readline.h>
#include <editline/history.h>
#endif


int main(int argc, char** argv) {

    
    /* Print Version and Exit Information */
    puts("\nLisp Version 0.0.0.0.1");
    puts("This is ALFA Version (Plz Be patient i have autism)");
    puts("Press Ctrl+c to Exit\n");
    
    while (1) {
    
    /* Output our prompt and get input*/
    char* input = readline("Handy> ");
    add_history(input);
    
    /* Echo input back to user */
    printf("Yes you're a %s\n'", input);
    free(input);
    
    }
    
    return 0;
}



