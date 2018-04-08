/**
 * API de operações sobre árvore binária
 */

#ifndef ARVORE
#define ARVORE

typedef struct node {
	char text[200];
	int depth;
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
int remove(node *parent, node *son);

#endif