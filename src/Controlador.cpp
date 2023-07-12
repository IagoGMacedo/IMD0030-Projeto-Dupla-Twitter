#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include "../include/Controlador.h"
/**
 * @since 21/06/2023
 * @date 13/06/2023
 * @authors Gilberto de Paiva Rodrigues e Iago Gabriel Nobre de Macedo
 * @file Controlador.cpp
 * @brief Controlador, utilizado como o main do projeto, para manipular as ações em geral do usuário.
*/

/**< Construtor e Destrutor*/
Controlador::Controlador() {
    this->listaUsuariosGeral = * new std::map<std::string, Usuario>();
    this->usuarioLogado;
    this->feedUsuarioLogado = * new Feed();
}

Controlador::~Controlador() {
}

/**
 * @brief Função main, instancia um novo controlador e chama o método iniciarPrograma(), ou quando for preciso, o fazerTestes()
 * @fn int main()
 */
int main(){
    Controlador controlador = * new Controlador();
    controlador.fazerTestes();
    controlador.iniciarPrograma();

    
    return 0;
}

/**
 * @brief iniciarPrograma é responsável por começar o loop de interação com o usuário
 * @fn void Controlador::iniciarPrograma()
 */
void Controlador::iniciarPrograma(){
    std::string stringEntrada;
    std::system("clear");

    /**< Loop inicial, com opções para chamada de métodos: fazerLogin(), registrar() ou encerrar o loop, e consequentemente o programa*/
    bool encerrarPrograma = false;
    while(!encerrarPrograma){
        std::system("figlet Twitter");
        std::cout << "Faça login ou registre-se para acessar a plataforma." << std::endl;
        std::cout << "[1] Fazer login" << std::endl;
        std::cout << "[2] Registre-se" << std::endl;
        std::cout << "[3] Encerrar programa" << std::endl;
        std::cin >> stringEntrada;
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
    }
}

/**
 * @brief Checagem de login do usuário para saber se é correspondente a algum usuário registrado, através do email e senha
 * @fn void Controlador::fazerLogin()
 */
void Controlador::fazerLogin(){
    std::system("clear");
    std::string emailDigitado, senhaDigitada;

    /**< recebendo como entrada o email e senha do usuário*/
    std::cout << "Digite o seu email:" << std::endl;
    std::cin >> emailDigitado;
    std::cout << "Digite a sua senha:" << std::endl;
    std::cin >> senhaDigitada;

    /**< Checando email e senha com dados da lista de usarios registrados (listaUsuariosGeral)*/
    auto contaExiste = this->listaUsuariosGeral.find(emailDigitado);
    if(contaExiste != this->listaUsuariosGeral.end()){
        if(this->listaUsuariosGeral.at(emailDigitado).conferirSenha(senhaDigitada)){
            //login deu certo 
            /**< Se o login estiver correto, chama o método iniciarSessao()*/
            std::cout << "login realizado com sucesso !" << std::endl;
            this->usuarioLogado = &this->listaUsuariosGeral.at(emailDigitado);
            this->iniciarSessao();
        } else{
            std::cout << "Senha inválida" << std::endl;
        }
    } else{
        std::cout << "Email inválido" << std::endl;
    }
    /**< Retorno para o primeiro loop, main menu*/
    std::cout << "aperte qualquer tecla para voltar ao menu inicial" << std::endl;
    std::cin >> emailDigitado;
}

/**
 * @brief Registra o usuário, salvando na listaUsuariosGeral
 * @fn void Controlador::registrar()
 */
void Controlador::registrar(){ 
    bool nomeUsuarioRepetido = false;
    std::system("clear");
    std::string nomeUsuarioDigitado, nomePerfilDigitado, senhaDigitada, emailDigitado;
    /**< Recebe como entrada os dados do usuário, nome de usuário, nome de perfil, senha e email*/
    std::cout << "Digite o nome do seu usuário(apelido): " << std::endl;
    std::cin >> nomeUsuarioDigitado;

    std::cout << "Digite o nome do seu perfil: " << std::endl;
    std::cin >> nomePerfilDigitado;

    std::cout << "Digite a sua senha: " << std::endl;
    std::cin >> senhaDigitada;

    std::cout << "Digite o seu email: " << std::endl;
    std::cin >> emailDigitado;

    /**< Verificações para a validez do nome de usuário, e email, para não haver repetições*/
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
    std::cout << "aperte qualquer tecla para voltar ao menu inicial" << std::endl;
    std::cin >> emailDigitado;
}

/**
 * @brief Após o usuário efetuar o login, este será o novo loop principal, o novo menu
 * @fn void Controlador::iniciarSessao()
 */
