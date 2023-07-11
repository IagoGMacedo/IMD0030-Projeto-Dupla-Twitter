#include "../include/Feed.h"
#include <vector>
#include <cstdlib>
/**
 * @file Feed.cpp
 * @brief Objeto feed e seus parâmetros
*/
//Construtores e destrutor
Feed::Feed(){
}

Feed::~Feed(){

}

/**
 * @brief Método para popular o feed de um usuário
 * 
 * @param user Usuario que vai ter o feed preenchido
 * @param listaUsuariosGeral Lista dos usuários registrados
 * @return A lista com tweets para o feed
 * 
 * @fn std::vector<Tweet> Feed::popularFeed(Usuario user, std::map<std::string, Usuario> listaUsuariosGeral)
*/
std::vector<Tweet> Feed::popularFeed(Usuario user, std::map<std::string, Usuario> listaUsuariosGeral){
    //acho que tá tudo ok por aqui
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
        //vetor de pessoas que eu estou seguindo
        for(auto iterator = mapSeguindo.begin(); iterator != mapSeguindo.end(); ++iterator){
            if(iterator->second.getListaTweets().size() > 0){
                if(iterator->first != user.getEmailUsuario()){
                    std::vector<Tweet> listaTweets = iterator->second.getListaTweets();
                    for(int i = 0; i < listaTweets.size(); i++){
                        listaTweetsFeed.insert(listaTweetsFeed.begin(), listaTweets.at(i));
                    }
                }
            }
        }
    } else{
        std::cout << "ainda não foi visto nenhum tweet "<<std::endl;
    }
    return listaTweetsFeed;
}

