#include <stdio.h>
#include "fila_estado.c"
#include "lista_estado.c"

/**
 * Insere na fila os estados a serem visitados, verificando se esse estado já não foi inserido na fila
 * @param estadosParaVisitar
 * @param G4L
 * @param G3L
 */
void inserirFilaSemDuplicar(Fila *estadosParaVisitar, Estado *listaEstadosVisitados, int G4L, int G3L) {
    if (pesquisarEstadoFila(estadosParaVisitar, G4L, G3L) == 0 && pesquisarEstado(listaEstadosVisitados, G4L, G3L) == NULL) {
        insere(estadosParaVisitar, G4L, G3L);
    }
}

/**
 * Verifica se é possível encher a garrafa de 4L e se verdadeiro insere o estado [4, estado.G3l]
 * na fila de estados a sem visitados
 * @param estado
 * @param estadosParaVisitar
 * @return
 */
int encherG4L(Celula estado, Fila *estadosParaVisitar, Estado *listaEstadosVisitados) {
    //só posso encher se não tiver cheia
    if (estado.G4L == 4) {
        return 0;
    }

    inserirFilaSemDuplicar(estadosParaVisitar, listaEstadosVisitados, 4, estado.G3L );
    return 1;
}

/**
 * Verifica se é possível encher a garrafa de 3L e se verdadeiro insere o estado [estado.G4l, 3]
 * na fila de estados a sem visitados
 * @param estado
 * @param estadosParaVisitar
 * @return
 */
int encherG3L(Celula estado, Fila *estadosParaVisitar, Estado *listaEstadosVisitados) {
    //só posso encher se não tiver cheia
    if (estado.G3L == 3) {
        return 0;
    }

    inserirFilaSemDuplicar(estadosParaVisitar, listaEstadosVisitados, estado.G4L, 3);
    return 1;
}

/**
 * Verifica se é possível esvaziar a garrafa de 4L e se verdadeiro insere o estado [0, estado.G3L]
 * na fila de estados a sem visitados
 * @param estado
 * @param estadosParaVisitar
 * @return
 */
int esvaziarG4L(Celula estado, Fila *estadosParaVisitar, Estado *listaEstadosVisitados) {

    //só posso esvaziar se a qtde existente for maior do que 0
    if (estado.G4L == 0) {
        return 0;
    }

    inserirFilaSemDuplicar(estadosParaVisitar,listaEstadosVisitados, 0, estado.G3L);
    return 1;
}

/**
 * Verifica se é possível esvaziar a garrafa de 3L e se verdadeiro insere o estado [estado.G4L, 0]
 * na fila de estados a sem visitados
 * @param estado
 * @param estadosParaVisitar
 * @return
 */
int esvaziarG3L(Celula estado, Fila *estadosParaVisitar, Estado *listaEstadosVisitados) {

    //só posso esvaziar se a qtde existente for maior do que 0
    if (estado.G3L == 0) {
        return 0;
    }

    inserirFilaSemDuplicar(estadosParaVisitar, listaEstadosVisitados, estado.G4L, 0);
    return 1;
}

/**
 * Verifica se é possível transferir o conteúdo da G3L para a G4L e se possível, insere esse estado na fila de
 * estados a serem visitados
 * @param estado
 * @param estadosParaVisitar
 * @return
 */
int transferirG3LParaG4L(Celula estado, Fila *estadosParaVisitar, Estado *listaEstadosVisitados) {

    //só posso transferir da G3L para a garrafa de G4L se G3L não estiver vazia ou a G4L não estiver totamente cheia
    if (estado.G3L == 0 || estado.G4L == 4) {
        return 0;
    }

    int g4lnova = estado.G4L + estado.G3L;

    if (g4lnova > 4) {
        int g3lnova = g4lnova - 4;
        inserirFilaSemDuplicar(estadosParaVisitar, listaEstadosVisitados, 4, g3lnova);
    }

    if (g4lnova <= 4) {
        inserirFilaSemDuplicar(estadosParaVisitar, listaEstadosVisitados, g4lnova, 0);
    }

    return 1;
}

/**
 * Verifica se é possível transferir o conteúdo da G4L para a G3L e se possível, insere esse estado na fila de
 * estados a serem visitados
 * @param estado
 * @param estadosParaVisitar
 * @return
 */
int transferirG4LParaG3L(Celula estado, Fila *estadosParaVisitar, Estado *listaEstadosVisitados) {

    //só posso transferir da G4L para a garrafa de G3L se G4L não estiver vazia ou a G3L não estiver totamente cheia
    if (estado.G4L == 0 || estado.G3L == 3) {
        return 0;
    }

    int g3lnova = estado.G4L + estado.G3L;

    if (g3lnova > 3) {
        int g4lnova = g3lnova - 3;
        inserirFilaSemDuplicar(estadosParaVisitar, listaEstadosVisitados, g4lnova, 3);
    }

    if (g3lnova <= 3) {
        inserirFilaSemDuplicar(estadosParaVisitar, listaEstadosVisitados, 0, g3lnova);
    }
    return 1;
}

/**
 * Recebe uma fila, remove um estado dessa fila e retorna o estado removido
 * @param f
 * @return
 */
Celula proxEstado(Fila *f) {
    Celula estado;

    if(f->ini == NULL){
        estado.elementoFinal = 0;
        return estado;
    }

    estado.elementoFinal = 1;
    estado.G3L = f->ini->G3L;
    estado.G4L = f->ini->G4L;
    estado.prox = f->ini;
    retira(f);

    return estado;
}

void main() {
    Estado *estadosVisitados = NULL;
    Fila *estadosParaVisitar = inicializarFilaEstados();
    insere(estadosParaVisitar, 0, 0);

    Celula estado = proxEstado(estadosParaVisitar);

    while(estado.elementoFinal != 0){
        if(pesquisarEstado(estadosVisitados, estado.G4L, estado.G3L) == NULL){
            encherG3L(estado, estadosParaVisitar, estadosVisitados);
            encherG4L(estado, estadosParaVisitar, estadosVisitados);
            esvaziarG3L(estado, estadosParaVisitar, estadosVisitados);
            esvaziarG4L(estado, estadosParaVisitar, estadosVisitados);
            transferirG3LParaG4L(estado, estadosParaVisitar, estadosVisitados);
            transferirG4LParaG3L(estado, estadosParaVisitar, estadosVisitados);

            estadosVisitados = insereEstadoLista(estadosVisitados, estado.G4L, estado.G3L);
        }
        estado = proxEstado(estadosParaVisitar);
    }
}