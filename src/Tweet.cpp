#include "../include/Tweet.h"
#include "../include/Usuario.h"
#include <vector>
#include <algorithm>

// Tweet::Tweet(Usuario autorTweet, std::string conteudoTweet) {
//     this->autorTweet = &autorTweet;
//     this->conteudoTweet = conteudoTweet;
//     this->qntdCurtidas = 0;
//     this->listaCurtidas = * new std::map<std::string, Usuario>;
//     this->listaComentarios = * new std::vector<Tweet*>;
// }

Tweet::Tweet(std::string conteudoTweet) {
    this->conteudoTweet = conteudoTweet;
    this->qntdCurtidas = 0;
    //this->listaCurtidas = * new std::map<std::string, Usuario>;
    this->listaComentarios = * new std::vector<Tweet>;
}

Tweet::Tweet(std::string conteudoTweet, std::string nomeUsuarioAutor, std::string nomePerfilAutor, std::string emailAutor) {
    this->conteudoTweet = conteudoTweet;
    this->nomeUsuarioAutor = nomeUsuarioAutor;
    this->nomePerfilAutor = nomePerfilAutor;
    this->emailAutor = emailAutor;
    this->qntdCurtidas = 0;
    //this->listaCurtidas = * new std::map<std::string, Usuario>;
    this->listaComentarios = * new std::vector<Tweet>;
}



Tweet::Tweet(void) {
    this->qntdCurtidas = 0;
}

Tweet::~Tweet(void) {
}

std::ostream& operator << (std::ostream &out, Tweet &post) {
    out << post.nomePerfilAutor  << " @" <<  post.nomeUsuarioAutor << std::endl
    << "------------------------------------------\n"
    << post.getConteudoTweet() << "\n"
    << "------------------------------------------\n"
    << "🗨️ " << post.getQntdComentarios() << " ❤️ " << post.getQntdCurtidas() << std::endl;
    return out;
};

bool Tweet::operator == (Tweet &t){
    //botando isso aqui temporario, depois eu arrumo
    return false;
}

//Getters
// Usuario Tweet::getAutorTweet() {
//     // return *this->autorTweet;
// } 
std::string Tweet::getConteudoTweet() {
    return this->conteudoTweet;
}
int Tweet::getQntdCurtidas() {
    return this->listaCurtidas.size();
}
int Tweet::getQntdComentarios() {
    return this->listaComentarios.size();
}
int Tweet::getQntdReTweets() {
    return this->listaReTweets.size();
}
std::vector<Tweet> Tweet::getListaComentarios(){
    return this->listaComentarios;
}

// std::map<std::string, Usuario> Tweet::getListaCurtidas() {
//     return this->listaCurtidas;
// }



//Setters
// void Tweet::setAutorTweet(Usuario autorTweet) {
//     this->autorTweet = &autorTweet;
// }
void Tweet::setConteudoTweet(std::string conteudoTweet) {
    this->conteudoTweet = conteudoTweet;
}
void Tweet::setQntdCurtidas(int qntdCurtidas) {
    this->qntdCurtidas = qntdCurtidas;
}
void Tweet::setQntdComentarios(int qntdComentarios) {
    this->qntdComentarios = qntdComentarios;
}
// void Tweet::setListaCurtidas(std::map<std::string, Usuario> listaCurtidas){
//     this->listaCurtidas = listaCurtidas;
// }

void Tweet::setListaComentarios(std::vector<Tweet> listaComentarios) {
    this->listaComentarios = listaComentarios;
}

//Outros metodos
void Tweet::curtirTweet(std::string emailUsuario) {
    auto jaCurtiu = std::find(this->listaCurtidas.begin(), this->listaCurtidas.end(), emailUsuario);
    if (jaCurtiu != this->listaCurtidas.end()) {
        std::cout << "Não é possível curtir um tweet já curtido" << std::endl;
    } else{
        this->listaCurtidas.insert(this->listaCurtidas.begin(),emailUsuario);
        this->qntdCurtidas++;
    }
}

// void Tweet::descurtirTweet(Usuario user) {
//     if (this->listaCurtidas.find(user.getEmailUsuario()) != this->listaCurtidas.end()) {
//         throw "Não é possível descurtir um tweet não curtido\n";
//     }
//     this->listaCurtidas.erase(user.getEmailUsuario());
//     this->qntdCurtidas--;
// }

void Tweet::comentarTweet(Tweet comentario) {
    this->listaComentarios.insert(this->listaComentarios.begin(), comentario) ;
    this->qntdComentarios++;
}

std::string Tweet::printarTweet(){
    std::string printTweet = 
                        this->nomeUsuarioAutor +" @"+this->nomePerfilAutor +"\n" +
                        this->getConteudoTweet() + "\n" +
                        "🗨️ " + std::to_string(this->qntdComentarios) +
                        " ❤️ " + std::to_string(this->qntdCurtidas) + "\n";
                        
    return printTweet;

}

bool Tweet::reTweet(std::string emailUsuario) {
    auto jaReTweetou = std::find(this->listaReTweets.begin(), this->listaReTweets.end(), emailUsuario);
    if (jaReTweetou != this->listaReTweets.end()) {
        return false;
    } else{
        this->listaReTweets.insert(this->listaReTweets.begin(), emailUsuario);
    }

    return true;
}


