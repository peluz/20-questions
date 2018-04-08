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
	sim = createNode("É um gato!\n");
	nao = createNode("É uma árvore!\n");
	root->left = sim;
	root->right = nao;
}