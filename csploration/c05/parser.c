/****************************************
 * C-ploration 5 for CS 271
 * 
 * [NAME] $Eric Johnson$
 * [TERM] FALL $YEAR$
 * 
 ****************************************/
#include "parser.h"


/*Function is_Atype
STUFF
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
void parse(FILE * file){
	//sets up variables
	char line[MAX_LINE_LENGTH] = {0};
	unsigned int line_num = 0;
	char inst_type;


	while (fgets(line, sizeof(line), file)) 
	{
		line_num += 1;
		strip(line); //alters line to strip of whitespace
		if (is_Ctype(line))
		{
			inst_type = 'C';
		}		
		if (is_Atype(line))
		{
			inst_type = 'A';
		}
		if (is_label(line))
		{
			inst_type = 'L';
		}	
		if (*line != '\0') //if memory at line is not equal to null terminator/empty line:
		{ 
			//Next, change your printf to print a single character %c and two blank spaces before your %s line.
			printf("%c  %s\n",inst_type,line);
		}
	}
	
}