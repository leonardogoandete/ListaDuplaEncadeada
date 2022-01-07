#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar(tLista *l){ //INICIA A LISTA
  l->inicio = NULL;   
  l->fim = NULL;   
  l->tamanho = 0;   
} 

void menu() { //MENU PARA AS OP��ES
  printf("\nEscolha uma das opcoes abaixo para navegar\n");
	printf("\na - Inserir contato na lista");
	printf("\nb - Removar contato da lista");
	printf("\nc - Consultar contato");
	printf("\nd - Listas contas");
    printf("\ne - Sair\n");
} 

int vazia(tLista *l){ //RETORNO SE VAZIO
    return (l->inicio == NULL);
}

void inserirContato(tLista *l, contato c){ //INSER��O DE CONTATO
    tipoNo *no = (tipoNo*)malloc(sizeof(tipoNo)); //ALOCA��O DE ESPA�O
    strcpy(no->dados.nome,c.nome); //C�PIA DE DADOS INSERIDOS
    strcpy(no->dados.cpf,c.cpf);
    strcpy(no->dados.email,c.email);
    if(vazia(l)){	
    if( no != NULL){//INSER��O DE CONTATO EM LISTA VAZIA
    	no -> prox = l->fim;
        no -> ant = l->inicio;
        l -> fim = no;
        l -> inicio = no;
        l->tamanho++;
        printf("\nLista vazia, primeiro contato inserido\n");
        }
        }else{
        	tipoNo *ante = (tipoNo*)malloc(sizeof(tipoNo)); //N�S AUXILIARES
        	tipoNo *atual = (tipoNo*)malloc(sizeof(tipoNo));
        	atual = l->inicio;
        	if(strcasecmp(atual->dados.email, c.email) !=0){ //CONDI��O SE EMAIL IGUAL J� � EXISTENTE
        	while(atual !=NULL && strcasecmp(atual->dados.email, c.email) <	 0){ //SE N�O PERCORRE NA LISTA PARA INSERIR 
        	    ante = atual;                                                    //CONFORME ORDEM ALFAB�TICA
			    atual = atual -> prox;
			}
			if(atual == l->inicio){ //INSER��O NO IN�CIO
				no -> ant = NULL;
				no->prox = l->inicio;
				l->inicio->ant = no;
				l->inicio = no;
				l->tamanho++;
				printf("\nContato inserido no in�cio\n");
			}else{
				if(atual == NULL){ //INSER��O NO FIM
				no -> prox = ante -> prox;
				no -> ant = ante;
				ante -> prox = no;
				l->fim = no;
				l->tamanho++;
				printf("\nContato inserido no fim da lista\n");
				}else{ //INSER��O NO MEIO
				no -> prox = ante -> prox;
				no -> ant = ante;
				ante -> prox = no;
				atual -> ant = no;
				l->tamanho++;
				printf("\nContato inserido no meio da lista\n");
				}
			}
		}else{
			printf("\nContato j� com email j� existente");
			return 0;
		}
	}
}

