#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <vector>

//#include "../include/ListaEncad.h"
//#include "../include/Conjunto.h"

//declarando que existe aqui para usar include somente no .cpp
class Usuario;

class Tweet{
    private:
        Usuario *autorTweet;
        std::string conteudoTweet;
        int qntdCurtidas;
        //talvez um conjunto de Usuario* de ruim, talvez mudar pra vector!
        //ListaEncad<Tweet> listaComentarios;
        std::vector<Usuario*> listaCurtidas;

    public:
        //Construtores e destrutor
        Tweet(Usuario autorTweet,  std::string conteudoTweet, int qntdCurtidas/*, ListaEncad<Tweet> listaComentarios*/);
        Tweet(void);
        ~Tweet(void);
        friend std::ostream& operator << (std::ostream &o, Tweet &tweet);
        bool operator == (Tweet &t);

        //Getters
        Usuario getAutorTweet();
        std::string getConteudoTweet();
        int getQntdCurtidas();
        std::vector<Usuario*> getListaCurtidas();
        //ListaEncad<Tweet> getListaComentarios();

        //Setters
        void setAutorTweet(Usuario autorTweet);
        void setConteudoTweet(std::string conteudoTweet);
        void setQntdCurtidas(int qntdCurtidas);
        void setListaCurtidas(std::vector<Usuario*>);
        //void setListaComentarios(ListaEncad<Tweet> listaComentarios);
        
        //Outros metodos
        void curtirTweet(Usuario user);
        void descurtirTweet(Usuario user);
        void comentarTweet(Tweet comentario);
        

};
#endif