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
	printf("%s", data);
	strcpy(new_node->text, data);
	new_node->left = new_node->right = NULL;
	new_node->depth = 0;
	return new_node;
}

node* createTree(void) 
{
	node *root, *sim, *nao;

	root = createNode("É um animal?\n");
	sim = createNode("É um gato!\n");
	nao = createNode("É uma árvore!\n");
	root->left = sim;
	root->right = nao;
	root->depth = 1;
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

void load(node *root, FILE* fp)
{
	char text[150];

	if (fgets(text, 150, fp) == NULL)
	{
		printf("hey\n");
		return;
	}

	if (strcmp(text, "-1\n") == 0)
	{
		return;
	}

	root = createNode(text);
	load(root->left, fp);
	load(root->right, fp);
}