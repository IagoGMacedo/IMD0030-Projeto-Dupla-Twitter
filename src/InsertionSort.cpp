<<<<<<< HEAD
#include "../include/helper.h"
=======
#include "../include/Helper.h"
>>>>>>> 93353da73c7a50d2e9c35f177ee4d9c967bdb0b8

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