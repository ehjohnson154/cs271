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


opcode instruction_to_opcode(c_instruction instr){
	//In this function, we need to convert of C-instruction struct to binary bits. 
	//I'll get us started.

	//In this function, we need to convert of C-instruction struct to binary bits. I'll get us started.
	// opcode op = 0;
	// op |= (7 << 13);
	// ... move to the left 13 places for cpu instructions
	//This adds the 111 bits and bitshifts it 13 places, so the three most significant bits are 111.
	//Continue this pattern and add the a, comp, dest, and jump bits, each bitshifted to their proper location.
	opcode op = 0;
	op |= (7 << 13);
	op |= (instr.a << 12);
	op |= (instr.comp << 6);
	op |= (instr.dest << 3);
	op |= (instr.jump << 0);
	return op;
	// Return the op variable.	

}

void assemble(const char * file_name, instruction* instructions, int num_instructions){
	
    // open a file for writing named after the given file_name with added file suffix ".hack"
    //     e.g.  "Max.asm" becomes "Max.asm.hack"
	FILE * fp;
	fp = fopen((file_name + '.hack'), 'w');
	int address=16;

    
    
	for(int i=0; i < instructions; i++) // iterate over the number of instructions
	{
		
		if(instructions->i_type.a.is_addr == false)// if A-type label
		{
			if (symtable_find(instructions->i_type.a.a_type.label == NULL)){
				symtable_insert(instructions->i_type.a.a_type.label, address);
				address++;
			}
			
			else{
				instructions -> i_type.a.a_type.address = symtable_find(instructions->i_type.a.a_type.label); //IS THIS RIGHT?
			}

			free(instructions->i_type.a.a_type.label);    // free the memory associated with the label in the instruction
			
		}
	
		if(instructions->i_type.a.is_addr == true) //if A-type address
		{
			instructions -> i_type.a.a_type.address = symtable_find(instructions->i_type.a.a_type.address); //IS THIS RIGHT?
		}

		if(instructions->field = Ctype) //if C-type instruction
		{
    //         lookup the opcode instruction_to_opcode (explained below)
			instruction_to_opcode(instructions->i_type.c);
		}
    //     print the 16 character %c opcode using macro OPCODE_TO_BINARY (explained below)
		printf("%c", OPCODE_TO_BINARY); //FINISH THIS
	} 
	fclose(fp); // close the file pointer
}


void parse_C_instruction(char *line, c_instruction *instr){
	char* temp;
	char* jump;
	char* comp;
	int a = 0;
	
	char* dest;
	//printf("program entered parse_c!");

	//split into jump, dest, comp
	temp = strtok(line, ";");
	jump = strtok(NULL, "");
	dest = strtok(temp, "=");
	comp = strtok(NULL, "");

	//printf("program split!");
	
	//check if comp is NULL

	if (comp == NULL){
		comp = dest;
		dest = NULL;
	}
	//printf("program checked null!");
	// printf(comp);
	// printf(a);
	instr -> comp = str_to_compid(comp, &a);
	//printf(comp);
	//printf(a);
	//printf("Program assigned comps!");
	instr -> dest = str_to_destid(dest);
	//printf("program assigned dests!");
	instr -> jump = str_to_jumpid(jump);

	//printf("program assigned values!");

	//split apart string by ; = 
	//catch if null after lass step
	//set jump, comp, a, dest fields of instr. use our 3 inline functions in hack.h
	//can do above step in one line
}

void add_predefined_symbols(){
	//for loop
	//iterate over NUM_PREDEFINED_SYMBOLS
	for(int i=0; i < NUM_PREDEFINED_SYMBOLS; i++)
	{
		//load each value of predefined_symbols array into instance of struct predefined_symbol
		predefined_symbol pred_sym = predefined_symbols[i];

		//Because we save string/int, set struct instance to "i-th" position of predefined_symbols array,
		//corresponding values become name and address

		//load predefined_symbol into symbol table using symtable_insert
		symtable_insert(pred_sym.name,pred_sym.address);

	}
}



bool parse_A_instruction(const char *line, a_instruction *instr){
	//temp string s, malloc based on length of line, skip usual +1
	char* s = (char*) malloc((strlen(line)));
	
	//Copy line+1 to s
	strcpy(s, (line+1));
	
	//Create a string s_end, set to null
	char* s_end = NULL;
	long result = strtol(s,&s_end, 10); //this means string to long in base 10
	//Check if s is equal to s_end, 
	if (s == s_end){
		//means we have a string
		//malloc operand.label, use length as size
		instr -> a_type.label = (char*)malloc(strlen(line));

		//copy s to operand.label of instr
		strcpy((instr-> a_type.label),s);
		//set is_address of instr to false, since label
		instr->is_addr = false;
	}
	
	else if (*s_end != 0){
		//means we have a mix of string and int
		return false;
	}
	else{
		//means we have a number
		//set operand.address of instr to be result
		instr -> a_type.address = result;
		//set is_addr of instr to be true, since its a address
		instr->is_addr = true;
	}
	return true;

}


char *extract_label(const char *line, char* label){


		// Your function extracts the name of the label (removing the parenthesis) and puts it in the variable label. 
		//You should also return label. 

	strcpy(label, line+1);
	label[strlen(line)-2] = '\0';
	return label;
}


/*Function is_Atype
An Atype (address) instruction will always begin with the @ symbol. 
So if the first character of line is the "at" symbol, then we return true. 
If not, we return false. 
*/

