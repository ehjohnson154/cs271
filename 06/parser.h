/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $Eric Johnson$
 * [TERM] FALL $YEAR$
 * 
 ****************************************/
#ifndef __PARSER_H__
#define __PARSER_H__

// All code in file

#include "hack.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
//#include <strtol.h>

typedef int16_t hack_addr;
typedef int16_t opcode;

#define MAX_LINE_LENGTH  200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH-2)


#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS

//Structs

typedef enum instr_type {
    Inval = -1, 
    Atype,
    Btype,
	Ctype,
    }instr_type;

typedef struct c_instruction {
	opcode a:1;
	opcode comp:7;
	opcode dest:4; 
	opcode jump:4;

} c_instruction;

typedef struct a_instruction {
	//Inside your a_instruction struct, we are going to store two things. 
	//The first is a union type, which allows us to store one of two types of things (like a choice).
	//The second field is a Boolean which tells us if the union is storing an address or a label.
	union a_type{
		//address of type hack_addr
		hack_addr address;
		//label of type char*
		char* label;

	}a_type;
	bool is_addr;
} a_instruction;

typedef struct instruction{
	//The union gives us the choice between A-type and C-type. 
	//The second field, which you can name whatever you think is appropriate, tells us which type of instruction we stored. 
	//We are using the enum we defined in an earlier exercise. 
	union i_type{
		a_instruction a;
		c_instruction c;
	}i_type;
	instr_type field;
} instruction;



void add_predefined_symbols();


bool parse_A_instruction(const char *line, a_instruction *instr);

/** function prototypes **/
char *strip(char *s);

//void parse(FILE * file);
int parse(FILE * file, instruction *instructions);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);
char *extract_label(const char *line, char* label);


void parse_C_instruction(char *line, c_instruction *instr);

//WRITE ASSEMBLY FUNCTION
void assemble(const char * file_name, instruction* instructions, int num_instructions);
//WRITE INSTRUCTION TO OPCODE FUNCTION
opcode instruction_to_opcode(c_instruction instr);

#endif