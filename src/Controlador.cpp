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
    std::system("clear");
    Usuario usuarioIago = * new Usuario("iagola", "iago", "iagognobre@gmail.com", "87020586");
    Usuario usuarioGilberto = * new Usuario("gilbertin","gilberto","gilberto@gmail.com", "87020586");

    //botando isso aqui pra facilitar testes, tirar depois
    this->listaUsuariosGeral.insert({usuarioIago.getEmailUsuario(),usuarioIago});
    this->listaUsuariosGeral.insert({usuarioGilberto.getEmailUsuario(), usuarioGilberto});


    bool encerrarPrograma = false;
    while(!encerrarPrograma){
        std::system("figlet Twitter");
        std::cout << "Faça login ou registre-se para acessar a plataforma." << std::endl;
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
    bool nomeUsuarioRepetido = false;
    std::system("clear");
    std::string nomeUsuarioDigitado, nomePerfilDigitado, senhaDigitada, emailDigitado;

    std::cout << "Digite o nome do seu usuário:" << std::endl;
    std::cin >> nomeUsuarioDigitado;

    std::cout << "Digite o nome do seu perfil (apelido):" << std::endl;
    std::cin >> nomePerfilDigitado;

    std::cout << "Digite a sua senha:" << std::endl;
    std::cin >> senhaDigitada;

    std::cout << "Digite o seu email:" << std::endl;
    std::cin >> emailDigitado;

    //verifica se nome usuário já não está sendo utilizado em algum canto
    for(auto iterator = this->listaUsuariosGeral.begin(); iterator != this->listaUsuariosGeral.end(); ++iterator){
        if(iterator->second.getNomeUsuario() == nomeUsuarioDigitado){
            std::cout << "Esse nome de usuário já está sendo usado, use outro" << std::endl;
            nomeUsuarioRepetido = true;
            break;
        } 
    }
    if(!nomeUsuarioRepetido){
        //vou verificar se já não existe alguma conta com esse email, caso exista, reclama!
        auto emailJaExiste = this->listaUsuariosGeral.find(emailDigitado);
        if(emailJaExiste != this->listaUsuariosGeral.end()){
            std::cout << "Esse email já existe, use outro" << std::endl;
        } else{
                Usuario novoUsuario = * new Usuario(nomeUsuarioDigitado, nomePerfilDigitado, emailDigitado,  senhaDigitada);
                this->listaUsuariosGeral.insert({novoUsuario.getEmailUsuario(), novoUsuario});
                std::cout << "Usuário "<<novoUsuario.getNomeUsuario() <<" criado com sucesso" << std::endl;
        }
    }
    //salvarListaUsuarios(this->listaUsuariosGeral);
   // lerListaUsuarios(this->listaUsuariosGeral);
    std::cout << "aperte qualquer tecla para voltar ao menu inicial" << std::endl;
    std::cin >> emailDigitado;
}

//função só pra gente testar outros metodos
void Controlador::fazerTestes(){

    Usuario usuarioIago = * new Usuario("iagola", "iago", "iagognobre@gmail.com", "87020586");
    Usuario usuarioGilberto = * new Usuario("gilbertin","gilberto","gilberto@gmail.com", "87020586");

    //colocando no map
    this->listaUsuariosGeral.insert({usuarioIago.getEmailUsuario(), usuarioIago});
    this->listaUsuariosGeral.insert({usuarioGilberto.getEmailUsuario(), usuarioGilberto});

    //criando tweets
    Tweet tweetIago = * new Tweet("chove chuva chove sem parar", usuarioIago.getNomeUsuario(), usuarioIago.getNomePerfil(), usuarioIago.getEmailUsuario());
    Tweet tweetGilberto = * new Tweet("ele tá sem zap",  usuarioGilberto.getNomeUsuario(), usuarioGilberto.getNomePerfil(), usuarioGilberto.getEmailUsuario());

    Tweet tweetRespostaGilberto = * new Tweet("pois eu vou fazer uma prece",  usuarioGilberto.getNomeUsuario(), usuarioGilberto.getNomePerfil(), usuarioGilberto.getEmailUsuario());

    tweetGilberto.curtirTweet(usuarioIago.getEmailUsuario());
    tweetGilberto.curtirTweet(usuarioIago.getEmailUsuario());

    std::cout << tweetGilberto << std::endl;

    //tentando incluir comentarios em um determinado tweet
    tweetIago.comentarTweet(tweetRespostaGilberto);

    //adicionando tweets
    usuarioIago.addTweet(tweetIago);
    usuarioGilberto.addTweet(tweetGilberto);
    usuarioGilberto.addTweet(tweetRespostaGilberto);

    //seguindo outro usuario 
    bool seguir1 = usuarioIago.seguirUsuario(&usuarioGilberto, usuarioIago);
    bool seguir2 = usuarioGilberto.seguirUsuario(&usuarioIago, usuarioGilberto);

    std::cout << "DEBUG:\n" << seguir1 << "\n" << usuarioGilberto << std::endl << std::endl;
    std::cout << "DEBUG:\n" << seguir2 << "\n" << usuarioIago << std::endl << std::endl;

    /*
    //tentando printar as respostas
    if(tweetIago.getQntdComentarios() > 0){
        std::cout << "printando respostas: " << std::endl;
        std::vector<Tweet> listaComentarios = tweetIago.getListaComentarios();
        for(int i=0; i<listaComentarios.size(); i++){
            std::cout << listaComentarios.at(i).printarTweet();
        }
    }

    

    
    //tentando popularfeed com o tweet da outra pessoa
    this->usuarioLogado = usuarioIago;
    this->feedUsuarioLogado.popularFeed(usuarioIago, this->listaUsuariosGeral);
    */

    // std::map<std::string, Usuario> mapSeguidores = maisNovoUsuario.getListaSeguindo();
    // for(auto iterator = mapSeguidores.begin(); iterator != mapSeguidores.end(); ++iterator){
    //     std::cout << "seguindo: " << iterator->second.getNomePerfil() <<", " << iterator->second.getEmailUsuario() << std::endl;
    // }

}

