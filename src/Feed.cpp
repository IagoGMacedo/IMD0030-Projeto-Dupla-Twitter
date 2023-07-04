#include "../include/Feed.h"


Feed::Feed(){
    this->listaTweets = * new Conjunto<Tweet>();
    //this->listaUsuarios = * new Conjunto<Usuario>();
}

Feed::~Feed(){

}

void Feed::popularFeed(Usuario user){


    //Exibir posts de usuarios que está seguindo
    /*
    for (int i = 0; i < user.getQntdSeguindo(); i++) {
        Usuario user_aux = user.getListaSeguindo().recuperar(i);
        for (int j = 0; j < user_aux.getListaTweets().tamanho(); j++) {
            Tweet post = user_aux.getListaTweets().recuperar(j);
            std::cout << post << std::endl;
        }
    }
    */

    //Exibir posts de usuarios com mais likes
    /*
    for (int i = 0; i < this->listaUsuarios.tamanho(); i++) {
        this->listaUsuarios.recuperar(i).getListaTweets().recuperar(0);
    }
    */
}
