//Chamando a funções e as especificando para a criação da biblioteca
typedef struct nodo Nodo;

typedef struct pilha Pilha;

Pilha *criarPilha();

void inserir (Pilha *pilha, int num);

int verificar (Pilha *pilha, int num);

int quantCarros (Pilha *pilha);

int verificarCarro (Pilha *pilha, int num);

int posicao (Pilha *pilha);

int imprimir (Pilha *pilha);

