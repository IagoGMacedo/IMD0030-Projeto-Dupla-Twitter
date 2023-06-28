#include "../include/helper.h"
using namespace std;

class Usuario {
private:
    string nomePerfil;
    
    //Conjunto<Tweet> listaTweets[];
    
    int qntdSeguidores;
    int qntdSeguindo;
    
    //Conjunto<Tweet> listaSeguindo;
    //Conjunto<Tweet> listaSeguidores;
    //Conjunto<Usuarios> listaBloqueados;
    
    string email;
    string nomeUsuario;

public:
    //Construtores e destrutor
    Usuario(string nomePerfil, /*Conjunto<Tweet> listaTweets[],*/ int qntdSeguidores, int qntdSeguindo, 
            /*Conjunto<Usuario> listaSeguindo, Conjunto<Usuario> listaSeguidores , Conjunto<Usuario> listaBloqueados, */ 
            string email, string nomeUsuario);
    Usuario();
    ~Usuario();

    //Getters
    void setNomePerfil(string nomePerfil);
    
    //void setlistaTweets(Conjunto<Tweet> listaTweets);
    
    void setQntdSeguidores(int qntdSeguidores);
    void setQntdSeguindo(int qntdSeguindo);

    //void setlistaSeguindo(Conjunto<Usuarios> listaSeguindo);
    //void setlistaSeguidores(Conjunto<Usuarios> listaSeguidos);
    //void setlistaBloqueados(Conjunto<Usuarios> listaBloqueados);

    void setEmail(string email);
    void setNomeUsuario(string nomeUsuario);
    

    //setters
    string getNomePerfil();
    
    //Conjunto<Tweet> getlistaTweets();
    
    int getQntdSeguidores();
    int getQntdSeguindo();

    //Conjunto<Usuarios> getlistaSeguindo();
    //Conjunto<Usuarios> getlistaSeguidores();
    //Conjunto<Usuarios> getlistaBloqueados();

    string getEmail();
    string getNomeUsuario();
    

    //Outros Metodos
    void deletarUsuario( string confirmacao );
    void seguirUsuario( Usuario user );
    void bloquearUsuario( Usuario user );


};
