#include <iostream>
#include <fstream>
#include "../include/Usuario.h"
#include "../include/Tweet.h"
#include <map>
#include <vector>
#define FILE "../data/teste.txt"
using namespace std;


int main() {
    Usuario user1;
    Usuario user2;
    Usuario user3;
    Usuario user4;
    Usuario user5;

    std::map<string, Usuario> listaUsuariosSalvos = * new std::map<std::string, Usuario>();
    listaUsuariosSalvos.insert(pair<string, Usuario>(user1.getEmailUsuario(), user1));
    listaUsuariosSalvos.insert(pair<string, Usuario>(user2.getEmailUsuario(), user2));
    listaUsuariosSalvos.insert(pair<string, Usuario>(user3.getEmailUsuario(), user3));
    listaUsuariosSalvos.insert(pair<string, Usuario>(user4.getEmailUsuario(), user4));
    listaUsuariosSalvos.insert(pair<string, Usuario>(user5.getEmailUsuario(), user5));

    Tweet twtTest1(user1, "a");
    Tweet twtTest2(user2, "b");
    std::vector<Tweet> listaTweets;
    listaTweets.push_back(twtTest1);
    listaTweets.push_back(twtTest2);

    std::map<std::string, Usuario> listaSeguindo = * new std::map<std::string, Usuario>();
    listaSeguindo.insert(pair<string, Usuario>(user2.getEmailUsuario(), user2));
    listaSeguindo.insert(pair<string, Usuario>(user3.getEmailUsuario(), user3));

    std::map<std::string, Usuario> listaSeguidores = * new std::map<std::string, Usuario>();
    listaSeguidores.insert(pair<string, Usuario>(user3.getEmailUsuario(), user3));
    listaSeguidores.insert(pair<string, Usuario>(user4.getEmailUsuario(), user4));

    std::map<std::string, Usuario> listaBloqueados = * new std::map<std::string, Usuario>();
    listaBloqueados.insert(pair<string, Usuario>(user5.getEmailUsuario(), user5));

    user1.setEmailUsuario("gilbertoknd5@gmail.com");
    user1.setNomePerfil("Gilberto Rodrigues");
    user1.setNomeUsuario("gilbertoknd");
    user1.setQntdSeguidores(10);
    user1.setQntdSeguindo(50);
    user1.setQntdTweets(2);

    user1.setListaSeguidores(listaSeguidores);
    user1.setListaSeguindo(listaSeguindo);
    user1.setListaBloqueados(listaBloqueados);
    user1.setListaTweets(listaTweets);

    ofstream outfile(FILE);

    if (!outfile.is_open()) {
        cerr << "erro ao abrir o arquivo";
        return -1;
    }
    else {
        //for (size_t i = 0; i < listaUsuariosSalvos.size(); i++) {
        //auto list = listaUsuariosSalvos.;

        //file.write(linha.c_str(), linha.size());
        //}
    }

    ifstream infile(FILE);

    if(!infile.is_open()) {
        cerr<< "Erro ao abrir o arquivo";
        return -1;
    }
    else {
        
    }

    return 0;
}