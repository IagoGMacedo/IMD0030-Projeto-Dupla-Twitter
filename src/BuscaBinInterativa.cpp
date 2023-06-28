<<<<<<< HEAD
#include "../include/helper.h"
=======
#include "../include/Helper.h"
>>>>>>> 93353da73c7a50d2e9c35f177ee4d9c967bdb0b8

template<typename T>
int buscaBinIte(T chave, T vet[], int esquerda, int direita) {
    while (esquerda <= direita) {
        int meio = esquerda + (direita-esquerda)/2;

        if (vet[meio] == chave) {
            return meio;
        }
        else if (vet[meio] < chave) {
            esquerda = meio + 1;
        }
        else {
            direita = meio - 1;
        }
    }

    return -1;
}

template<typename T>
int buscaBinIte(T chave, T vet[], int tamanho) {
    buscaBinIte(chave, vet, 0, tamanho-1);
}