#include <stdio.h>

void subArraySum(int arr[], int size, int sum){
	int curr_sum = arr[0], start = 0, i;
	for(i = 1; i <= size; i++){
		while(curr_sum > sum && start < i - 1){
			curr_sum -= arr[start];
			start++;
		}
		if(curr_sum == sum){
			printf("subArraySum Sub array found at %d, %d\n", start, i-1);
			return;
		}
		// Add this element to curr_sum 
        if (i < size) 
			curr_sum += arr[i];
	}
	printf("subArraySum Sub array not found");
}

void main(){
	int arr[] = {0,2,3,4,5,6,7,8,9,10};
	int expSum = 15;
	int arrSize = 10;
	int startInd, endIndex = -1;
	int sum = 0;
	
	subArraySum(arr, arrSize, expSum);
	
	//Iterate through the array
	for(int i = 0; i < arrSize; i++){
		sum = arr[i];
		startInd = i;
		endIndex = -1;
		//printf("%d : %d \n", i, sum);
		if(sum == expSum){
			endIndex = i;
			break;
		}else{
			int j = i+1;
			while(j < arrSize){
				sum += arr[j];
				//printf("%d : %d \n", i, sum);
				if(sum == expSum){
					endIndex = j;
					break;
				}else if(sum > expSum){
					break;
				}
				j++;
			}
			if(startInd != -1 && endIndex != -1){
				printf("Subarray exists from index %d to %d\n", startInd,endIndex);				
			}
		}		
	}
	
}

