#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include "../include/ListaEncad.h"
#include "../include/Conjunto.h"
#include "../include/Usuario.h"


class Tweet{
    private:
        //Usuario autorTweet;
        std::string conteudoTweet;
        int qntdCurtidas;
        //Conjunto<Usuario> listaCurtidas;
        ListaEncad<Tweet> listaComentarios;

    public:
        //Construtores e destrutor
        Tweet(/*Usuario autorTweet, */ std::string conteudoTweet, int qntdCurtidas, ListaEncad<Tweet> listaComentarios);
        Tweet(void);
        ~Tweet(void);

        //Getters
        //Usuario getAutorTweet();
        std::string getConteudoTweet();
        int getQntdCurtidas();
        ListaEncad<Tweet> getListaComentarios();

        //Setters
        //void getAutorTweet(Usuario autorTweet);
        void getConteudoTweet(std::string conteudoTweet);
        void getQntdCurtidas(int qntdCurtidas);
        void getListaComentarios(ListaEncad<Tweet> listaComentarios);

        //Outros metodos
        //void curtirTweet(Usuario user);
        //void descurtirTweet(Usuario user);
        void comentarTweet(Tweet comentario);

};
#endif