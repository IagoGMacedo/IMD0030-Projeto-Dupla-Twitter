#include "../include/Tweet.h"
#include "../include/Usuario.h"


Tweet::Tweet(Usuario autorTweet, std::string conteudoTweet) {
    this->autorTweet = &autorTweet;
    this->conteudoTweet = conteudoTweet;
    this->qntdCurtidas = 0;
    this->listaCurtidas = * new std::vector<Usuario*>;
}

Tweet::Tweet(void) {
    //this->listaComentarios = * new ListaEncad<Tweet>();
    //this->autorTweet = * new Usuario();
    this->qntdCurtidas = 0;
    //this->listaCurtidas = * new Conjunto<Usuario*>;

    //this->listaCurtidas = * new Conjunto<Usuario>;
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
std::vector<Usuario*> Tweet::getListaCurtidas(){
    return this->listaCurtidas;
}

/*
ListaEncad<Tweet> Tweet::getListaComentarios() {
    return this->listaComentarios;
}
*/


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
void Tweet::setListaCurtidas(std::vector<Usuario*> listaCurtidas){
    this->listaCurtidas = listaCurtidas;
}

/*
void Tweet::setListaComentarios(ListaEncad<Tweet> listaComentarios) {
    this->listaComentarios = listaComentarios;
}
*/

//Outros metodos
/*
void Tweet::curtirTweet(Usuario user) {
    /*
    if (this->listaCurtidas.buscar(user)) {
        throw "Não é possível curtir um tweet já curtido\n";
    }
    this->listaCurtidas.inserir(&user);
    this->qntdCurtidas++;
}
*/

/*
void Tweet::descurtirTweet(Usuario user) {
    if (!this->listaCurtidas.buscar(user)) {
        throw "Não é possível descurtir um tweet não curtido\n";
    }
    this->listaCurtidas.remover(user);
    this->qntdCurtidas--;
}

void Tweet::comentarTweet(Tweet comentario) {
    this->listaComentarios.inserirNaCauda(comentario);
}

*/
