#include <stdio.h>
#include <stdlib.h>

struct celula {
    int G4L;
    int G3L;
    char operacao[30];
    int elementoFinal;
    struct celula *prox;
};
typedef struct celula Celula;

struct fila {
    Celula *ini;
    Celula *fim;
};
typedef struct fila Fila;

Fila *inicializarFilaEstados(void) {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}


Celula *enfileirarEstado(Celula *fim, int G4L, int G3L) {
    Celula *p = (Celula *) malloc(sizeof(Celula));
    p->G4L = G4L;
    p->G3L = G3L;
    p->prox = NULL;

    //da primeira vez última celula aponta para o NULL, então apenas retorna a célula que acabou de ser criada
    if (fim != NULL) {
        fim->prox = p;
    }

    return p;
}

Celula *desenfileira(Celula *ini) {
    Celula *p = ini->prox;
    free(ini);
    return p;
}


int count(Fila *f) {
    Celula *q;
    int count = 0;
    for (q = f->ini; q != NULL; q = q->prox) {
        count++;
    }

    return count;
}
/**
 * Pesquisa na fila se um dado estado já existe
 * @param f
 * @param G4L
 * @param G3L
 * @return
 */
int pesquisarEstadoFila(Fila *f, int G4L, int G3L) {
    Celula *q;
    for (q = f->ini; q != NULL; q = q->prox) {
        if (q->G4L == G4L && q->G3L == G3L)
            return 1;
    }

    return 0;
}

void insere(Fila *f, int G4L, int G3L) {
    //chamo o enfileirarEstado passando a última célula e o fim deixa de ser null apontando para a celula que acabou de ser inserida
    f->fim = enfileirarEstado(f->fim, G4L, G3L);

    //só é entra aqui da primeira vez, significa que não há elementos na fila
    if (f->ini == NULL) {
        //então, o primeiro elemento é o elento que acabou de ser incluido no fim
        f->ini = f->fim;
    }

}

int vazia(Fila *f) {
    return (f->ini == NULL);
}

int retira(Fila *f) {
    int v;
    if (vazia(f)) {
        printf("Fila vazia.\n");
        return 0;
    }

    f->ini = desenfileira(f->ini);
    if (f->ini == NULL){
        f->fim = NULL;
    }

    return 1;
}


