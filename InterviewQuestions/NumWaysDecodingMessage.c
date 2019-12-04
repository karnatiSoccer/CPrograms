#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int NumWaysToDecode(char str[], int len){
	
	if(len == 0){
		return 1;
	}
	if(str[0] == '0'){
		return 0;
	}
	int result = NumWaysToDecode(str+1, len - 1);
	if(len >=2){
		char substr[3]; 
		strncpy(substr, str, 2); //{str[0], str[1], '\0'};
		// printf("sub string %s\n", substr);
		// printf("sub string %d\n", atoi(substr));
		if(atoi(substr) <= 26){
			result += NumWaysToDecode(str+2, len - 2);
		}
	}
	return result;
}

int main()
{
	char str[50];
	int len = 0;
	
	printf("Enter encoded message: ");
	scanf("%s", &str);
	len = strlen(str);
	// printf("Len of str %s is %d \n", str, len);
	
	printf("Num ways to decode the given message is %d", NumWaysToDecode(str, len));
    return 0;
}
