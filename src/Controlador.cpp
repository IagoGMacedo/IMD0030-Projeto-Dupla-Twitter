#include <iostream>
#include "../include/Controlador.h"

Controlador::Controlador() {
}

Controlador::~Controlador() {
}

void Controlador::iniciarPrograma(){
    std::cout << "programa iniciado!" << std::endl;
}

int main(){
    Controlador controlador;
    controlador.iniciarPrograma();

    return 0;
}