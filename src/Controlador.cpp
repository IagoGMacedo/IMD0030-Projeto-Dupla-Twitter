#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
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
        arquivoEmpregados.read((char*)&vetorUsuariosRecuperados,sizeof(listaUsuarios));
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
        std::cout << "Usuário "<<novoUsuario.getNomeUsuario() <<" criado com sucesso" << std::endl;
        //fazerTestes(novoUsuario);
    }
    //salvarListaUsuarios(this->listaUsuariosGeral);
   // lerListaUsuarios(this->listaUsuariosGeral);
    std::cout << "aperte qualquer tecla para voltar ao menu inicial" << std::endl;
    std::cin >> emailDigitado;
}

//função só pra gente testar outros metodos
void Controlador::fazerTestes(){
   Usuario maisNovoUsuario = * new Usuario("iago", "iagola", "iagognobre@gmail.com", "123456");
   this->listaUsuariosGeral.insert({maisNovoUsuario.getEmailUsuario(), maisNovoUsuario});

   //criando tweet
   Tweet tweet = * new Tweet(maisNovoUsuario, "vai tomar no cu eu odeio essa linguagem");

   //tentando ver o autor desse tweet
   Usuario autorTweet = tweet.getAutorTweet();
   std::cout << "corno: " << autorTweet.getNomeUsuario() << std::endl;

   //iterando usuarios
   maisNovoUsuario.addTweet(tweet);

   //pegando o desse vetor
   std::vector<Tweet> listaTweets = maisNovoUsuario.getListaTweets();
   for(int i =0;i<listaTweets.size();i++){
        std::cout << listaTweets.at(i).printarTweet() << std::endl;
    }

}

int main(){
    Controlador controlador = * new Controlador();
    controlador.iniciarPrograma();

    //controlador.fazerTestes();
    return 0;
}

void Controlador::iniciarSessao(){
    std::string opcaoDigitada;
    while(opcaoDigitada!="4"){
        std::system("clear");
        std::cout << "Seja bem vindo," << this->usuarioLogado.getNomeUsuario() << std::endl;
        std::cout << "O que deseja fazer??" << std::endl;
        std::cout << "[1] Escrever Tweet" << std::endl;
        std::cout << "[2] Acessar Feed" << std::endl;
        std::cout << "[3] Pesquisar Usuário" << std::endl;
        std::cout << "[4] Encerrar Sessão" << std::endl;
        std::cin >>opcaoDigitada;

        if (opcaoDigitada == "1") {
            std::system("clear");
            std::string conteudoTweet;
            std::cout << "O que está pensando? " << std::endl;
            std::cin >> conteudoTweet;
            Tweet novoTweet = *new Tweet(usuarioLogado, conteudoTweet);
            usuarioLogado.addTweet(novoTweet);

        } else if (opcaoDigitada == "2") {
            std::system("clear");
            this->feedUsuarioLogado.popularFeed(this->usuarioLogado);
            std::cout << "Pressione qualquer tecla para voltar" << std::endl;
            std::cin >>opcaoDigitada;

        } else if(opcaoDigitada == "3"){
            std::string profileName;
            std::cout << "Insira o nome do usuário que deseja pesquisar: " << std::endl;
            std::cin >> profileName;

            for (auto user : listaUsuariosGeral) {
                if (user.second.getNomePerfil() == profileName) {
                    std::system("clear");
                    std::cout << user.second;

                    std::string opcaoDigitada1;
                    while (opcaoDigitada1 != "6") {
                        std::cout << "O que deseja fazer??\n" 
                        << "[1] Explorar Tweets\n" 
                        << "[2] Seguir Usuario\n" 
                        << "[3] Deixar de Seguir\n" 
                        << "[4] Bloquear Usuario\n"
                        << "[5] Desbloquear Usuario\n"
                        << "[6] Sair do Perfil\n"
                        << std::endl;
                        std::cin >> opcaoDigitada1;

                        if (opcaoDigitada1 == "1") { 
                            for (int i = 0; i < user.second.getQntdTweets(); i++) {
                                std::cout << user.second.getListaTweets()[i];
                                
                                std::string opcaoDigitada2;
                                while (opcaoDigitada2 != "4") {
                                    std::cout << "\nO que deseja fazer??\n" 
                                    << "[1] Curtir\n" 
                                    << "[2] Comentar\n" 
                                    << "[3] Exibir Comentários\n" 
                                    << "[4] Próximo Tweet\n"
                                    << std::endl;
                                    std::cin >> opcaoDigitada2;
                                } 
                            }
                        }

                        else if (opcaoDigitada1 == "2") { 
                            usuarioLogado.seguirUsuario(user.second, usuarioLogado);
                        }

                        else if (opcaoDigitada1 == "3") { 
                            usuarioLogado.deixarDeSeguir(user.second, usuarioLogado);
                        }

                        else if (opcaoDigitada1 == "4") { 
                            usuarioLogado.bloquearUsuario(user.second);
                        }

                        else if (opcaoDigitada1 == "5") { 
                            usuarioLogado.desbloquearUsuario(user.second);
                        }

                        else if (opcaoDigitada == "6") { 
                            break;
                        }
                    }
                    
                }
            }
            
            //OperarTweet
        }

        
    }
}


