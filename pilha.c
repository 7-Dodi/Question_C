#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo{ //Criar a estrutura de armazenamento
	int numero;
	struct nodo *proximo;
}Nodo;
typedef struct{  //Criando o ponteiro
	Nodo *topo;
}Pilha;
Pilha *criarPilha(){  //Criando a estrututa de Pilha
	Pilha *pilha= (Pilha*)malloc(sizeof(Pilha));
	pilha->topo=NULL;
	return pilha;
}
void inserir (Pilha *pilha, int num){  //Aramzenando valores dentro da estrura
	Nodo *novo= (Nodo*)malloc(sizeof(Nodo));
	novo->numero=num;
	novo->proximo= pilha->topo;
	pilha->topo= novo;
}
int verificar (Pilha *pilha, int num){ //Verificando se não há valores iguais dentro da estrutura
	Nodo *aux= pilha->topo;
	int cont=0;
	while(aux!=NULL){
		if(aux->numero==num){
			cont++;
		}
		aux=aux->proximo;
	}
	return cont;
}
int quantCarros (Pilha *pilha){ //Verificando a quantidade carros
	Nodo *aux= pilha->topo;
	int cont=0;
	while(aux!=NULL){
		cont++;
		aux=aux->proximo;
	}
	return cont;
}
int verificarCarro (Pilha *pilha, int num){  //Procurando a posição do carro em questão, além de verificar se o carro esta dentro da estrutura
	Nodo *aux= pilha->topo;
	int cont=0;
	while(aux!=NULL){
		if(aux->numero==num){
			cont++;
		}
		aux=aux->proximo;
	}
	if(cont>0){
		return 1;
	}
	else{
		return 0;
	}
}
int posicao (Pilha *pilha){ //Verificando se o carro esta na ultima posição da pilha
	Nodo *aux= pilha->topo;
	int cont= aux->numero;
	return cont;
}
int imprimir (Pilha *pilha){ //Imprimindo o carros que devem sair primeiro, usado no calculo de rota
	Nodo *aux= pilha->topo;
	int valor= aux->numero;
	pilha->topo= aux->proximo;
	return valor;
}

