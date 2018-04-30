#include <iostream>
#include <stdlib.h>
#include "conjvet.h"
#include "conjvet.cpp"

using namespace std;

int main()
{
    int tamanhoconjunto,tamanhoconjunto2,escolha;
    bool maior;
    char continua='s';

	while(continua=='s')
	{
        cout<<"-----------------------------------------Trabalho de Conjuntos .By JaPaCoDeR! -----------------------------------------\n\n";
		cout<<"Digite 1 para { Descobrir se os conjuntos são vazios }\n";
		cout<<"Digite 2 para { A união B }\n";
		cout<<"Digite 3 para { A intersecção B }\n";
		cout<<"Digite 4 para { A - B } \n";
		cout<<"Digite 5 para { B - A } \n";
		cout<<"Digite 6 para { Descobrir se A é subconjunto de B }\n";
		cout<<"Digite 7 para { Descobrir se B é subconjunto de A }\n";
		cout<<"Digite 8 para { Descobrir se A é B sao conjuntos identicos }\n";
		cout<<"Digite 9 para { Descobrir se A é B sao conjuntos disjuntos }\n";
		cout<<"Digite 10 para { Amplitude de A é B }\n";
		cout<<"Digite 11 para { Produto escalar entre A e B }\n";

		cout<<"\nDigite a operação que você deseja realizar : ";

		cin>>escolha;

		cout << "\t Digite o tamanho do primeiro conjunto : " ;
		maior=true;
		while(maior==true)
		{
			cin>>tamanhoconjunto;
			if(tamanhoconjunto>=0)
			{
				maior=false;
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
			{
				maior=false;
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

		switch(escolha)
		{
			case 1:
			{
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

				break;
			}
			//uniao vets
			case 2:
			{
				aux.uniao(p1,p2);
				cout<< "\n A uniao entre A e B é == " ; aux.impvet();
				break;
			}

			//intersecção
			case 3:
			{
				aux.intersec(p1,p2);
				cout<< "\n A diferença entre A e B é == " ; aux.impvet();

				break;
			}

			//subtração de conjuntos
			case 4:
			{
				aux.menas(p1,p2);
				cout<< "\n O conjunto A-B == " ; aux.impvet();

				break;
			}

			//sub ao contrario
			case 5:
			{
				aux.menas(p2,p1);
				cout<< "\n O conjunto B-A == " ; aux.impvet();

				break;
			}

			case 6:
			{
				if(aux.subconj(p1,p2))
				{
				cout<< "\n A é subconjunto de B ! " <<endl;
				}
				else
				{
				cout<< "\n A não é subconjunto de B ! " <<endl;
				}

				break;

			}

			case 7:
			{
				if(aux.subconj(p2,p1))
				{
				cout<< "\n B é subconjunto de A ! " <<endl;
				}
				else
				{
				cout<< "\n B não é subconjunto de A ! " <<endl;
				}

				break;
			}

			case 8:
			{
				if(aux.conjiden(p1,p2))
				{
					cout << "\n São identicos ! "<<endl;
				}
				else
				{
					cout<< "\n Não são identicos ! " <<endl;
				}


				break;
			}

			case 9:
			{
				if(aux.disjunt(p1,p2))
				{
					cout<< "\n São disjuntos ! "<< endl ;
				}
				else
				{
					cout<< "\n Não são disjuntos ! "<< endl ;
				}

				break;
			}

			case 10:
			{
				cout<< "\n A amplitude de A e B é : "<<aux.ampl(p1,p2)<<endl;

				break;
			}
			//Produto escalar dos conjuntos
			case 11:
			{
				aux.escalar(p1,p2);
				cout<< "\n O Produto escalar entre A e B == " ; aux.impvet();

				break;
			}

			default:
			{
				cout<<"\n Querido usuario digite um numero valido ou vá tomar no seu cuca ! '_' ! ";

				break;
			}



		}
		cout<<"\n Desejas continuar ? Se sim digite s : " ;
		cin>>continua;
		system("clear");
        system("cls");
	}
}
