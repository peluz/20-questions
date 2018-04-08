/**
 * Implementa jogo de 20 perguntas
 */

#include "includes/arvore.h"
#include <stdio.h>

int main(void) {
	struct node* node = NULL;
	node = createNode("Eu sou um nó");
	printf("%s", node->text);
	return 0;
}