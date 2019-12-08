// C program to find largest word in Dictionary 
// by deleting some characters of given string 
#include <stdio.h>
#include<stdbool.h>
#include<string.h>

// Returns true if str1[] is a subsequence of str2[]. 
// m is length of str1 and n is length of str2 
bool isSubSequence(char *word, char *str) 
{ 
	int m = strlen(word), n = strlen(str); 

	int j = 0; // For index of word (or subsequence 

	// Traverse str and word, and compare current 
	// character of str with first unmatched char 
	// of word, if matched then move ahead in word 
	for (int i=0; i < n && j < m; i++) 
		if (word[j] == str[i]) 
			j++; 

	// If all characters of str1 were found in str2 
	return (j == m); 
} 

// Returns the longest string in dictionary which is a 
// subsequence of str. 
char* findLongestString(char dict[][10], int size, char *str) 
{ 
	char *result = ""; 
	int length = 0; 
	int i;
	// Traverse through all words of dictionary 
	for (i = 0; i < size; i++) 
	{ 	
		char *word = dict[i];
		// If current word is subsequence of str and is largest 
		// such word so far. 
		if (length < strlen(word) && isSubSequence(word, str)) 
		{ 
			result = word; 
			length = strlen(word); 
		} 
	} 

	// Return longest string 
	return result; 
} 

// Driver program to test above function 
int main() 
{ 
	char dict[][10] = {"ale", "apple", "monkey", "plea"}; 
	char *str = "abpcplea" ; 
	printf("Longest word is %s ", findLongestString(dict, 4, str)); 
	return 0; 
} 
