/**
 * API de operações sobre árvore binária
 */

#ifndef ARVORE
#define ARVORE

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
 * Recebe como parâmetro um ponteiro para node
 * Retorna ponteiro que aponta para raíz
 */
node* createTree(void);

/**
 * Libera memória alocada para a árvore
 * Recebe como parâmetro ponteiro para a raiz da árvore
 */
void freeTree(node* root);

/**
 * Adiciona filho a esquerda de parent se branch = 0
 * e a direita de parent se branch = 1
 * retorna 1 caso seja bem sucedido, 0 caso contrário
 */
int insert(node *parent, node *son, int branch);

#endif