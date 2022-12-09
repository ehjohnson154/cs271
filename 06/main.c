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

#define MAX_INSTRUCTION_COUNT 30000

int main(int argc, const char *argv[])
{		
	
    instruction *instructions = malloc(MAX_INSTRUCTION_COUNT * sizeof(instruction));

	//// if incorrect number of arguments
if (argc != 2) {
    exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);        
}  
	FILE *fin = fopen(argv[1], "r");

	//Add an if statement to make sure the file pointer is not NULL. 
	//If it is NULL then we want to print the following error and exit the program.
if(fin == NULL){ 
   exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
}

	int num_instructions = parse(fin, instructions);
	//symtable_print_labels();
	fclose(fin);
    //CALL ASSEMBLE FUNCTION
	// for(int i=0; i < num_instructions; i++){
	// 	instruction * instr = instructions+i;
	// 	printf("%d\n", instr->field);
	// }

    assemble(argv[1], instructions, num_instructions);
    free(instructions);
}


