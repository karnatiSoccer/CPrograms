#include<stdio.h>
#include<stdlib.h>

void main(){
	int *arr, n, i;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	arr = malloc(n * (sizeof(int)));
	printf("\nEnter elements into array:\n");
	for(i = 0; i < n; i++){
		scanf("%d", arr + i);
	}
	
	printf("\nEnterd elements are:");
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	
	int checkincSeq = 1;
	int max_len = 0;
	int incLen = 1, decLen = 1;
	
	for(i = 1; i < n; i++){
		if(checkincSeq == 1){
			if(arr[i - 1] < arr[i]){
				incLen++;
			}else{
				if(incLen > 1){ // incLen > 1 added for a cases like 10 4 2 1 ie no increment sequence found yet
					checkincSeq = 0;				
				}
			}
		}else if(checkincSeq == 0){
			if(arr[i - 1] > arr[i]){
				decLen++;
			}
			if(arr[i - 1] < arr[i] || i == n-1){
				if(i != n - 1) i--; // if the sequence has multiple bitonic then after first sequence len we miss the prev element so decrement once
				if(max_len < incLen + decLen){ 
					max_len = incLen + decLen;
					printf("len %d \n", max_len);
				}
				checkincSeq = 1;
				incLen = 1;
				decLen = 1;
			}
		}
	}
	
	printf("Longest Sub sequence is %d ", max_len);
}