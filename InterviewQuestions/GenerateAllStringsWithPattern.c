// Recursive C program to generate all binary strings 
// formed by replacing each wildcard(?) character by 0 or 1 
#include<stdio.h>
#include<string.h>

// Recursive function to generate all binary strings 
// formed by replacing each wildcard character by 0 or 1 
void generateAllStrings(char *str, int index) 
{ 
	
	if (index == strlen(str) - 1) 
	{ 
		printf("%s \n", str); 
		return; 
	} 
	
	if (str[index] == '?') 
	{ 
		// replace '?' by '0' and recurse 
		str[index] = '0'; 		
		generateAllStrings(str, index + 1); 

		// replace '?' by '1' and recurse 
		str[index] = '1'; 
		generateAllStrings(str, index + 1); 

		// No need to backtrack as string is passed 
		// by value to the function 
	} 
	else
		generateAllStrings(str, index + 1); 
} 

// Driver code to test above function 
int main() 
{ 
	char *str = "1??0?101"; 

	generateAllStrings(str, 0); 

	return 0; 
} 
