#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


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
    }symbol_id;


typedef struct predefined_symbol
{
    char* name;
    int16_t address;
}predefined_symbol;



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

//EXERCISE 1 //

typedef enum jump_id{
    JMP_INVALID = -1,
    JMP_NULL,
    JMP_JGT,
    JMP_JEQ,
    JMP_JGE,
    JMP_JLT,
    JMP_JNE,
    JMP_JLE,
    JMP_JMP,
}jump_id;

//EXERCISE 2//
typedef enum dest_id{
    DEST_INVALID = -1,
    DEST_NULL,
    DEST_M,
    DEST_D,
    DEST_MD,
    DEST_A,
    DEST_AM,
    DEST_AD,
    DEST_AMD,

    //DEFINE RESTS OF JUMP OPTIONS
}dest_id;

//EXERCISE 3//

typedef enum comp_id{
    // COMP_INVALID = -1,
    // COMP_NULL = 0,
    // COMP_0 = 42,
    // COMP_1 = 63,
    // COMP_2 = 58, //-1
    // COMP_3 = 12, //D
    // COMP_4 = 48, //A
    // COMP_5 = 13, //!D
    // COMP_6 = 49, //!A
    // COMP_7 = 15, //-D
    // COMP_8 = 51, //-A
    // COMP_9 = 31, //D+1
    // COMP_10 = 55, //A+1
    // COMP_11 = 14, //D-1
    // COMP_12 = 50, //A-1
    // COMP_13 = 2, //D+A
    // COMP_14 = 19, //D-A
    // COMP_15 = 7, //A-D
    // COMP_16 = 0, // D&A
    // COMP_17 = 21, //D|A

    COMP_INVALID = -1,
    COMP_0 = 42,
    COMP_1 = 63,
    COMP_2 = 58,
    COMP_3 = 12,
    COMP_4 = 48,
    COMP_5 = 13,
    COMP_6 = 49,
    COMP_7 = 15,
    COMP_8 = 51,
    COMP_9 = 31,
    COMP_10 = 55,
    COMP_11 = 14,
    COMP_12 = 50,
    COMP_13 = 2,
    COMP_14 = 19,
    COMP_15 = 7,
    COMP_16 = 0,
    COMP_17 = 21,
    COMP_18 = 48,
    COMP_19 = 49,
    COMP_20 = 51,
    COMP_21 = 55,
    COMP_22 = 50,
    COMP_23 = 2,
    COMP_24 = 19,
    COMP_25 = 7,
    COMP_26 = 0,
    COMP_27 = 21
}comp_id;

//EXERCISE 4//

static inline jump_id str_to_jumpid(const char *s){
    jump_id id = JMP_INVALID;
    if (s == NULL) {
    id = JMP_NULL;
    } 
    //continue else-if statements to check against various jumps
    else if (!strcmp(s,"JGT")){
    id = JMP_JGT;
    }
    else if (strcmp(s,"JEQ")==0){
    id = JMP_JEQ;
    }
    else if (strcmp(s,"JGE")== 0){
    id = JMP_JGE;
    }
    else if (strcmp(s,"JLT") == 0){
    id = JMP_JLT;
    }
    else if (strcmp(s,"JNE") == 0){
    id = JMP_JNE;
    }
    else if (strcmp(s,"JLE")== 0){
    id = JMP_JLE;
    }
    else if (strcmp(s,"JMP")== 0){
    id = JMP_JMP;
    }
    return id;
}

//exercise 5//

static inline dest_id str_to_destid(const char *s){
    //similar function to 4, except destinations. FINISH
    dest_id id = DEST_INVALID;
    if (s == NULL) {
    id = DEST_NULL;
    } 
    else if (strcmp(s,"M")== 0){
    id = DEST_M;
    }
    else if (strcmp(s,"D")== 0){
    id = DEST_D;
    }
    else if (strcmp(s,"MD") == 0){
    id = DEST_MD;
    }
    else if (strcmp(s,"A") == 0){
    id = DEST_A;
    }
    else if (strcmp(s,"AM") == 0){
    id = DEST_AM;
    }
    else if (strcmp(s,"AD") == 0){
    id = DEST_AD;
    }
    else if (strcmp(s,"AMD") == 0){
    id = DEST_AMD;
    }
    return id;

}

