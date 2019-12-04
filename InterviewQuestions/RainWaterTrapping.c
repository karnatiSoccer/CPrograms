//https://codepumpkin.com/trapping-rain-water-algorithm-problem/

#include<stdio.h>

int min(int,int);
int max(int,int);

void main(){
	int arr[] = {0, 1, 0, 2, 4, 0, 1};
	int left[7] = {0};
	int right[7] = {0};
	int i = 0, n = 7;
	int totalwater = 0;
	
	left[0] = arr[0];
	for(i = 1; i < n ; i++){
		left[i] = max(left[i - 1], arr[i]);
	}
	
	right[n - 1] = arr[n - 1];
	for(i = n - 2; i >= 0 ; i--){
		right[i] = max(right[i + 1], arr[i]);
	}
	
	for(i = 0; i < n; i++){
		totalwater += min(left[i], right[i]) - arr[i];
	}
	
	printf("Total water %d", totalwater);
}

int min(int x,int y){
	return (x < y)?x:y;
}

int max(int x,int y){
	return (x > y)?x:y;
}