void Controlador::iniciarSessao(){
    std::string opcaoDigitada;
    /**< Loop para as novas opções de ações, escrever um tweet, acessar o feed, pesquisar por usuarios ou encerrar a sessão*/
    while(opcaoDigitada != "5"){
        std::system("clear");
        std::cout << *this->usuarioLogado << std::endl;
        std::cout << "\nSeja bem vindo," << this->usuarioLogado->getNomeUsuario() << std::endl;
        std::cout << "O que deseja fazer??" << std::endl;
        std::cout << "[1] Escrever Tweet" << std::endl;
        std::cout << "[2] Acessar Feed" << std::endl;
        std::cout << "[3] Meus Tweets" << std::endl;
        std::cout << "[4] Pesquisar Usuário" << std::endl;
        std::cout << "[5] Encerrar Sessão" << std::endl;
        std::cin >>opcaoDigitada;

        /**< Escrevendo um tweet, limite de texto 280 caractéres, o usuário insere o texto, e é instanciado um novo tweet e vinculado ao seu perfil*/
        if (opcaoDigitada == "1") {
            std::system("clear");
            char conteudoTweet[280] = {0};
            std::string teste;

            std::cout << "O que está pensando? " << std::endl;
            std::cin.ignore();
            std::cin.getline(conteudoTweet, 280);

            Tweet novoTweet = *new Tweet(conteudoTweet, this->usuarioLogado->getNomeUsuario(), this->usuarioLogado->getNomePerfil(), this->usuarioLogado->getEmailUsuario());
            this->usuarioLogado->addTweet(novoTweet);


            std::cout <<"Tweet adicionado com sucesso, aperte qualquer tecla para voltar" << std::endl;
            std::cin >> teste;

        /**< Acesso ao feed, chama o metodo percorrerFeedGeral, do feedUsuarioLogado*/
        } else if (opcaoDigitada == "2") {
            std::system("clear");
            this->feedUsuarioLogado.percorrerFeedGeral(*this->usuarioLogado, &this->listaUsuariosGeral);

        /**< Acessar meus tweets, Percorrendo lista de tweets do usuário logado, caso não haja tweets, exibição de uma mensagem sobre isso*/
        } else if(opcaoDigitada == "3"){
            std::system("clear");
            
            //aplicando percorrerFeed no contexto de feed de um outro usuário.
            if(this->usuarioLogado->getQntdTweets()>0){
                std::vector<Tweet> listaTweets = this->usuarioLogado->getListaTweets();
                this->feedUsuarioLogado.percorrerFeed(*this->usuarioLogado, &listaTweets);
                this->usuarioLogado->setListaTweets(listaTweets);
            
            } else{
                std::string qualquerTecla;
                std::cout << "Você ainda não escreveu nenhum Tweet. Aperte qualquer tecla para voltar" <<std::endl;
                std::cin >> qualquerTecla;
            }

        /**< Pesquisando nome de usuário, é feita uma busca pela listaUsuariosGeral, de acordo com o nome inserido pelo usuário atual*/
        } else if(opcaoDigitada == "4"){
            bool achouPerfil = false;
            std::string userName;
            std::cout << "Insira o nome do usuário que deseja pesquisar: " << std::endl;
            std::cin >> userName;

            for (auto user : this->listaUsuariosGeral) {
                if (user.second.getNomeUsuario() == userName) {
                    /**< Caso o usuário seja encontrado, exibe o perfil*/
                    achouPerfil = true;
                    this->visualizarOutroPerfil(&this->listaUsuariosGeral.at(user.second.getEmailUsuario()));
                }
            }
            if(!achouPerfil){
                /**< Caso não seja encontrado, é exibida uma mensagem informando*/
                std::cout << "Não foi encontrado nenhum usuário com esse nome" <<std::endl;
                std::cout << "Pressione qualquer tecla para voltar" << std::endl;
                std::cin >>opcaoDigitada;
            }
        }
    }
}

/**
 * @brief Visualizando o perfil de outro usuário
 * @param user Ponteiro para Usuario
 * @fn void Controlador::visualizarOutroPefil(Usuario *user)
*/
void Controlador::visualizarOutroPerfil(Usuario *user){
    /**< Menu de opções exibido ao visualizar um perfil, Explorar os tweets, seguir ou deixar de seguir Usuario, sair do perfil*/
    std::string seguir;
    std::string opcaoDigitada1;
    while (opcaoDigitada1 != "4") {
        std::system("clear");
        if(this->usuarioLogado->estaSeguindoUsuario(user->getEmailUsuario())){
            seguir = "[2] Deixar de seguir Usuario\n" ;
        } else{
            seguir = "[2] Seguir Usuario\n" ;
        }

        std::cout << *user << std::endl;
        std::cout << "O que deseja fazer??\n" 
        << "[1] Explorar Tweets\n" 
        << seguir
        << "[3] Sair do Perfil\n"
        << std::endl;
        std::cin >> opcaoDigitada1;

        /**< Explorando tweets do usuário com o método percorrerFeed, caso esse usuário tenha tweets*/
        if (opcaoDigitada1 == "1") { 
            //aplicando percorrerFeed no contexto de feed de um outro usuário.
            if(user->getQntdTweets() > 0){
                std::vector<Tweet> listaTweets = user->getListaTweets();
                this->feedUsuarioLogado.percorrerFeed(*this->usuarioLogado, &listaTweets);
                user->setListaTweets(listaTweets);
            } else{
                std::string qualquerTecla;
                std::cout <<"Este usuário ainda não escreveu nenhum Tweet. Aperte qualquer tecla para continuar" <<std::endl;
                std::cin >> qualquerTecla;
            }
        }
        /**< Seguir ou deixar de seguir usuário*/
        else if (opcaoDigitada1 == "2" ) { 
            if(!this->usuarioLogado->estaSeguindoUsuario(user->getEmailUsuario())){
                seguir = "[2] Deixar de seguir Usuario\n" ;
                this->usuarioLogado->seguirUsuario(user, *this->usuarioLogado);
            } else{
                seguir = "[2] Seguir Usuario\n" ;
                this->usuarioLogado->deixarDeSeguir(user, *this->usuarioLogado);
            }

        }
        
        /**< Encerrar loop*/
        else if (opcaoDigitada1 == "3") { 
            break;
        }
    }
}

