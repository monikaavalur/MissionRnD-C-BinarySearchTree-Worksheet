/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int AddToArray(struct node *root, int *arr, int index);
int AddToArray1(struct node *root, int *arr, int index1);
int AddToArray2(struct node *root, int *arr, int index2);
void inorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
		return;
	int index = 0;
	AddToArray(root, arr, index);
}
int AddToArray(struct node *root, int *arr, int index){
	if (root != NULL || arr != NULL)
	{
		if (root->left != NULL)
		{
			index=AddToArray(root->left, arr,index);
		}
		arr[index] = root->data;
		index++;
		if (root->right != NULL)
		{
			index=AddToArray(root->right, arr,index);
		}
	}
	return index;
}
void preorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
		return;
	int index1 = 0;
	AddToArray1(root, arr, index1);
}
int AddToArray1(struct node *root, int *arr, int index1){
	if (root != NULL || arr != NULL)
	{
		arr[index1] = root->data;
		index1++;
		if (root->left != NULL){
			index1=AddToArray1(root->left, arr,index1);
		}
		if (root->right != NULL){
			index1=AddToArray1(root->right, arr,index1);
		}
	}
	return index1;
}
void postorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
		return;
	int index2 = 0;
	AddToArray2(root, arr, index2);
}
int AddToArray2(struct node *root, int *arr, int index2){
	if (root != NULL || arr != NULL)
	{
		if (root->left != NULL)
		{
			index2=AddToArray2(root->left, arr,index2);
		}
		if (root->right != NULL){
			index2=AddToArray2(root->right, arr,index2);
		}
		arr[index2] = root->data;
		index2++;
	}
	return index2;
}

