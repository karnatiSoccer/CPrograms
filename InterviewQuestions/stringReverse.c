#include<stdio.h>
#include<string.h>

char* reverse(char str[], int len){
	int i, j;
	char temp;
	for(i = 0, j = len - 1; i<j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}

void main(){
	char str[] = "abcd";
	int size = strlen(str);
	
	printf("Reversed string %s ", reverse(str, size));
}