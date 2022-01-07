//estrutura tipo contato
typedef struct{
	char nome[100];
	char cpf[20];
	char email[100];
} contato;

//define a estrutura do nodo
typedef struct{
	contato dados;
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
void inserirContato(tLista *l, contato c);
void removerContato(tLista *l);
void consultarPosicao(tLista *l);
void listarContatos(tLista *l);
int tamanho(tLista *l);
