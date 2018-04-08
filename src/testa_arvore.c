/**
 * Implementa os testes relativos ao módulo
 * arvore.c
 */

#include "includes/catch.hpp"
#include "includes/arvore.h"
#include <string.h>

SCENARIO("Teste de criação", "[createTree, createNode]")
{
	GIVEN("Não há árvore nem nós") {
		node* root = NULL;

		WHEN("Um nó é criado") {
			root = createNode("Eu sou um nó\n");

			THEN("O texto é correto e esquerda e direita são NULL") {
				REQUIRE(root != NULL);
				REQUIRE(strcmp("Eu sou um nó\n", root->text) == 0);
				REQUIRE(root->left == NULL);
				REQUIRE(root->right == NULL);
			}
			free(root);
		}

		WHEN("Uma árvore é criada") {
			root = createTree();

			THEN("Node não é NULL") {
				REQUIRE(root != NULL);
			}

			THEN("A pergunta está correta") {
				REQUIRE(strcmp("É um animal?\n", root->text) == 0);
			}

			THEN("A resposta direita está correta") {
				REQUIRE(strcmp("gato\n", root->left->text) == 0);
			}

			THEN("A resposta esquerda está correta") {
				REQUIRE(strcmp("árvore\n", root->right->text) == 0);
			}

			THEN("Depth do root é 1") {
				REQUIRE(root->depth == 1);
			}

			freeTree(root);
		}
	}
}

SCENARIO("Teste de inserção", "[insert]")
{
	GIVEN("Parent e son criados, parent sem filhos")
	{
		node *parent, *son;
		parent = createNode("É maior que um cão?\n");
		son = createNode("É um cavalo!\n");

		WHEN("Inserção a esquerda")
		{
			insert(parent, son, 0);

			THEN("son é nó a esquerda de parent")
			{
				REQUIRE(parent->left == son);
			}

			THEN("depth do som é o depth do pai + 1")
			{
				REQUIRE(son->depth == parent->depth + 1);
			}
		}

		WHEN("Inserção a direita")
		{
			insert(parent, son, 1);

			THEN("son é nó a direita de parent")
			{
				REQUIRE(parent->right == son);
			}

			THEN("depth do som é o depth do pai + 1")
			{
				REQUIRE(son->depth == parent->depth + 1);
			}
		}

		WHEN("Branch diferente de 1 ou 0")
		{
			int feedback = insert(parent, son, 2);

			THEN("feedback sinaliza erro")
			{
				REQUIRE(feedback == 1);
			}
			THEN("Filhos de parent não são son")
			{
				REQUIRE(parent->left != son);
				REQUIRE(parent->right != son);
			}

			freeTree(son);
		}

		freeTree(parent);
	}

	GIVEN("Parent e son criados, parent com filhos")
	{
		node *parent, *son;
		parent = createTree();
		son = createNode("Eu sou um filhote de cuco!\n");

		WHEN("Tentativa de inserir filho numa posição ocupada")
		{
			int feedback = insert(parent, son, 0);

			THEN("insert retorna erro")
			{
				REQUIRE(feedback == 1);
			}
		}

		freeTree(parent);
		freeTree(son);
	}
}

SCENARIO("Teste de remoção", "[removeNode]")
{
	GIVEN("Parent e son existem, son filho de parent")
	{
		node *parent, *leftSon, *rightSon;
		parent = createTree();
		leftSon = parent->left;
		rightSon = parent->right;

		WHEN("Remove son a esquerda")
		{
			int feedback = removeNode(parent, leftSon);

			THEN("onde havia son, agora é null")
			{
				REQUIRE(parent->left == NULL);
			}
			THEN("o right son continua igual")
			{
				REQUIRE(parent->right == rightSon);
			}
			THEN("feedback não retorna erro")
			{
				REQUIRE(feedback == 0);
			}
		}

		WHEN("Remove son a direita")
		{
			int feedback = removeNode(parent, rightSon);

			THEN("onde havia son, agora é null")
			{
				REQUIRE(parent->right == NULL);
			}
			THEN("o left son continua igual")
			{
				REQUIRE(parent->left == leftSon);
			}
			THEN("feedback não retorna erro")
			{
				REQUIRE(feedback == 0);
			}
		}

		freeTree(parent);
	}

	GIVEN("Parent e son existem, son não é filho de parent")
	{
		node *parent, *son, *leftSon, *rightSon;
		parent = createTree();
		son = createNode("Eu sou um farsante!\n");
		leftSon = parent->left;
		rightSon = parent->right;

		WHEN("Remove son falso de parent")
		{
			int feedback = removeNode(parent, son);

			THEN("feedback retorna erro")
			{
				REQUIRE(feedback == 1);
			}
			THEN("filhos verdadeiros não se alteram")
			{
				REQUIRE(parent->left == leftSon);
				REQUIRE(parent->right == rightSon);
			}
		}

		freeTree(parent);
		freeTree(son);
	}

}

// SCENARIO("Teste de salvar e carregar", "[save, load]")
// {
// 	GIVEN("Árvores existem")
// 	{
// 		node *root, *loaded = NULL;
// 		root = createTree();

// 		WHEN("Salva árvore no arquivo e depois a carrega")
// 		{
// 			FILE *fp = fopen("test.txt", "w");
// 			save(root, fp);
// 			fclose(fp);
// 			fp = fopen("test.txt", "r");
// 			load(loaded, fp);

// 			THEN("Árvore salva e carregada são idênticas")
// 			{
// 				inorder(loaded);
// 				REQUIRE(strcmp(root->text,loaded->text));
// 				REQUIRE(strcmp(root->left->text, loaded->left->text));
// 				REQUIRE(strcmp(root->right->text, loaded->right->text));
// 			}

// 			fclose(fp);
// 		}
// 	}
// }