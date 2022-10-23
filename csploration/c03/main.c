/****************************************
 * C-ploration 3 for CS 271
 * 
 * [NAME] $YOUR_NAME$
 * [TERM] FALL $YEAR$
 * 
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>

//exercise 1
#define MAX_LIMIT 200  /* max size for static string */

int main(int argc, const char *argv[])
{	
	//exercise 2
	//// if incorrect number of arguments
	if (argc != 2)
	{
	printf("Usage: %s [filename]\n", argv[0]);
	exit(EXIT_FAILURE);
	}
	
	//exercise 3
	FILE *fin = fopen( argv[1], "r" );

	//Add an if statement to make sure the file pointer is not NULL. 
	//If it is NULL then we want to print the following error and exit the program.
	if (fin == NULL) 
	{
	perror("Unable to open file!");
	exit(EXIT_FAILURE);
	}

	//exercise 4
	//copy name of file given as argument
	//concatonate suffix ".echo"
	//use fopen again on outfile, except 1.  name file pointer fout 2. pass outfile as first argument 3. w+ as second argument
	char out_file[80];
	strcpy(out_file, argv[1]);
	//out_file = argv[1]; //is this just grabbing the file though?
	strcat(out_file, ".echo");

	FILE *fout = fopen(out_file, "w+");

	//Exercise 5
	char line[MAX_LIMIT] = {0};
	unsigned int line_num = 0;

	while (fgets(line, sizeof(line), fin)) 
	{
	line_num += 1;
	printf("[%04d] %s", line_num, line);
	fprintf(fout, line);
	//increment the line number variable 
	//print the line number (fin brackets) and the line text (use [%04d])
	//fprintf the line to output file
	}
	//exercise 6
	//check if correct!
	fclose(fin);
	fclose(fout);


	return 1;
}
