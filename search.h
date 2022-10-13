// Functions used to search for words

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct board{
	int r;
	int c;
	char **matrix;
};



// get word from user to search for
void searchWord(char *userInput){
	
	printf("Please enter the word you would like to search for or type 'exit' to quit: ");
	scanf("%s", userInput); // gets user input and stores it in a 1D Array for strings

}



// Search for word horizontally
void horizontalSearch(char *input, struct board *boardObject){
	int iterator = 0;
	int inputLength = strlen(input);										// gets length of string in the array
	
	for (int i = 0; i < boardObject -> r; i++){		
		for(int j = 0; j < boardObject -> c; j++){
			
			if ((boardObject -> matrix)[i][j] == input[0]){					// checks if first character in inputArray matches character in matrix
				iterator = 0;												// resets iterator to 0 incase search finds matching first character without the correct succeeding characters							
				for (int a = 0; a < inputLength; a++){			
					if (j+a < boardObject -> c){							// Keeps iterator from going out of bounds
						if ((boardObject -> matrix)[i][j+a] == input[a]){	// checks if succeeding characters to first letter match the userInput word in the matrix
							iterator++;
						}
					}
				}
				if (iterator == inputLength){								// if length matches and characters match, exists loop and prints a success statement
					printf("WORD FOUND HORIZONTALLY! Size: ");
					printf("%d", iterator);
					
				}
			}
		}
	}
	return;
}
	
	
// search for word vertically
void verticalSearch(char *input, struct board *boardObject){
	int iterator = 0;
	int inputLength = strlen(input);										// gets length of the string in the input array
	
	for (int i = 0; i < boardObject -> r; i++){
		for (int j = 0; j < boardObject -> c; j++){
			
			if ((boardObject -> matrix)[i][j] == input[0]){					// checks if first character in input array matches character in matrix
				iterator = 0;												// resets iterator to 0 incase search finds matching first character without the correct succeeding characters
				for (int a = 0; a < inputLength; a++){
					if (i+a < boardObject -> r){							// keeps iterator from going out of bounds
						if ((boardObject -> matrix)[i+a][j] == input[a]){	// checks if succeeding characters to first letter match the user inputted word in the matrix
							iterator++;
							
						}
					}
				}
				if (iterator == inputLength){								//  if iterator and inputLength matches, exits loop and prints success statement
					printf("WORD FOUND VERTICALLY! Length: ");
					printf("%d", iterator);
			
				}
			}
		}
	}
	return;
}


// search for word diagonally
void diagonalSearch(char *input, struct board *boardObject){
	int iterator = 0;
	int inputLength = strlen(input);										// gets length of the string in the input array
	
	for (int i = 0; i < boardObject -> r; i++){
		for (int j = 0; j < boardObject -> c; j++){
			if((boardObject -> matrix)[i][j] == input[0]){					// checks if first character in input array matches character in matrix
				iterator = 0;												// resets iterator to 0 incase search finds matching first character without the correct succeeding  characters
				for (int a = 0; a < inputLength; a++){
					if (i+a < boardObject -> r){							// keeps iterator from going out of bounds
						if ((boardObject -> matrix)[i+a][j+a] == input[a]){	// checks if succeeding characters to first character match input
							iterator++;
						}
					}
				}
				
				if (iterator == inputLength){								// if iterator and inputLength matches, exits loop and prints success statement
					printf("WORD FOUND DIAGONALLY! Length: ");
					printf ("%d", iterator);
					
				}
			}
		}
	}
	return;
}
			
	
