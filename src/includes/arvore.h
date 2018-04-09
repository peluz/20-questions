/**
 * @file arvore.h 
 * @author Pedro Luz
 * 
 * API de operações sobre árvore binária
 */

#ifndef ARVORE
#define ARVORE

#include <stdio.h>

typedef struct node {
	char text[200];
	struct node *left;
	struct node *right;
}node;

/**
 * Função para criar um nó da árvore
 * Recebe como parâmetro o texto armazenado
 * na árvore
 * Retorna ponteiro para o nó
 */
node* createNode(char const *text);

/** 
 * Cria árvore cuja raíz é a pergunta default
 * e cujas árvores são as respostas default
 * Retorna ponteiro que aponta para raíz
 */
node* createTree(void);

/**
 * Libera memória alocada para a árvore
 * Recebe como parâmetro ponteiro para a raiz da árvore
 */
void freeTree(node* root);

/**
 * Adiciona son a esquerda de parent se branch = 0
 * e a direita de parent se branch = 1
 * retorna 0 caso seja bem sucedido, 1 caso contrário
 */
int insert(node *parent, node *son, int branch);

/**
 * Remove filho e seus respectivos filhos de pai
 * Recebe como parâmetros ponteiros para son e parent
 * retorna 0 caso bem sucedido, 1 caso contrário
 */
int removeNode(node *parent, node *son);

/**
 * Salva árvore serializada em arquivo
 * Recebe como parâmetros ponteiro para raiz da árvore
 * e arquivo onde será salva a árvore
 */
void save(node *root, FILE *fp);

/**
 * Carrega de arquivo com árvore serializada
 * Recebe como parâmetro aquivo onde está salva a árvore
 * Retorna ponteiro para raíz da árvore
 */
node* load(FILE *fp);
#endif