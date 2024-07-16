//(START)		// reset pixel counter to 8192
    @SCREEN
    D = A
    @address
    M = D
    @8192	// total number of pixels on screen
    D = A
    @pixels
    M = D

(CHECK) 	// keyboard input
    @pixels	// check for missing pixels
    D = M
    @START
    D;JEQ	// if out = 0, goto START
    //@KBD	// check keyboard input
    D = M
    //@BLACKSCREEN 	// black screen if key is pressed
    D;JNE

//(BLACKSCREEN)	
	@address	// set the pixel at address to 1
	A = M
	M = -1
	@address
	M = M + 1
	@pixels	
	M = M - 1
	
	@CHECK	// retrieve user input
	0;JMP

