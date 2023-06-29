#include "../include/Helper.h"

template<typename T>
void trocar(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
int particionar(T vet[], int esquerda, int direita) {
    int tamanho = direita - esquerda + 1;
    int mediana, indice_mediana;

    if (tamanho % 2 == 0) {
        int i1 = esquerda + tamanho/2 - 1;
        int i2 = esquerda + tamanho/2;
        
        if (vet[i1] < vet[i2]) {
            indice_mediana = i1;
        } else {
        indice_mediana = i2;
        }
    } else {
        indice_mediana = esquerda + tamanho/2;
    }

    mediana = vet[indice_mediana];

    trocar(&vet[indice_mediana], &vet[direita]);

    T pivot = vet[direita];
    int i = esquerda - 1;
    int j = direita;

    while (true) {
        do {
            i++;
        } while (vet[i] < pivot);

        do {
            j--;
        } while (j > esquerda && vet[j] > pivot);

        if (i >= j) {
            break;
        }

        trocar(&vet[i], &vet[j]);
    }

    trocar(&vet[i], &vet[direita]);

    return i;
}

template<typename T>
void quickSort(T vet[], int esquerda, int direita) {
    if (esquerda < direita) {
        int particao = particionar(vet, esquerda, direita);

        quickSort(vet, esquerda, particao - 1);
        quickSort(vet, particao + 1, direita);
    }
}

template<typename T>
void quickSort(T vet[], int tamanho) {
    quickSort(vet, 0, tamanho - 1);
}
