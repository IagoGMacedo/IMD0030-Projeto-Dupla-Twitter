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
    this->listaUsuariosGeral = * new std::map<std::string, Usuario>();
    this->usuarioLogado = * new Usuario();
    this->feedUsuarioLogado = * new Feed();
}

Controlador::~Controlador() {
}


void lerListaUsuarios(std::map<std::string,Usuario> listaUsuarios){
    std::fstream arquivoEmpregados;
    std::map<std::string, Usuario> vetorUsuariosRecuperados = * new std::map<std::string, Usuario>;
    arquivoEmpregados.open(USERS_FILE, std::ios::in | std::ios::binary);
    if(arquivoEmpregados.is_open()){
        arquivoEmpregados.read((char*)&vetorUsuariosRecuperados,sizeof(vetorUsuariosRecuperados));
        for(auto i : vetorUsuariosRecuperados){
            std::cout << i.second.getNomeUsuario() << std::endl;
        }
        std::cout << "programa feito com sucesso" << std::endl;
        
    }
    arquivoEmpregados.close();
}

void salvarListaUsuarios(std::map<std::string,Usuario> listaUsuarios){
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
    std::string emailDigitado, senhaDigitada;


    std::cout << "Digite o seu email:" << std::endl;
    std::cin >> emailDigitado;
    std::cout << "Digite a sua senha:" << std::endl;
    std::cin >> senhaDigitada;

    auto contaExiste = this->listaUsuariosGeral.find(emailDigitado);
    if(contaExiste != this->listaUsuariosGeral.end()){
        if(this->listaUsuariosGeral.at(emailDigitado).conferirSenha(senhaDigitada)){
            //login deu certo 
            //mandar ele para pagina inicial do programa
            std::cout << "login realizado com sucesso !" << std::endl;
            this->usuarioLogado = this->listaUsuariosGeral.at(emailDigitado);
            this->iniciarSessao();
        } else{
            std::cout << "Senha inválida" << std::endl;
        }
    } else{
        std::cout << "Email inválido" << std::endl;
    }
    std::cout << "aperte qualquer tecla para voltar ao menu inicial" << std::endl;
    std::cin >> emailDigitado;
    
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
    //vou verificar se já não existe alguma conta com esse email, caso exista, reclama!
    auto emailJaExiste = this->listaUsuariosGeral.find(emailDigitado);
    if(emailJaExiste != this->listaUsuariosGeral.end()){
        std::cout << "Esse email já existe, use outro" << std::endl;
    } else{
        Usuario novoUsuario = * new Usuario(nomeUsuarioDigitado, nomePerfilDigitado, emailDigitado,  senhaDigitada);
        this->listaUsuariosGeral.insert({novoUsuario.getEmailUsuario(), novoUsuario});
        Tweet novoTweet = * new Tweet(novoUsuario, "primeiro tweet");
        novoUsuario.addTweet(novoTweet);
        //for(int i =0;i<listaUsuariosGeral.size();i++){
        std::cout << "Usuário "<<novoUsuario.getNomeUsuario() <<" criado com sucesso" << std::endl;
        for(auto i :this->listaUsuariosGeral){
            std::cout <<i.second.getNomeUsuario() <<", "<<i.second.getEmailUsuario()<<std::endl;
            for(int i =0;i<novoUsuario.getQntdTweets();i++){
                std::cout << novoUsuario.getListaTweets()[i].getConteudoTweet() <<std::endl;
            }
        }
    }
    std:: cout << "--------------"<< std::endl;
    salvarListaUsuarios(this->listaUsuariosGeral);
    std:: cout << "--------------"<< std::endl;
    lerListaUsuarios(this->listaUsuariosGeral);

    std::cout << "aperte qualquer tecla para voltar ao menu inicial" << std::endl;
    std::cin >> emailDigitado;
}

int main(){
    Controlador controlador = * new Controlador();
    controlador.iniciarPrograma();
    return 0;
}

void Controlador::iniciarSessao(){
    std::string opcaoDigitada;
    while(opcaoDigitada!="3"){
        std::system("clear");
        std::cout << "Seja bem vindo," << this->usuarioLogado.getNomeUsuario() << std::endl;
        std::cout << "O que deseja fazer??" << std::endl;
        std::cout << "[1] Escrever Tweet" << std::endl;
        std::cout << "[2] Acessar Feed" << std::endl;
        std::cout << "[3] Encerrar Sessão" << std::endl;
        std::cin >>opcaoDigitada;

        if (opcaoDigitada == "1") {
            std::system("clear");
            std::string conteudoTweet;
            std::cout << "O que está pensando? " << std::endl;
            std::cin >> conteudoTweet;

            Tweet novoTweet = *new Tweet(usuarioLogado, conteudoTweet);

            usuarioLogado.addTweet(novoTweet);
        }

        if (opcaoDigitada == "2") {
            std::system("clear");
            //PopularFeed() e tal
        }
    }
}


