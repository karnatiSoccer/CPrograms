/*
Moore’s Voting Algorithm: We will cancel out each occurrence of K for all other element other than K. If count of K is non zero till end of array then K is a majority element.
Assume first element of array is majority element and initialize the count of majority element to 1. Traverse inputArray from index 0 to N-1.
If current element is equal to majority element then increment count else decrement count.
If cunt is equal to zero then set current element as majority element and count as 1.
Time Complexity : O(n)
*/
#include <stdio.h>

void findMajElem(int *arr1, int n) 
{
	int i,IndexOfMajElem = 0, ctr = 1;
    for(i = 1; i < n; i++) 
	{
        if(arr1[IndexOfMajElem] == arr1[i])
            ctr++;
        else
            ctr--;
         
        if(ctr == 0) {
            IndexOfMajElem = i;
            ctr = 1;
        }
    }
    ctr = 0;
    for (i = 0; i < n; i++) 
	{
        if(arr1[i] == arr1[IndexOfMajElem])
            ctr++; 
	}
    if(ctr > (n/2))
        printf("Majority Element : %d\n", arr1[IndexOfMajElem]);
    else
        printf("There are no Majority Elements in the given array.\n");
}
 
int main()
{
    int i, ctr,m;
    int arr1[] = { 5, 8, 5, 6, 5 , 8, 7};	
    ctr = sizeof(arr1)/sizeof(arr1[0]);
    printf("The given array is :  ");
	for(i = 0; i < ctr; i++)
	{
		printf("%d  ", arr1[i]);
    } 
	
    printf("\n");
	findMajElem(arr1, ctr);
    return 0;
}