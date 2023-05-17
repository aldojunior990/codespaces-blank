#define true 1
#define false 0
#define INT_MAX 32000

typedef struct adjacencia
{
    // registra o número do vertice
    int vertice;
    // registra o peso do vertices
    // proximo elemento da lista
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice
{
    /* Dados armazenados vao aqui */
    ADJACENCIA *cab;
} VERTICE;


typedef struct grafo
{
    // Guarda o número de vertives
    int vertices;
    // guarda o numero de arestas
    int arestas;
    // listas com os vértices adjacentes
    VERTICE *adj;
} GRAFO;

GRAFO *criarGrafo(int v);
ADJACENCIA *criaAdj(int v);
int criaAresta(GRAFO *gr, int vi, int vf);
void imprime(GRAFO *gr);