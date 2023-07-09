#include "../include/Feed.h"
#include <vector>

Feed::Feed(){
    this->listaTweets = * new std::vector<Tweet>();
    this->listaUsuarios = * new std::vector<Usuario>();
}

Feed::~Feed(){

}

void Feed::popularFeed(Usuario user, std::map<std::string, Usuario> listaUsuariosGeral){
    //Exibir posts de usuarios que está seguindo
    std::cout << "populando feed" << std::endl;
    std::map<std::string, Usuario> mapSeguindo;
    if(user.getListaSeguindo().size() > 0){
        mapSeguindo = user.getListaSeguindo();
    } else{
        mapSeguindo = listaUsuariosGeral;
    }
    if(mapSeguindo.size() > 0){
        //iterando
        for(auto iterator = mapSeguindo.begin(); iterator != mapSeguindo.end(); ++iterator){
            //std::cout << "teste, seguindo:: " << iterator->second.getNomeUsuario() << std::endl;
            if(iterator->second.getListaTweets().size() > 0){
                std::vector<Tweet> listaTweets = iterator->second.getListaTweets();
                //printando cada um  dos tweets
                for(int i =0;i<listaTweets.size();i++){
                        std::cout << listaTweets.at(i).printarTweet() << std::endl;
                }
            }
            
        }
    } else{
        std::cout << "ainda não foi visto nenhum tweet "<<std::endl;
    }

}
