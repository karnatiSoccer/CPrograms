#include<stdio.h>
#include<stdlib.h>

/* Segretgates the arr to move all negative integers to left and positive integers to right 
 return the starting index of positive integers */
int segregate(int arr[], int len){
	// printf("segregate\n");
	int j = 0, i;
	for(i = 0; i < len; i++){
		if(arr[i] < 0){
			//Swap the integers
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
	}
	// printf("Array after segregation \n");
	// for(int i = 0; i < len; i++){
		// printf("%d ", arr[i]);
	// }
	return j;
}

int findMissingInteger(int arr[], int len){
	// printf("findMissingInteger\n");
	//loop through array and complement the integers in that index if the index is in bounds
	for(int i = 0; i < len; i++){
		if(abs(arr[i])-1 < len && arr[abs(arr[i]) - 1] > 0){
			arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1];
		}
	}
	// printf("Array after complements \n");
	// for(int i = 0; i < len; i++){
		// printf("%d ", arr[i]);
	// }
	// loop through array to find first positive integer and return its index+1
	for(int i = 0; i< len; i++){
		if(arr[i] > 0){
			return i+1;
		}
	}
}

int main(){
    int arr[] = {1, 2, 0};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	int posItemIndex, missingInteger;
	
	posItemIndex = segregate(arr, arrlen);
	// printf("posItemIndex %d", posItemIndex);
	
	missingInteger = findMissingInteger(arr+posItemIndex, arrlen-posItemIndex);
	
	printf("Missing integer is %d", missingInteger);
	
}