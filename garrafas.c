#include <stdio.h>
#include "fila_estado.h"

void inserirSemDuplicar(Fila *estadosParaVisitar, int G4L, int G3L) {
    if (search(estadosParaVisitar, G4L, G3L) == 0) {
        insere(estadosParaVisitar, G4L, G3L);
    }

}

int encherG4L(Celula estado, Fila *estadosParaVisitar) {
    //só posso encher se não tiver cheia
    if (estado.G4L == 4) {
        return 0;
    }

    inserirSemDuplicar(estadosParaVisitar, 4, estado.G3L);
    return 1;
}

int encherG3L(Celula estado, Fila *estadosParaVisitar) {
    //só posso encher se não tiver cheia
    if (estado.G3L == 3) {
        return 0;
    }

    inserirSemDuplicar(estadosParaVisitar, estado.G4L, 3);
    return 1;
}

int esvaziarG4L(Celula estado, Fila *estadosParaVisitar) {

    //só posso esvaziar se a qtde existente for maior do que 0
    if (estado.G4L == 0) {
        return 0;
    }

    inserirSemDuplicar(estadosParaVisitar, 0, estado.G3L);
    return 1;
}

int esvaziarG3L(Celula estado, Fila *estadosParaVisitar) {

    //só posso esvaziar se a qtde existente for maior do que 0
    if (estado.G3L == 0) {
        return 0;
    }

    inserirSemDuplicar(estadosParaVisitar, estado.G4L, 0);
    return 1;
}

int transferirG3LParaG4L(Celula estado, Fila *estadosParaVisitar) {

    //só posso transferir da G3L para a garrafa de G4L se G3L não estiver vazia ou a G4L não estiver totamente cheia
    if (estado.G3L == 0 || estado.G4L == 4) {
        return 0;
    }

    int g4lnova = estado.G4L + estado.G3L;

    if (g4lnova > 4) {
        int g3lnova = g4lnova - 4;
        inserirSemDuplicar(estadosParaVisitar, 4, g3lnova);
    }

    if (g4lnova <= 4) {
        inserirSemDuplicar(estadosParaVisitar, g4lnova, 0);
    }

    return 1;
}

int transferirG4LParaG3L(Celula estado, Fila *estadosParaVisitar) {

    //só posso transferir da G4L para a garrafa de G3L se G4L não estiver vazia ou a G3L não estiver totamente cheia
    if (estado.G4L == 0 || estado.G3L == 3) {
        return 0;
    }

    int g3lnova = estado.G4L + estado.G3L;

    if (g3lnova > 3) {
        int g4lnova = g3lnova - 3;
        inserirSemDuplicar(estadosParaVisitar, g4lnova, 3);
    }

    if (g3lnova <= 3) {
        inserirSemDuplicar(estadosParaVisitar, g3lnova, 0);
    }
    return 1;
}

Celula proxEstado(Fila *f) {
    Celula estado;

    estado.G3L = f->ini->G3L;
    estado.G4L = f->ini->G4L;
    retira(f);

    return estado;
}


void main() {
    // Estado *estado;
    // estado = inicializaEstadoLista();
    // estado = insereEstadoLista(estado, 4,3);
    // encherG4L(estado);

    Fila *estadosParaVisitar = inicializarFilaEstados();
    insere(estadosParaVisitar, 0, 0);

    printf("Numero de elementos antes: %d \n", count(estadosParaVisitar));

    Celula *estadoAtual = NULL;
    Celula estado;


    int i = 0;
    for (estadoAtual = estadosParaVisitar->ini; (estadoAtual != NULL && i < 20); estadoAtual = estadoAtual->prox) {
        i++;

        estado = proxEstado(estadosParaVisitar);
        /*
         * TODO:
         *      Criar uma lista para armazenar estados visitados
         *      Refatorar as outras funções para ficar igual a encherG3L
         */

        encherG3L(estado, estadosParaVisitar);
        encherG4L(estado, estadosParaVisitar);
        esvaziarG3L(estado, estadosParaVisitar);
        esvaziarG4L(estado, estadosParaVisitar);
        transferirG3LParaG4L(estado, estadosParaVisitar);
        transferirG4LParaG3L(estado, estadosParaVisitar);

    }
    printf("Numero de elementos antes: %d\n", count(estadosParaVisitar));
}