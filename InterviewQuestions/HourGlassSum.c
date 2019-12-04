#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Complete the hourglassSum function below.
int hourglassSum(int arr_rows, int arr_columns, int arr[6][6]) {

    int maxSum = -0xFFFF;
    int currSum = 0;
   // int maxSumRow, maxSumCol;

    /*for(int i = 0; i <= arr_rows - 1; i++){
        for(int j = 0; j <= arr_columns - 1; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
	*/
    for(int i = 0; i < arr_rows - 2; i++){
        for(int j = 0; j < arr_columns - 2; j++){
           // printf("arr[i][j] = %d ", arr[i][j]);
            
            currSum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            printf("curr sum = %d ", currSum);
            printf("max sum = %d \n", maxSum);
            if(currSum > maxSum){
                maxSum = currSum;
                //maxSumRow = i;
                //maxSumCol = j;
            }
        }
    }
    return maxSum;
}

int main()
{
   
    int arr_rows = 6;
    int arr_columns = 6;
	int arr[6][6] = {					
					{0, -4, -6, 0, -7, -6},
					{-1, -2, -6, -8, -3, -1},
					{-8, -4, -2, -8, -8, -6},
					{-3, -1, -2, -5, -7, -4},
					{-3, -5, -3, -6, -6, -6},
					{-3, -6, 0, -8, -6, -7}
					};
	printf("calculation started\n");
    int result = hourglassSum(arr_rows, arr_columns, arr);

    printf("result %d\n", result);

    return 0;
}
