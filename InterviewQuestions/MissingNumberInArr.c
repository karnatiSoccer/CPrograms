#include <stdio.h>

void main(){
	int arr[] = {1,2,3,5};
	int n = 5;
	int actualSum = (n * (n + 1))/2; //Summation of n terms formula
	int arrSum = 0;
	
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		arrSum += arr[i];
	}
	printf("Missing element is %d", actualSum - arrSum);	
}


