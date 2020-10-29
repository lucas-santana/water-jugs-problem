#include <stdio.h>
struct celula
{
    int info;
    struct celula *prox;
};
typedef struct celula Celula;

struct fila
{
    Celula *ini;
    Celula *fim;
};
typedef struct fila Fila;

Fila *inicializarFila(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}


Celula *enfileirar(Celula *fim, int v)
{
    Celula *p = (Celula *)malloc(sizeof(Celula));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL) 
        fim->prox = p;
    return p;
}

Celula *desenfileira(Celula *ini)
{
    Celula *p = ini->prox;
    free(ini);
    return p;
}


int count(Fila *f)
{
    Celula *q;
    int count = 0;
    for (q = f->ini; q != NULL; q = q->prox){
        count++;
    }
    
    return count;
}

int search(Fila *f,int valor )
{
    Celula *q;
    int count = 0;
    for (q = f->ini; q != NULL; q = q->prox){
        if(q->info == valor )
            return 1;
    }
    
    return 0;
}

void insere(Fila *f, int v)
{
    f->fim = enfileirar(f->fim, v);
    if (f->ini == NULL)
        f->ini = f->fim;
}
int retira(Fila *f)
{
    int v;
    if (vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
        
    }
    v = f->ini->info;
    f->ini = desenfileira(f->ini);
    if (f->ini == NULL)
       
        f->fim = NULL;
    return v;
}
int vazia(Fila *f)
{
    return (f->ini == NULL);
}


int main()
{
    Fila *f = inicializarFila();
    printf("Numero de elementos antes: %d\n",  count(f));
    insere(f, 123);
    insere(f, 22);
    insere(f, 23);
    insere(f, 24);
    retira(f);
    printf("Numero de elementos depois: %d\n",  count(f));
    int found = search(f,22);
    if(found == 1){
        printf("22 encontrado\n" );
    }else{
         printf("22 não encontrado\n" );
    }
   
    return 0;
}