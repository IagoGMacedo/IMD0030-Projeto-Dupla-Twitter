#include <iostream>
#include "../include/Usuario.h"

/**
 * @file Usuario.cpp
 * @brief Objeto Usuario e seus métodos
*/

/**< Construtores e destrutor*/
Usuario::Usuario(std::string nomeUsuario, std::string nomePerfil, std::string emailUsuario, std::string senhaUsuario){
    this->nomePerfil = nomePerfil;
    this->nomeUsuario = nomeUsuario;
    this->emailUsuario = emailUsuario;
    this->senhaUsuario = senhaUsuario;

    this->listaTweets = * new std::vector<Tweet>();
    this->listaSeguindo = * new std::map<std::string, Usuario>();
    this->listaSeguidores = * new std::map<std::string, Usuario>();
}

Usuario::Usuario(void) {
    this->listaTweets =  * new std::vector<Tweet>();
    this->listaSeguindo = * new std::map<std::string, Usuario>();
    this->listaSeguidores = * new std::map<std::string, Usuario>();
}

Usuario::~Usuario() {
}

/**< Sobrecargas de saída e de comparação*/
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

/**< Métodos Getters, Setters e Updaters*/
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

//Outros Metodos
/**
 * @brief Deletar um usuário
 * 
 * @param confirmacao nome de perfil como confirmação para deletar o usuário
 * @return Verdadeiro se o usuário for deletado, e false se não
 * 
 * @fn bool Usuario::deletarUsuario(std::string confirmacao)
*/
bool Usuario::deletarUsuario(std::string confirmacao) {
    if (confirmacao == this->getNomePerfil()) {
        this->~Usuario();
        return true;
    }
    return false;
}

/**
 * @brief Seguir um usuário
 * @param user Usuario a ser seguido
 * @param ownner Usuario que está realizando a ação
 * @return Verdadeiro se for possível seguir, e falso caso contrário
 * @fn bool Usuario::seguirUsuario(Usuario *user, Usuario ownner)
*/
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

/**
 * @brief Deixar de seguir um usuário
 * @param user Usuario a ser deseguido
 * @param ownner Usuario que está realizando a ação
 * @return Verdadeiro se for possível deseguir, e falso caso contrário
 * @fn bool Usuario::deixarDeSeguir(Usuario *user, Usuario ownner)
*/
bool Usuario::deixarDeSeguir(Usuario *user, Usuario ownner) {
    if (this->listaSeguindo.find(user->getEmailUsuario()) != this->listaSeguindo.end()) {
        return false;
    }
    this->updtListaSeguindo(*user, "-");
    user->updtListaSeguidores(ownner, "-");
    return true;
}
/**
 * @brief Vincular um tweet ao usuário
 * @param novoTweet Tweet a se vinculado ao usuário
 * @fn void Usuario::addTweet(Tweet novoTweet)
*/
void Usuario::addTweet(Tweet novoTweet){
    this->listaTweets.insert(this->listaTweets.begin(), novoTweet);
}

/**
 * @brief Confere a senha digitada com a senha armazenada no usuário
 * @param senhaDigitada Senha a ser comparada
 * @return Verdadeiro se a senha confere, e falso caso o contrário
 * @fn bool Usuario::conferirSenha(std::string senhaDigitada)
*/
bool Usuario::conferirSenha(std::string senhaDigitada){
    if(senhaDigitada == this->senhaUsuario){
        return true;
    }
    return false;
}
