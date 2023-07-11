#ifndef FEED_H
#define FEED_H

#include "../include/Usuario.h"
#include <vector>

/**
 * @brief Arquivo cabeçalho de Feed.cpp
 * @headerfile Feed.h
*/

class Feed {
    public:
        Feed();
        ~Feed();
        std::vector<Tweet> popularFeed(Usuario user, std::map<std::string, Usuario> listaUsuariosGeral);
        void percorrerFeed(Usuario ownner, std::vector<Tweet> *vetorPercorrendo);
        void percorrerFeedGeral(Usuario ownner, std::map<std::string, Usuario> *listaUsuariosGeral);
};
#endif
