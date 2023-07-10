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
        std::vector<Tweet> popularFeed(Usuario user, std::map<std::string, Usuario> listaUsuariosGeral);
        void popularProprioFeed(Usuario user);
        void percorrerFeed(Usuario ownner, std::vector<Tweet> *vetorPercorrendo);
};
#endif
