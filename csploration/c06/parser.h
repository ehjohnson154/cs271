/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $Eric Johnson$
 * [TERM] FALL $YEAR$
 * 
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

typedef int16_t hack_addr;
typedef int16_t opcode;

#define MAX_LINE_LENGTH  200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH-2)

typedef enum instr_type {
    Inval = -1, 
    Atype,
    Btype
    }instr_type;

typedef struct c_instruction {
	opcode a:1;
	opcode comp:6;
	opcode dest:3; 
	opcode jump:3;

} c_instruction;

typedef struct a_instruction {
	//Inside your a_instruction struct, we are going to store two things. 
	//The first is a union type, which allows us to store one of two types of things (like a choice).
	//The second field is a Boolean which tells us if the union is storing an address or a label.
	union {
		//address of type hack_addr
		hack_addr address;
		//label of type char*
		char* label;

	};
	bool is_addr;
} a_instruction;

typedef struct instruction{
	//The union gives us the choice between A-type and C-type. 
	//The second field, which you can name whatever you think is appropriate, tells us which type of instruction we stored. 
	//We are using the enum we defined in an earlier exercise. 
	union{
		a_instruction a;
		c_instruction c;
	};
	instr_type field;
} instruction;

/** function prototypes **/
char *strip(char *s);

void parse(FILE * file);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);
char *extract_label(const char *line, char* label);



