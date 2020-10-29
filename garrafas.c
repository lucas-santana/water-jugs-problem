#include <stdio.h>
#include "fila_estado.h"

int encherG4L(Celula *estado) {

    //só posso encher se não tiver cheia
    if (estado->G4L == 4) {
        return 0;
    }
    return 1;
}

int encherG3L(Celula *estado) {

    //só posso encher se não tiver cheia
    if (estado->G3L == 3) {
        return 0;
    }
    return 1;
}

int esvaziarG4L(Celula *estado) {

    //só posso esvaziar se a qtde existente for maior do que 0
    if (estado->G4L == 0) {
        return 0;
    }
    return 1;
}

int esvaziarG3L(Celula *estado) {

    //só posso esvaziar se a qtde existente for maior do que 0
    if (estado->G3L == 0) {
        return 0;
    }
    return 1;
}

int transferirG3LParaG4L(Celula *estado) {

    //só posso transferir da G3L para a garrafa de G4L se G3L não estiver vazia ou a G4L não estiver totamente cheia
    if (estado->G3L == 0 || estado->G4L == 4) {
        return 0;
    }

    return 1;
}

int transferirG4LParaG3L(Celula *estado) {

    //só posso transferir da G4L para a garrafa de G3L se G4L não estiver vazia ou a G3L não estiver totamente cheia
    if (estado->G4L == 0 || estado->G3L == 3) {
        return 0;
    }

    return 1;
}


void main() {
    // Estado *estado;
    // estado = inicializaEstadoLista();
    // estado = insereEstadoLista(estado, 4,3);
    // encherG4L(estado);

    Fila *estadosParaVisitar = inicializarFilaEstados();
    insere(estadosParaVisitar, 0, 0);

    printf("Numero de elementos antes: %d \n", count(estadosParaVisitar));

    Celula *estadoAtual;
    int i =0;
    for (estadoAtual = estadosParaVisitar->ini; (estadoAtual != NULL && i<10); estadoAtual = estadoAtual->prox) {

        i++;
        retira(estadosParaVisitar);
        if(encherG3L(estadoAtual)){
            insere(estadosParaVisitar, estadoAtual->G4L, 3);
        }

        if(encherG4L(estadoAtual)){
            insere(estadosParaVisitar, 4, estadoAtual->G3L);
        }

        if(esvaziarG3L(estadoAtual)){
           insere(estadosParaVisitar, estadoAtual->G4L, 0);
       }

        if(esvaziarG4L(estadoAtual)){
             insere(estadosParaVisitar, 0, estadoAtual->G3L);
         }

         /*if(transferirG3LParaG4L(estadoAtual)){

             int g4lnova = estadoAtual->G4L+estadoAtual->G3L;

             if(g4lnova>4){
                 int g3lnova = g4lnova - 4;
                 insere(estadosParaVisitar, 4, g3lnova);
             }

             if(g4lnova <= 4){

                 insere(estadosParaVisitar, g4lnova, 0);
             }

         }

         if(transferirG4LParaG3L(estadoAtual)){

             int g3lnova = estadoAtual->G4L+estadoAtual->G3L;

             if(g3lnova>3){
                 int g4lnova = g3lnova - 3;
                 insere(estadosParaVisitar, g4lnova, 3);
             }

             if(g3lnova <= 3){
                 insere(estadosParaVisitar, g3lnova, 0);
             }
         }*/



    }
    printf("Numero de elementos antes: %d\n", count(estadosParaVisitar));
}