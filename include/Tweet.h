#ifndef TWEET_H
#define FEED_H

#include "iostream"
#include <Usuario.h>
#include <ListaEncad.h>

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