static inline comp_id str_to_compid(const char *s, int *a){
    //similar function to 4, except computations. 
    //also set value of a, passed by pointer. FINISH
    comp_id id = COMP_INVALID;
//     if (strcmp(s,"0") == 0){
//     id = COMP_0;
//     *a = 0;
//     }
//     else if (strcmp(s,"1") == 0){
//     id = COMP_1;
//     *a = 0;
//     }
//     else if (strcmp(s,"-1") == 0){
//     id = COMP_2;
//     *a = 0;
//     }
//     else if (strcmp(s,"D") == 0){
//     id = COMP_3;
//     *a = 0;
//     }
//     else if (strcmp(s,"A") == 0){
//     id = COMP_4;
//     *a = 0;
//     }
//     else if (strcmp(s,"M") == 0){
//     id = COMP_4;
//     *a = 1;
//     }
//     else if (strcmp(s,"!D") == 0){
//     id = COMP_5;
//     *a = 0;
//     }
//     else if (strcmp(s,"!A") == 0){
//     id = COMP_6;
//     *a = 0;
//     }
//     else if (strcmp(s,"!M")== 0){
//     id = COMP_6;
//     *a = 1;
//     }
//     else if (strcmp(s,"-D") == 0){
//     id = COMP_7;
//     *a = 0;
//     }
//     else if (strcmp(s,"-A") == 0){
//     id = COMP_8;
//     *a = 0;
//     }
//     else if (strcmp(s,"-M") == 0){
//     id = COMP_8;
//     *a = 1;
//     }
//     else if (strcmp(s,"D+1") == 0){
//     id = COMP_9;
//     *a = 0;
//     }
//     else if (strcmp(s,"A+1") == 0){
//     id = COMP_10;
//     *a = 0;
//     }
//     else if (strcmp(s,"M+1") == 0){
//     id = COMP_10;
//     *a = 1;
//     }
//     else if (strcmp(s,"D-1") == 0){
//     id = COMP_11;
//     *a = 0;
//     }
//     else if (strcmp(s,"A-1") == 0){
//     id = COMP_12;
//     a = 0;
//     }
//     else if (strcmp(s,"M-1") == 0){
//     id = COMP_12;
//     *a = 1;
//     }
//     else if (strcmp(s,"D+A") == 0){
//     id = COMP_13;
//     *a = 0;
//     }
//     else if (strcmp(s,"D+M") == 0){
//     id = COMP_13;
//     *a = 1;
//     }
//     else if (strcmp(s,"D-A") == 0){
//     id = COMP_14;
//     *a = 0;
//     }
//     else if (strcmp(s,"D-M") == 0){
//     id = COMP_14;
//     *a = 1;
//     }
//     else if (strcmp(s,"A-D") == 0){
//     id = COMP_15;
//     *a = 0;
//     }
//     else if (strcmp(s,"M-D") == 0){
//     id = COMP_15;
//     *a = 1;
//     }
//     else if (strcmp(s,"D&A") == 0){
//     id = COMP_16;
//     *a = 0;
//     }
//     else if (strcmp(s,"D&M") == 0){
//     id = COMP_16;
//     *a = 1;
//     }
//     else if (strcmp(s,"D|A") == 0){
//     id = COMP_17;
//     *a = 0;
//     }
//     else if (strcmp(s,"D|M") == 0){
//     id = COMP_17;
//     *a = 1;
//     }
//     return id;

// }

	if (!strcmp(s, "0")) {
		id = COMP_0;
	} else if (!strcmp(s, "1")) {
		*a = 0;
		id = COMP_1;
	} else if (!strcmp(s, "-1")) {
		*a = 0;
		id = COMP_2;
	} else if (!strcmp(s, "D")) {
		*a = 0;
		id = COMP_3;
	} else if (!strcmp(s, "A")) {
		*a = 0;
		id = COMP_4;
	} else if (!strcmp(s, "!D")) {
		*a = 0;
		id = COMP_5;
	} else if (!strcmp(s, "!A")) {
		*a = 0;
		id = COMP_6;
	} else if (!strcmp(s, "-D")) {
		*a = 0;
		id = COMP_7;
	} else if (!strcmp(s, "-A")) {
		*a = 0;
		id = COMP_8;
	} else if (!strcmp(s, "D+1")) {
		*a = 0;
		id = COMP_9;
	} else if (!strcmp(s, "A+1")) {
		*a = 0;
		id = COMP_10;
	} else if (!strcmp(s, "D-1")) {
		*a = 0;
		id = COMP_11;
	} else if (!strcmp(s, "A-1")) {
		*a = 0;
		id = COMP_12;
	} else if (!strcmp(s, "D+A")) {
		*a = 0;
		id = COMP_13;
	} else if (!strcmp(s, "D-A")) {
		*a = 0;
		id = COMP_14;
	} else if (!strcmp(s, "A-D")) {
		*a = 0;
		id = COMP_15;
	} else if (!strcmp(s, "D&A")) {
		*a = 0;
		id = COMP_16;
	} else if (!strcmp(s, "D|A")) {
		*a = 0;
		id = COMP_17;
	} else if (!strcmp(s, "M")) {
		*a = 1;
		id = COMP_18;
	} else if (!strcmp(s, "!M")) {
		*a = 1;
		id = COMP_19;
	} else if (!strcmp(s, "-M")) {
		*a = 1;
		id = COMP_20;
	} else if (!strcmp(s, "M+1")) {
		*a = 1;
		id = COMP_21;
	} else if (!strcmp(s, "M-1")) {
		*a = 1;
		id = COMP_22;
	} else if (!strcmp(s, "D+M")) {
		*a = 1;
		id = COMP_23;
	} else if (!strcmp(s, "D-M")) {
		*a = 1;
		id = COMP_24;
	} else if (!strcmp(s, "M-D")) {
		*a = 1;
		id = COMP_25;
	} else if (!strcmp(s, "D&M")) {
		*a = 1;
		id = COMP_26;
	} else if (!strcmp(s, "D|M")) {
		*a = 1;
		id = COMP_27;
	}
	return id;
}

//WRITE OPCODE TO BINARY
#define OPCODE_TO_BINARY(opcode) \
  (opcode & 0x8000 ? '1' : '0'), \
  (opcode & 0x4000 ? '1' : '0'), \
  (opcode & 0x2000 ? '1' : '0'), \
  (opcode & 0x1000 ? '1' : '0'), \
  (opcode & 0x0800 ? '1' : '0'), \
  ...
  //define this for other 15 bitsg

  