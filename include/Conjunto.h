#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>



template <typename T>
class Conjunto{
        public:
        Conjunto();
        //Conjunto(int capacidade);
        ~Conjunto();

        bool inserir(T elemento);
        bool remover(T elemento);
        T recuperar(int);
        bool buscar(T elemento) const;
        int tamanho() const;
        void imprimir() const;
    
    private:
        T* elementos;
        int capacidade;
        int quantidade;
};
//metodos vão ser aqui mesmo, nao tem cpp
template<typename T>
Conjunto<T>::Conjunto(void){
    this->quantidade = 0;
    this->capacidade = 10;
    this->elementos  = new T[capacidade];
}

template<typename T>
Conjunto<T>::~Conjunto(void){
    delete []this->elementos;
}

template<typename T>
bool Conjunto<T>::inserir(T elemento)
{
    if(this->quantidade < this->capacidade){
        this->elementos[quantidade] = elemento;
        this->quantidade++;
        return true;
    } 
    return false;
}

template<typename T>
bool Conjunto<T>::buscar(T elemento) const
{
    for(int i =0;i<this->quantidade;i++){
        if(this->elementos[i]==elemento){
            return true;
        } 
    }
    return false;

}
template<typename T>
bool Conjunto<T>::remover(T elemento)
{
    //TO-DO
    if(this->buscar(elemento)){
        for(int i =0;i<this->quantidade;i++){
            if(this->elementos[i]==elemento){
                //abordagem de fazer swap
                T auxiliar = this->elementos[i];
                this->elementos[i] = this->elementos[this->quantidade-1];
                this->elementos[this->quantidade-1] = auxiliar;
                this->quantidade--;
                return true;
            }
        }
    }
    return false;
}

template<typename T>
T Conjunto<T>::recuperar(int i) 
{
    if (this->quantidade > 0) {
        return this->elementos[i];
    }

    throw "false";
}

template<typename T>
int Conjunto<T>::tamanho() const
{
    return this->quantidade;
}


template<typename T>
void Conjunto<T>::imprimir() const
{
    std::cout << "{ ";
    for(int i = 0; i < quantidade; ++i)
    {
        std::cout << this->elementos[i] << " ";
    }
    std::cout << "}" << std::endl;
}


#endif