bool is_Atype(const char *line){
	if (line[0] == '@'){
		return true;
	}
	else {
		return false;
	}
}
/*
Function is_label
verify that the first and the last characters are ( and ) respectively (and thus a label). 
Remember that strings are just character arrays, 
so the last character is at the length of the line minus one. 

This is relevant because this gives us two ways to ask our question here. 
We can ask if both the first and last characters are ( and ) then return true. Or, in the other approach, we can ask if the first character is not 
( and return false and then ask if the last character is not ) and also return false. 
*/
bool is_label(const char *line){
	int linelen = strlen(line);
	if ((line[0] == '(') &&(line[linelen-1] == ')') ){
		return true;
	}
	else {
		return false;
	}
}

bool is_Ctype(const char *line){
	if ((is_label(line) == false)&&(is_Atype(line) == false)){
		return true;
	}
	else {
		return false;
	}
}

/* Function: strip
 * -------------
 * remove whitespace and comments from a line
 *
 * s: the char* string to strip
 *
 * returns: the stripped char* string
 */
char *strip(char *s){	

	// set up variables
	char s_new[(strlen(s)+1)];
	unsigned int i = 0;

	for (char *s2 = s; *s2; s2++) //temp pointer *s2 = passed in string; While there is character in s2 ;
	 { 
		if ((*s2 == '/') && (*(s2+1) == '/'))//checking for code comments
		{
			break;
		}
		else if (!(isspace(*s2)))//checking to confirm is not empty string
		{
			s_new[i++] = *s2; //adding character in string position
		}
	}
	s_new[i] = '\0'; //ending string with null terminator
	strcpy(s, s_new); //s copies s_new
	
    return s;	
}

/* Function: parse
 * -------------
 * iterate each line in the file and strip whitespace and comments. 
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 */
//EXERCISE 8//

//void parse(FILE * file){
int parse(FILE * file, instruction *instructions){
	
	instruction instr; //will load up instr with A or C instruction
	char line[MAX_LINE_LENGTH] = {0}; //sets up variables
	//char label[MAX_LABEL_LENGTH] = {0};
	
	unsigned int line_num = 0;
	//char inst_type;
	unsigned int instr_num = 0;


	//EXERCISE 8//
	char tmp_line[MAX_LINE_LENGTH];



	add_predefined_symbols();
	//symtable_display_table(); //verify
	while (fgets(line, sizeof(line), file)) 
	{
		line_num += 1;

		//Add an if statement that checks if the instr_num is greater than our constant MAX_INSTRUCTIONS. 
		//If it is, call this function to exit.
		if (instr_num > MAX_INSTRUCTIONS)
		{
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
		}

		strip(line); //alters line to strip of whitespace

		if (*line == '\0') //if memory at line is not equal to null terminator/empty line:
		{ 
			continue;
		}

		
		else if (is_Ctype(line))
		{

		strcpy(tmp_line, line);

		parse_C_instruction(tmp_line, (&instr.i_type.c)); //??

		//printf("program parsed c instructions!");

		if (instr.i_type.c.dest == DEST_INVALID){
			exit_program(EXIT_INVALID_C_DEST, line_num, line);
		}
		if (instr.i_type.c.comp == COMP_INVALID){
			exit_program(EXIT_INVALID_C_COMP, line_num, line);
		}
		if (instr.i_type.c.jump == JMP_INVALID){
			exit_program(EXIT_INVALID_C_JUMP, line_num, line);
		}
		instructions->field = Ctype;

		printf("C: d=%d, c=%d, j=%d\n", instr.i_type.c.dest, instr.i_type.c.comp, instr.i_type.c.jump);
		//printf("program did not exit!");


		}		
		else if (is_Atype(line))
		{
			//EXERCISE 6:
			if (!parse_A_instruction(line, &instr.i_type.a)){
    			exit_program(EXIT_INVALID_A_INSTR, line_num, line);
 			}
 			instr.field = Atype;

			//inst_type = 'A';
			if (instr.i_type.a.is_addr == true){
				printf("A: %d\n", instr.i_type.a.a_type.address);
			}
			else{
				printf("A: %s\n", instr.i_type.a.a_type.label);
			}
			
		}
		else if (is_label(line))
		{


			//inst_type = 'L';

			char new_label[MAX_LABEL_LENGTH];
			extract_label(line, new_label);


			if(isalpha(new_label[0])==0){
				exit_program(EXIT_INVALID_LABEL, line_num, new_label);
			}

			if(symtable_find(new_label) != NULL){
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, new_label);
			}

			symtable_insert(new_label, instr_num);
			continue;

		}

		//printf("%c  %s\n",inst_type,line);
		//printf("%u: %c  %s\n", instr_num, inst_type, line);
		instructions[instr_num++] = instr;
		

	
	}
	//EXERCISE 9
	return instr_num;
	
}


// Test Failed: b'A: 42\nERROR: Line 4: DAM=A : Invalid destination part of C-instruction\n' 
// !=           b'A: 42\nC: d=-1, c=48, j=0\nA: 0\nC: d=0, c=42, j=7\n' 
// : incorrect catch of invalid C-type dest instruction.

// Test Failed: b'A: 100\nERROR: Line 4: D=A+A : Invalid compare part of C-instruction\n' 
// != b'A: 100\nC: d=2, c=-1, j=0\nA: 0\nC: d=0, c=42, j=7\n' 
// : incorrect catch of invalid C-type comp instruction.

// Test Failed: b'A: [72 chars]: 0\nERROR: Line 10: 0;JUMP : Invalid jump par[16 chars]on\n' 
// != b'A: [72 chars]: 0\nC: d=0, c=42, j=-1\n' 
// : incorrect catch of invalid C-type jump instruction.