#include<stdio.h>

int subArrayWithReqSum(int arr[], int sum, int len){
	if(len == 0){
		return -1;
	}
	if(arr[0] == sum){
		printf("%d ", arr[0]);
		return 0;
	}
	if(arr[0] > sum){
		int val = subArrayWithReqSum(arr+1, sum, len-1);
		if(val == -1){
			printf("Sum not found");
			// return -1;
		}
	}else{
		int val = subArrayWithReqSum(arr+1, sum - arr[0], len-1);
		if(val == -1){ //sum not found by remaining elements
			subArrayWithReqSum(arr+1, sum, len-1);
		}else{
			printf("%d ", arr[0]);
		}
	}	
}

void main(){
	int arr[] = {12, 1, 61, 5, 9, 2};
	int len = 6;
	int sum = 40;
	
	subArrayWithReqSum(arr, sum, len);
}