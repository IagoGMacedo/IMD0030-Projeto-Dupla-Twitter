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
        for (auto user : listaUsuariosSalvos) {
            
            auto listaBloqueados = user.second.getListaBloqueados();
            for (auto bloqueado : listaBloqueados) {
                //bloqueado.second.
                //to-do
            }

            auto listaSeguidores = user.second.getListaSeguidores();
            for (auto seguidor : listaSeguidores) {
                //to-do
            }

            auto listaSeguindo = user.second.getListaSeguindo();
            for (auto seguindo : listaSeguindo) {
                //to-do
            }

            auto listaTweets = user.second.getListaTweets();
            for (auto tweet : listaTweets) {
                //to-do
            }

            auto email = user.second.getEmailUsuario();
            auto nomePerfil = user.second.getNomePerfil();
            auto nomeUsuario = user.second.getNomeUsuario();
            auto qntdSeguidores = user.second.getQntdSeguidores();
            auto qntdSeguindo = user.second.getQntdSeguindo();
            auto qntdTweets = user.second.getQntdTweets();

            outfile.write(email.c_str(), email.size());
            outfile.write(nomePerfil.c_str(), nomePerfil.size());
            outfile.write(nomeUsuario.c_str(), nomeUsuario.size());
            //outfile.write(qntdSeguidores.c_str(), qntdSeguidores.size());
            //outfile.write(qntdSeguindo.c_str(), qntdSeguindo.size());
            //outfile.write(qntdTweets.c_str(), qntdTweets.size());

        }
    }

    ifstream infile(FILE);

    if(!infile.is_open()) {
        cerr<< "Erro ao abrir o arquivo";
        return -1;
    }

    return 0;
}