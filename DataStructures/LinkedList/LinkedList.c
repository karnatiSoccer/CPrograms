#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void removeLoop(struct Node *loopNode, struct Node *head)
{
    struct Node *ptr1 = loopNode;
    struct Node *ptr2 = loopNode;
    int i, looplen = 1;
     
    // count the number of nodes in loop
    while(ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        looplen++;
    }
     
    ptr1 = head;
    ptr2 = head;
    for(i=0; i < looplen; i++)
    {
        ptr2 = ptr2->next;
    }
     
    while(ptr2->next != ptr1->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
     
    ptr2->next = NULL; // breaking the loop
}

int detectLoopOptimised(struct Node *head){
	// printf("detectLoop");
	struct Node *hare, *turtle;
	hare = head;
	turtle = head;
	while(turtle != NULL && hare != NULL && hare -> next != NULL){
		turtle = turtle -> next;
		hare = hare -> next -> next;
		if(hare == turtle){
			return 1;
		}
	}
	return 0;
	
}

int detectLoop(struct Node *head){
	// printf("detectLoop");
	struct Node *hare, *turtle;
	hare = head;
	turtle = head;
	int loop = 1;
	while(loop){
		// printf("detectLoop..");
		hare = hare -> next;
		if(hare == NULL || turtle == NULL){
			loop = 0;
			break;
		}
		hare = hare -> next;
		turtle = turtle -> next;
		if(hare == NULL || turtle == NULL){
			loop = 0;
			break;
		}
		if(hare == turtle){
			loop = 0;
			break;
		}		
	}
	if(hare == turtle){
		// printf("returning 1..");
		return 1;
	}else{
		// printf("returning 0..");
		return 0;
	}
}

void rotateLinkedList(struct Node **head, int index){
	if(*head == NULL){
		return;
	}
	struct Node *nthNode, *lastNode;
	lastNode = *head;
	
	int tempIndex = 0;
	while (lastNode -> next != NULL){
		tempIndex ++;
		if(tempIndex == index){
			nthNode = lastNode;
		}
		lastNode = lastNode -> next;		
	}
	
	lastNode -> next = *head;
	*head = nthNode -> next;
	nthNode -> next = NULL;
		
}

void reverseLinkedList(struct Node **head){
	struct Node *next, *prev, *curr;
	prev = NULL;
	curr = *head;
	if(*head == NULL){
		return;
	}
	next = curr -> next;
	while(curr != NULL){
		curr -> next= prev;
		prev = curr;
		curr = next;
		if(next != NULL)
			next = next -> next;
	}	
	*head = prev;
}

void reverseLinkedListRecursion(struct Node **head, struct Node *node){
	if(node -> next == NULL){
		*head = node;
		return;
	}
	reverseLinkedListRecursion(head, node -> next);
	struct Node *temp = node -> next;
	temp -> next = node;
	node -> next = NULL;
}

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

/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)  
{  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n\n", slow_ptr->data);  
    }  
} 

void print(struct Node *head){
	struct Node *temp;
	temp = head;
	while(temp != NULL){
		printf("%d ->", temp -> data);
		temp = temp -> next;
	}
}

void printAtIndex(struct Node *head, int Idx){
	struct Node *temp;
	temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		if(count == Idx){
			printf("%d", temp -> data);
			break;
		}
		temp = temp -> next;
	}
}

int getListElementsCount(struct Node *head){
	int count = 0;
	struct Node *temp;
	temp = head;
	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}

void removeDuplicates(struct Node *head){
	struct Node *curr = head;
	struct Node *next = curr -> next;
	while(curr != NULL){
		next = curr -> next;
		if(next != NULL && curr -> data == next -> data){
			curr -> next = next -> next;
			next -> next = NULL;			
		}else{
			curr = next;
		}
	}
}

void main(){
	struct Node *head = NULL;
	//adding 5 nodes at the top of linked list	
	for(int i = 0; i < 6; i++){
		insertAtBegining(&head, i);
	}
	
	// insertAtBegining(&head, 1);
	// insertAtBegining(&head, 2);
	// insertAtBegining(&head, 2);
	// insertAtBegining(&head, 2);
	// insertAtBegining(&head, 4);
	// insertAtBegining(&head, 4);
	print(head);
	// printf("\n");
	
	// reverseLinkedList(&head);
	// reverseLinkedListRecursion(&head, head);
	// rotateLinkedList(&head, 4);
	// printf("\nReversed list is \n");
	// print(head);
	// int loop = detectLoop(head);
	// printf("loop %d", loop);
	// if(loop == 1){
		// printf("\nLoop Exists");
	// }else{
		// printf("\nLoop doesnot exists");
	// }
	
	//Print middle element Method1
	// int numElements = getListElementsCount(head);
	// printf("\nNum elements in list %d\n", numElements);
	// printf("\nMiddle element is ");
	// printAtIndex(head, numElements/2+1);
	// Method 2
	// printMiddle(head);
	
	// removeDuplicates(head);
	// print(head);
}