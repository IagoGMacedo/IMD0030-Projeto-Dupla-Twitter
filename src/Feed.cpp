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
                if(iterator->first != user.getEmailUsuario()){
                    std::vector<Tweet> listaTweets = iterator->second.getListaTweets();
                    //printando cada um  dos tweets
                    for(int i = 0; i < listaTweets.size(); i++){
                        std::cout << listaTweets.at(i) << std::endl;
                    }
                }
            }
        }
    } else{
        std::cout << "ainda não foi visto nenhum tweet "<<std::endl;
    }

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

void Feed::percorrerFeed(Usuario *user, Usuario ownner){
    std::string opcaoDigitada;
    int indiceTarget = 0;
    while( opcaoDigitada!="l"){
        if(opcaoDigitada=="s" && indiceTarget+1<user->getQntdTweets()){
            indiceTarget++;
        }
        if(opcaoDigitada=="w" && indiceTarget>0){
            indiceTarget--;
        }
        if(opcaoDigitada=="j"){
            std::vector<Tweet> listaRecuperada = user->getListaTweets();
            listaRecuperada[indiceTarget].curtirTweet(ownner.getEmailUsuario());
            user->setListaTweets(listaRecuperada);
        }
        if(opcaoDigitada=="k"){
            std::system("clear");
            char conteudoTweet[280] = {0};
            std::cout << "Digite sua resposta" << std::endl;
            std::cin.ignore();
            std::cin.getline(conteudoTweet, 280);
            Tweet novoTweet = * new Tweet(conteudoTweet, ownner.getNomeUsuario(), ownner.getNomePerfil(), ownner.getEmailUsuario());
            std::vector<Tweet> listaRecuperada = user->getListaTweets();
            listaRecuperada[indiceTarget].comentarTweet(novoTweet);
            user->setListaTweets(listaRecuperada);
        }
        
        std::system("clear");
        for (int i = 0; i < user->getQntdTweets(); i++) {
            if(i==indiceTarget){
                std::cout << "➡️";
            }
            std::cout << user->getListaTweets()[i] << std::endl;
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
