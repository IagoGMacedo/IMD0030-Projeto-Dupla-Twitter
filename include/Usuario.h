#ifndef USUARIO_H
#define USUARIO_H

#include "../include/Tweet.h"
#include <iostream>
#include <vector>
#include <map>
/**
 * @brief Arquivo cabeçalho de Usuario.cpp
 * @headerfile Usuario.h
*/
class Usuario {
private:
    std::string nomePerfil;
    std::string nomeUsuario;
    std::string senhaUsuario;
    std::string emailUsuario;
    
    std::vector<Tweet> listaTweets;
    std::map<std::string, Usuario> listaSeguindo;
    std::map<std::string, Usuario> listaSeguidores;
    
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
    std::string getEmailUsuario();
    std::string getNomeUsuario();
    int getQntdTweets();

    //Setters
    void setNomePerfil(std::string nomePerfil);
    void setListaTweets(std::vector<Tweet> listaTweets);
    void setListaSeguindo(std::map<std::string, Usuario> listaSeguindo);
    void setListaSeguidores(std::map<std::string, Usuario> listaSeguidos);
    void setEmailUsuario(std::string emailUsuario);
    void setNomeUsuario(std::string nomeUsuario);
    bool updtListaSeguidores(Usuario, std::string);
    bool updtListaSeguindo(Usuario, std::string);

    //Outros Metodos
    bool deletarUsuario(std::string confirmacao);
    bool seguirUsuario(Usuario *user, Usuario ownner);
    bool deixarDeSeguir(Usuario *user, Usuario ownner);
    void addTweet(Tweet novoTweet);
    bool conferirSenha(std::string senhaDigitada);
    bool estaSeguindoUsuario(std::string emailUsuario);
    
};

#endif