void removerContato(tLista *l){
	if(vazia(l)){//CONDI��O PARA REMOVA��O, SE NULL N�O PODER� REMOVER
	    printf("\nImposs�vel remover com lista vazia\n");
	}else{
		tipoNo * no = l-> inicio;
		tipoNo *aux_ant = (tipoNo*)malloc(sizeof(tipoNo));
		tipoNo *aux_prox = (tipoNo*)malloc(sizeof(tipoNo));
		int escolha, i;
     	printf("\nDigite a posi��o a remover:");
        scanf("%d", &escolha);
        if(escolha > 0 && escolha <= l->tamanho ){ //ESCOLHA DEVE SER MAIOR QUE 0 E MENOR IGUAL AO TAMANHO DA LISTA
        	if(escolha!= 1){ //SE FOR MAIOR QUE UM, ANDAR� NA LISTA EM SEGUIDA
        		for(i = 1; i < escolha; ++i) no = no -> prox;
                if(no -> ant != NULL & no -> prox != NULL){ //REMOVA��O NO MEIO
                	 printf("\nContato a ser removido: %s\n", no->dados.nome);
                	 aux_ant = no -> ant;
                	 aux_ant -> prox = no -> prox;
                	 aux_prox = no -> prox;
                	 aux_prox -> ant = no -> ant;
                	 free(no);
                	 printf("\nContato removido com sucesso\n");
                	l->tamanho--;
				}else{ //REMO��O NO FIM
					printf("\nContato a ser removido: %s\n", no->dados.nome);
					aux_ant = no -> ant;
					aux_ant -> prox = NULL;
					l->fim = aux_ant;
					free(no);
					printf("\nContato removido com sucesso\n");
					l->tamanho--;
				}
			}else{ //REMO��O NO INICIO 
				printf("\nContato a ser removido: %s\n", no->dados.nome);
				l->inicio = no->prox;
				l->inicio->ant = NULL;
				l->inicio->prox = l->inicio->prox;
				free(no);
				printf("\nContato removido com sucesso\n");
				l->tamanho--;
				}
		}else{
			printf("\nN�o existe contato a ser removido\n");
		}
	}
} 
	
void consultarPosicao(tLista *l){
    if(vazia(l)){ //SE VAZIA N�O � POSS�VEL CONSULTAR
	printf("\nImposs�vel consultar nome, pois a lista est� vazia\n");
 	}else{
	int escolha, i;
	int inexistente = 0;
	tipoNo * aux = l -> inicio;	
    printf("\nDigite a posic�o de contato a ser consultado:");
    scanf(" %d", &escolha);
    if(escolha > 0 && escolha <= l->tamanho){ //ESCOLHA DEVE SER MAIOR QUE ZERO E MENOR IGUAL AO TAMANHO DA LISTA
    if(escolha != 1){
	for(i = 1; i < escolha; ++i) aux = aux -> prox; //IMPRIME POSI��ES POSTERIORES
	printf("\n%s", aux->dados.nome);
    printf("\n%s", aux -> dados.cpf);
    printf("\n%s\n", aux -> dados.email);
        }else{//IMPRIME O PRIMEIRO CONTATO
        printf("\n%s", aux->dados.nome);
        printf("\n%s", aux -> dados.cpf);
        printf("\n%s\n", aux -> dados.email);	
		}
      }else{
      	printf("\nN�o existe contato a ser consultado\n");
	    }
    }
}

void listarContatos(tLista *l){
	tipoNo * auxinicio = l->inicio;
	tipoNo * auxfim = l -> fim;
	tipoNo * aux = l -> inicio;
	tipoNo * aux_no_anterior = l -> inicio;
	int contador = 1;
    if(vazia(l)) { //MENSAGEM DE VERIFICA��O SE ESTIVER VAZIA
        printf("\nLista VAZIA.\n");
    }
    while (aux!=NULL){ //"ANDA" NA LISTA PARA LISTAR OS CONTATOS
    	aux_no_anterior = aux_no_anterior -> ant; //APONTA PARA O ANTERIOR DO N� ATUAL
    	printf("\nAnterior do n� �: %s\n", aux_no_anterior -> dados.nome);
        printf("\n%d� Elemento e atual da lista: %s\n ",contador, aux->dados.nome);
        aux = aux->prox; // "ANDA" PARA O PR�XIMO DO N�
		aux_no_anterior = aux; // RECEBE N� ATUAL PARA APONTAR PARA O ANTERIOR NO PR�XIMO LOOPING
        contador++;
        printf("\nproximo do n� �: %s\n ",aux->dados.nome);
    }
    printf("\n");
    printf("\nElemento inicial: %s", auxinicio -> dados.nome);
    printf("\nElemento final: %s", auxfim -> dados.nome);
}

int tamanho(tLista *l){
	return (l->tamanho);
}
