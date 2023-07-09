#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <vector>
#include <map>

//declarando que existe aqui para usar include somente no .cpp
class Usuario;

class Tweet{
    private:
        // Usuario *autorTweet;

        //apenas testando!
        std::string nomeUsuarioAutor;
        std::string nomePerfilAutor;
        std::string emailAutor;

        std::string conteudoTweet;
        int qntdCurtidas;
        int qntdComentarios;

        //std::map<std::string, Usuario> listaCurtidas;
        std::vector<std::string> listaCurtidas;

        //listaComentarios pode ser um hash com o email
        std::vector<Tweet> listaComentarios;

    public:
        //Construtores e destrutor
        Tweet(std::string conteudoTweet);
        Tweet(std::string conteudoTweet, std::string nomeUsuarioAutor, std::string nomePerfilAutor, std::string emailAutor);
        // Tweet(Usuario autorTweet,  std::string conteudoTweet);
        Tweet(void);
        ~Tweet(void);
        friend std::ostream& operator << (std::ostream &o, Tweet &tweet);
        bool operator == (Tweet &t);

        //Getters
        //Usuario getAutorTweet();
        std::string getConteudoTweet();
        int getQntdCurtidas();
        //std::map<std::string, Usuario> getListaCurtidas();
        std::vector<Tweet> getListaComentarios();
        int getQntdComentarios();


        //Setters
        //void setAutorTweet(Usuario autorTweet);
        void setConteudoTweet(std::string conteudoTweet);
        void setQntdCurtidas(int qntdCurtidas);
        void setListaCurtidas(std::map<std::string, Usuario> listaCurtidas);
        void setListaComentarios(std::vector<Tweet>);
        void setQntdComentarios(int qntdComentarios);
        
        //Outros metodos
        void curtirTweet(std::string emailUsuario);
        void descurtirTweet(Usuario user);
        void comentarTweet(Tweet comentario);
        std::string printarTweet();
        

};
#endif