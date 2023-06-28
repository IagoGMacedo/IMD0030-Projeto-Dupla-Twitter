#ifndef TWEET_H
#define TWEET_H

#include "../include/Usuario.h"
#include "../include/ListaEncad.h"
#include <iostream>


class Tweet{
    private:
        Usuario autorTweet;
        std::string conteudoTweet;
        int qntdCurtidas;
        ListaEncad<Tweet> listaComentarios;

    public:
        Tweet(void);
        ~Tweet(void);
        void curtirTweet(Usuario user);
        void comentarTweet(Usuario user);

};
#endif