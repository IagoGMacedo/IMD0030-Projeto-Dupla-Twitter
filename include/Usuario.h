#ifndef USUARIO_H
#define USUARIO_H

#include "../include/Helper.h"
#include "../include/ListaEncad.h"
#include "../include/Conjunto.h"
#include <iostream>
using namespace std;

class Usuario {
private:
    std::string nomePerfil;
    Conjunto<Tweet> listaTweets;
    int qntdSeguidores;
    int qntdSeguindo;
    Conjunto<Usuario> listaSeguindo;
    Conjunto<Usuario> listaSeguidores;
    Conjunto<Usuario> listaBloqueados;
    std::string email;
    std::string nomeUsuario;

public:
    //Construtores e destrutor
    Usuario(std::string nomePerfil, Conjunto<Tweet> listaTweets, int qntdSeguidores, int qntdSeguindo, Conjunto<Usuario> listaSeguindo, Conjunto<Usuario> listaSeguidores , Conjunto<Usuario> listaBloqueados, std::string email, std::string nomeUsuario);
    Usuario(std::string nomePerfil, std::string email, std::string nomeUsuario);
    Usuario();
    ~Usuario();

    //Getters
    std::string getNomePerfil();
    Conjunto<Tweet> getListaTweets();
    int getQntdSeguidores();
    int getQntdSeguindo();
    Conjunto<Usuario> getListaSeguindo();
    Conjunto<Usuario> getListaSeguidores();
    Conjunto<Usuario> getListaBloqueados();
    std::string getEmail();
    std::string getNomeUsuario();

    //Setters
    void setNomePerfil(std::string nomePerfil);
    void setListaTweets(Conjunto<Tweet> listaTweets);
    void setQntdSeguidores(int qntdSeguidores);
    void setQntdSeguindo(int qntdSeguindo);
    void setListaSeguindo(Conjunto<Usuario> listaSeguindo);
    void setListaSeguidores(Conjunto<Usuario> listaSeguidos);
    void setListaBloqueados(Conjunto<Usuario> listaBloqueados);
    void setEmail(std::string email);
    void setNomeUsuario(std::string nomeUsuario);

    //Outros Metodos
    void deletarUsuario(std::string confirmacao);
    void seguirUsuario(Usuario user, Usuario ownner);
    void deixarDeSeguir(Usuario user, Usuario ownner);
    void bloquearUsuario(Usuario user);

};

#endif