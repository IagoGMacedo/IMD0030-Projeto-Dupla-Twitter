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
    std::cout << "printando feed" << std::endl;
    std::map<std::string, Usuario> mapSeguindo = user.getListaSeguindo();
    //iterando
    for(auto iterator = mapSeguindo.begin(); iterator != mapSeguindo.end(); ++iterator){
        std::cout << "teste, seguindo:: " << iterator->second.getNomeUsuario() << std::endl;
        std::vector<Tweet> listaTweets = iterator->second.getListaTweets();
        //printando cada um  dos tweets de cada um que eu estou seguindo
        for(int i =0;i<listaTweets.size();i++){
                std::cout << listaTweets.at(i).getAutorTweet().getNomeUsuario() << std::endl;
                std::cout << listaTweets.at(i).getAutorTweet().getEmailUsuario() << std::endl;
                std::cout << listaTweets.at(i).getConteudoTweet() << std::endl;

        }
    }
}
