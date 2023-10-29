/// faça as seguintes funçoes: 
///1. De vetor para lista.  Escreva uma função que copie o conteúdo de um vetor para uma lista encadeada preservando a ordem dos elementos.
///2. De lista para vetor.  Escreva uma função que copie o conteúdo de uma lista encadeada para um vetor preservando a ordem dos elementos.

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista *inicializa(void){
    return NULL;
}

Lista *insere(Lista *l, int i){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void imprime(Lista *l){
    Lista *p;
    for(p = l; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}

/// Função que passa um vetor para uma lista encadeada
Lista *vetor_para_lista(int *vet, int tam){
    Lista *l = inicializa();
    int i;
    for(i = 0; i < tam; i++){
        l = insere(l, vet[i]);
    }
    return l;
}

/// Função que passa uma lista encadeada para um vetor
int *lista_para_vetor(Lista *l, int tam){
    int *vet = (int*)malloc(tam*sizeof(int));
    Lista *p;
    int i;
    for(p = l, i = 0; p != NULL; p = p->prox, i++){
        vet[i] = p->info;
    }
    return vet;
}

int main(void){
    Lista *l = inicializa();
    int vet[5] = {1, 2, 3, 4, 5};
    l = vetor_para_lista(vet, 5);
    imprime(l);
    int *vet2 = lista_para_vetor(l, 5);
    int i;
    for(i = 0; i < 5; i++){
        printf("%d\n", vet2[i]);
    }
    return 0;
}