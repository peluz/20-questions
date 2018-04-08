/**
 * Implementa jogo de 20 perguntas
 */

#include "includes/arvore.h"
#include <stdio.h>

int main(void) {
	node* root = NULL;
	root = createTree();
	freeTree(root);
	return 0;
}