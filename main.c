/**********************************
 * Author: Joshua Mohanroy
 * Email: j_mohanroy@u.pacific.edu
 * *******************************/
 
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>		// Allows toupper+tolower function 
 #include <stdlib.h>	// malloc, calloc, etc
 #include <stdbool.h>	// allows for bool operations
 #include "search.h"	// contains all search functions
 #include "logic.h"		// contains all non-search functions
 
 
 

 int main(void){
	 
	 int i,j,l;
	 struct board puzzle;
	 char inputWord[30]; // array to store input word from user
	 char revWord[30];	 // holds reverse word of user input if origional input is not found
	 char textFile[15];  // storing text file input from user


	printf("WELCOME TO WORD SEARCH!\n");
	printf("Enter the name of the wordSearch file: ");
	scanf ("%s", textFile);
	
	// File management
	FILE *fptr;
	fptr = fopen(textFile, "r");
	
			if(fptr){			// File Verification
				printf("FILE FOUND\n\n");
				fscanf(fptr, "%d %d", &puzzle.r, &puzzle.c);
				
				//malloc
				puzzle.matrix = (char**)malloc(sizeof(char*)*puzzle.r);
				for(i = 0; i < puzzle.r; i++){
					(puzzle.matrix)[i] = (char*)malloc(sizeof(char)*puzzle.c);
				}
				
				//populate array with word search puzzle
				for (i = 0; i < puzzle.r; i++){
					for (j = 0; j < puzzle.c; j++){
						l = fgetc(fptr);
						if(l != '\n'){					// skips null character and reads the next actual character
							(puzzle.matrix)[i][j] = l;
						}else{
							l = fgetc(fptr);
							(puzzle.matrix)[i][j] = l;
						}
					}
				}
			}else{
				printf("\nError! File not found.\n");	// fail statement and program termination if file is not found
				printf("PROGRAM TERMINATED!\n");
				exit(0);
			}
			
			
		lowerPuzzle(&puzzle); 							//converts puzzle to lowercase
				
	
	while(inputWord[1] != 'x'){				// loops through program unless user enters 'exit'
		
		system("clear");						// clears console for a cleaner output during multiple word searches
		printPuzzle(&puzzle);					// Prints wordSearch to user
		searchWord(inputWord);					// Asks user for word to search for and saves that data
		horizontalSearch(inputWord, &puzzle);	// horizontally searches for word
		verticalSearch(inputWord, &puzzle);		// vertically searches for word
		diagonalSearch(inputWord, &puzzle);		// diagonally searches for word
		
		reverseWord(inputWord, revWord);		// reverses word and searches for it if it is not found in the correct direction
		
		horizontalSearch(revWord, &puzzle);		// horizontally searches for word
		verticalSearch(revWord, &puzzle);		// vertically searches for word
		diagonalSearch(revWord, &puzzle);		// diagonally searches for word
		
		
}

	
	free(puzzle.matrix); 	// freeing dynamic memory
	fclose(fptr); 			// closing file
	exit(0);	  			// exiting program
    return 0;
}
 
 
	 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
