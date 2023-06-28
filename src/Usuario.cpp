<<<<<<< HEAD
#include "../include/Usuario.h"
#include "../include/helper.h"
#include <string>
using namespace std;

//Construtores e destrutor
Usuario::Usuario(string nomePerfil, /*Conjunto<Tweet> listaTweets[],*/ int qntdSeguidores, int qntdSeguindo, 
                /*Conjunto<Usuario> listaSeguindo, Conjunto<Usuario> listaSeguidores , Conjunto<Usuario> listaBloqueados, */ 
                string email, string nomeUsuario) {
    this->nomePerfil = nomePerfil;
    //this->listaTweets = listaTweets;
    this->qntdSeguidores = qntdSeguidores;
    this->qntdSeguindo = qntdSeguindo;
    //this->listaSeguindo = listaSeguindo;
    //this->listaSeguidores = listaSeguidores;
    //this->listaBloqueados = listaBloqueados;
    this->email = email;
    this->nomeUsuario = nomeUsuario;    
    
};

Usuario::Usuario() {
}

Usuario::~Usuario() {
}


//Setters
void Usuario::setNomePerfil(string nomePerfil) {
    this->nomePerfil = nomePerfil;
};
/*  
void Usuario::setlistaTweets(Conjunto<Tweet> listaTweets) {
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
void Usuario::setlistaSeguindo(Conjunto<Usuarios> listaSeguindo) {
    this->listaSeguindo = listaSeguindo;
}

void Usuario::setlistaSeguidores(Conjunto<Usuarios> listaSeguidos) {
    this->listaSeguidores = listaeguidores;
}
*/
void Usuario::setEmail(string email) {
    this->email = email;
}
    
void Usuario::setNomeUsuario(string nomeUsuario) {
    this->nomeUsuario = nomeUsuario;
}


//Setters
string Usuario::getNomePerfil() {
    return this->nomePerfil;
}
/*    
Conjunto<Tweet> Usuario::getlistaTweets();
    
int Usuario::getQntdSeguidores();
int Usuario::getQntdSeguindo();
*/

int Usuario::getQntdSeguidores() {
    return this->qntdSeguidores;
}

int Usuario::getQntdSeguindo() {
    return this->qntdSeguindo;
}

/*
Conjunto<Usuarios> Usuario::getlistaSeguindo(){
}

Conjunto<Usuarios> Usuario::getlistaSeguidores(){
}
*/
string Usuario::getEmail() {
    return this->email;
}

string Usuario::getNomeUsuario() {
    return this->nomeUsuario;
}
    

//Outros Metodos
void Usuario::deletarUsuario( string confirmacao ) {
    if (confirmacao == this->getNomePerfil()) {
        this->~Usuario();
    }
}

void Usuario::seguirUsuario( Usuario user ) {
    //this->listaSeguindo.adicionar(user);
    //user->listaSeguidores.adicionar();
}

void Usuario::bloquearUsuario( Usuario user ){
    //this->listaBloqueados.adicionar(user);
}


=======
#include "../include/Usuario.h"
#include "../include/Conjunto.h"


Usuario::Usuario(){

}
>>>>>>> 93353da73c7a50d2e9c35f177ee4d9c967bdb0b8
