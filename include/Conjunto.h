#ifndef CONJUNTO_H
#define CONJUNTO_H

//#include <iostream>

template <typename T>
class Conjunto{
        public:
        Conjunto();
        //Conjunto(int capacidade);
        ~Conjunto();
        bool inserir(T elemento);
        bool remover(T elemento);
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
}

template<typename T>
Conjunto<T>::~Conjunto(void){
}

/*
template<typename T>
Conjunto<T>::Conjunto(int capacidade){

}
template<typename T>
Conjunto<T>::Conjunto(int capacidade){
    this->capacidade=capacidade;
    this->elementos = new T[capacidade];
    this->quantidade = 0;
}



template<typename T>
Conjunto<T>::~Conjunto(void){

}

template<typename T>
bool Conjunto<T>::inserir(T elemento)
{
    if(this->quantidade<this->capacidade && !this->buscar(elemento)){
        this->elementos[quantidade] = elemento;
        this->quantidade++;
        return true;
    } 
    return false;
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
*/

#endif