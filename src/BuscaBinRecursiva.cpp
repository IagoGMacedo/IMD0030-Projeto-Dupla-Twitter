#include "../include/Helper.h"

template<typename T>
int buscaBinRec(T chave, T vet[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;

    if (chave < entrada[meio]) {
        return buscaBinRec(chave, entrada, inicio, meio - 1);
    }

    else if (chave > entrada[meio]) {
        return buscaBinRec(chave, entrada, meio + 1, fim);
    }

    else {
        return meio;
    }

    return -1;
}

template<typename T>
T buscaBinRec(T chave, T vet[], int tamanho) {
    buscaBinRec(chave, vet, 0, tamanho-1);
}