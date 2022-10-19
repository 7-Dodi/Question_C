//Construa um programa utilizando uma pilha que resolva o seguinte problema:
//Armazene as placas dos carros (apenas os números) que estão estacionados numa rua sem saída estreita.
//Dado uma placa verifique se o carro está estacionado na rua.
//Caso esteja, informe a sequência de carros que deverá ser retirada para que o carro em questão consiga sair.
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h" //Biblioteca Criada
void main(){
	Pilha *pilha= criarPilha();
	int placa;
	printf("\n################ ENTRADA ################\n");			///////
	printf("Informe as placas dos carros que estao estacionados\n\n");      //
	printf("\nInforme os numeros da placa do carro:");                     //// Entrada dos dados 
	scanf("%d", & placa);                                             ////// 
	while(placa!=0){
		if(verificar(pilha, placa)==0){ //Analisando o numero da placas, para evitar que tenha duas placas iguais
			inserir(pilha, placa); //Inserindo o valor da placa na estrutura
		}
		else{
			printf("\nERRO!!!Ja existe outro carros com essa placa. TENTE NOVAMENTE");
		}
		printf("\nInforme os numeros da placa do carro:");
		scanf("%d", & placa);
	}
	int valor;
	printf("\n\n############# VERIFICANDO POSICAO DO CARRO ############\n"); 
	printf("\nDigite a Placa do carro:"); //Verificando a localidade do carro, segundo a sua placa
	scanf("%d", & valor);
	printf("\nProcurando por placa... Clique em qualquer tecla para continuar");
	getch(); //Para deixar o programa mais tranquilo a pecepção do usuario, deixar mais devagar
	printf("\n\n\n############# RESULTADO DE BUSCA #################"); 
	if(verificarCarro(pilha, valor)==1){
		printf("\n\nCarro de placa %d, encontrado.", valor);
		printf("\n\nCalculando rota... Clique em qualquer tecla para continuar...");
		getch();
		printf("\n\n\n################ RESULTADO DE ROTA #################\n");                     //////////////////
		int cont= posicao(pilha);																				  ///	
		if(cont==valor){																					     ///		
			printf("\n\nO carro esta estacionado no ultimo lugar, o carro esta pronto para sair.");             ///
		}                                                                                                      ///
		else{                                                                                                 ///
			int num;                                                                                         ///
			printf("\n\nDeve-se retirar primeiro o(s) carro(os) de placa:\n");                              ///
			while(num!=valor){                                                                             ////// Calculando rotas, vendo quais carros devem sair primeiro para o carro em
				num= imprimir(pilha);                                                                     ////// questão sair.
				if(num!=valor){                                                                          ///
					printf("\n%d;", num);                                                               ///
				}                                                                                      ///
			}                                                                                         ///
		}                                                                                            ///
	}                                                                                 /////////////////
	else{
		printf("\n\nNao foi encontardo um carro com essa placa"); //Caso o carro nao seja encontrado
	}
	printf("\n\nFinalizando programa... Clique em qualquer tecla para fechar"); //Fianlizando o programa;
	getch();
}
