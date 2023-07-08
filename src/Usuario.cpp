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
    this->listaSeguindo = * new std::map<std::string, Usuario>();
    this->listaSeguidores = * new std::map<std::string, Usuario>();
    this->listaBloqueados = * new std::map<std::string, Usuario>();

}


Usuario::Usuario(void) {
    this->listaTweets =  * new std::vector<Tweet>();
    this->listaSeguindo = * new std::map<std::string, Usuario>();
    this->listaSeguidores = * new std::map<std::string, Usuario>();
    this->listaBloqueados = * new std::map<std::string, Usuario>();
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
void Usuario::setListaSeguindo(std::map<std::string, Usuario> listaSeguindo) {
    this->listaSeguindo = listaSeguindo;
}
void Usuario::setListaSeguidores(std::map<std::string, Usuario> listaSeguidos) {
    this->listaSeguidores = listaSeguidores;
}
void Usuario::setListaBloqueados(std::map<std::string, Usuario> listaBloqueados) {
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
std::map<std::string, Usuario> Usuario::getListaSeguidores() {
    return this->listaSeguidores;
}
std::map<std::string, Usuario> Usuario::getListaSeguindo(){
    return this->listaSeguindo;
}
std::map<std::string, Usuario> Usuario::getListaBloqueados() {
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
    std::pair<std::string, Usuario> par_user = std::pair<std::string, Usuario>(user.getEmailUsuario(), user);
    std::pair<std::string, Usuario> par_ownner = std::pair<std::string, Usuario>(ownner.getEmailUsuario(), ownner);

    if (this->listaSeguindo.find(user.getEmailUsuario()) == this->listaSeguindo.end()) {
        throw "Usuario já seguido";
    }
    
    this->listaSeguindo.insert(par_user);
    this->qntdSeguindo++;
    
    user.listaSeguidores.insert(par_ownner);
    user.qntdSeguidores++;
}

void Usuario::deixarDeSeguir(Usuario user, Usuario ownner) {
    std::pair<std::string, Usuario> par_user = std::pair<std::string, Usuario>(user.getEmailUsuario(), user);
    std::pair<std::string, Usuario> par_ownner = std::pair<std::string, Usuario>(ownner.getEmailUsuario(), ownner);

    if (this->listaSeguindo.find(user.getEmailUsuario()) != this->listaSeguindo.end()) {
        throw "Usuario não seguido";
    }
    
    this->listaSeguindo.insert(par_user);
    this->qntdSeguindo--;
    
    user.listaSeguidores.insert(par_ownner);
    user.qntdSeguidores--;
}

void Usuario::bloquearUsuario(Usuario user){
    if (this->listaSeguindo.find(user.getEmailUsuario()) != this->listaSeguindo.end()) {
        throw "Usuario já bloqueado";
    }
    this->listaBloqueados.insert(std::pair<std::string, Usuario>(user.getEmailUsuario(), user));
}

void Usuario::desbloquearUsuario(Usuario user){
    if (this->listaSeguindo.find(user.getEmailUsuario()) == this->listaSeguindo.end()) {
        throw "Usuario não bloqueado";
    }
    this->listaBloqueados.erase(user.getEmailUsuario());
}


void Usuario::addTweet(Tweet novoTweet){
    this->listaTweets.insert(this->listaTweets.begin(), novoTweet) ;
    this->qntdTweets++;
}

bool Usuario::conferirSenha(std::string senhaDigitada){
    if(senhaDigitada == this->senhaUsuario){
        return true;
    }
    return false;
}

