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
		}
	}
}