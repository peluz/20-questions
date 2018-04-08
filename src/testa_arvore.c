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
				REQUIRE(strcmp("É um gato!\n", root->left->text) == 0);
			}

			THEN("A resposta esquerda está correta") {
				REQUIRE(strcmp("É uma árvore!\n", root->right->text) == 0);
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
		}

		WHEN("Inserção a direita")
		{
			insert(parent, son, 1);

			THEN("son é nó a direita de parent")
			{
				REQUIRE(parent->right == son);
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