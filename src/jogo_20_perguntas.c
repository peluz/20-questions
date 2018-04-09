/**
 * Implementa jogo de 20 perguntas
 */

#include "includes/arvore.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	node *temp;
	node *root = NULL;
	node *prev = NULL;
	node *aux = NULL;
	node *aux2 = NULL;
	root = createTree();
	temp = root;
	char answer;
	char question[200];
	char correct[200];
	char incorrect[200];
	int prevBranch;
	FILE* fp;

	printf("Pense em algo para eu tentar advinhar!\nResponda s para sim, n para não e q para sair do jogo!\n");

	printf("Deseja carregar árvore salva anteriormente?(s/n)\n");

	do
	{
		scanf("%c", &answer);
	}
	while (answer != 's' && answer != 'n');

	if (answer == 's')
	{
		fp = fopen("arvore.txt", "r");
		root = load(fp);
		temp = root;
		fclose(fp);
	}


	while(1)
	{
		printf("%s", temp->text);

		if(temp->right == NULL)
		{
			printf("É a resposta certa?(s/n)\n");

			do
			{
				scanf("%c", &answer);
			}
			while (answer != 's' && answer != 'n');

			if(answer == 's')
			{
				printf("Ótimo! Agora pense em outra palavra! Lá vamos nós!\n");
			}
			else
			{
				strcpy(incorrect, temp->text);

				printf("Qual é a resposta?\n");
				scanf("\n");

				fgets(correct, 200, stdin);

				printf("Que pergunta distingue a resposta certa da errada?\n");

				fgets(question, 200, stdin);

				removeNode(prev, temp);
				aux = createNode(question);
				insert(prev, aux, prevBranch);
				if (prevBranch == 0)
				{
					temp = prev->left;
				}
				else
				{
					temp = prev->right;
				}
				

				printf("A resposta pra essa pergunta é sim (s) ou nao (n) para %s", incorrect);

				do
				{
					scanf("%c", &answer);
				}
				while (answer != 's' && answer != 'n');

				aux = createNode(incorrect);
				aux2 = createNode(correct);
				if (answer == 's')
				{
					insert(temp, aux, 0);
					insert(temp, aux2, 1);
				}
				else
				{
					insert(temp, aux, 1);
					insert(temp, aux2, 0);
				}

				printf("Alterações Salvas! Vamos começar de novo!\n");
			}

			
			temp = root;
			prev = NULL;
		}

		else
		{
			prev = temp;
			do
			{
				scanf("%c", &answer);
			}
			while (answer != 's' && answer != 'n' && answer != 'q' );

			if (answer == 'q')
			{
				printf("Saindo do jogo! Árvore salva em arvore.txt\n");
				fp = fopen("arvore.txt", "w");
				save(root, fp);
				fclose(fp);
				break;
			}

			if (answer == 's')
			{
				temp = temp->left;
				prevBranch = 0;
			}
			else
			{
				temp = temp->right;
				prevBranch = 1;
			}
		}

	}


	freeTree(root);
	return 0;
}