/*
A number is called as a Jumping Number if all adjacent digits in it differ by 1. The difference between ‘9’ and ‘0’ is 
not considered as 1.
All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are 
Jumping numbers but 796 and 89098 are not.
Input: x = 20
Output:  0 1 2 3 4 5 6 7 8 9 10 12

Input: x = 105
Output:  0 1 2 3 4 5 6 7 8 9 10 12
         21 23 32 34 43 45 54 56 65
         67 76 78 87 89 98 101
*/ 
#include <stdio.h>
#include<stdbool.h>
#define MAX 10

int front, rear;

bool isEmpty(){
	if(front == -1) return true;
	return false;
}

// Prints all jumping numbers smaller than or equal to x starting 
// with 'num'. It mainly does BFS starting from 'num'. 
void bfs(int x, int num) 
{ 
	// Create a queue and enqueue 'i' to it 
	int q[MAX];
	front = -1;
	rear = -1;
	
	//Enqueue
	q[++rear] = num;
	front = 0;
	
	// Do BFS starting from i 
	while (!isEmpty()) { 
		//Dequeue
		num = q[front++];
		
		// printf("\n=== %d \n ", num);
		if (num <= x) { 
			printf("%d ", num); 
			int last_dig = num % 10; 
			
			// If last digit is 0, append next digit only 
			if (last_dig == 0) 
				//Enqueue
				q[++rear] = (num * 10) + (last_dig + 1);
			
			// If last digit is 9, append previous digit only 
			else if (last_dig == 9) 
				//Enqueue
				q[++rear] = (num * 10) + (last_dig - 1);	
			
			// If last digit is neighter 0 nor 9, append both 
			// previous and next digits 
			else { 
				//Enqueue
				q[++rear] = (num * 10) + (last_dig - 1);
				q[++rear] = (num * 10) + (last_dig + 1);
			} 
		}
			
		if(front > rear){
			front = -1;
			rear = -1;
		}
	} 
} 

// Prints all jumping numbers smaller than or equal to 
// a positive number x 
void printJumping(int x) 
{ 
	int i = 0;
	printf("%d ", i); 
	for (i = 1; i <= 9 && i <= x; i++) 
		bfs(x, i); 
} 

// Driver program 
int main() 
{ 
	int x = 40; 
	printJumping(x); 
	return 0; 
} 
