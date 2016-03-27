/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void swap(int*, int*);
void fixBST(struct node*, struct node**, struct node** , struct node**, struct node**);

void fix_bst(struct node *root)
{
	struct node *start, *mid, *end, *last;
	start = mid =end = last = NULL;
	fixBST(root, &start, &mid, &end, &last);
	if (start&& end)
		swap(&(start->data), &(end->data));
	else if (start && mid)
		swap(&(start->data), &(mid->data));


}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void fixBST(struct node* root, struct node** first,struct node** middle, struct node** last,struct node** prev)
{
	if (root)
	{
		fixBST(root->left, first, middle, last, prev);
		if (*prev&& root->data < (*prev)->data)
		{
			if (!*first)
			{
				*first = *prev;
				*middle = root;
			}
			else
				*last = root;
		}
		*prev = root;
		fixBST(root->right, first, middle, last, prev);
	}
}

