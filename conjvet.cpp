#include "conjvet.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

conjvet::conjvet(int tama)
{
    tamanhovet=tamacopia=tama;
    vetor=new int[tamanhovet];
   
    
}

void conjvet::lervet()
{		
        for(int i=0;i<tamanhovet;i++)
        {
		cin>>vetor[i];
        }
}

void conjvet::impvet()
{		
	 int tamacop=tamanhovet;
     for(int i=0;i<tamacop;i++)
     {
		cout<< vetor[i];
		if(i<tamacop-1)
		{
			cout<< " -- " ;
		}
     }
        
}

bool conjvet::vazio()
{
    if(tamanhovet == 0)
 	{
 	  return true;
	}
      return false;
}

void conjvet::uniao(conjvet x,conjvet y)
{
    int i,j,k;
    for(k=0;k<x.tamanhovet;k++)
    {
      vetor[k] = x.vetor[k];
    }
   for(i=0;i<y.tamanhovet;i++)
   {
	 for(j=0;j<x.tamanhovet && y.vetor[i] != x.vetor[j]; j++);
     {}
     if(j == x.tamanhovet)
		{
		  vetor[k] = y.vetor[i];
		  k++;
		}
   }
      tamanhovet = k;
}

void conjvet::intersec(conjvet x, conjvet y)
{
    int i,j,newsize = 0;
	for(i=0;i<x.tamanhovet;i++)
	{
		for(j=0;j<y.tamanhovet;j++)
		{
			if(x.vetor[i] == y.vetor[j])
			{
				vetor[newsize++] = x.vetor[i];
			}
		}
	}
	 tamanhovet = newsize;
}
void conjvet::menas(conjvet x, conjvet y)
{
    int i,j,newsize = 0;
	for(i=0;i<x.tamanhovet;i++)
	{
		for(j=0;j<y.tamanhovet && x.vetor[i] != y.vetor[j]; j++);
		 {
		 }
		 if(j == y.tamanhovet)
		 {
		   vetor[newsize++] = x.vetor[i];
		 }
	}
    tamanhovet=newsize;
}

int conjvet::escalar(conjvet x, conjvet y)
{
    int i,somaescalar;
	if(x.tamanhovet==y.tamanhovet)
	{
		for(somaescalar=0,i=0;i<x.tamanhovet;i++)
		{
			 somaescalar += x.vetor[i] * y.vetor[i];
		}
		return somaescalar;
	}
	return 0;
}

bool conjvet::subconj(conjvet x, conjvet y)
{
    int i,j;
    int cont=0;
	for(i=0;i<x.tamanhovet;i++)
	{
	  for(j=0;j<y.tamanhovet && x.vetor[i]!=y.vetor[j];j++)
	  {
	  }
	  if(j==y.tamanhovet)
	  {
		return false;
	  }
	  else
	  {
	  cont++;
	  }
	}

	if(cont==x.tamanhovet)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool conjvet::conjiden(conjvet x, conjvet y)
{
   int i,j;
   int conta=0;
	for(i=0;i<x.tamanhovet && x.tamanhovet == y.tamanhovet;i++)
	{
		for(j=0;j<y.tamanhovet;j++)
		{
			if(x.vetor[i] == y.vetor[j])
			{
				conta++;
			}
	    }
	}
        tamanhovet = conta;
        if(tamanhovet == x.tamanhovet)
        {
        return true;
        }
        return false;
}

bool conjvet::disjunt(conjvet x, conjvet y)
{
    int i,j;
	for(i=0;i<x.tamanhovet;i++)
	{
		for(j=0;j<y.tamanhovet;j++)
		{
			if(x.vetor[i] == y.vetor[j])
			{
				return false;
			}
	    }
	}
	return true;
}

int conjvet::ampl(conjvet x, conjvet y)
{
    int i,maior=0;
    int menor = x.vetor[0];
	for(i=0;i<x.tamanhovet;i++)
	{
		if(x.vetor[i] > maior)
		{
			maior = x.vetor[i];
		}
	}

	for(i=1;i<x.tamanhovet;i++)
	{
		if(x.vetor[i] < menor)
		{
			menor = x.vetor[i];
		}
	}

	return maior - menor;
}

conjvet::~conjvet()
{
	delete []vetor;
}
