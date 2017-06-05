#include <stdio.h>
#include <string.h>
#include <ctype.h>

//This method is used to check for integers, not including doublesor floats.
int tokenCheck(char *e){
	//If there is a space, newline, or string termination, the loop stops
	while(*e != ' ' && *e != '\n' && *e != '\0'){
		if(!isdigit(*e)){ //If it isn't an int, then it returns false
			return 0;
		}
		*e++; //Used to iterate through the entire string
	}
	return 1;
}


//Method used to take in data and break up data into tokens
int scanAndPrint(){
	char *ptr;
	char buff[66];
	char buff2[66];
	int count = 0;

	printf("> "); //Caret used to initiate user input
	fgets(buff, 65, stdin); //Takes in no more than 65 chars into the buff array

	strncpy(buff2, buff, 66); //Copy user input into another array for later use

	ptr = strtok(buff, " \n"); //Breaks up array into tokens separated by spaces
	count = 0; //Counter for tokens
	while(ptr != NULL){
	    
	    count++; //Increments count for tokens present
		if(count > 2){
			printf("ERROR! Incorrect number of tokens found.\n");
			scanAndPrint(); //Recursive call in case user enters too many tokens
			return 0;
			}
		ptr = strtok(NULL, " \n"); //Moves on in the char array
		
		}
	ptr = strtok(buff2, " "); //Breaks up array into tokens separated by spaces
	
	while(ptr != NULL){
	    
	    if(count <= 0){
			printf("ERROR! Incorrect number of tokens found.\n");
			scanAndPrint(); //Recursive call in case user enters too many tokens
			return 0;
			}

		//If the token is a number (no decimals), then "INT" is printed
		if(tokenCheck(ptr)){
			printf("INT ");
		}
		//If token is not an int, then "STR" is printed
		else{
			printf("STR ");
		}
		ptr = strtok(NULL, " \n");
	}
	return 0;
}


int main(){
	printf("Assignment #1-3, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com\n");
	scanAndPrint(); //Method that does all of the work
	return 0;
}


