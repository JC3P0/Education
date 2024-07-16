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

    @1
    D = M		// set 1 to D
    @i			
    M = D
    @sum		// sum = 0
    M = 0

(LOOP)			// loop condition while i > 0
    @i
    D = M
    @END		// goto END
    D;JEQ
    @0
    D = M
    @sum		
    M = D + M
    @i			
    M = M - 1	
    @LOOP		// restart loop
    0;JMP
	
(END)
    @sum		// set sum to D
    D = M
    @2			// store sum in 2
    M = D
    @END
    0;JMP 		// infinite loop