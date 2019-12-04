#include<stdio.h>

void printPyramid();
void drawCircle(int);

void main(){
	// printPyramid();
	drawCircle(8); 
}

// C code to demonstrate to draw 
// circle without floating 
// point arithmetic 
void drawCircle(int r) 
{ 
	// Consider a rectangle of size N*N 
	int N = 2*r+1; 

	int x, y; // Coordinates inside the rectangle 

	// Draw a square of size N*N. 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
		{ 
			// Start from the left most corner point 
			x = i-r; 
			y = j-r; 

			// If this point is inside the circle, print it 
			if (x*x + y*y <= r*r+1 ) 
				printf("."); 
			else // If outside the circle, print space 
				printf(" "); 
			printf(" "); 
		} 
		printf("\n"); 
	} 
} 

void printPyramid(){
	/*
	     1
		121
	   12321
	  1234321
	 123454321
	*/
	int ROWS = 5;
	int space = 4;
	int i, j;
	
	//Loop through number of rows
	for(i = 1; i <= ROWS; i++){
		//Print spaces
		for(j = 1; j <= space; j++){
			printf(" ");
		}
		//Print increasing order
		for(j = 1; j <=  i; j++){
			printf("%d", j);
		}
		//print decreasing order
		for(j = i - 1; j > 0; j--){
			printf("%d", j);
		}
		space--;
		printf("\n");
	}
}