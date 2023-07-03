#include <iostream>
#include "../include/Usuario.h"
//#include "../include/Helper.h"
//#include "../include/Tweet.h"
//#include "../include/ListaEncad.h"

//Construtores e destrutor

Usuario::Usuario(std::string nomePerfil, /*Conjunto<Tweet> listaTweets,*/ int qntdSeguidores, int qntdSeguindo, /*Conjunto<Usuario> listaSeguindo, Conjunto<Usuario> listaSeguidores , Conjunto<Usuario> listaBloqueados,*/ std::string emailUsuario, std::string nomeUsuario, std::string senhaUsuario) {
    this->nomePerfil = nomePerfil;
    //this->listaTweets = listaTweets;
    this->qntdSeguidores = 0;
    this->qntdSeguindo = 0;
    /*
    this->listaSeguindo = listaSeguindo;
    this->listaSeguidores = listaSeguidores;
    this->listaBloqueados = listaBloqueados;
    */
    this->emailUsuario = emailUsuario;
    this->nomeUsuario = nomeUsuario;
    this->senhaUsuario = senhaUsuario;
    /*
    this->listaTweets = Conjunto<Tweet>();
    this->listaSeguindo = Conjunto<Usuario>();
    this->listaSeguidores = Conjunto<Usuario>();
    this->listaBloqueados = Conjunto<Usuario>(); 
    */
} 


Usuario::Usuario(std::string nomeUsuario, std::string nomePerfil, std::string emailUsuario, std::string senhaUsuario){
    this->nomePerfil = nomePerfil;
    this->nomeUsuario = nomeUsuario;
    this->emailUsuario = emailUsuario;
    this->senhaUsuario = senhaUsuario;
    /*
    this->listaTweets = Conjunto<Tweet>();
    this->listaSeguindo = Conjunto<Usuario>();
    this->listaSeguidores = Conjunto<Usuario>();
    this->listaBloqueados = Conjunto<Usuario>();
*/
}


Usuario::Usuario(void) {
}

Usuario::~Usuario() {
}

std::ostream& operator<< (std::ostream &o, Usuario &user){
            o << user.getNomeUsuario() <<", "<<user.getNomePerfil();
            return o;
        };


//Setters
void Usuario::setNomePerfil(std::string nomePerfil) {
    this->nomePerfil = nomePerfil;
};  
/*
void Usuario::setListaTweets(Conjunto<Tweet> listaTweets) {
    this->listaTweets = listaTweets;
}
*/
void Usuario::setQntdSeguidores(int qntdSeguidores) {
    this->qntdSeguidores = qntdSeguidores;
}
void Usuario::setQntdSeguindo(int qntdSeguindo) {
    this->qntdSeguindo = qntdSeguindo;
}
/*
void Usuario::setListaSeguindo(Conjunto<Usuario> listaSeguindo) {
    this->listaSeguindo = listaSeguindo;
}
void Usuario::setListaSeguidores(Conjunto<Usuario> listaSeguidos) {
    this->listaSeguidores = listaSeguidores;
}
void Usuario::setListaBloqueados(Conjunto<Usuario> listaBloqueados) {
    this->listaBloqueados = listaBloqueados;
}
*/
void Usuario::setEmailUsuario(std::string emailUsuario) {
    this->emailUsuario = emailUsuario;
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
/*
Conjunto<Usuario> Usuario::getListaSeguindo(){
    return this->listaSeguindo;
}
Conjunto<Usuario> Usuario::getListaSeguidores(){
    return this->listaSeguidores;
}
Conjunto<Usuario> Usuario::getListaBloqueados(){
    return this->listaBloqueados;
}
*/
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
/*
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
*/