#include <iostream>
#include "../include/Usuario.h"
//#include "../include/Tweet.h"
//#include "../include/std::vector.h"

//#include "../include/ListaEncad.h"

//Construtores e destrutor


Usuario::Usuario(std::string nomeUsuario, std::string nomePerfil, std::string emailUsuario, std::string senhaUsuario){
    this->nomePerfil = nomePerfil;
    this->nomeUsuario = nomeUsuario;
    this->emailUsuario = emailUsuario;
    this->senhaUsuario = senhaUsuario;

    this->listaTweets = * new std::vector<Tweet>();
    this->listaSeguindo = * new std::vector<Usuario>();
    this->listaSeguidores = * new std::vector<Usuario>();
    this->listaBloqueados = * new std::vector<Usuario>();

}


Usuario::Usuario(void) {
    this->listaTweets =  * new std::vector<Tweet>();
    this->listaSeguindo = * new std::vector<Usuario>();
    this->listaSeguidores = * new std::vector<Usuario>();
    this->listaBloqueados = * new std::vector<Usuario>();
}

Usuario::~Usuario() {
}

std::ostream& operator<< (std::ostream &o, Usuario &user){
    o << user.getNomeUsuario() <<", "<<user.getNomePerfil();
    return o;
};

bool Usuario::operator== (Usuario &u){
    if(this->emailUsuario == u.getEmailUsuario()){
        return true;
    } else{
        return false;
    }
}


//Setters
void Usuario::setNomePerfil(std::string nomePerfil) {
    this->nomePerfil = nomePerfil;
};  
void Usuario::setListaTweets(std::vector<Tweet> listaTweets) {
    this->listaTweets = listaTweets;
}
void Usuario::setQntdSeguidores(int qntdSeguidores) {
    this->qntdSeguidores = qntdSeguidores;
}
void Usuario::setQntdSeguindo(int qntdSeguindo) {
    this->qntdSeguindo = qntdSeguindo;
}
void Usuario::setQntdTweets(int novaQuantidade){
    this->qntdTweets = novaQuantidade;
}
void Usuario::setListaSeguindo(std::vector<Usuario> listaSeguindo) {
    this->listaSeguindo = listaSeguindo;
}
void Usuario::setListaSeguidores(std::vector<Usuario> listaSeguidos) {
    this->listaSeguidores = listaSeguidores;
}
void Usuario::setListaBloqueados(std::vector<Usuario> listaBloqueados) {
    this->listaBloqueados = listaBloqueados;
}
void Usuario::setEmailUsuario(std::string emailUsuario) {
    this->emailUsuario = emailUsuario;
}
void Usuario::setNomeUsuario(std::string nomeUsuario) {
    this->nomeUsuario = nomeUsuario;
}


//Getters
std::string Usuario::getNomePerfil() {
    return this->nomePerfil;
}  
std::vector<Tweet> Usuario::getListaTweets() {
    return this->listaTweets;
}
std::vector<Usuario> Usuario::getListaSeguidores() {
    return this->listaSeguidores;
}
std::vector<Usuario> Usuario::getListaSeguindo(){
    return this->listaSeguindo;
}
std::vector<Usuario> Usuario::getListaBloqueados() {
    return this->listaBloqueados;
}
int Usuario::getQntdSeguidores() {
    return this->qntdSeguidores;
}
int Usuario::getQntdSeguindo() {
    return this->qntdSeguindo;
}

int Usuario::getQntdTweets(){
    return this->qntdTweets;
}

std::string Usuario::getEmailUsuario() {
    return this->emailUsuario;
}
std::string Usuario::getNomeUsuario() {
    return this->nomeUsuario;
}


//Outros Metodos
void Usuario::deletarUsuario(std::string confirmacao) {
    if (confirmacao == this->getNomePerfil()) {
        this->~Usuario();
    }
}

void Usuario::seguirUsuario(Usuario user, Usuario ownner) {
    /* não tem buscar direto no vector, mas tem o std::find
    if (this->listaSeguindo.buscar(user)) {
        throw "Usuario já seguido";
    }
    */
    this->listaSeguindo.push_back(user);
    this->qntdSeguindo++;
    
    user.listaSeguidores.push_back(ownner);
    user.qntdSeguidores++;
}

void Usuario::deixarDeSeguir(Usuario user, Usuario ownner) {
    /*
    if (!this->listaSeguindo.buscar(user)) {
        throw "Usuario não seguido";
    }
    */
    this->listaSeguindo.push_back(user);
    this->qntdSeguindo--;
    
    user.listaSeguidores.push_back(ownner);
    user.qntdSeguidores--;
}

void Usuario::bloquearUsuario(Usuario user){
    this->listaBloqueados.push_back(user);
}
void Usuario::addTweet(Tweet novoTweet){
    this->listaTweets.push_back(novoTweet);
    this->qntdTweets++;
}
