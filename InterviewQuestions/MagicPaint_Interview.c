#include<stdio.h>

int numSpokesColored(int arr[], int arrlen){
	int i;
	int result = 5;
	// int arrlen = sizeof(arr)/sizeof(arr[0]);
	if(arrlen == 1){
		return result;
	}
	
	for(i = 1; i < arrlen; i++){
		int delta = arr[i] - arr[i - 1];
		if(delta > 5){
			result += 5;
		}else{
			result += delta;
		}
	}
	return result;
}

void main(){
	int arr[] = {1,3,11};
	int numSpokes = numSpokesColored(arr, 3);
	printf("Num spokes colored are %d", numSpokes);
}
