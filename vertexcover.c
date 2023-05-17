#include "grafo.h"
#include "grafo.c"

int C(GRAFO I, int *S){
    int *visited;
    GRAFO aux = I;

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