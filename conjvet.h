//                         !!!!!!!      IN CONSTRUCTION !!!!!!!
#ifndef CONJVET_H
#define CONJVET_H
#include <string>
#include <iostream>

class conjvet
{
private:
    int* vetor;
    int tamanhovet;

public:
    conjvet(int);
    void lervet();
    void impvet();
    bool vazio();
    void uniao(conjvet x,conjvet y);
    void intersec(conjvet x,conjvet y);
    void menas(conjvet x, conjvet y);
    int escalar(conjvet x, conjvet y);


};
#endif
