#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(tLista *f){   
  f->inicio = NULL;   
  f->fim = NULL;   
  f->tamanho = 0;   
} 

void menu() {
  printf("\nEscolha uma das opcoes abaixo para navegar\n");
	printf("\na - Inserir contato na lista");
	printf("\nb - Removar contato da lista");
	printf("\nc - Consultar contato");
	printf("\nd - Listas contas");
    printf("\ne - Sair\n");
} 

int vazia(tLista *l){
	
}
int inserirContato(tLista *l, contato c){
	
}
int removerContato(tLista *l, contato *c){
	
}
void consultarPosicao(tLista *l, contato c){
	
}
void listarContatos(tLista *l){
	
}
int tamanho(tLista *l){
	
}
