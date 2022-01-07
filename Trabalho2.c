#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include <locale.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	char escolha;
	contato pessoa;
	tLista l;
	inicializar(&l);
	menu();
	do{
	printf("\nDigite a opcao desejada: ");
    scanf(" %s", &escolha);
    switch(tolower(escolha)){//Caso de escolha do menu
    	case 'a': //Inserção de elemento - ITEM A
    	printf("\nDigite o Nome: ");
    	scanf(" %[^\n]", &pessoa.nome);
        printf("\nDigite o CPF: ");
        scanf(" %s", &pessoa.cpf);
        printf("\nDigite o email : ");
        scanf(" %s", &pessoa.email);
        inserirContato(&l, pessoa);
        printf("\n--------------------------------------------");
    		break;
    	case 'b': //Remoção de elemento - ITEM B
        removerContato(&l);
        printf("\n--------------------------------------------");
    		break;
    	case 'c': //Consulta de elemento - ITEM C
        consultarPosicao(&l);
        //consultarPosicao(&l, pessoa);
        printf("--------------------------------------------");
    		break;
    	case 'd': //Listagem de elemento - ITEM D
        listarContatos(&l);
        printf("\nTamanho atual da lista: %d\n", tamanho(&l));
        printf("--------------------------------------------");
    		break;
    	case 'e':
        //system("cls");
        printf("Saindo...");
    		break;
    	default:
    		printf("\nOpcao invalida\n");
	}
} while(escolha != 'e');
	return 0;
}
