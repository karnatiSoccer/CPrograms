#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void sort(char *array, int size){
	for (int step = 0; step < size - 1; ++step)
	{
		for (int i = 0; i < size - step - 1; ++i)
		{
		  // To sort in descending order, change">" to "<".
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

bool isAnagram(char str1[], int n1, char str2[], int n2){
	char *temp;
	int i;
	for(i = 0; i < (n1 - n2 + 1); i++){
		strncpy(temp, str1 + i, n2);
		temp[n2] = '\0';		
		sort(temp, n2);
		printf("Sorted temp %s\n", temp);	
		if(strcmp(str2, temp) == 0){	
			return true;
		}
	}
	return false;
}

void main(){
	char str1[] = "abcde";
	char str2[] = "bca";
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	
	sort(str2, n2);
	printf("Sorted str2 %s\n", str2);	
	if(isAnagram(str1, n1, str2, n2) == true){
		printf("Given string is anagram of the main string\n");	
	}else{
		printf("Given string is not anagram of the main string\n");	
	}
}