#ifndef LISTAENCAD_H
#define LISTAENCAD_H

#include <No.h>

template <typename T>
class ListaEncad{
    private:
    No<T>* cabeca;
    No<T>* cauda;
    int quantidade;
    
public:
    ListaEncad(void);
    ~ListaEncad(void);

    No<T>* getCabeca(void);
    No<T>* getCauda(void);
    
    T recuperar(int);
    int buscar(T);
    
    bool inserirNaCabeca(T);
    bool inserirNaCauda(T);
    bool inserir(int, T);
    bool inserirOrdenado(T);

    T removerDaCabeca(void);
    T removerDaCauda(void);
    T remover(int);
    
    
    void imprimir(void);
    
    bool vazia(void);
    int tamanho(void);
};
#endif