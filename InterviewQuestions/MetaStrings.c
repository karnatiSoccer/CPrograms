// C program to check if two strings are meta strings 
/*
Given two strings, the task is to check whether these strings are meta strings or not. 
Meta strings are the strings which can be made equal by exactly one swap in any of the strings. 
Equal string are not considered here as Meta strings.
Input : str1 = "geeks" 
        str2 = "keegs"
Output : Yes
By just swapping 'k' and 'g' in any of string, 
both will become same.

Algorithm:
	Check if both strings are of equal length or not, if not return false.
	Otherwise, start comparing both strings and count number of unmatched characters and also store the index of unmatched characters.
	If unmatched characters are more than 2 then return false.
	Otherwise check if on swapping any of these two characters in any string would make the string equal or not.
	If yes then return true. Otherwise return false.
*/
#include<stdio.h>
#include<stdbool.h> 
#include<string.h>

// Returns true if str1 and str2 are meta strings 
bool areMetaStrings(char *str1, char *str2) 
{ 
	int len1 = strlen(str1); 
	int len2 = strlen(str2); 

	// Return false if both are not of equal length 
	if (len1 != len2) 
		return false; 

	// To store indexes of previously mismatched 
	// characters 
	int prev = -1, curr = -1; 

	int count = 0; 
	for (int i=0; i<len1; i++) 
	{ 
		// If current character doesn't match 
		if (str1[i] != str2[i]) 
		{ 
			// Count number of unmatched character 
			count++; 

			// If unmatched are greater than 2, 
			// then return false 
			if (count > 2) 
				return false; 

			// Store both unmatched characters of 
			// both strings 
			prev = curr; 
			curr = i; 
		} 
	} 

	// Check if previous unmatched of string1 
	// is equal to curr unmatched of string2 
	// and also check for curr unmatched character, 
	// if both are same, then return true 
	return (count == 2 && 
			str1[prev] == str2[curr] && 
			str1[curr] == str2[prev]); 
} 

// Driver code 
int main() 
{ 
	char *str1 = "converse"; 
	char *str2 = "conserve"; 

	areMetaStrings(str1,str2) ? printf("Yes")
							: printf("No"); 
	return 0; 
} 
