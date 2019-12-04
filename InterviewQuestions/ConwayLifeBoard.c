/*Conway's Game of Life
Conway's Game of Life takes place on an infinite two-dimensional board of square cells. 
Each cell is either dead or alive, and at each tick, the following rules apply:
	* Any live cell with less than two live neighbours dies.
	* Any live cell with two or three live neighbours remains living.
	* Any live cell with more than three live neighbours dies.
	* Any dead cell with exactly three live neighbours becomes a live cell.
	* A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.
*/

#include<stdio.h>

void main(){
	char board[5][5] = {
		".*...",
		"...**",
		".*..*",
		".*.**",
		"**..*"
	};
	char nextboard[5][5] = {
		".*...",
		"...**",
		".*..*",
		".*.**",
		"**..*"
	};
	int rows = 5, cols = 5;
	int i, j, x, y;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			int neighbours = 0;
			for(x = -1; x <= 1 ; x++){
				for(y = -1; y <= 1; y++){
					if( (x+i) > 0 && (x+i) < rows && (y+j) > 0 && (y+j) < cols && board[x+i][y+j] == '*'){
						neighbours ++; 
					}
				}
			}
			//Subtract current cells count if its live
			if(board[i][j] == '*') neighbours -= 1;
			
			//decide next state
			if(board[i][j] == '*' && neighbours < 2){
				nextboard[i][j] = '.';
			}else if(board[i][j] == '*' && neighbours > 3){
				nextboard[i][j] = '.';
			}else if(board[i][j] == '.' && neighbours == 3){
				nextboard[i][j] = '*';
			}
		}
	}

	printf("Next gen board \n");
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			printf("%c", nextboard[i][j]);
	}
	printf("\n");
	}
}