int main(){
    Controlador controlador = * new Controlador();
    controlador.iniciarPrograma();

    //controlador.fazerTestes();
    return 0;
}

void Controlador::iniciarSessao(){
    std::string opcaoDigitada;
    while(opcaoDigitada!="5"){
        std::system("clear");
        std::cout << "Seja bem vindo," << this->usuarioLogado.getNomeUsuario() << std::endl;
        std::cout << "O que deseja fazer??" << std::endl;
        std::cout << "[1] Escrever Tweet" << std::endl;
        std::cout << "[2] Acessar Feed" << std::endl;
        std::cout << "[3] Acessar o meu feed" << std::endl;
        std::cout << "[4] Pesquisar Usuário" << std::endl;
        std::cout << "[5] Encerrar Sessão" << std::endl;
        std::cin >>opcaoDigitada;

        if (opcaoDigitada == "1") {
            std::system("clear");
            char conteudoTweet[280] = {0};
            std::string teste;
            std::cout << "O que está pensando? " << std::endl;
            std::cin.ignore();
            std::cin.getline(conteudoTweet, 280);
            Tweet novoTweet = *new Tweet(conteudoTweet, this->usuarioLogado.getNomeUsuario(), this->usuarioLogado.getNomePerfil(), this->usuarioLogado.getEmailUsuario());
            this->listaUsuariosGeral.at(this->usuarioLogado.getEmailUsuario()).addTweet(novoTweet);
            //this->usuarioLogado.addTweet(novoTweet);

            std::vector<Tweet> listaComentarios = this->usuarioLogado.getListaTweets();
            for(int i=0; i<listaComentarios.size(); i++){
                std::cout << listaComentarios.at(i).printarTweet();
            }

            std::cout <<"Tweet adicionado com sucesso, aperte qualquer tecla para voltar" << std::endl;
            std::cin >> teste;
        } else if (opcaoDigitada == "2") {
            std::system("clear");
            this->feedUsuarioLogado.popularFeed(this->listaUsuariosGeral.at(this->usuarioLogado.getEmailUsuario()), this->listaUsuariosGeral);
            std::cout << "Pressione qualquer tecla para voltar" << std::endl;
            std::cin >>opcaoDigitada;

        } else if(opcaoDigitada == "3"){
            std::system("clear");
            this->feedUsuarioLogado.popularProprioFeed(this->listaUsuariosGeral.at(this->usuarioLogado.getEmailUsuario()));
            std::cout << "Pressione qualquer tecla para voltar" << std::endl;
            std::cin >>opcaoDigitada;
        } else if(opcaoDigitada == "4"){
            bool achouPerfil = false;
            std::string userName;
            std::cout << "Insira o nome do usuário que deseja pesquisar: " << std::endl;
            std::cin >> userName;

            for (auto user : this->listaUsuariosGeral) {
                if (user.second.getNomeUsuario() == userName) {
                    achouPerfil = true;
                    this->visualizarOutroPerfil(&this->listaUsuariosGeral.at(user.second.getEmailUsuario()));
                }
            }
            if(!achouPerfil){
                std::cout << "Não foi encontrado nenhum usuário com esse nome" <<std::endl;
            }
            // std::cout << "Pressione qualquer tecla para voltar" << std::endl;
            // std::cin >>opcaoDigitada;
        }
    }
}

void Controlador::visualizarOutroPerfil(Usuario *user){


    std::string opcaoDigitada1;
    while (opcaoDigitada1 != "6") {
        std::system("clear");
        std::cout << *user << std::endl;
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
            this->feedUsuarioLogado.percorrerFeed(user, this->listaUsuariosGeral.at(usuarioLogado.getEmailUsuario()));
        }

        else if (opcaoDigitada1 == "2") { 
            this->listaUsuariosGeral.at(usuarioLogado.getEmailUsuario()).seguirUsuario(user, this->listaUsuariosGeral.at(usuarioLogado.getEmailUsuario()));
        }

        else if (opcaoDigitada1 == "3") { 
            this->listaUsuariosGeral.at(usuarioLogado.getEmailUsuario()).deixarDeSeguir(*user, this->listaUsuariosGeral.at(usuarioLogado.getEmailUsuario()));
        }

        else if (opcaoDigitada1 == "4") { 
            this->listaUsuariosGeral.at(usuarioLogado.getEmailUsuario()).bloquearUsuario(*user);
        }

        else if (opcaoDigitada1 == "5") { 
            this->listaUsuariosGeral.at(usuarioLogado.getEmailUsuario()).desbloquearUsuario(*user);
        }
        else if (opcaoDigitada1 == "6") { 
            break;
        }
    }
}


