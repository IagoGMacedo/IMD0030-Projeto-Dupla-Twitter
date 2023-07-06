#ifndef USUARIO_H
#define USUARIO_H

#include "../include/Helper.h"
#include "../include/ListaEncad.h"
//#include "../include/std::vector.h"
#include "../include/Tweet.h"
#include <iostream>
#include <vector>
#include <map>

class Usuario {
private:
    std::string nomePerfil;
    std::string nomeUsuario;
    std::string senhaUsuario;
    std::string emailUsuario;

    int qntdSeguidores;
    int qntdSeguindo;
    int qntdTweets;
    
    std::vector<Tweet> listaTweets;
    std::map<std::string, Usuario> listaSeguindo;
    std::map<std::string, Usuario> listaSeguidores;
    std::map<std::string, Usuario> listaBloqueados;
    
public:
    //Construtores e destrutor
    Usuario(std::string nomeUsuario, std::string nomePerfil, std::string emailUsuario, std::string senhaUsuario);
    Usuario(void);
    ~Usuario();
    friend std::ostream& operator << (std::ostream &o, Usuario &user);
    bool operator == (Usuario &u);

    //Getters
    std::string getNomePerfil();
    std::vector<Tweet> getListaTweets();
    int getQntdSeguidores();
    int getQntdSeguindo();
    std::map<std::string, Usuario> getListaSeguindo();
    std::map<std::string, Usuario> getListaSeguidores();
    std::map<std::string, Usuario> getListaBloqueados();
    std::string getEmailUsuario();
    std::string getNomeUsuario();
    int getQntdTweets();

    //Setters
    void setNomePerfil(std::string nomePerfil);
    void setListaTweets(std::vector<Tweet> listaTweets);
    void setQntdSeguidores(int qntdSeguidores);
    void setQntdSeguindo(int qntdSeguindo);
    void setListaSeguindo(std::map<std::string, Usuario> listaSeguindo);
    void setListaSeguidores(std::map<std::string, Usuario> listaSeguidos);
    void setListaBloqueados(std::map<std::string, Usuario> listaBloqueados);
    void setEmailUsuario(std::string emailUsuario);
    void setNomeUsuario(std::string nomeUsuario);
    void setQntdTweets(int novaQuantidade);

    //Outros Metodos
    void deletarUsuario(std::string confirmacao);
    void seguirUsuario(Usuario user, Usuario ownner);
    void deixarDeSeguir(Usuario user, Usuario ownner);
    void bloquearUsuario(Usuario user);
    void desbloquearUsuario(Usuario user);
    void addTweet(Tweet novoTweet);
    bool conferirSenha(std::string senhaDigitada);
    
};

#endif