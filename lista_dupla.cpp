#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct Tipo_Lista{
	int cod;
	struct Tipo_Lista *Prox;
	struct Tipo_Lista *Ant;
};

struct Tipo_Lista *Primeiro;
struct Tipo_Lista *Ultimo;

void FLVazia(){
	struct Tipo_Lista *aux;
	aux = (struct Tipo_Lista*)malloc(sizeof(struct Tipo_Lista));
	Primeiro = aux;
	Ultimo = Primeiro;
	Primeiro->Ant = NULL;
}

void Insere(int x){
	struct Tipo_Lista *aux;
	aux = (struct Tipo_Lista*)malloc(sizeof(struct Tipo_Lista));
	aux->cod = x;
	Ultimo->Prox = aux;
	aux->Ant = Ultimo;
	Ultimo = Ultimo->Prox;
	aux->Prox = NULL;
}

void Imprime(){
	struct Tipo_Lista *aux;
	aux = Primeiro->Prox;
	while(aux != NULL){
		printf("Item = %d\n", aux->cod);
		aux = aux->Prox;
	}
}

void Imprime_Atras(){
	struct Tipo_Lista *aux;
	aux = Ultimo;
	while(aux->Ant != NULL){
		printf("Item = %d\n", aux->cod);
		aux = aux->Ant;
	}
}

void Pesquisa(int x) {
	struct Tipo_Lista *aux;
	int flag = 0;
	aux = Primeiro->Prox;
	while(aux != NULL){
		if(aux->cod == x){
			printf("ACHOU ITEM %d ", x);
			flag = 1;
			aux = NULL;
		}
		else
		aux = aux->Prox;
	}
	if (flag == 0)
	printf("Item %d Nao se encontra nesta Lista!!!", x);
}

void Remove(int x){
	struct Tipo_Lista *aux;
	int flag = 0;
	aux = Primeiro->Prox;
	while(aux != NULL){
		if(aux->cod == x){
			if (aux->Prox == NULL){
				Ultimo = aux->Ant;
				aux->Ant->Prox = NULL;
				aux = NULL;
				flag = 1;
			}
			else {
			printf("REMOVEU ITEM %d ", x);
			aux->Ant->Prox = aux->Prox;
			aux->Prox->Ant = aux->Ant;
			aux = NULL;
			flag = 1;
			}
		}
		else
		aux = aux->Prox;
		
	}
	free(aux);
	if (flag == 0)
	printf("Item %d Nao se encontra nesta Lista!!!", x);
}


main()
{
	char op = '2';
	int i, codigo;
	FLVazia();
	while(op != '0'){
		printf("Entre com o codigo: ");
		scanf("%d", &codigo);
		Insere(codigo);
		printf("\n\n\nContinuar com o Cadastro? 1 = sim 0 = nao: \n\n");
		op = getch();
	}
	Imprime();
	printf("\n\n Entre com um item para pesquisa: ");
	scanf("%d", &codigo);
	Pesquisa(codigo);
	printf("Item A ser removido: ");
	scanf("%d", &codigo);
	Remove(codigo);
	Imprime();
	getch();
	Imprime_Atras();
	getch();
}





















