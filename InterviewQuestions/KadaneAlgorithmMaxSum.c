#include<stdio.h>

void main(){
	// int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	// int n = 8;
	int arr[] = {-5, -2, -3, -4};
	int n = 4;
	int max_so_far = -32768, max_end = 0;
	
	for(int i = 0; i < n; i++){
		max_end += arr[i];		
		if(max_so_far < max_end){
			max_so_far = max_end;
		}
		if(max_end < 0){
			max_end = 0;
		}
	}
	printf("Max sum is %d", max_so_far);
}