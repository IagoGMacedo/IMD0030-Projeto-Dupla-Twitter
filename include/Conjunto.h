#ifndef CONJUNTO_H
#define CONJUNTO_H


template <typename T>
class Conjunto{
        public:
        Conjunto();
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

#endif