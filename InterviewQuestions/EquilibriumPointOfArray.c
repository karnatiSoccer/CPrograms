#include<stdio.h>

void main(){
	int arr[] = {1,3,5,2,2};
	int sum, leftsum, rightSum;
	leftsum = 0;
	sum = 0;
	rightSum = 0;
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	
	//Calculate total sum
	for(int i = 0; i < arrlen; i++){
		sum += arr[i];
	}
	
	int i;
	for(i = 0; i < arrlen; i++){
		rightSum = sum;
		for (int j = 0; j <= i; j++) {
			rightSum -= arr[j];
		}
		printf("leftsum %d\n", leftsum);
		printf("rightSum %d\n", rightSum);
		if(leftsum == rightSum){
			printf("Equilibrium point is %d", i);
			break;
		}
		leftsum += arr[i];
	}
	
	if(i == arrlen){
		printf("Equilibrium point not found");
	}
	
}
