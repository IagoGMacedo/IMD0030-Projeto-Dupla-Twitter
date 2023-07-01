#ifndef LISTAENCAD_H
#define LISTAENCAD_H

#include "../include/No.h"

template <typename T>
class ListaEncad{
    private:
    No<T>* cabeca;
    No<T>* cauda;
    int quantidade;
    
public:
    ListaEncad(void);
    ListaEncad(int);
    ~ListaEncad(void);

    No<T>* getCabeca(void);
    No<T>* getCauda(void);
    
    T recuperar(int);
    int buscar(T);
    
    bool encadear(No<T>*, No<T>*, No<T>*);
    bool inserirNaCabeca(T);
    bool inserirNaCauda(T);
    bool inserir(int, T);
    bool inserirOrdenado(T);

    T removerDaCabeca(void);
    T removerDaCauda(void);
    T remover(int);
    
    void imprimir(void);
    
    bool vazia(void);
    int getTamanho(void);
};


template <typename T>
ListaEncad<T>::ListaEncad(void) {
    this->cabeca = new No<T>;
    this->cauda = new No<T>;

    this->cabeca->setProximo(this->cauda);
    this->cauda->setAnterior(this->cabeca);

    this->cabeca->setAnterior(nullptr);
    this->cauda->setProximo(nullptr);

    this->quantidade = 100;
}

template <typename T>
ListaEncad<T>::ListaEncad(int quantidade) {
    this->cabeca = new No<T>;
    this->cauda = new No<T>;

    this->cabeca->setProximo(this->cauda);
    this->cauda->setAnterior(this->cabeca);

    this->cabeca->setAnterior(nullptr);
    this->cauda->setProximo(nullptr);

    this->quantidade = quantidade;
}

template <typename T>
ListaEncad<T>::~ListaEncad(void) {
    delete this->cabeca;
    delete this->cauda;
}

template <typename T>
No<T>* ListaEncad<T>::getCabeca(void) {
    return this->cabeca;
}

template <typename T>
No<T>* ListaEncad<T>::getCauda(void) {
    return this->cauda;
}

template <typename T>
T ListaEncad<T>::recuperar(int pos) {
    if (pos > this->getTamanho()) {
        throw "Posição não existente";
    }
    if (this->vazia()) {
        throw "Lista vazia";
    }

    No<T> *aux = getCabeca();

    for (int j = 1; j <= pos; j++) {
        aux = aux->getProximo();
    }

    return aux->getValor();
}

template <typename T>
int ListaEncad<T>::buscar(T elemento) {
    No<T>* aux = getCabeca->getProximo();
    int i = 1;

    while (aux != cauda) {
        if (aux->getValor() == elemento) {
            return i;
        }

        aux = aux->getProximo();
        i++;
    }

    return -1;
}

template <typename T>
bool ListaEncad<T>::encadear(No<T>* novo, No<T>* anterior, No<T>* proximo) {
    novo->setAnterior( anterior );
    novo->setProximo( proximo );
    
    anterior->setProximo( novo );
    proximo->setAnterior( novo );

    return true;
}

template <typename T>
bool ListaEncad<T>::inserirNaCabeca(T elemento) {
    No<T>* novo = new No<T>(elemento);

    bool encad = encadear(novo, getCabeca(), getCabeca()->getProximo());
    this->quantidade++;

    return encad;
}

template <typename T>
bool ListaEncad<T>::inserirNaCauda(T elemento) {
    No<T>* novo = new No<T>(elemento);

    bool encad = encadear(novo, getCauda()->getAnterior(), getCauda() );
    this->quantidade++;

    return encad;
}

template <typename T>
bool ListaEncad<T>::inserir(int pos, T elemento) {
    No<T>* novo = new No<T>(elemento);
    No<T>* aux = getCabeca();

    for (int i = 1; i < pos; i++) {
        aux = aux->getProximo();
    }

    bool encad = encadear(novo, aux, aux->getProximo());

    return encad;
}

template <typename T>
bool ListaEncad<T>::inserirOrdenado(T elemento) {
    No<T> novo = new No<T>(elemento);
    No<T> aux = getCabeca()->getProximo();

    while (aux->getProximo() != getCauda()) {
        if (getCabeca()->getProximo()->getValor() <= novo->getValor()) {
            bool encadHead = encadear( novo, getCabeca(), getCabeca()->getProximo() );
            this->quantidade++;

            return encadHead;
        }
        else if (aux->getValor() <= novo->getValor() && aux->getProximo()->getValor() ) {
            bool encad = encadear( novo, aux, aux->getProximo() );
            this->quantidade++;

            return encad;
        }
        else {
            bool encadTail = encadear(novo, getCauda()->getAnterior(), getCauda());
            this->quantidade++;

            return encadTail;
        }
        
        aux = aux->getProximo();
    }

    return false;
}

template <typename T>
T ListaEncad<T>::removerDaCabeca(void) {
    No<T>* del = getCabeca()->getProximo();
    T del_valor = del->getValor();

    del->getProximo()->setAnterior( del->getAnterior() );
    del->getAnterior()->setProximo( del->getProximo() );

    delete del;
    quantidade--;

    return del_valor;
}

template <typename T>
T ListaEncad<T>::removerDaCauda(void) {
    No<T>* del = getCauda()->getAnterior();
    T del_valor = del->getValor();

    del->getProximo()->setAnterior( del->getAnterior() );
    del->getAnterior()->setProximo( del->getProximo() );

    delete del;
    quantidade--;
    
    return del_valor;
}

template <typename T>
T ListaEncad<T>::remover(int pos) {
    No<T>* del = getCabeca()->proximo();

    for (int i = 1; i < pos; i++) {
        del = del->proximo();
    }

    del->getProximo()->setAnterior( del->getAnterior() );
    del->getAnterior()->setProximo( del->getProximo() );

    T del_valor = del->getValor();
    delete del;
    quantidade--;

    return del_valor;
}

template <typename T>
void ListaEncad<T>::imprimir(void) {
    for (auto i = getCabeca()->getProximo(); i != getCauda(); i++) {
        std::cout << i->getValor() << " | ";
    }
    std::cout << std::endl;
}

template <typename T>
bool ListaEncad<T>::vazia(void) {
    return getTamanho() == 0;
}

template <typename T>
int ListaEncad<T>::getTamanho(void) {
    return this->quantidade;
}


#endif