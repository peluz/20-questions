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
	new_node->depth = 0;
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
	root->depth = 1;
	sim->depth = 2;
	nao->depth = 2;
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
			son->depth = parent->depth + 1;
			return 0;
		case 1:
			if (parent->right != NULL)
			{
				break;
			}
			parent->right = son;
			son->depth = parent->depth + 1;
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