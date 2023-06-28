#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../include/Usuario.h"
#include "../include/Feed.h"

class Controlador{
    private:
        Usuario usuarioLogado;
        Feed feedUsuarioLogado;
    public:
        void fazerLogin(std::string nomeUsuario, std::string senhaUsuario);
        void encerrarSessao();
        void iniciarPrograma();
        Controlador();
        ~Controlador();
};
#endif