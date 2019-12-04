#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node *next;
};

void insertAtBegining(struct Node **head, int val){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node -> data = val;
	node -> next = NULL;
	
	if(*head == NULL){
		*head = node;
	}else{
		node -> next = *head;
		*head = node;
	}
}

void addLists(struct Node *first, struct Node *second){
	int sum = 0, i = 0;
	float temp;
	while(first != NULL || second != NULL){
		if(first != NULL && second != NULL){
			temp = (first -> data + second -> data) * pow(10, i++);
			first = first -> next;
			second = second -> next;
		}else if(first != NULL){
			temp = (first -> data) * pow(10, i++);
			first = first -> next;
		}else if(second != NULL){
			temp = (second -> data) * pow(10, i++);
			second = second -> next;
		}
		sum += temp;
	}
	
	printf("\nSum = %d ", sum);
}

void print(struct Node *head){
	struct Node *temp;
	temp = head;
	while(temp != NULL){
		printf("%d ->", temp -> data);
		temp = temp -> next;
	}
}

void main(){
	struct Node *first = NULL, *second = NULL;
	//adding 3 nodes at the top of linked list	
	insertAtBegining(&first, 5);
	insertAtBegining(&first, 1);
	insertAtBegining(&first, 3);
	
	//adding 3 nodes at the top of linked list	
	insertAtBegining(&second, 2);
	insertAtBegining(&second, 9);
	insertAtBegining(&second, 5);
	insertAtBegining(&second, 4);
	
	printf("List one ");
	print(first);
	printf("\nList second ");
	print(second);
	
	addLists(first, second);
}