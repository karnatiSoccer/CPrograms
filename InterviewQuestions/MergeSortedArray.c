#include<stdio.h>

void main(){
	int arr1[] = {2, 3, 7, 8, 9};
	int arr2[] = {-2, -1, 1, 4, 5};
	int arr1len = sizeof(arr1)/sizeof(arr1[0]);
	int arr2len = sizeof(arr2)/sizeof(arr2[0]);
	int i, j, temp;
	
	for(i = arr2len - 1; i >= 0; i--){
		temp = arr1[arr1len - 1];
		for(j = arr1len - 2; j >= 0 && arr1[j] > arr2[i]; j--){
			arr1[j + 1] = arr1[j];
		}
		if(j != arr1len - 2 || temp > arr2[i]){
			arr1[j + 1] = arr2[i];
			arr2[i] = temp;
		}
	}
	
	for(i = 0; i < arr1len; i++){
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for(i = 0; i < arr2len; i++){
		printf("%d ", arr2[i]);
	}
	
}