/*
C program to fint minimum insertions needed to onvert to palindrome
*/
#include<stdio.h>
#include<string.h>

int findMinInsertions(char *, int , int);
int min(int , int);

void main(){
	char str[20];
	printf("Enter the string : ");
	scanf("%s", str);
	printf("Entered string %s is of length %d\n", str, strlen(str));
	printf("Minimum insertions needed are %d", findMinInsertions(str, 0, strlen(str) - 1));
}

// l is lower index, h is higher index
int findMinInsertions(char *str, int l, int h){
	// printf("l: %d, h: %d ", l, h);
	//base cases
	if(l == h) return 0;
	if(l == h -1) return (str[l] == str[h])?0:1;
	
	return (str[l] == str[h])?(findMinInsertions(str, l + 1, h - 1)):(min(findMinInsertions(str, l + 1, h), findMinInsertions(str, l, h - 1))+1);
}

int min(int x, int y){
	return (x < y)?x:y;
}