#include <stdio.h>

void main(){
	int arr[] = {-1,-2,-3,4};
	int n = 4;
	int sum = 0;
	int maxSum = -1;
	int globalMaxSum = -1;
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = i; j < n; j++){
			sum += arr[j];
			if(maxSum < sum){
				maxSum = sum;
			}
		}
		// printf("maxsum for %d is %d\n", arr[i], maxSum);
		if(globalMaxSum < maxSum){
			globalMaxSum = maxSum;
		}
	}
	printf("Max sum is %d", globalMaxSum);	
}


