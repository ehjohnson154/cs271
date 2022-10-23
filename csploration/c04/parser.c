/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $YOUR_NAME$
 * [TERM] FALL $YEAR$
 * 
 ****************************************/
#include "parser.h"

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
		else if (isspace(*s2) != 0)//checking to confirm is not empty string
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

	while (fgets(line, sizeof(line), file)) 
	{
	line_num += 1;
	strip(line); //alters line to strip of whitespace
	
	if (*line != '\0') //if memory at line is not equal to null terminator/empty line:
	{ 
		printf(line);
	}
	}
	
}