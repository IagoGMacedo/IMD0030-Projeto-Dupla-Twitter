#include "../include/Tweet.h"
//#include "../include/ListaEncad.h"


Tweet::Tweet(/*Usuario autorTweet,*/ std::string conteudoTweet, int qntdCurtidas/*, ListaEncad<Tweet> listaComentarios*/) {
    //this->autorTweet = autorTweet;
    this->conteudoTweet = conteudoTweet;
    this->qntdCurtidas = qntdCurtidas;
    //this->listaComentarios = listaComentarios;


}

Tweet::Tweet(void) {
    //this->listaComentarios = ListaEncad<Tweet>();
}

Tweet::~Tweet(void) {
}

//Getters
/*
Usuario Tweet::getAutorTweet() {
    return this->autorTweet;
} */
std::string Tweet::getConteudoTweet() {
    return this->conteudoTweet;
}
int Tweet::getQntdCurtidas() {
    return this->qntdCurtidas;
}
/*
ListaEncad<Tweet> Tweet::getListaComentarios() {
    return this->listaComentarios;
}

//Setters

void Tweet::getAutorTweet(Usuario autorTweet) {
    this->autorTweet = autorTweet;
}*/
void Tweet::getConteudoTweet(std::string conteudoTweet) {
    this->conteudoTweet = conteudoTweet;
}
void Tweet::getQntdCurtidas(int qntdCurtidas) {
    this->qntdCurtidas = qntdCurtidas;
}
/*
void Tweet::getListaComentarios(ListaEncad<Tweet> listaComentarios) {
    this->listaComentarios = listaComentarios;
}

//Outros metodos

void Tweet::curtirTweet(Usuario user) {
    if (this->listaCurtidas.buscar(user)) {
        throw "Não é possível curtir um tweet já curtido\n";
    }
    this->listaCurtidas.inserir(user);
    this->qntdCurtidas++;
}

void Tweet::descurtirTweet(Usuario user) {
    if (!this->listaCurtidas.buscar(user)) {
        throw "Não é possível descurtir um tweet não curtido\n";
    }
    this->listaCurtidas.remover(user);
    this->qntdCurtidas--;
}

void Tweet::comentarTweet(Tweet comentario) {
    this->listaComentarios.inserirNaCauda(comentario);
}
*/