#include<stdio.h>
#include<stdlib.h>

int min(int,int);
int max(int,int);

void main(){
	int *ip, *res, n, i = 0, minCandies = 0;
	
	printf("Enter number of elements : ");
	scanf("%d", &n);
		
	ip = malloc(n*sizeof(int));
	res = malloc(n*sizeof(int));
	
	printf("\nEnter elements :");
	for(i = 0; i < n; i++){
		scanf("%d", ip + i);
		res[i] = 1;
	}
	
	for(i = 1; i < n; i++)
        if(ip[i] > ip[i-1])
          res[i] = max(res[i], res[i-1] + 1);
    
    for(i = n-2; i >= 0; i--)
        if(ip[i] > ip[i+1])
          res[i] = max(res[i], res[i+1] + 1);
	
	for(i = 0; i < n; i++){
		printf("%d ", res[i]);
		minCandies += res[i];
	}
	printf("\nMinimum candies required are %d", minCandies);
}

int min(int x,int y){
	return (x < y)?x:y;
}

int max(int x,int y){
	return (x > y)?x:y;
}