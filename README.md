# IMD0030-Projeto-Dupla-Twitter
Repositório criado para armazenar o projeto final da matéria IMD0030 de Linguagem de Programação 1. O projeto consiste em fazer uma réplica do twitter.

Discentes: 
Iago Gabriel Nobre de Macedo
Gilberto de Paiva Rodrigues

Diagrama de classes:
https://app.diagrams.net/#G1vhq0o9B52dkYAM5V6SN-4IUuvqF0ho83

Apresentação do projeto:
https://www.youtube.com/watch?v=_ssT-4duTzM&ab_channel=IagoGabriel

Tads utilizadas:
Utilizaremos as tads Lista Duplamente Encadeada e Conjunto no sistema. A lista duplamente enceada
será usada para relacionar os tweets com comentários entre si, podendo haver threads. O conjunto será usada
para armazenar os tweets postados por um usuário, e os tweets que estão no feed daquele usuário para serem
visualizados.

Para executar:
- É necessário um ambiente linux ou wsl.
- Instalar a biblioteca figlet com sudo apt-get install figlet
- Estando na pasta raíz do projeto, execute "make" para compilar, e logo depois "make run" para iniciar o programa.


Estrutura do projeto:
- ``src`` - Os arquivos .cpp devem ser armazenados neste diretório.
- ``include`` - Os arquivos .h devem ser armazenados neste diretório.
- ``bin`` - Os arquivos binários devem ser gerados neste diretório.
