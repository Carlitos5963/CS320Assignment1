#include <stdio.h>
#include <string.h>

int main(){

	printf("Assignment #1-1, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com\n");
	char *ptr; //Pointer to point at char array
	char buff[66]; //Char array to hold user input
	int i; //For for loops


	fgets(buff, 65, stdin); //Takes in 65 chars and puts them in char array

	ptr = strtok(buff, " "); //Scans the array for delimiters

	//When the pointer reaches a NULL space, print the word, then move on in the array.
	while(ptr != NULL){
		printf("=%s=\n", ptr);
		ptr = strtok(NULL, " \n");
	}

	return 0;

}
