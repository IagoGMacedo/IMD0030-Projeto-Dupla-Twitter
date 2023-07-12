#include "../include/Tweet.h"
#include <vector>
#include <algorithm>
/**
 * @file Tweet.cpp
 * @brief Objeto Tweet e seus métodos
*/

/**< Construtores e destrutor*/
Tweet::Tweet(std::string conteudoTweet) {
    this->conteudoTweet = conteudoTweet;
    this->qntdCurtidas = 0;
    this->listaComentarios = * new std::vector<Tweet>;
}

Tweet::Tweet(std::string conteudoTweet, std::string nomeUsuarioAutor, std::string nomePerfilAutor, std::string emailAutor) {
    this->conteudoTweet = conteudoTweet;
    this->nomeUsuarioAutor = nomeUsuarioAutor;
    this->nomePerfilAutor = nomePerfilAutor;
    this->emailAutor = emailAutor;
    this->qntdCurtidas = 0;
    this->listaComentarios = * new std::vector<Tweet>;
} 

Tweet::Tweet(void) {
    this->qntdCurtidas = 0;
    this->listaComentarios = * new std::vector<Tweet>;
}

Tweet::~Tweet(void) {
}

/**< Sobrecarga de saída para exibição do tweet*/
std::ostream& operator << (std::ostream &out, Tweet &post) {
    out << post.nomePerfilAutor  << " @" <<  post.nomeUsuarioAutor << std::endl
    << "------------------------------------------\n"
    << post.getConteudoTweet() << "\n"
    << "------------------------------------------\n"
    << "🗨️ " << post.getQntdComentarios() << " ❤️ " << post.getQntdCurtidas() << std::endl;
    return out;
};
/**< Sobrecarga de comparação entre tweets*/
bool Tweet::operator == (Tweet &t){
    if(t.getEmailAutor() == this->getEmailAutor() && t.getConteudoTweet() == this->getConteudoTweet() && t.getNomeUsuarioAutor() == this->getNomeUsuarioAutor()){
        return true;
    }
    return false;
}

/**< Getters e Setters*/
//Getters
std::string Tweet::getConteudoTweet() {
    return this->conteudoTweet;
}
int Tweet::getQntdCurtidas() {
    return this->listaCurtidas.size();
}
int Tweet::getQntdComentarios() {
    return this->listaComentarios.size();
}
std::vector<Tweet> Tweet::getListaComentarios(){
    return this->listaComentarios;
}
std::vector<std::string> Tweet::getListaCurtida(){
    return this->listaCurtidas;
}
int Tweet::getQntdReTweets() {
    return this->listaReTweets.size();
}
std::string Tweet::getNomeUsuarioAutor(){
    return this->nomeUsuarioAutor;
}
std::string Tweet::getNomePerfilAutor(){
    return this->nomePerfilAutor;
}
std::string Tweet::getEmailAutor(){
    return this->emailAutor;
}


//Setters
void Tweet::setConteudoTweet(std::string conteudoTweet) {
    this->conteudoTweet = conteudoTweet;
}
void Tweet::setQntdCurtidas(int qntdCurtidas) {
    this->qntdCurtidas = qntdCurtidas;
}
void Tweet::setQntdComentarios(int qntdComentarios) {
    this->qntdComentarios = qntdComentarios;
}
void Tweet::setListaComentarios(std::vector<Tweet> listaComentarios) {
    this->listaComentarios = listaComentarios;
}

//Outros metodos
/**
 * @brief Curte um tweet
 * @param emailusuario
 * @fn void Tweet::curtirTweet(std::string emailUsuario)
*/
void Tweet::curtirTweet(std::string emailUsuario) {
    auto jaCurtiu = std::find(this->listaCurtidas.begin(), this->listaCurtidas.end(), emailUsuario);
    if (jaCurtiu != this->listaCurtidas.end()) {
        std::cout << "Não é possível curtir um tweet já curtido" << std::endl;
    } else{
        this->listaCurtidas.insert(this->listaCurtidas.begin(),emailUsuario);
        this->qntdCurtidas++;
    }
}
/**
 * @brief Descurte um tweet
 * @param emailusuario Email do usuário utilizado como chave de busca na lista de curtidas
 * @fn void Tweet::descurtirTweet(std::string emailUsuario)
*/
void Tweet::descurtirTweet(std::string emailUsuario) {
    auto jaCurtiu = std::find(this->listaCurtidas.begin(), this->listaCurtidas.end(), emailUsuario);
    if (jaCurtiu != this->listaCurtidas.end()) {
            this->listaCurtidas.erase(jaCurtiu);
            this->qntdCurtidas--;
    } else{
        std::cout << "Não é possível descurtir um tweet não curtido\n" << std::endl;
    }
}
/**
 * @brief Comenta um tweet
 * @param comentar Comentário a ser inserido na lista
 * @fn void Tweet::comentarTweet(std::string emailUsuario)
*/
void Tweet::comentarTweet(Tweet comentario) {
    this->listaComentarios.insert(this->listaComentarios.begin(), comentario) ;
    this->qntdComentarios++;
}
/**
 * @brief Verifica se um determinado usuário já curtiu um tweet
 * @param emailUsuario Email do usuário a ser verificado
 * @fn bool Tweet::usuarioJacurtiu(std::string emailUsuario)
*/
bool Tweet::usuarioJacurtiu(std::string emailUsuario){
    auto jaCurtiu = std::find(this->listaCurtidas.begin(), this->listaCurtidas.end(), emailUsuario);
    if (jaCurtiu != this->listaCurtidas.end()) {
        return true;
    } else{
        return false;
    }
}



