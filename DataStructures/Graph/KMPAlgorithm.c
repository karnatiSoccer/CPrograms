#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

// Function to implement KMP algorithm
void KMP(char* str, char* pattern, int m, int n)
{
	// Base Case 1: pattern is NULL or empty
	if (*pattern == '\0' || n == 0)
		printf("Pattern occurs with shift 0");

	// Base Case 2: str is NULL or str's length is less than that of pattern's
	if (*str == '\0' || n > m)
		printf("Pattern not found");

	// lps[i] stores the index of lps best partial match
	int lps[n]; // Longest proper prefix
	
	for (int i = 0; i < n + 1; i++)
		lps[i] = 0;
	
	// Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pattern, n, lps); 
	
	for (int i = 0, j = 0; i < m; i++)
	{
		if (*(str + i) == *(pattern + j))
		{
			if (++j == n)
				printf("Pattern occurs with shift %d\n", i - j + 1);
		}
		else if (j > 0) {
			j = lps[j];
			i--;	// since i will be incremented in lps iteration
		}
	}
}

// Program to implement KMP Algorithm in C
int main(void)
{
	char* text = "ABCABAABCACAC";
	char* pattern = "ABC";

	int n = strlen(text);
	int m = strlen(pattern);

	KMP(text, pattern, n, m);

	return 0;
}