/**
 * @brief Função para testar as funcionalidades do programa
 * @fn void Controlador::fazerTestes()
*/
//função só pra gente testar outros metodos
void Controlador::fazerTestes(){
    //Instanciando usuários
    Usuario usuarioIago = * new Usuario("iagola", "iago", "iagognobre@gmail.com", "87020586");
    Usuario usuarioGilberto = * new Usuario("gilbertin","gilberto","gilberto@gmail.com", "87020586");
    Usuario usuarioGabriel= * new Usuario("gabrielzin","gabriel","gabriel@gmail.com", "87020586");

    //Criando tweets e respostas
    Tweet tweet1Iago = * new Tweet("Chove chuva chove sem parar", usuarioIago.getNomeUsuario(), usuarioIago.getNomePerfil(), usuarioIago.getEmailUsuario());
    Tweet tweet2Iago = * new Tweet("É o minino de papai é?", usuarioIago.getNomeUsuario(), usuarioIago.getNomePerfil(), usuarioIago.getEmailUsuario());
    Tweet tweetGilberto = * new Tweet("Rapaz, ele tá sem zap",  usuarioGilberto.getNomeUsuario(), usuarioGilberto.getNomePerfil(), usuarioGilberto.getEmailUsuario());
    Tweet tweetRespostaGilberto = * new Tweet("Pois eu vou fazer uma prece", usuarioGilberto.getNomeUsuario(), usuarioGilberto.getNomePerfil(), usuarioGilberto.getEmailUsuario());
    Tweet tweetRespostaGabriel = * new Tweet("Pra Deus, nosso senhor", usuarioGabriel.getNomeUsuario(), usuarioGabriel.getNomePerfil(), usuarioGabriel.getEmailUsuario());
    

    //Respondendo tweets
    tweet1Iago.comentarTweet(tweetRespostaGilberto);
    tweet1Iago.comentarTweet(tweetRespostaGabriel);

    //Curtindo tweets
    tweet1Iago.curtirTweet(usuarioGilberto.getEmailUsuario());
    tweet1Iago.curtirTweet(usuarioGabriel.getEmailUsuario());
    tweet1Iago.curtirTweet(usuarioIago.getEmailUsuario());


    //Inserindo usuários na lista geral
    this->listaUsuariosGeral.insert(std::pair<std::string, Usuario>(usuarioIago.getEmailUsuario(), usuarioIago));
    this->listaUsuariosGeral.insert(std::pair<std::string, Usuario>(usuarioGilberto.getEmailUsuario(), usuarioGilberto));
    this->listaUsuariosGeral.insert(std::pair<std::string, Usuario>(usuarioGabriel.getEmailUsuario(), usuarioGabriel));

    //Adicionando tweets
    this->listaUsuariosGeral.at(usuarioIago.getEmailUsuario()).addTweet(tweet1Iago);
    this->listaUsuariosGeral.at(usuarioIago.getEmailUsuario()).addTweet(tweet2Iago);
    this->listaUsuariosGeral.at(usuarioGilberto.getEmailUsuario()).addTweet(tweetGilberto);
    this->listaUsuariosGeral.at(usuarioGilberto.getEmailUsuario()).addTweet(tweetRespostaGilberto);
    this->listaUsuariosGeral.at(usuarioGabriel.getEmailUsuario()).addTweet(tweetRespostaGabriel);

    //Seguindo
    this->listaUsuariosGeral.at(usuarioGilberto.getEmailUsuario()).seguirUsuario(&this->listaUsuariosGeral.at(usuarioIago.getEmailUsuario()), this->listaUsuariosGeral.at(usuarioGilberto.getEmailUsuario()));
    this->listaUsuariosGeral.at(usuarioGabriel.getEmailUsuario()).seguirUsuario(&this->listaUsuariosGeral.at(usuarioIago.getEmailUsuario()), this->listaUsuariosGeral.at(usuarioGabriel.getEmailUsuario()));
    this->listaUsuariosGeral.at(usuarioGabriel.getEmailUsuario()).seguirUsuario(&this->listaUsuariosGeral.at(usuarioGilberto.getEmailUsuario()), this->listaUsuariosGeral.at(usuarioGabriel.getEmailUsuario()));


}






