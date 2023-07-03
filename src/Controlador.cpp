#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "../include/Controlador.h"
#define USERS_FILE "../data/Users.txt"
//#include "../include/Conjunto.h"

/*
    ideias
    pode fazer os codigos de input e output aqui local e só passar as infos pra classe OU
    fazer tudo no metodo da classe mesmo (fazerLogin e registrar)
    Usuario

    Utilizar arquivo em binário para salvar os dados de usuários
    usar o arquivo em formato txt para os testes
*/

Controlador::Controlador() {
    //talvez use new aqui

    this->listaUsuariosGeral = * new Conjunto<Usuario>();
    //this->feedUsuarioLogado = Feed();
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

    ifstream file(USERS_FILE);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
    }
    else {
        //Inserção do conjunto de Usuarios no arquivo
        /*
        std::string line;
        while (file.getline(file, line.c_str())) {
            listaUsuariosGeral.inserir(line);
        }
        */
        file.close();
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
    */
}

#define FILE_NAME "../data/Users.dat"
int salvarListaUsuarios(Conjunto<Usuario> conjuntoUsuario){
    std::fstream file;

	file.open(FILE_NAME,ios::out|ios::binary);

	if(!file){
		cout<<"Erro ao criar arquivo...\n";
		return -1;
	}
	
	file.write((char*)&conjuntoUsuario,sizeof(conjuntoUsuario));
	file.close();
	cout<<"Dados salvos no arquivo (array).\n";
    return 1;

}
Conjunto<Usuario> conjuntoRecuperado = * new Conjunto<Usuario>;
void lerListaUsuarios(Conjunto<Usuario> conjuntoUsuario){
    std::fstream file;
	//Funcionario*listaFuncionarioRecuperados;
	file.open(FILE_NAME,ios::in|ios::binary);
	if(!file){
		cout<<"Erro ao abrir arquivo...\n";
	}
	
	if( file.read((char*)&conjuntoRecuperado, sizeof(conjuntoUsuario)) ){
			cout<<endl<<endl;
			cout<<"Dado extraido do arquivo...\n";
			//Imprime o objeto
            conjuntoRecuperado.imprimir();

	}
	else{
		cout<<"Erro ao ler dado do arquivo...\n";
	}
	file.close();	
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
    
    this->listaUsuariosGeral.inserir(novoUsuario);
    this->listaUsuariosGeral.imprimir();
     std:: cout << "--------------"<< std::endl;
        std::vector<Usuario*> vetorUsuarios;
        vetorUsuarios.push_back(&novoUsuario);
        salvarListaUsuarios(this->listaUsuariosGeral);
        lerListaUsuarios(this->listaUsuariosGeral);
        std::cout << "Usuário " << novoUsuario.getNomeUsuario() << " criado com sucesso, aperte qualquer tecla para fazer login" << std::endl;
        std::cin >> emailDigitado;

    //Inserir usuario no arquivo binário, ou txt
    
    /*
    ofstream file(USERS_FILE);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
    }
    else {
        //Inserção do conjunto de Usuarios no arquivo
        for (int i = 0; i < listaUsuariosGeral.tamanho(); i++) {
            listaUsuariosGeral.recuperar(i);
        }
        
        file.close();

         std:: cout << "--------------"<< std::endl;
        salvarListaUsuarios(this->listaUsuariosGeral);
        lerListaUsuarios();
        std::cout << "Usuário " << novoUsuario.getNomeUsuario() << " criado com sucesso, aperte qualquer tecla para fazer login" << std::endl;
        std::cin >> emailDigitado;
    }
    */
    //std:: cout << novoUsuario << std::endl;
   
}

int main(){
    Controlador controlador;
    controlador.iniciarPrograma();

    return 0;
}

