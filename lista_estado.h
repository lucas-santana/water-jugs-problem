#include <stdio.h>

struct estado
{
    int G4L;
    int G3L;
    char operacao[30];
    struct estado *pai;
};
typedef struct estado Estado;

Estado *inicializaEstadoLista(void)
{
    Estado *novoEstado = (Estado *) malloc(sizeof(Estado));
    novoEstado->G4L = 0;
    novoEstado->G3L = 0;
    novoEstado->pai = NULL;
    return novoEstado;
}

Estado *insereEstadoLista(Estado *estadoAtual, int G4L, int G3L)
{
    Estado *novoEstado = (Estado *) malloc(sizeof(Estado));
    novoEstado->G4L = G4L;
    novoEstado->G3L = G3L;
    novoEstado->pai = estadoAtual;
    return novoEstado;
}

/* função busca: busca um elemento na lista */
Estado *pesquisarEstado(Estado *estado, int G4L, int G3L)
{
    Estado *p;
    for (p = estado; p->pai != NULL; p = p->pai)
        if (p->G3L == G3L && p->G4L == G4L)
            return p;
    return NULL;
    /* não achou o elemento */
}

/*void encherG4L(Estado *estado)
{
    //pesquisar para saber se esse estado já existe na lista
    Estado *estadoPesquisado = pesquisarEstado(estado, 4, 3);

    if(estadoPesquisado == NULL){
        printf("Estado G4L = 4 e G3L = 3 não encontrado\n");
    }else{
        printf("Estado G4L = 4 e G3L = 3 encontrado\n");
    }
}*/

/*int encherG3L(Estado *estado)
{
    int qtde = 3 - estado->G3L;
    if(qtde <= 3){
        return qtde;
    }
}*/

void montarEstados(Estado *estado){
    while(estado->pai != NULL){

    }
}
