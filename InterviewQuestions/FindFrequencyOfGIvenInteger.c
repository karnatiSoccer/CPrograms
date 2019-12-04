/* Find Frequency of given number */
#include<stdio.h>

int getFirstOccurenceIndex(int arr[], int low, int high, int element){
	if(high < low) 
		return -1;
	
	int mid = (low + high)/2;
	if(arr[mid] == element && (mid == 0 || element > arr[mid - 1])) 
		return mid;
	else if(element > arr[mid])
		return getFirstOccurenceIndex(arr, mid + 1, high, element);
	else		
		return getFirstOccurenceIndex(arr, low, mid, element);
  
}
int getLastOccurenceIndex(int arr[], int low, int high, int element){
	if(high < low) 
		return -1;
	
	int mid = (low + high)/2;
	if(arr[mid] == element && (mid == high - 1 || element < arr[mid + 1])) 
		return mid;
	else if(element < arr[mid])
		return getLastOccurenceIndex(arr, low, mid, element);
	else
		return getLastOccurenceIndex(arr, mid + 1, high, element);
  
}

void main(){
	int arr[] = {1,1,1,2,3,4};
	int size = 6;
	int element = 0;
	int i, j;
	i = getFirstOccurenceIndex(arr, 0, size, element);//Binary search
	if(i == -1) {
		printf("Given Element not found\n");
		return;
	}
	
	j = getLastOccurenceIndex(arr, 0, size, element);//Binary search
	
	printf("Frequency of the given element %d is %d", element, j-i+1);
}
