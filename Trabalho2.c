#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char escolha;
	int posicao;
	contato pessoa, pAux;
	tLista l;
	inicializar(&l);
	menu();
	do{
	printf("\nDigite a opcao desejada: ");
    scanf("%c", &escolha);
    switch(tolower(escolha)){//Caso de escolha do menu
    	case 'a':
    	printf("\nDigite o Nome: ");
    	scanf(" %s", &pessoa.nome);
        //gets(pessoa.nome);
        printf("\nDigite o CPF: ");
        scanf(" %s", &pessoa.cpf);
        //gets(pessoa.cpf);
        printf("\nDigite o email : ");
        scanf(" %s", &pessoa.email);
        //gets(pessoa.email);
        inserirContato(&l, pessoa);
        printf("--------------------------------------------");
    		break;
    	case 'b':
        printf("\nDigite a posi��o a remover:");
        scanf("%d", &posicao);
        //removerContato(&l, &pAux);
        printf("--------------------------------------------");
    		break;
    	case 'c':
    	printf("\nDigite a posi��o a ser consultar:");
        scanf("%d", &posicao);
        //consultarPosicao(&l, pessoa);
        printf("--------------------------------------------");
    		break;
    	case 'd':
        //listarContatos(&l);
        printf("--------------------------------------------");
    		break;
    	case 'e':
        system("cls");
        printf("Saindo...");
    		break;
    	default:
    		printf("\nOpcao invalida\n");
	}
} while(escolha != 'e');
	return 0;
}
