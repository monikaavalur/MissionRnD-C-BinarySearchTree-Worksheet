/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of right subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int get_height(struct node *root)
{
	if (root == NULL)
		return 0;
	int heightl = get_height(root->left);
	int heightr = get_height(root->right);
	if (heightl > heightr)
		return heightl + 1;
	else
		return heightr + 1;
}
int Node(struct node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return 0;
}
int get_left_subtree_sum(struct node *root)
{
		int sum_left = 0;
		if (root != NULL)
		{
			if (Node(root->left)==1)
				sum_left += root->left->data;
			else 
				sum_left += get_left_subtree_sum(root->left);
			sum_left += get_left_subtree_sum(root->right);
		}
		return sum_left;
}


int get_right_subtree_sum(struct node *root){
	int sum_right = 0;
	if (root != NULL)
	{
		if (Node(root->right)==1)
			sum_right += root->right->data;
		else 
			sum_right += get_right_subtree_sum(root->right);
		sum_right += get_right_subtree_sum(root->left);
	}
	return sum_right;
}

