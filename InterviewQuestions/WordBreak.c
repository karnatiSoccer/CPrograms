#include<stdio.h>
#include<string.h>

char arr[][30] = { "i", "like", "sam", "sung", 
						"samsung", "mobile", "ice", 
						"cream", "icecream", "man", "go", "mango"};
int N = 12;						
int isInDict(char word[]){    //check whether the word is in dictionary or not
	for (int i = 0; i < N; i++){
      if (strcmp(arr[i], word) == 0){
			printf("String   %s   is in dictionary\n", word);
			return 1;
	  }
	}
   return 0;
}

void wordBreak(char str[], int n, char result[]) {
   for (int i=1; i<=n; i++) {
		char subStr[20];
		strncpy(subStr, str, i);       //get string from 0 to ith location of the string
		subStr[i] = '\0';
		// printf("subStr for  %s \n", subStr);
		if (isInDict(subStr) == 1) {       //if subStr is found in the dictionary
			if (i == n) {
				strcat(result,subStr);
				// result += subStr; //add substring in the result.
				printf("%s\n", result);
				return;
			}
			// printf("Recurse result for  %s \n", result);
			strcat(result,subStr);	
			strcat(result," ");
			// printf("Recurse result for  %s \n", result);
			strncpy(subStr, str + i, n - i); //get rest of the string starting from i 
			subStr[n - i] = '\0';
			// printf("Recurse subStr for  %s \n", subStr);
			wordBreak(subStr, n-i, result);    //otherwise break rest part
		}
   }
}

void main(){
	
	// int indices[12], i;
	char str[] = "ilikesamsung";
	
	wordBreak(str, strlen(str), "");
	
	/*char *ptr;
	//initialise indices array
	for(i = 0; i < 12; i++){
		indices[i] = -1;
	}
	
	for(i = 0; i < 12; i++){
		// printf("%s \n" , arr[i]);
		ptr = strstr(str, arr[i]);
		if(ptr != NULL){
			indices[i] = ptr - str + 1;
		}
		// printf("ind %d \n" , indices[i]);		
	}
	
	int currIndex = -1;
	for(i = 0; i < 12; i++){
		if(indices[i] != -1 && indices[i] > currIndex){
			printf("%s " , arr[i]);
			currIndex = indices[i];
		}
	}*/
}