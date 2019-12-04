//Maximum sum Problem
#include<stdio.h>

int maxSumRecursive(int);

void main(){
	int num;
	
	printf("Enter the Number : ");
	scanf(" %d", &num);

	int max_sum = maxSumRecursive(num);
	printf("Max sum is %d", max_sum);
}

int max(int x, int y){
	return (x > y) ? x : y;
}

int maxSumRecursive(int n){
	int sum = n/2 + n/3 + n/4;
	if(n == sum){
		return n;
	}
	sum = 0;
	sum += max(n/2, maxSumRecursive(n/2));
	sum += max(n/3, maxSumRecursive(n/3));
	sum += max(n/4, maxSumRecursive(n/4));
	return sum;
}