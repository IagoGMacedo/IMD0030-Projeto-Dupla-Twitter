#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "../include/Controlador.h"
#define USERS_FILE "../data/Users.dat"

/*
    ideias
    pode fazer os codigos de input e output aqui local e só passar as infos pra classe OU
    fazer tudo no metodo da classe mesmo (fazerLogin e registrar)
    Usuario

    Utilizar arquivo em binário para salvar os dados de usuários
    usar o arquivo em formato txt para os testes

    talvez usar um hashmap ao inves de vector de usuario.
*/

Controlador::Controlador() {
    this->listaUsuariosGeral = * new std::vector<Usuario>();
    this->usuarioLogado = * new Usuario();
    this->feedUsuarioLogado = * new Feed();
}

Controlador::~Controlador() {
}


void lerListaUsuarios(std::vector<Usuario> listaUsuarios){
    std::fstream arquivoEmpregados;
    std::vector<Usuario> vetorUsuariosRecuperados = * new std::vector<Usuario>;
    arquivoEmpregados.open(USERS_FILE, std::ios::in | std::ios::binary);
    if(arquivoEmpregados.is_open()){
        arquivoEmpregados.read((char*)&vetorUsuariosRecuperados,sizeof(listaUsuarios));
        for(int i =0;i< vetorUsuariosRecuperados.size();i++){
            std::cout << vetorUsuariosRecuperados[i].getNomeUsuario() << std::endl;
        }
        std::cout << "programa feito com sucesso" << std::endl;
        
    }
    arquivoEmpregados.close();
}

void salvarListaUsuarios(std::vector<Usuario> listaUsuarios){
    std::fstream arquivoUsuarios;
    arquivoUsuarios.open(USERS_FILE, std::ios::out | std::ios::binary);
    if(arquivoUsuarios.is_open()){
        arquivoUsuarios.write((char*)&listaUsuarios,sizeof(listaUsuarios));
        std::cout << "arquivo salvo com sucesso" << std::endl;
        arquivoUsuarios.close();
    }
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
        //std::system("clear");

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
        /*
    ifstream file(USERS_FILE);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
    }
    else {
        //Inserção do conjunto de Usuarios no arquivo
        std::string line;
        while (file.getline(file, line.c_str())) {
            listaUsuariosGeral.inserir(line);
        }
        file.close();
        */

    }

    //Compara com o arquivo txt ou bin para ver se o login coincide
    //Se sim, popularFeed(Usuario)
    /*
    bool encontrado = buscarUsuario(USERS_FILE);
    if (encontrado) {
        std::cout << "Fazendo login" << std::endl;
        std::system(clear);
        this->feedUsuarioLogado.popularFeed();
    }
    */
    /*Se não chamar o fazer login novamente, e exibir mensagem de login ou senha incorretos
    else {
        std::cout << "Login ou senha incorretos" << std::endl;
        return fazerLogin();
    }
}

    */

void Controlador::registrar(){ 
    std::system("clear");
    std::string nomeUsuarioDigitado, nomePerfilDigitado, senhaDigitada, emailDigitado;

    std::cout << "Digite o seu nome:" << std::endl;
    std::cin >> nomeUsuarioDigitado;

    std::cout << "Digite o nome do seu perfil (apelido):" << std::endl;
    std::cin >> nomePerfilDigitado;

    std::cout << "Digite a sua senha:" << std::endl;
    std::cin >> senhaDigitada;

    std::cout << "Digite o seu email:" << std::endl;
    std::cin >> emailDigitado;

    Usuario novoUsuario = * new Usuario(nomeUsuarioDigitado, nomePerfilDigitado, emailDigitado,  senhaDigitada);
    
    this->listaUsuariosGeral.push_back(novoUsuario);
    Tweet novoTweet = * new Tweet(novoUsuario, "primeiro tweet", 0);
    novoUsuario.addTweet(novoTweet);
    for(int i =0;i<listaUsuariosGeral.size();i++){
        std::cout << listaUsuariosGeral[i].getNomeUsuario() <<", "<<listaUsuariosGeral[i].getEmailUsuario()<<std::endl;
        for(int i =0;i<novoUsuario.getQntdTweets();i++){
            std::cout << novoUsuario.getListaTweets()[i].getConteudoTweet() <<std::endl;
        }
    }
    std:: cout << "--------------"<< std::endl;
    salvarListaUsuarios(this->listaUsuariosGeral);
    //lerListaUsuarios(this->listaUsuariosGeral); tá dando segmentation fault

    std::cout << "Usuário " << novoUsuario.getNomeUsuario() << " criado com sucesso, aperte qualquer tecla para fazer login" << std::endl;
    std::cin >> emailDigitado;

}

int main(){
    Controlador controlador = * new Controlador();
    controlador.iniciarPrograma();

    return 0;
}

