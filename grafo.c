#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#define true 1
#define false 0
#define INT_MAX 32000


GRAFO *criarGrafo(int v)
{
    // aloca memoria para uma strutura do tipo grafo
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));

    // inicializa o quantidade de vertives
    g->vertices = v;
    // inicializa a quantidade arestas
    g->arestas = 0;
    // aloca memoria para uma vetor da quantidade de vertices
    g->adj = (VERTICE *)malloc(v * sizeof(VERTICE));
    int i;

    // inicializar as posições do vertives com NULL
    for (i = 0; i < v; i++)
        g->adj[i].cab = NULL;

    return g;
}

ADJACENCIA *criaAdj(int v)
{
    // Aloca memoria para um vertices adjacente
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    // define qual é o vertice
    temp->vertice = v;
    // define o proximo da lista como NULL
    temp->prox = NULL;
    return (temp);
}

int criaAresta(GRAFO *gr, int vi, int vf)
{
    if (!gr)
        return (false);
    if ((vf < 0) || (vf >= gr->vertices))
        return (false);
    if ((vi < 0) || (vf >= gr->vertices))
        return (false);

    // cria o nome vertice adjacente
    ADJACENCIA *novo = criaAdj(vf);

    // o proximo do novo vertice recebe o antigo primeiro elemento da lista de adjacencia
    novo->prox = gr->adj[vi].cab;

    // o primeiro elemento lista de adjacente se tornao novo
    gr->adj[vi].cab = novo;

    ADJACENCIA *novo2 = criaAdj(vi);
    novo2->prox = gr->adj[vf].cab;
    gr->adj[vf].cab = novo2;

    gr->arestas++;
    return (true);
}

void imprime(GRAFO *gr)
{
    printf("Vertices: %d. Arestas: %d, \n", gr->vertices, gr->arestas);

    int i;
    for (i = 0; i < gr->vertices; i++)
    {
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad)
        {
            printf("v%d(%d) ", ad->vertice);
            ad = ad->prox;
        }

        printf("\n");
    }
}





