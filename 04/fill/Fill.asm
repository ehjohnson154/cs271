// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.




//Listens to memory, if memory >0, blacken screen. Else, clear screen


//iterate through allthe screen registers
//fill with 0 or -1 (key not pressed vs pressed)
//once done iterating, jump to listening for keyboard

//KBD 
//SCREEN 
//screen points to first register that contains data on screen
//screen follows screen registry
//Keyboard follwoing screen as "end stop"

//Go to screen symbol, fill with 1 or -1, increment by 1

//go to keyboard memory address to find if key is pressed, save in data register (Temp D) from memory
//Jump depending on result



//SCREEN SECTIONw

@KEYBOARD
0;JMP

(WHITE) //loop through to make screen white
@0
D = M //grabs pointer to first screen location
A=D
M = 0 //stuff to make the screen white
@0
M=D+1 //POINTER ITERATOR
@KBD
D=D+1
D=D-A
@KEYBOARD 
D; JGE //If equal to keyboard location, jump
@WHITE
0;JMP


(BLACK)  //loop through to make screen black
@0
D = M //grabs pointer to first screen location
A=D
M = -1 //STUFF TO MAKE SCREEN BLACK
@0
M=D+1 //POINTER ITERATOR
@KBD
D=D+1
D=D-A
@KEYBOARD 
D; JGE //If equal to keyboard location, jump
@BLACK
0;JMP


//KEYBOARD SECTION


(KEYBOARD)

@SCREEN
D=A //Saves pointer to screen in D
@0
M=D // Saves pointer in memory 0

@KBD
D=M //CHECK KEYBOARD input value

@WHITE //if statement for no keyboard press
D;JEQ

@BLACK //if statement for keyboard press
D;JNE


@KEYBOARD
0; JMP // jumps to start of listen loop 


(END)
@END
0;JMP