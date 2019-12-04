//Maximum sum Problem
/*
Divide given number t0 n/2, n/3, n/4 and sum them up. Furthur sub divide n/2 and get max sum
IP = 12, OP = 13
We break n = 12 in three parts {12/2, 12/3, 12/4} = {6, 4, 3},  now current sum is = (6 + 4 + 3) = 13
Again, we break 6 = {6/2, 6/3, 6/4} = {3, 2, 1} = 3 + 2 + 1 = 6 and further breaking 3, 2 and 1 we get maximum
summation as 1, so breaking 6 in three parts produces maximum sum 6 only similarly breaking 4 in three parts we can get maximum sum 4 and same for 3 also. Thus maximum sum by breaking number in parts  is=13
*/
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