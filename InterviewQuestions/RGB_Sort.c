#include<stdio.h>

void main(){
	char arr[] = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i = 0, rInd = 0, bInd = size - 1;
	char temp;

	while(i<= bInd){
		switch(arr[i]){
			case 'R':
				temp = arr[i];
				arr[i] = arr[rInd];
				arr[rInd] = temp;
				rInd++;
				i++;
				break;
			case 'B':
				temp = arr[i];
				arr[i] = arr[bInd];
				arr[bInd] = temp;
				bInd--;
				break;
			default:
				i++;
				break;
		}
	}
	
	for(i = 0; i < size; i++){
		printf("%c ", arr[i]);
	}
}
