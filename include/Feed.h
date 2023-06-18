#ifndef FEED_H
#define FEED_H

#include <Conjunto.h>
#include <Tweet.h>
#include <Usuario.h>


class Feed{
    private:
        Conjunto<Tweet> listaTweets;
        Conjunto<Usuario> listaUsuario;
    public:
        void popularFeed(Usuario user);
};
#endif
