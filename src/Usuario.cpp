#include "../include/Usuario.h"
#include "../include/Helper.h"
#include <iostream>

//Construtores e destrutor
Usuario::Usuario(std::string nomePerfil, Conjunto<Tweet> listaTweets, int qntdSeguidores, int qntdSeguindo, Conjunto<Usuario> listaSeguindo, Conjunto<Usuario> listaSeguidores , Conjunto<Usuario> listaBloqueados, std::string email, std::string nomeUsuario) {
    this->nomePerfil = nomePerfil;
    this->listaTweets = listaTweets;
    this->qntdSeguidores = qntdSeguidores;
    this->qntdSeguindo = qntdSeguindo;
    this->listaSeguindo = listaSeguindo;
    this->listaSeguidores = listaSeguidores;
    this->listaBloqueados = listaBloqueados;
    this->email = email;
    this->nomeUsuario = nomeUsuario;    
}

Usuario::Usuario(std::string nomePerfil, std::string email, std::string nomeUsuario) {
    this->nomePerfil = nomePerfil;
    this->email = email;
    this->nomeUsuario = nomeUsuario;
}

Usuario::Usuario() {
}

Usuario::~Usuario() {
}


//Setters
void Usuario::setNomePerfil(std::string nomePerfil) {
    this->nomePerfil = nomePerfil;
};  
void Usuario::setListaTweets(Conjunto<Tweet> listaTweets) {
    this->listaTweets = listaTweets;
}
void Usuario::setQntdSeguidores(int qntdSeguidores) {
    this->qntdSeguidores = qntdSeguidores;
}
void Usuario::setQntdSeguindo(int qntdSeguindo) {
    this->qntdSeguindo = qntdSeguindo;
}
void Usuario::setListaSeguindo(Conjunto<Usuario> listaSeguindo) {
    this->listaSeguindo = listaSeguindo;
}
void Usuario::setListaSeguidores(Conjunto<Usuario> listaSeguidos) {
    this->listaSeguidores = listaSeguidores;
}
void Usuario::setListaBloqueados(Conjunto<Usuario> listaBloqueados) {
    this->listaBloqueados = listaBloqueados;
}
void Usuario::setEmail(std::string email) {
    this->email = email;
}
void Usuario::setNomeUsuario(std::string nomeUsuario) {
    this->nomeUsuario = nomeUsuario;
}


//Setters
std::string Usuario::getNomePerfil() {
    return this->nomePerfil;
}
/*    
Conjunto<Tweet> Usuario::setListaTweets( Conjunto<Tweet> listaTweet ) {
    this->listaTweet = listaTweet;
}
    
Conjunto<Tweet> Usuario::setListaSeguidores( Conjunto<Tweet> listaSeguidores ) {

}
Conjunto<Tweet> Usuario::setListaSeguindo( Conjunto<Tweet> listaSeguindo ){
    
}
*/
int Usuario::getQntdSeguidores() {
    return this->qntdSeguidores;
}
int Usuario::getQntdSeguindo() {
    return this->qntdSeguindo;
}
Conjunto<Usuario> Usuario::getListaSeguindo(){
    return this->listaSeguindo;
}
Conjunto<Usuario> Usuario::getListaSeguidores(){
    return this->listaSeguidores;
}
Conjunto<Usuario> Usuario::getListaBloqueados(){
    return this->listaBloqueados;
}
std::string Usuario::getEmail() {
    return this->email;
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
    if (this->listaSeguindo.buscar(user)) {
        throw "Usuario já seguido";
    }
    this->listaSeguindo.inserir(user);
    this->qntdSeguindo++;
    
    user.listaSeguidores.inserir(ownner);
    user.qntdSeguidores++;
}

void Usuario::deixarDeSeguir(Usuario user, Usuario ownner) {
    if (!this->listaSeguindo.buscar(user)) {
        throw "Usuario não seguido";
    }
    this->listaSeguindo.inserir(user);
    this->qntdSeguindo--;
    
    user.listaSeguidores.inserir(ownner);
    user.qntdSeguidores--;
}

void Usuario::bloquearUsuario(Usuario user){
    this->listaBloqueados.inserir(user);
}
