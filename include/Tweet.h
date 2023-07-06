#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <vector>
#include <map>

//declarando que existe aqui para usar include somente no .cpp
class Usuario;

class Tweet{
    private:
        Usuario *autorTweet;
        std::string conteudoTweet;
        int qntdCurtidas;
        std::map<std::string, Usuario> listaCurtidas;
        std::vector<Tweet*> listaComentarios;

    public:
        //Construtores e destrutor
        Tweet(Usuario autorTweet,  std::string conteudoTweet);
        Tweet(void);
        ~Tweet(void);
        friend std::ostream& operator << (std::ostream &o, Tweet &tweet);
        bool operator == (Tweet &t);

        //Getters
        Usuario getAutorTweet();
        std::string getConteudoTweet();
        int getQntdCurtidas();
        std::map<std::string, Usuario> getListaCurtidas();
        std::vector<Tweet*> getListaComentarios();

        //Setters
        void setAutorTweet(Usuario autorTweet);
        void setConteudoTweet(std::string conteudoTweet);
        void setQntdCurtidas(int qntdCurtidas);
        void setListaCurtidas(std::map<std::string, Usuario> listaCurtidas);
        void setListaComentarios(std::vector<Tweet*>);
        
        //Outros metodos
        void curtirTweet(Usuario user);
        void descurtirTweet(Usuario user);
        void comentarTweet(Tweet *comentario);
        std::string printarTweet();
        

};
#endif