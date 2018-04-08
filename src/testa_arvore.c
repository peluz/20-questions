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
		struct node* node = NULL;

		WHEN("Um nó é criado") {
			node = createNode("Eu sou um nó\n");

			THEN("O texto é correto e esquerda e direita são NULL") {
				REQUIRE(node != NULL);
				REQUIRE(strcmp("Eu sou um nó\n", node->text) == 0);
				REQUIRE(node->left == NULL);
				REQUIRE(node->right == NULL);
			}
		}
	}
}