#include <iostream>
#include "../include/Tweet.h"


int main() {
    std::string S = "Hello, World!";
    int i = 0;
    
    Tweet *Test = new Tweet(S, i);
    
    std::cout << Test->getConteudoTweet() << std::endl 
    << Test->getQntdCurtidas() << std::endl;

    return 0;
}