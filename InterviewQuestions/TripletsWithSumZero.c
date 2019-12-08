// C program to find triplets in a given 
// array whose sum is zero 
#include<stdio.h> 
#include<stdbool.h>

void sort(int *array, int size){
	for (int step = 0; step < size - 1; ++step)
	{
		for (int i = 0; i < size - step - 1; ++i)
		{
		  // To sort in descending order, change">" to "<".
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

// function to print triplets with 0 sum 
void findTriplets(int arr[], int n) 
{ 
	bool found = false; 

	// sort array elements 
	sort(arr, n); 

	for (int i=0; i<n-1; i++) 
	{ 
		// initialize left and right 
		int l = i + 1; 
		int r = n - 1; 
		int x = arr[i]; 
		while (l < r) 
		{ 
			if (x + arr[l] + arr[r] == 0) 
			{ 
				// print elements if it's sum is zero 
				printf("%d %d %d\n", x, arr[l], arr[r]); 
				l++; 
				r--; 
				found = true; 
			} 

			// If sum of three elements is less 
			// than zero then increment in left 
			else if (x + arr[l] + arr[r] < 0) 
				l++; 

			// if sum is greater than zero than 
			// decrement in right side 
			else
				r--; 
		} 
	} 

	if (found == false) 
		printf(" No Triplet Found"); 
} 

// Driven source 
int main() 
{ 
	int arr[] = {0, -1, 2, -3, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	findTriplets(arr, n); 
	return 0; 
} 
