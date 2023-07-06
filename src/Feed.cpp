#include "../include/Feed.h"
#include <vector>

Feed::Feed(){
    this->listaTweets = * new std::vector<Tweet>();
    this->listaUsuarios = * new std::vector<Usuario>();
}

Feed::~Feed(){

}

void Feed::popularFeed(Usuario user){
    //Exibir posts de usuarios que está seguindo
    for(auto m : user.getListaSeguindo()){
        for(Tweet tweet : user.getListaTweets()){
            tweet.printarTweet();
        }
    }
    //Exibir posts de usuarios com mais likes
    /*
    for (int i = 0; i < this->listaUsuarios.tamanho(); i++) {
        this->listaUsuarios.recuperar(i).getListaTweets().recuperar(0);
    }
    */
}
