/*
Given a string you need to print longest possible substring that has exactly M unique characters. 
If there are more than one substring of longest possible length, then print any one of them.
Ex: IP "aabacbebebe"
	OP = "cbebebe" has only 3 characters b,c,e and length 7  
		 "aabac" also has only 3 characters a,b,c but length is 5
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_CHARS 26 

char* FindLongestSequence(char[], int);
bool isValid(int[], int); //To check if the sequence has exactly k unique characters

void main(){
	char *str = "aabacbebebe";
	int k = 3;
	char *result = FindLongestSequence(str, k);
	printf("Longest sequence with %d unique characters is %s", k, result);
}

char* FindLongestSequence(char str[], int k){
	
	int i, n = strlen(str); 
	char *result;
	
	// Associative array to store the count of characters 
    int count[MAX_CHARS];
	// Initialize associative array count[] with zero 
    memset(count, 0, sizeof(count)); 
    
    // Otherwise take a window with first element in it. 
    // start and end variables. 
    int curr_start = 0, curr_end = 0; 
  
    // Also initialize values for result longest window 
    int max_window_size = 1, max_window_start = 0; 
     
    count[str[0]-'a']++;  // put the first character 
  
    // Start from the second character and add 
    // characters in window according to above 
    // explanation 
    for (i = 1; i < n; i++) 
    { 
		// Add the character 's[i]' to current window 
        count[str[i]-'a']++; 
        curr_end++; 
		
        // If there are more than k unique characters in 
        // current window, remove from left side 
        while (!isValid(count, k)) 
        { 
            count[str[curr_start]-'a']--; 
            curr_start++; 
        } 
  
        // Update the max window size if required 
        if (curr_end - curr_start + 1 > max_window_size) 
        { 
            max_window_size = curr_end - curr_start + 1; 
            max_window_start = curr_start; 
        } 
    } 
	
	strncpy(result, str + max_window_start, max_window_size);
	
	return result;
}

bool isValid(int count[], int k) 
{ 
    int val = 0; 
    for (int i=0; i<MAX_CHARS; i++) 
        if (count[i] > 0) 
            val++; 
  
    // Return true if k is greater than or equal to val 
    return (k >= val); 
} 