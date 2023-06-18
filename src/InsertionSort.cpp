#include "../Include/helper.h"

template<typename T>
void insertionSort(T vet[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        T pos = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > pos) {
            vet[j + 1] = vet[j];
            j--;
        }

        vet[j + 1] = pos;
    }
}