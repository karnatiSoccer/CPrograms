#include<stdio.h>
#include<stdlib.h>

/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
	node -> data = value;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

int getRootIndex(int arr[], int size, int value){
	// Using linear search to find the root value index, can be optimised using binary search
	int index = -1;
	for(int i = 0; i < size; i++){
		if(arr[i] == value){
			index = i;
			break;
		}
	}
	return index;
}

struct Node* constructBinaryTree(int inOrder[], int postorder[], int size){
	if(size == 0) return NULL;
	/*Root value will be the last item in the postorder array
	  Search for that element in inOrder array, the elements left to it will be left sub tree
	  elements right to it are right sub tree
	*/
	int rootIndex = getRootIndex(inOrder, size, postorder[size - 1]);	
	struct Node* root = createNode(inOrder[rootIndex]);
	root -> left = constructBinaryTree(inOrder, postorder, size - rootIndex - 1);
	root -> right = constructBinaryTree(inOrder + rootIndex + 1, postorder + rootIndex, size - rootIndex - 1);
	return root;
}

//PreOrder printing
void printTree(struct Node* root){
	if(root == NULL) return;
	printf("%d ", root -> data);
	printTree(root -> left);	
	printTree(root -> right);
}

void main(){
	int inOrder[] = {1, 2, 3, 4, 5, 6, 7};
	int postorder[] = {1, 3, 2, 5, 7, 6, 4};
	int size = 7;
	
	struct Node* root;
	
	root = constructBinaryTree(inOrder, postorder, size);
	printTree(root);
}