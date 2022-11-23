#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>



/*
 * Error code 1 represents that given file does not exist.
 */
typedef enum exitcode
{
    EXIT_INCORRECT_ARGUMENTS = 1,
    EXIT_CANNOT_OPEN_FILE,
    EXIT_TOO_MANY_INSTRUCTIONS,
    EXIT_INVALID_ARGUMENTS,
    EXIT_INVALID_LABEL,
    EXIT_SYMBOL_ALREADY_EXISTS,
    EXIT_INVALID_A_INSTR,
    }exitcode;


//add the item to enum exitcode (it's number 2)

void exit_program(enum exitcode code, ...);

#endif