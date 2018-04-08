/**
 * Implementa jogo de 20 perguntas
 */

#include "includes/arvore.h"
#include <stdio.h>

int main(void) {
	node *temp;
	node *root = NULL;
	root = createTree();
	temp = root;
	char answer;

	printf("Pense em algo para eu tentar advinhar!\nResponda s para sim, n para não e q para sair do jogo!\n");

	while(1)
	{
		printf("%s", temp->text);

		do
		{
			scanf("%c", &answer);
		}
		while (answer != 's' && answer != 'n' && answer != 'q' );

		if (answer == 'q')
		{
			break;
		}

		if (answer == 's')
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}

	}


	freeTree(root);
	return 0;
}