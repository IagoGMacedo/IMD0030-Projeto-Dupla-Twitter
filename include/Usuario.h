#ifndef USUARIO_H
#define USUARIO_H

#include "../include/Conjunto.h"
#include "../include/Tweet.h"
#include <iostream>

class Usuario{
    private:
        std::string nomeUsuario;
        std::string senhaUsuario;
        int qntdSeguidores; 
        int qntdSeguindo; 
        Conjunto<Tweet> listaTweets;
        Conjunto<Usuario> ListaUsuariosSeguindo;
        Conjunto<Usuario> ListaUsuariosSeguidores;
        std::string emailUsuario; 
    public:
        Usuario();
        ~Usuario();
        void deletarUsuario(); 
        void seguirUsuario(Usuario user); 
        void bloquearUsuario(Usuario user); 
};

#endif