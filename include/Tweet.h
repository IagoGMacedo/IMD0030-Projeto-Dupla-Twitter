#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <vector>
#include <map>
/**
 * @brief Arquivo cabeçalho de Tweet.cpp
 * @headerfile Tweet.h
*/
class Tweet{
    private:

        std::string nomeUsuarioAutor;
        std::string nomePerfilAutor;
        std::string emailAutor;

        std::string conteudoTweet;
        int qntdCurtidas;
        int qntdComentarios;

        std::vector<std::string> listaCurtidas;

        std::vector<Tweet> listaComentarios;

        //lista de reTweets
        std::vector<std::string>listaReTweets;

    public:
        //Construtores e destrutor
        Tweet(std::string conteudoTweet);
        Tweet(std::string conteudoTweet, std::string nomeUsuarioAutor, std::string nomePerfilAutor, std::string emailAutor);
        Tweet(void);
        ~Tweet(void);
        friend std::ostream& operator << (std::ostream &o, Tweet &tweet);
        bool operator == (Tweet &t);

        //Getters
        std::string getConteudoTweet();
        int getQntdCurtidas();
        int getQntdReTweets();
        std::string getNomeUsuarioAutor();
        std::string getNomePerfilAutor();
        std::string getEmailAutor();
        std::vector<Tweet> getListaComentarios();
        std::vector<std::string> getListaCurtida();
        int getQntdComentarios();


        //Setters
        void setConteudoTweet(std::string conteudoTweet);
        void setQntdCurtidas(int qntdCurtidas);
        void setListaComentarios(std::vector<Tweet>);
        void setQntdComentarios(int qntdComentarios);
        
        //Outros metodos
        void curtirTweet(std::string emailUsuario);
        void descurtirTweet(std::string emailUsuario);
        void comentarTweet(Tweet comentario);
        bool reTweet(std::string emailUsuario);
        std::string printarTweet();
        std::vector<Tweet*> getListaComentariosPonteiros();
        bool usuarioJacurtiu(std::string emailUsuario);
        

};
#endif