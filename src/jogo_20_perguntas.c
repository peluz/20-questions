/**
 * Implementa jogo de 20 perguntas
 */

#include "includes/arvore.h"
#include <stdio.h>

int main(void) {
	node* loaded;
	node* root = NULL;
	root = createTree();
	FILE *fp = fopen("test.txt", "w");
	save(root, fp);
	fclose(fp);
	fp = fopen("test.txt", "r");
	load(loaded, fp);
	printf("ola\n");
	printf("%s", loaded->text);
	printf("%s", loaded->left->text);
	printf("%s", loaded->right->text);
	fclose(fp);
	freeTree(loaded);
	freeTree(root);
	return 0;
}