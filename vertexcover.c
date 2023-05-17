#include "grafo.h"
#include "grafo.c"



typedef struct arestas{
    ADJACENCIA *inicio;
    ADJACENCIA *fim;
} ARESTAS;


int C(GRAFO I, int *S){

    int *vertex;
    ARESTAS *arestas;
    GRAFO *aux = &I;


    // PREENCHENDO O VETOR COM TODAS AS ARESTAS DO GRAFO
    for(int i =0; i < aux->arestas; i++){
        ADJACENCIA *ad = aux->adj[i].cab;
        while (ad)
        {
            arestas[i].inicio = ad;
            arestas[i].fim = ad->prox;
            ad = ad->prox;
        }
    }

    int j = 0;
    while (j != aux->arestas)
    {
        vertex[j] = arestas[j].inicio;
        vertex[j + 1] = arestas[j].fim;
        if(arestas[j].inicio->prox == arestas[j].fim){
            free(arestas[j].fim);
        }        
    }


    for(int i = 0; i < 5; i++){
        printf("%d", vertex[i]);
    }

}


int main()
{

    GRAFO *gr = criarGrafo(6);
    criaAresta(gr, 0, 1);
    criaAresta(gr, 1, 3);
    criaAresta(gr, 3, 4);
    
    int *s;

    c(gr, s);

}