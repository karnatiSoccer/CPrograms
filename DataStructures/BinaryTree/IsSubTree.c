/* C program to check if a tree is sub tree of another tree */
/*
Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a struct Node in T and all of its descendants in T. The subtree corresponding to the root struct Node is the entire tree; the subtree corresponding to any other struct Node is called a proper subtree.

For example, in the following case, tree S is a subtree of tree T.

        Tree 2
          10  
        /    \ 
      4       6
       \
        30


        Tree 1
              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> 

/* A binary tree struct Node has data, 
left child and right child */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

/* A utility function to check 
whether trees with roots as root1 and 
root2 are identical or not */
bool areIdentical(struct Node * root1, struct Node *root2) 
{ 
	/* base cases */
	if (root1 == NULL && root2 == NULL) 
		return true; 

	if (root1 == NULL || root2 == NULL) 
		return false; 

	/* Check if the data of both roots is 
	same and data of left and right 
	subtrees are also same */
	return (root1->data == root2->data && 
			areIdentical(root1->left, root2->left) && 
			areIdentical(root1->right, root2->right) ); 
} 


/* This function returns true if 
S is a subtree of T, otherwise false */
bool isSubtree(struct Node *T, struct Node *S) 
{ 
	/* base cases */
	if (S == NULL) 
		return true; 

	if (T == NULL) 
		return false; 

	/* Check the tree with root as current struct Node */
	if (areIdentical(T, S)) 
		return true; 

	/* If the tree with root as current 
	struct Node doesn't match then try left 
	and right subtrees one by one */
	return isSubtree(T->left, S) || 
		isSubtree(T->right, S); 
} 


/* Helper function that allocates 
a new struct Node with the given data 
and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
	struct Node* Node = (struct Node*)malloc(sizeof(struct Node*)); 
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 
	return(Node); 
} 

/* Driver code*/
int main() 
{ 
	// TREE 1 
	/* Construct the following tree 
			26 
			/ \ 
		   10  3 
		   / \  \ 
	      4   6  3 
		   \ 
		   30 
	*/
	struct Node *T = newNode(26); 
	T->right		 = newNode(3); 
	T->right->right = newNode(3); 
	T->left		 = newNode(10); 
	T->left->left	 = newNode(4); 
	T->left->left->right = newNode(30); 
	T->left->right	 = newNode(6); 

	// TREE 2 
	/* Construct the following tree 
		 10 
		/ \ 
	   4  6 
	   \ 
		30 
	*/
	struct Node *S = newNode(10); 
	S->right	 = newNode(6); 
	S->left	 = newNode(4); 
	S->left->right = newNode(30); 


	if (isSubtree(T, S)) 
		printf("Tree 2 is subtree of Tree 1"); 
	else
		printf("Tree 2 is not a subtree of Tree 1");

	return 0; 
} 