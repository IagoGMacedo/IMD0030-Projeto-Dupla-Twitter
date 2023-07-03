#ifndef TWEET_H
#define TWEET_H

#include <iostream>
//#include "../include/ListaEncad.h"
#include "../include/Conjunto.h"
#include "../include/Usuario.h"



class Tweet{
    private:
        Usuario autorTweet;
        std::string conteudoTweet;
        int qntdCurtidas;
        Conjunto<Usuario> listaCurtidas;
        ListaEncad<Tweet> listaComentarios;

    public:
        //Construtores e destrutor
        Tweet(Usuario autorTweet,  std::string conteudoTweet, int qntdCurtidas/*, ListaEncad<Tweet> listaComentarios*/);
        Tweet(void);
        ~Tweet(void);
        friend std::ostream& operator << (std::ostream &o, Tweet &tweet);

        //Getters
        Usuario getAutorTweet();
        std::string getConteudoTweet();
        int getQntdCurtidas();
        ListaEncad<Tweet> getListaComentarios();

        //Setters
        void setAutorTweet(Usuario autorTweet);
        void setConteudoTweet(std::string conteudoTweet);
        void setQntdCurtidas(int qntdCurtidas);
        void setListaComentarios(ListaEncad<Tweet> listaComentarios);
        
        //Outros metodos
        void curtirTweet(Usuario user);
        void descurtirTweet(Usuario user);
        void comentarTweet(Tweet comentario);
        

};
#endif