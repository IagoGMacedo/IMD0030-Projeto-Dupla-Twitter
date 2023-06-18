#ifndef NO_H
#define NO_H

template <typename T>
class No
{
private:
    T valor;
    No* proximo;
    No* anterior;
    
public:
    No();
    No( T );
    No( T, No*, No* );
    T getValor();
    void setValor(T val);
    No* getProximo();
    void setProximo(No*);
	No* getAnterior();
	void setAnterior(No*);
};
#endif