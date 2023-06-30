#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../include/Usuario.h"
#include "../include/Feed.h"

class Controlador{
    private:
        Usuario usuarioLogado;
        Feed feedUsuarioLogado;
        //Conjunto<Usuario> listaUsuariosGeral;
    public:
        void fazerLogin();
        void registrar();
        void encerrarSessao();
        void iniciarPrograma();
        Controlador();
        ~Controlador();
};

#endif