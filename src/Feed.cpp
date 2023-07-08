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
    std::cout << "printando tudo do feed" << std::endl;
    std::map<std::string, Usuario> mapSeguidores = user.getListaSeguidores();
    for(auto iterator = mapSeguidores.begin(); iterator != mapSeguidores.end(); ++iterator){
        std::vector<Tweet> listaTweets = iterator->second.getListaTweets();
        for(int i =0;i<listaTweets.size();i++){
                std::cout << listaTweets.at(i).printarTweet() << std::endl;
        }
    }
}
