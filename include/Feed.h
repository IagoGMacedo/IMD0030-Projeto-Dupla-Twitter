#ifndef FEED_H
#define FEED_H

#include "../include/Conjunto.h"
#include "../include/Usuario.h"
#include <vector>


class Feed {
    private:
        std::vector<Tweet> listaTweets;
        std::vector<Usuario> listaUsuarios;

    public:
        Feed();
        ~Feed();
        void popularFeed(Usuario user, std::map<std::string, Usuario> listaUsuariosGeral);

    
};
#endif
