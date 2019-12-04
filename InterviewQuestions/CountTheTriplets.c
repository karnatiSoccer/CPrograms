#include <stdio.h>
#include<stdbool.h>

// int searchTriplet(int arr[], int, int, int);

int searchTriplet(int arr[], int arrsize, int sum, int ind1, int ind2){
	// printf("Sum %d i: %d j:%d \n", sum, ind1, ind2);
	// int arrsize = sizeof(arr)/sizeof(arr[0]);
	// printf("arrsize : %d", arrsize);
	for(int i = 0; i < arrsize; i++){
		// printf("arr[i] : %d\n", arr[i]);
		if(i != ind1 && i != ind2 && sum == arr[i]) return 1; //to eliminate the case of say 1+0 gives 1 at the index of self
	}
	return 0;
}

void main(){
	int arr[] = {1,5,3,2,};
	int	arrSize = 4;
	int numTriplets = 0;
	
	for(int i = 0; i < arrSize; i++){
		int j = i+1;
		while(j < arrSize){
			if(searchTriplet(arr, arrSize, arr[i]+arr[j], i, j) == 1){
				numTriplets++;
			}
			j++;
		}
	}
	printf("Number of triplets found : %d", numTriplets);
}


