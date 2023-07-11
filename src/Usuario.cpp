#include <iostream>
#include "../include/Usuario.h"


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
    int i = 0;
    o << user.getNomePerfil() << "\n"
    << "@" << user.getNomeUsuario() << "\n"
    << user.getQntdSeguindo() << " Seguindo | " << user.getQntdSeguidores() << " Seguidores | "<< user.getQntdTweets() <<" Tweets \n"; 
    return o;
};

bool Usuario::operator==(Usuario &u){
    if(this->emailUsuario == u.getEmailUsuario()){
        return true;
    } else{
        return false;
    }
}


//Setters
void Usuario::setNomePerfil(std::string nomePerfil) {
    this->nomePerfil = nomePerfil;
}
void Usuario::setListaTweets(std::vector<Tweet> listaTweets) {
    this->listaTweets = listaTweets;
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
std::map<std::string, Usuario> Usuario::getListaSeguindo(){
    return this->listaSeguindo;
}
std::map<std::string, Usuario> Usuario::getListaSeguidores() {
    return this->listaSeguidores;
}
std::map<std::string, Usuario> Usuario::getListaBloqueados() {
    return this->listaBloqueados;
}
std::string Usuario::getEmailUsuario() {
    return this->emailUsuario;
}
std::string Usuario::getNomeUsuario() {
    return this->nomeUsuario;
}
int Usuario::getQntdSeguidores() {
    return this->listaSeguidores.size();
}
int Usuario::getQntdSeguindo() {
    return this->listaSeguindo.size();
}
int Usuario::getQntdTweets() {
    return this->listaTweets.size();
} 

//Updaters
bool Usuario::updtListaSeguidores(Usuario user, std::string s) {
    auto iter = this->listaSeguidores.find(user.getEmailUsuario());
    if (s == "+" && iter == this->listaSeguidores.end()) {
        this->listaSeguidores.insert(std::pair<std::string, Usuario>(user.getEmailUsuario(), user));
        return true;
    } 
    else if (s == "-" && iter != this->listaSeguidores.end()) {
        this->listaSeguidores.erase(user.getEmailUsuario());
        return true;
    }

    return false;
}

bool Usuario::updtListaSeguindo(Usuario user, std::string s) {
    auto iter = this->listaSeguindo.find(user.getEmailUsuario());
    if (s == "+" && iter == this->listaSeguindo.end()) {
        this->listaSeguindo.insert(std::pair<std::string, Usuario>(user.getEmailUsuario(), user));
        return true;
    } 
    else if (s == "-" && iter != this->listaSeguindo.end()) {
        this->listaSeguindo.erase(user.getEmailUsuario());
        return true;
    }

    return false;
}

bool Usuario::updtListaBloqueados(Usuario user, std::string s) {
    auto iter = this->listaBloqueados.find(user.getEmailUsuario());
    if (s == "+" && iter == this->listaBloqueados.end()) {
        this->listaBloqueados.insert(std::pair<std::string, Usuario>(user.getEmailUsuario(), user));
        return true;
    } else if (s == "-" && iter != this->listaBloqueados.end()) {
        this->listaBloqueados.erase(user.getEmailUsuario());
        return true;
    }
    return false;
}

//Outros Metodos
bool Usuario::deletarUsuario(std::string confirmacao) {
    if (confirmacao == this->getNomePerfil()) {
        this->~Usuario();
        return true;
    }
    return false;
}
// user = outro usuario
// ownner = eu
bool Usuario::seguirUsuario(Usuario *user, Usuario ownner) {
    if (this->listaSeguindo.find(user->getEmailUsuario()) != this->listaSeguindo.end()) {
        return false;
    }
    this->updtListaSeguindo(*user, "+");
    user->updtListaSeguidores(ownner, "+");
    return true;
}
bool Usuario::deixarDeSeguir(Usuario user, Usuario ownner) {
    if (this->listaSeguindo.find(user.getEmailUsuario()) != this->listaSeguindo.end()) {
        return false;
    }
    this->updtListaSeguindo(user, "-");
    user.updtListaSeguidores(ownner, "-");
    return true;
}
bool Usuario::bloquearUsuario(Usuario user){
    if (this->listaBloqueados.find(user.getEmailUsuario()) != this->listaBloqueados.end()) {
        return false;
    }
    this->updtListaBloqueados(user, "+");
    return true;
}
bool Usuario::desbloquearUsuario(Usuario user){
    if (this->listaBloqueados.find(user.getEmailUsuario()) != this->listaBloqueados.end()) {
        return false;
    }
    this->updtListaBloqueados(user, "-");
    return true;
}
void Usuario::addTweet(Tweet novoTweet){
    this->listaTweets.insert(this->listaTweets.begin(), novoTweet);
}
bool Usuario::conferirSenha(std::string senhaDigitada){
    if(senhaDigitada == this->senhaUsuario){
        return true;
    }
    return false;
}
