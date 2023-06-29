#include "../include/Helper.h"

template<typename T>
int buscaBinRec(T chave, T vet[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;

    if (chave < vet[meio]) {
        return buscaBinRec(chave, vet, inicio, meio - 1);
    }

    else if (chave > vet[meio]) {
        return buscaBinRec(chave, vet, meio + 1, fim);
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