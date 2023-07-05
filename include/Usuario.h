#ifndef USUARIO_H
#define USUARIO_H

#include "../include/Helper.h"
#include "../include/ListaEncad.h"
//#include "../include/std::vector.h"
#include "../include/Tweet.h"
#include <iostream>
#include <vector>


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
    std::vector<Usuario> listaSeguindo;
    std::vector<Usuario> listaSeguidores;
    std::vector<Usuario> listaBloqueados;
    
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
    std::vector<Usuario> getListaSeguindo();
    std::vector<Usuario> getListaSeguidores();
    std::vector<Usuario> getListaBloqueados();
    std::string getEmailUsuario();
    std::string getNomeUsuario();
    int getQntdTweets();

    //Setters
    void setNomePerfil(std::string nomePerfil);
    void setListaTweets(std::vector<Tweet> listaTweets);
    void setQntdSeguidores(int qntdSeguidores);
    void setQntdSeguindo(int qntdSeguindo);
    void setListaSeguindo(std::vector<Usuario> listaSeguindo);
    void setListaSeguidores(std::vector<Usuario> listaSeguidos);
    void setListaBloqueados(std::vector<Usuario> listaBloqueados);
    void setEmailUsuario(std::string emailUsuario);
    void setNomeUsuario(std::string nomeUsuario);
    void setQntdTweets(int novaQuantidade);

    //Outros Metodos
    void deletarUsuario(std::string confirmacao);
    void seguirUsuario(Usuario user, Usuario ownner);
    void deixarDeSeguir(Usuario user, Usuario ownner);
    void bloquearUsuario(Usuario user);
    void addTweet(Tweet novoTweet);
    bool conferirSenha(std::string senhaDigitada);
    
};

#endif