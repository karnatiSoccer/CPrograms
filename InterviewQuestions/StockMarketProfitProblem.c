/*
Given a array of numbers representing the stock prices of a company in chronological order, 
write a function that calculates the maximum profit you could have made from buying and selling 
that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars 
and sell it at 10 dollars.
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void main(){
	int *arr;
	int n, i;
    int	minIndex = -1, maxIndex = -1;
	int max_sofar, max_diff = INT_MIN;
	
	printf("Enter nummber of elements : ");
	scanf("%d", &n);
	
	// Dynamically allocate memory using malloc() 
    arr = (int*)malloc(n * sizeof(int)); 
  
    // Check if the memory has been successfully 
    // allocated by malloc or not 
    if (arr == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
	
	printf("\nEnter the elements : ");
	for(i = 0; i < n; i++){
		scanf("%d", arr + i);
	}
	
	// printf("\nEntered the elements : ");
	// for(i = 0; i < n; i++){
		// printf("%d ", arr[i]);
	// }
	// printf("\n");
	
	max_sofar = arr[n - 1];
	maxIndex = n - 1;
	for(i = n - 2; i >= 0; i--){
		if(arr[i] > max_sofar){
			max_sofar = arr[i];
			maxIndex = i;
		}else if(max_sofar - arr[i] > max_diff){
			max_diff = max_sofar - arr[i];
			minIndex = i;
		}
	}
	if(minIndex != -1 && maxIndex != -1){
		// printf("Maximum profit can be obtained by buying at %d and Selling at %d ", arr[minIndex], arr[maxIndex]);
		printf("Maximum profit can be obtained by buying at index %d and profit is %d ", minIndex, max_diff);
	}else{
		printf("Profit option doesnot exists");
	}
	
}