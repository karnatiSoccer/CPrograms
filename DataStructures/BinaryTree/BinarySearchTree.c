#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* items[SIZE];
int front = -1, rear = -1;

void enQueue(struct node*);

struct node* deQueue();

struct node* createNode(int value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
    
struct node* insert(struct node* root, int data)
{
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}

void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root == NULL) return;
    printf("%d ->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}

void level_order_traversal(struct node* root)
{
	if(root == NULL)
		return;
	enQueue(root);
	struct node* temp=deQueue();
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		if(temp->left!=NULL)
			enQueue(temp->left);
		if(temp->right)
			enQueue(temp->right);
		temp=deQueue();	
	}
}

void mirror(struct node* root){
	if(root == NULL){
		return;
	}
	mirror(root -> left);
	mirror(root -> right);
	
	//Swap let/right sub trees
	struct node* temp;
	temp = root -> left;
	root -> left = root -> right;
	root -> right = temp;
}

int main(){
    struct node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);
    inorder(root);
	printf("\n");
	mirror(root);
	inorder(root);
	printf("Level order traversal\n");
	level_order_traversal(root);
}

void enQueue(struct node* value){
    if(rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        // printf("\nInserted -> %d", value);
    }
}
struct node* deQueue(){
    if(front == -1)
        printf("\nQueue is Empty!!");
    else{
        // printf("\nDeleted : %d", items[front]);		
        int temp = front;
		front++;
        if(front > rear)
            front = rear = -1;
		return items[temp];
    }
}