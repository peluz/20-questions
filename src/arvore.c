/**
 * Implementação das operações sobre
 * a árvore
 */

#include "includes/arvore.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

node* createNode(char const *data) 
{
	node *new_node = (struct node*) malloc(sizeof(struct node));
	strcpy(new_node->text, data);
	new_node->left = new_node->right = NULL;
	return new_node;
}

node* createTree(void) 
{
	node *root, *sim, *nao;

	root = createNode("É um animal?\n");
	sim = createNode("gato\n");
	nao = createNode("árvore\n");
	root->left = sim;
	root->right = nao;
}

void freeTree(node* root)
{
	if (root == NULL) 
	{
		return;
	}

	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int insert(node *parent, node *son, int branch)
{
	switch (branch)
	{
		case 0:
			if (parent->left != NULL)
			{
				break;
			}
			parent->left = son;
			return 0;
		case 1:
			if (parent->right != NULL)
			{
				break;
			}
			parent->right = son;
			return 0;
		default:
			return 1;
	}
}

int removeNode(node *parent, node *son)
{
	if(parent->left != son && parent->right != son)
	{
		return 1;
	}

	if(parent->left == son)
	{
		parent->left = NULL;
	}
	else
	{
		parent->right = NULL;
	}

	freeTree(son);
	return 0;
}

void save(node *root, FILE *fp)
{
	if(root == NULL)
	{
		fprintf(fp, "-1\n");
		return;
	}

	fprintf(fp, "%s", root->text);
	save(root->left, fp);
	save(root->right, fp);
}

node* load(FILE* fp)
{
	char text[200];

	if (fgets(text, 200, fp) == NULL || strcmp(text, "-1\n") == 0)
	{
		return NULL;
	}

	node *root = createNode(text);
	root->left = load(fp);
	root->right = load(fp);
	return root;
}