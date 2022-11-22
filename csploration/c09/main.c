/****************************************
 * C-ploration 5 for CS 271
 * 
 * [NAME] $Eric Johnson$
 * [TERM] FALL $YEAR$
 * 
 ****************************************/
#include "parser.h"
#include "symtable.h"
#include "error.h"

int main(int argc, const char *argv[])
{		
	
    //Check that one argument has been passed. If not, print a "Usage" message and exit with a failure (like last week). 
    //Open the argument passed as a file and save it as a file pointer FILE* variable (like last week). 
   // Check if your file pointer is NULL. If so, print an error message and exit with a failure (like last week).
    //Call our function (yet to be written!) parse and pass it the file pointer. 
    //Close your file pointer (like last week).

	
	//exercise 2
	//// if incorrect number of arguments
if (argc != 2) {
    // incorrect number of arguments
    exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);        
}  
	
	//exercise 3
	FILE *fin = fopen(argv[1], "r");

	//Add an if statement to make sure the file pointer is not NULL. 
	//If it is NULL then we want to print the following error and exit the program.
if(fin == NULL){ 
   exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
}

	parse(fin);
	//symtable_print_labels();
	fclose(fin);
}


