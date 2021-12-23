//estrutura tipo contato
typedef struct{
	char nome[100];
	char cpf[10];
	char email[100];
} contato;

//define a estrutura do nodo
typedef struct{
	contato c;
	struct tipoNo* prox;
	struct tipoNo* ant;
}tipoNo;

//cria a lista
typedef struct{
    tipoNo *inicio;
    tipoNo *fim;
    int tamanho;
} tLista;

void menu();
void inicializar(tLista *l);
int vazia(tLista *l);
int inserirContato(tLista *l, contato c);
int removerContato(tLista *l, contato *c);
void consultarPosicao(tLista *l, contato c);
void listarContatos(tLista *l);
int tamanho(tLista *l);
