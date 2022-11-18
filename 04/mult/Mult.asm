// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

//@0
//D=M
//@1
//D=D&M
//@2
//M=D
//(Infinite_loop)
//@Infinite_loop
//0; JMP


@2 //
M=0 //set R2 to 0 STORE VALUE HERE
(WHILE) 
@1 //
D=M //Set D = R1
@END
D;JLE //Check that R1 >= 1
@0 
D=M //Set D equal to R0
@2
M=M+D //Add R0 to R2
@1
M=M-1 //Iterate down R1
@WHILE
0;JMP

(END)
@END
0;JMP