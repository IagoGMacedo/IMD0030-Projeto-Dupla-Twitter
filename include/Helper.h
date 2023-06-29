#ifndef HELPER_H
#define HELPER_H

//Quick Sort
template<typename T>
void quickSort(T vet[], int tamanho);

//Insertion Sort
template<typename T>
void insertionSort(T vet[], int tamanho);


//Busca Binaria Recursiva
template<typename T>
int buscaBinRec(T chave, T vet[], int tamanho);

//Busca Binaria Iterativa
template<typename T>
int buscaBinIte(T chave, T vet[], int tamanho);


//TADs
//Conjunto

//ListaEncad

#endif