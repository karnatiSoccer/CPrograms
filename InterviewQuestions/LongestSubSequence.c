#include <stdio.h>
#include<stdlib.h>

int max(int x,int y){
	return (x > y)?x:y;
}

int longestSubSeq(int subArr[], int n) {
    int *length;
	length = malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) 
		length[i] = 0; 
    //set all length to 0
    length[0] = 1;                            //subsequence ending with subArr[0] is 1

    for (int i = 1; i < n; i++) {            //ignore first character, second to all
		for (int j = 0; j < i; j++) {         //longest inreasing subsequence ends with subArr[j]
			// printf("subArr[j] %d\n", subArr[j]);
			if (subArr[j] < subArr[i] && length[j] > length[i]){
				length[i] = length[j];
				// printf("length[i] %d\n", length[i]);
			}
			
		}
		length[i]++;              //add arr[i]
		// for (int k = 0; k < n; k++) {
			// printf("%d ", length[k]);
		// }
		// printf("\n");
    }

    int lis = 0;
    for (int i = 0; i<n; i++)           // find longest increasing subsequence
      lis = max(lis, length[i]);

    return lis;
}

int main() {
   int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
   int n = 16;
   printf("Length of Longest Increasing Subsequence is: %d", longestSubSeq(arr, n));
   return 0;
}