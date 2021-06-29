// Write a Program to Find the Maximum Depth or Height of a Tree

#include<stdio.h> 
#include<conio.h>
#include<stdlib.h> 

/* A binary tree Node has data, pointer to left childand a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

/* Compute the "maxDepth" of a tree -- the number of Nodes along the longest path from the root Node down to the farthest leaf Node.*/
int maxDepth(struct Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int main()
{
	struct Node *root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->right = newNode(7);
	printf("Height of tree is %d", maxDepth(root));

	getchar();
	return 0;
}
