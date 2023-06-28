#include "../include/Controlador.h"

void Controlador::iniciarPrograma(){
    std::cout << "programa iniciado!" << std::endl;
}

int main(){
    Controlador controlador;
    controlador.iniciarPrograma();
    return 0;
}