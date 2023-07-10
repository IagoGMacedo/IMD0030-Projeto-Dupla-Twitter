#include "../include/Feed.h"
#include <vector>

Feed::Feed(){
    this->listaTweets = * new std::vector<Tweet>();
    this->listaUsuarios = * new std::vector<Usuario>();
}

Feed::~Feed(){

}

std::vector<Tweet> Feed::popularFeed(Usuario user, std::map<std::string, Usuario> listaUsuariosGeral){
    //Exibir posts de usuarios que está seguindo
    std::vector<Tweet> listaTweetsFeed = * new std::vector<Tweet>;
    std::map<std::string, Usuario> mapSeguindo;
    if(user.getListaSeguindo().size() > 0){
        mapSeguindo = user.getListaSeguindo();
    } else{
        //se ele não seguir ninguem ele vai tipo ver os tweets gerais da plataforma, tem que melhorar isso depois
        mapSeguindo = listaUsuariosGeral;
    }
    if(mapSeguindo.size() > 0){
        //iterando
        for(auto iterator = mapSeguindo.begin(); iterator != mapSeguindo.end(); ++iterator){
            //std::cout << "teste, seguindo:: " << iterator->second.getNomeUsuario() << std::endl;
            if(iterator->second.getListaTweets().size() > 0){
                if(iterator->first != user.getEmailUsuario()){
                    std::vector<Tweet> listaTweets = iterator->second.getListaTweets();
                    //printando cada um  dos tweets
                    for(int i = 0; i < listaTweets.size(); i++){
                        listaTweetsFeed.insert(listaTweetsFeed.begin(), listaTweets.at(i));
                        //std::cout << listaTweets.at(i) << std::endl;
                    }
                }
            }
        }
    } else{
        std::cout << "ainda não foi visto nenhum tweet "<<std::endl;
    }
    return listaTweetsFeed;
}

void Feed::popularProprioFeed(Usuario user){
    std::map<std::string, Usuario> mapSeguindo;
    if(user.getListaTweets().size() > 0){   
        if(user.getListaTweets().size() > 0){
                std::vector<Tweet> listaTweets = user.getListaTweets();
                //printando cada um  dos tweets
                for(int i = 0; i < listaTweets.size(); i++){
                    std::cout << listaTweets.at(i) << std::endl;
                }
        }
    }
}

void Feed::percorrerFeed(Usuario ownner, std::vector<Tweet> *vetorPercorrendo){
    std::string opcaoDigitada;
    int indiceTarget = 0;
    while( opcaoDigitada!="l"){
        if(opcaoDigitada=="s" && indiceTarget+1<vetorPercorrendo->size()){
            indiceTarget++;
        }
        if(opcaoDigitada=="w" && indiceTarget>0){
            indiceTarget--;
        }
        if(opcaoDigitada=="j"){
            vetorPercorrendo->at(indiceTarget).curtirTweet(ownner.getEmailUsuario());
        }
        if(opcaoDigitada=="k"){
            std::system("clear");
            char conteudoTweet[280] = {0};
            std::cout << "Digite sua resposta" << std::endl;
            std::cin.ignore();
            std::cin.getline(conteudoTweet, 280);
            Tweet novoTweet = * new Tweet(conteudoTweet, ownner.getNomeUsuario(), ownner.getNomePerfil(), ownner.getEmailUsuario());
            vetorPercorrendo->at(indiceTarget).comentarTweet(novoTweet);
        }
        
        std::system("clear");
        for (int i = 0; i < vetorPercorrendo->size(); i++) {
            if(i==indiceTarget){
                std::cout << "➡️";
            }
            std::cout << vetorPercorrendo->at(i) << std::endl;
        }
        /*
         std::cout << "\nO que deseja fazer??\n" 
        << "[1] Curtir\n" 
        << "[2] Comentar\n" 
        << "[3] Exibir Comentários\n" 
        << "[4] Próximo Tweet\n"
        << std::endl;
        */
       std::cout <<"[w] Anterior [s] Próximo [j] Curtir Tweet [k] Comentar Tweet [l] sair do feed "<< std::endl;
        std::cin >> opcaoDigitada;
    }
}
