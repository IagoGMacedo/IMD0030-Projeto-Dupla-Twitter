#include <iostream>
#include <iomanip>
#include <string>
#include "../include/Controlador.h"


/*
    ideias
    pode fazer os codigos de input e output aqui local e só passar as infos pra classe OU
    fazer tudo no metodo da classe mesmo (fazerLogin e registrar)

*/

Controlador::Controlador() {
    //this->listaUsuariosGeral=Conjunto<Usuario>(10);
}

Controlador::~Controlador() {
}

void Controlador::iniciarPrograma(){
    std::string stringEntrada;

    std::cout << "programa iniciado!" << std::endl;

    bool encerrarPrograma = false;
    while(!encerrarPrograma){
        std::cout << "Faça login ou registre-se para acessar o Twitter." << std::endl;
        std::cout << "[1] Fazer login" << std::endl;
        std::cout << "[2] Registre-se" << std::endl;
        std::cout << "[3] Encerrar programa" << std::endl;
        std::cin >> stringEntrada;
        std::system("clear");
        if(stringEntrada.length() > 1)
            stringEntrada = "0";
        switch(stringEntrada[0]){
            case '1':
                this->fazerLogin();
            break;
            case '2':
                this->registrar();
            break;
            case '3':
                std::cout << "Programa encerrado" << std::endl;
                encerrarPrograma = true;
            break;
            default:
                std::cout << "Insira um dos valores esperados" << std::endl;
            break;
        }
        std::system("clear");
        //std::cout << "digitado: ," <<stringEntrada<<"," <<std::endl;
    }

    
}

void Controlador::fazerLogin(){
    std::system("clear");
    std::string usuarioDigitado;
    std::string senhaDigitada;


    std::cout << "Digite o seu usuario:" << std::endl;
    std::cin >> usuarioDigitado;
    std::cout << "Digite a sua senha:" << std::endl;
    std::cin >> senhaDigitada;

    std::cout << "usuario:" << usuarioDigitado <<std::endl;
    std::cout << "senha:" << senhaDigitada<<std::endl;

}

void Controlador::registrar(){ 
    std::system("clear");
    std::string nomeUsuarioDigitado;
    std::string nomePerfilDigitado;
    std::string senhaDigitada;
    std::string emailDigitado;

    std::cout << "Digite o seu nome:" << std::endl;
    std::cin >> nomeUsuarioDigitado;
    std::cout << "Digite o nome do seu perfil (apelido):" << std::endl;
    std::cin >> nomePerfilDigitado;
    std::cout << "Digite a sua senha:" << std::endl;
    std::cin >> senhaDigitada;
    std::cout << "Digite o seu email:" << std::endl;
    std::cin >> emailDigitado;
    Usuario novoUsuario(nomeUsuarioDigitado, nomePerfilDigitado, emailDigitado,  senhaDigitada);
    std:: cout << novoUsuario.getemailUsuario() << std::endl;
    std::cout << "Usuário criado com sucesso, aperte qualquer tecla para fazer login" << std::endl;
    std::cin >> emailDigitado;
}

int main(){
    Controlador controlador;
    controlador.iniciarPrograma();

    return 0;
}