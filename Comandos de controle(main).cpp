#include <iostream>
#include "conjvet.h"
#include "conjvet.cpp"

using namespace std;

int main()
{
    int tamanhoconjunto,tamanhoconjunto2;
    bool maior=true;

    cout << "\t Digite o tamanho do primeiro conjunto : " ;
    while(maior==true)
    {
    cin>>tamanhoconjunto;
    if(tamanhoconjunto>=0)
    { maior=false;
    }
    else
    {
     cout<< "\n \tTamanho invalido !!!\n";
     cout << "\t Digite o tamanho do primeiro conjunto : " ;
    }
    }


    cout<< "\t Digite o tamanho do segundo conjunto : " ;
    maior= true;
    while(maior==true)
    {
    cin>>tamanhoconjunto2;
    if(tamanhoconjunto2>=0)
    { maior=false;
    }
    else
    {
     cout<< "\n \tTamanho invalido !!!\n";
     cout << "\t Digite o tamanho do segundo conjunto : " ;
    }
    }


    conjvet p1(tamanhoconjunto), p2(tamanhoconjunto2), aux(tamanhoconjunto+tamanhoconjunto2);
    cout << "\n Digite os valores do conjunto A : ";
    //Digitar o vetor
    p1.lervet();

    cout<< "\n Digite os valores do conjunto B : ";
    p2.lervet();

    //vazio
    if(p1.vazio())
    {
        cout<<"\n O conjunto A é vazio !!! ";
    }
    else
    {
        cout<<"\n O conjunto A não é vazio !!! ";
    }
    if(p2.vazio())
    {
        cout<<"\n O conjunto B é vazio !!! ";
    }
    else
    {
        cout<<"\n O conjunto B não é vazio !!! ";
    }
    //uniao vets

    aux.uniao(p1,p2);

    cout<< "\n A uniao entre A e B é == " ; aux.impvet();



}
