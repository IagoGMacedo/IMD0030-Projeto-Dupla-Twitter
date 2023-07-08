#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../include/Usuario.h"
#include "../include/Feed.h"
#include "../include/Conjunto.h"
#include <map>


class Controlador{
    private:
        Usuario usuarioLogado;
        Feed feedUsuarioLogado;
        std::map<std::string, Usuario> listaUsuariosGeral;
    public:
        void fazerLogin();
        void registrar();
        void iniciarSessao();
        void encerrarSessao();
        void iniciarPrograma();
        Controlador();
        ~Controlador();
        void fazerTestes();
};

#endif