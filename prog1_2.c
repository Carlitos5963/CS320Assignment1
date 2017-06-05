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

int main(){
	printf("Assignment #1-2, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com\n");
	char *ptr;
	char buff[66];
	int i;

	printf("> "); //Caret used to initiate user input
	fgets(buff, 65, stdin); //Takes in no more than 65 chars into the buff array

	ptr = strtok(buff, " "); //Breaks up array into tokens separated by spaces
	while(ptr != NULL){
		//If the token is a number (no decimals), then "INT" is printed
		if(tokenCheck(ptr)){
			printf("INT ");
		}
		//If token is not an int, then "STR" is printed
		else{
			printf("STR ");
		}
		ptr = strtok(NULL, " ");
	}
	return 0;
}