/**
 * @brief Usado para percorrer um vetor de tweets
 * 
 * @param ownner Usuario "dono" do vetor
 * @param vetorPercorrendo Ponteiro para o vetor que vai ser percorrido
 * 
 * @fn void Feed::percorrerFeed(Usuario ownner, std::vector<Tweet> *vetorPercorrendo)
*/
void Feed::percorrerFeed(Usuario ownner, std::vector<Tweet> *vetorPercorrendo){
    std::string opcaoDigitada;
    std::string stringConcatenar;
    std::string stringCurtir;
    int indiceTarget = 0;
    /**< Loop para opções de ações em relação aos tweets*/
    while( opcaoDigitada!="s"){
        stringConcatenar = "";
        /**< Passar para o próximo tweet*/
        if(opcaoDigitada=="d" && indiceTarget+1<vetorPercorrendo->size()){
            indiceTarget++;
        }
        /**< Ir para tweet anterior*/
        if(opcaoDigitada=="a" && indiceTarget>0){
            indiceTarget--;
        }
        /**< Curtir o tweet*/
        if(opcaoDigitada=="l"){
            vetorPercorrendo->at(indiceTarget).curtirTweet(ownner.getEmailUsuario());
        }
        /**< Comentar Tweet*/
        if(opcaoDigitada=="c"){
            std::system("clear");
            char conteudoTweet[280] = {0};
            std::cout << "Digite sua resposta\n" << std::endl;
            std::cin.ignore();
            std::cin.getline(conteudoTweet, 280);
            Tweet novoTweet = * new Tweet(conteudoTweet, ownner.getNomeUsuario(), ownner.getNomePerfil(), ownner.getEmailUsuario());
            vetorPercorrendo->at(indiceTarget).comentarTweet(novoTweet);
        }
        /**< Visualizar comentários*/
        if(opcaoDigitada=="v" && vetorPercorrendo->at(indiceTarget).getQntdComentarios() > 0){
            std::vector<Tweet> vectorListaComentarios = vetorPercorrendo->at(indiceTarget).getListaComentarios();
            this->percorrerFeed(ownner , &vectorListaComentarios);
            vetorPercorrendo->at(indiceTarget).setListaComentarios(vectorListaComentarios);
        }

        std::system("clear");
        for (int i = 0; i < vetorPercorrendo->size(); i++) {
            if(i==indiceTarget){
                std::cout << "➡️";
            }
            std::cout << vetorPercorrendo->at(i) << std::endl;
        }
        if(vetorPercorrendo->at(indiceTarget).getQntdComentarios() > 0){
            stringConcatenar = "[v] ver comentários ";
        }
        if(vetorPercorrendo->at(indiceTarget).usuarioJacurtiu(ownner.getEmailUsuario())){
            stringCurtir = "[l] descurtir Tweet";
        } else{
            stringCurtir = "[l] Curtir Tweet";
        }
        //if(vetorPercorrendo->at(indiceTarget).cur)
        //std::cout <<"[w] Anterior [s] Próximo [j] Curtir Tweet [k] Comentar Tweet "<<stringConcatenar<< std::endl;
        std::cout <<"[a] Anterior [d] Próximo "<<stringCurtir<<" [c] Comentar Tweet "<<stringConcatenar<<"[s] sair do feed ";
        std::cin >> opcaoDigitada;
    }
}
/**
 * @brief Percorre o feed geral do usuário
 * 
 * @param listaUsuariosgeral Ponteiro para lista de usuarios registrados
 * @param ownner Usuario operante
 * 
 * @fn void Feed::percorrerFeedGeral(Usuario ownner, std::map<std::string, Usuario> *listaUsuariosGeral)
*/
void Feed::percorrerFeedGeral(Usuario ownner, std::map<std::string, Usuario> *listaUsuariosGeral){
    std::string opcaoDigitada;
    std::string stringConcatenar;
    int indiceTarget = this->popularFeed(ownner, *listaUsuariosGeral).size() - 1;
    std::vector<Tweet> vetorPercorrendo;
    /**< Loop para ações do usuário sob os tweets*/
    while( opcaoDigitada!="s"){
        stringConcatenar = "";
        vetorPercorrendo = this->popularFeed(ownner, *listaUsuariosGeral);
        if(vetorPercorrendo.size() > 0){
            std::system("clear");
            for (int i = vetorPercorrendo.size() - 1; i >= 0; i--) {
                if(i==indiceTarget){
                    std::cout << "➡️";
                }
                std::cout << vetorPercorrendo.at(i) << std::endl;
            }
            if(vetorPercorrendo.at(indiceTarget).getQntdComentarios() > 0){
                stringConcatenar = "[v] ver comentários ";
            }
            std::cout <<"[a] Anterior [d] Próximo [l] Curtir Tweet [c] Comentar Tweet "<<stringConcatenar<<"[s] sair do feed " << std::endl;
            std::cin >> opcaoDigitada;

            if(opcaoDigitada=="d" && indiceTarget>0){
                indiceTarget--;
            }
            if(opcaoDigitada=="a" && indiceTarget<vetorPercorrendo.size() - 1 ){
                indiceTarget++;
            }
            if(opcaoDigitada=="l"){
                std::string emailAutor = vetorPercorrendo.at(indiceTarget).getEmailAutor();
                std::vector<Tweet> vetorRecuperado = listaUsuariosGeral->at(emailAutor).getListaTweets();
                for(int i =0;i<vetorRecuperado.size();i++){
                    if(vetorRecuperado.at(i) == vetorPercorrendo.at(indiceTarget)){
                        vetorRecuperado.at(i).curtirTweet(ownner.getEmailUsuario());
                        listaUsuariosGeral->at(emailAutor).setListaTweets(vetorRecuperado);
                        break;
                    }
                }
            }
            if(opcaoDigitada=="c"){
                std::system("clear");
                char conteudoTweet[280] = {0};
                std::cout << "Digite sua resposta" << std::endl;
                std::cin.ignore();
                std::cin.getline(conteudoTweet, 280);
                Tweet novoTweet = * new Tweet(conteudoTweet, ownner.getNomeUsuario(), ownner.getNomePerfil(), ownner.getEmailUsuario());

                std::string emailAutor = vetorPercorrendo.at(indiceTarget).getEmailAutor();
                std::vector<Tweet> vetorRecuperado = listaUsuariosGeral->at(emailAutor).getListaTweets();
                for(int i =0;i<vetorRecuperado.size();i++){
                    if(vetorRecuperado.at(i) == vetorPercorrendo.at(indiceTarget)){
                        vetorRecuperado.at(i).comentarTweet(novoTweet);
                        listaUsuariosGeral->at(emailAutor).setListaTweets(vetorRecuperado);
                        break;
                    }
                }
            }
            if(opcaoDigitada=="v" && vetorPercorrendo.at(indiceTarget).getQntdComentarios() > 0){
                std::vector<Tweet> listaTweets = vetorPercorrendo.at(indiceTarget).getListaComentarios();
                this->percorrerFeed(ownner, &listaTweets);
                vetorPercorrendo.at(indiceTarget).setListaComentarios(listaTweets);
            }
        } else{
            std::string qualquerTecla;
            std::cout <<"Nenhum Tweet foi encontrado. Aperte qualquer tecla para voltar"<<std::endl;
            std::cin >> qualquerTecla;
            break;
        }
    }
}
