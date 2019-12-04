// C++ program to find minimum number of 
// operations required to transform one string to other 
#include<stdio.h> 
#include<stdlib.h>

// Function to find minimum number of operations required to transform 
// A to B. 
int minOps(char A[], int lenA, char B[],int lenB) 
{ 
	int m = lenA, n = lenB; 

	// This parts checks whether conversion is 
	// possible or not 
	if (n != m) 
		return -1; 
	
	//Check if the number of characters also matches
	int *count = calloc(26, sizeof(int)); 		
	for (int i = 0; i < n; i++){ // count characters in A 
		int index = A[i] - 'A'; //Mapping A to 0 index
		count[index]++; 
	}
	for (int i = 0; i < n; i++){ // subtract count for 
		int index = B[i] - 'A'; //Mapping A to 0 index
		count[index]--;		 // every character in B 
	}
	for (int i = 0; i < 26; i++){ // Check if all counts become 0 
		if (count[i]) 
			return -1; 
	}
	
	// This part calculates the number of operations required 
	int res = 0; 
	for (int i = n-1, j = n-1; i >= 0; ) 
	{ 
		// If there is a mismatch, then keep incrementing 
		// result 'res' until B[j] is not found in A[0..i] 
		while (i>=0 && A[i] != B[j]) 
		{ 
			i--; 
			res++; 
		} 

		// If A[i] and B[j] match 
		if (i >= 0) 
		{ 
			i--; 
			j--; 
		} 
	} 
	return res; 
} 

// Driver program 
int main() 
{ 
	char A[] = "ABD"; 
	char B[] = "BAD"; 
	
	printf("Minimum number of operations required is %d" , minOps(A, 3, B, 3)); 
	return 0; 
} 
