#ifndef FEED_H
#define FEED_H

#include "../include/Conjunto.h"
#include "../include/Tweet.h"
#include "../include/Usuario.h"



class Feed {
    private:
        Conjunto<Tweet> listaTweets;
        Conjunto<Usuario> listaUsuarios;

    public:
        Feed();
        ~Feed();
        void popularFeed(Usuario user);
    
};
#endif
