#include "../include/Tweet.h"
#include "../include/Usuario.h"
#include <vector>

Tweet::Tweet(Usuario autorTweet, std::string conteudoTweet) {
    this->autorTweet = &autorTweet;
    this->conteudoTweet = conteudoTweet;
    this->qntdCurtidas = 0;
    this->listaCurtidas = * new std::map<std::string, Usuario>;
    this->listaComentarios = * new std::vector<Tweet*>;
}

Tweet::Tweet(void) {
    this->qntdCurtidas = 0;
}

Tweet::~Tweet(void) {
}

std::ostream& operator << (std::ostream &out, Tweet &post) {
    Usuario user = post.getAutorTweet();
    out << user.getNomeUsuario() << " @" << user.getNomePerfil() << "\n"
    << post.getConteudoTweet() << "\n"
    << "👍" << post.getQntdCurtidas() /*<< post.getListaComentarios().getTamanho()*/
    << std::endl;
    return out;
};

bool Tweet::operator == (Tweet &t){
    //botando isso aqui temporario, depois eu arrumo
    return false;
}

//Getters
Usuario Tweet::getAutorTweet() {
    return *this->autorTweet;
} 
std::string Tweet::getConteudoTweet() {
    return this->conteudoTweet;
}
int Tweet::getQntdCurtidas() {
    return this->qntdCurtidas;
}
std::vector<Tweet*> Tweet::getListaComentarios(){
    return this->listaComentarios;
}

std::map<std::string, Usuario> Tweet::getListaCurtidas() {
    return this->listaCurtidas;
}



//Setters
void Tweet::setAutorTweet(Usuario autorTweet) {
    this->autorTweet = &autorTweet;
}
void Tweet::setConteudoTweet(std::string conteudoTweet) {
    this->conteudoTweet = conteudoTweet;
}
void Tweet::setQntdCurtidas(int qntdCurtidas) {
    this->qntdCurtidas = qntdCurtidas;
}
void Tweet::setListaCurtidas(std::map<std::string, Usuario> listaCurtidas){
    this->listaCurtidas = listaCurtidas;
}

void Tweet::setListaComentarios(std::vector<Tweet*> listaComentarios) {
    this->listaComentarios = listaComentarios;
}

//Outros metodos
void Tweet::curtirTweet(Usuario user) {
    if (this->listaCurtidas.find(user.getEmailUsuario()) == this->listaCurtidas.end()) {
        throw "Não é possível curtir um tweet já curtido\n";
    }
    this->listaCurtidas.insert(std::pair<std::string, Usuario>(user.getEmailUsuario(), user));
    this->qntdCurtidas++;
}

void Tweet::descurtirTweet(Usuario user) {
    if (this->listaCurtidas.find(user.getEmailUsuario()) != this->listaCurtidas.end()) {
        throw "Não é possível descurtir um tweet não curtido\n";
    }
    this->listaCurtidas.erase(user.getEmailUsuario());
    this->qntdCurtidas--;
}

void Tweet::comentarTweet(Tweet *comentario) {
    this->listaComentarios.push_back(comentario);
}

std::string Tweet::printarTweet(){
    //ou printa direto aqui, ou retorna a string pra printar lá
    std::cout <<this->getAutorTweet().getNomePerfil() << std::endl;
    std::cout <<this->getConteudoTweet() << std::endl;
    std::cout <<"com " << this->listaComentarios.size() << " ";
    std::cout <<"like " << this->qntdCurtidas << " ";
    std::cout <<" " << std::endl;

}



