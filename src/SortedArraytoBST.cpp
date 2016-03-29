/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
#include<stdio.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node *sortedArrayToBST(int *arr, int start, int end);
struct node *new_node(int data);
struct node *convert_array_to_bst(int *arr, int len)
{
	return sortedArrayToBST(arr, 0, len-1);
}
struct node *sortedArrayToBST(int *arr, int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start+end) / 2;
	struct node *root=new_node(arr[mid]);
	root->left = sortedArrayToBST(arr, start, mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);
	return root;
}

struct node * new_node(int data)
{
	struct node *temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->data = data;
	temp1->left = NULL;
	temp1->right = NULL;
	return temp1;
}

