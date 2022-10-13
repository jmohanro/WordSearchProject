// holds all functions not relating to search 

#include <stdio.h>
#include <string.h>
#include <unistd.h>


//converts input file to lowercase
void lowerPuzzle(struct board* boardObject){
	
	for (int i = 0; i < boardObject -> r; i++){
		for (int j = 0; j < boardObject -> c; j++){
			(boardObject -> matrix)[i][j] = tolower((boardObject -> matrix)[i][j]);	// line that converts file contents to lowercase
		}
	}
}


//prints wordsearch puzzle
 void printPuzzle(struct board* boardObject){
	 
	 printf("\n");
	 for (int i= 0; i < boardObject-> r;i++){
		 for(int j = 0; j < boardObject-> c; j++){
																// "\t" formats the grid by one tab space each to make it easier for the user to read
			 printf("%c\t",(boardObject -> matrix)[i][j]);		// boardObject points to array storing the wordsearch
		 }
		 printf("\n\n");
	 }
 }
 
 
//reverses input word
void reverseWord(char *input, char*reverse){					
	int i, j, inputLength = strlen(input);
	for(i = (inputLength - 1), j = 0; i >=0; i--, j++){			// takes the original userInput and reverses it. Stores it in a seperate array to be tested.
		reverse[j] = input[i];
	}
	
	reverse[inputLength + 1] = '\0';
	//reverse[end_position] = '\0';
	/*for (int x = 0; x < inputLength; x++){					// TEST
		printf("%c", reverse[x]);
	}*/
}	
