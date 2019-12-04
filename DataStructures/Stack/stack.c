#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 10

struct stack{
	int items[MAX];
	int top;
};
typedef struct stack st;

int isFull(st *s){
	if(s -> top == MAX - 1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(st *s){
	if(s -> top == -1){
		return 1;
	}else{
		return 0;
	}
}

void push(st *s){
	if(isFull(s)){
		printf("Stack is full\n");
	}else{
		int value;
		printf("Enter value to push\n");
		scanf("%d", &value);
		s -> top++;
		s -> items[s -> top] = value;
	}
}

void pop(st *s){
	if(isEmpty(s)){
		printf("Stack is empty\n");
	}else{
		printf("Popped value is %d\n", s -> items[s -> top]);
		s -> top--;		
	}
}

void print(st *s){
	printf("Values in stack are \n");
	for(int i = s-> top; i >= 0; i--){
		printf("%d", s -> items[i]);
	}
	printf("\n");
}

void createEmptyStack(st *s){
	s -> top = -1;
}

void main(){
	st *s;
	int loop = 1;
	int ch;
	
	createEmptyStack(s);
	
	do{
		printf("======== Stack Operations =======\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Print\n");
		printf("4.Exit\n");
		printf("===============\n");
		
		printf("\nEnter your choice: ");
        scanf("%d", &ch);
		
		switch(ch){
			case 1:
				push(s);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				print(s);
				break;
			case 4:
				printf("Thank you!\n");
				loop = 0;
				exit(0);
			default:
				printf("Invalid choice\n");
				break;
		}
			
	}while(loop);
	
	getch();
}