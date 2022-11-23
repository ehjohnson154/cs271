


//EXERCISE 1: Enum for predefined symbols
//add 23 symbols,see textbook/slides for full list and values

#include <stdint.h>

#define NUM_PREDEFINED_SYMBOLS 23

typedef enum symbol_id
{
    SYM_R0 = 0,
    SYM_R1 = 1,
    SYM_R2 = 2,
    SYM_R3 = 3,
    SYM_R4 = 4,
    SYM_R5 = 5,
    SYM_R6 = 6,
    SYM_R7 = 7,
    SYM_R8 = 8,
    SYM_R9 = 9,
    SYM_R10 = 10,
    SYM_R11 = 11,
    SYM_R12 = 12,
    SYM_R13 = 13,
    SYM_R14 = 14,
    SYM_R15 = 15,
    SYM_SCREEN = 16384,
    SYM_KBD = 24576,
    SP = 0,
    LCL = 1,
    ARG = 2,
    THIS = 3,
    THAT = 4,

    //COMPLETE REMAINING SYMBOLS!!
    }symbol_id;

//EXERCISE 2:
typedef struct predefined_symbol
{
    //FINISH AND CHECK
    char* name;
    int16_t address;
}predefined_symbol;

//EXERCISE 3

static const predefined_symbol predefined_symbols[NUM_PREDEFINED_SYMBOLS] = {
    {"R0", SYM_R0}, 
    {"R1", SYM_R1}, 
    {"R2", SYM_R2},
    {"R3", SYM_R3},
    {"R4", SYM_R4},
    {"R5", SYM_R5},
    {"R6", SYM_R6},
    {"R7", SYM_R7},
    {"R8", SYM_R8},
    {"R9", SYM_R9},
    {"R10", SYM_R10},
    {"R11", SYM_R11},
    {"R12", SYM_R12},
    {"R13", SYM_R13},
    {"R14", SYM_R14},
    {"R15", SYM_R15},
    {"SCREEN", SYM_SCREEN},
    {"KBD", SYM_KBD},
    {"SP", SP},
    {"LCL", LCL},
    {"ARG", ARG},
    {"THIS", THIS},
    {"THAT", THAT}

};