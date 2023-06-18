#ifndef USUARIO_H
#define USUARIO_H

#include <Conjunto.h>

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
        void deletarUsuario(); 
        void seguirUsuario(Usuario user); 
        void bloquearUsuario(Usuario user); 
};

#endif