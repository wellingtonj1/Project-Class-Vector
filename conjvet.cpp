#include "conjvet.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

conjvet::conjvet(int tama)
{
    tamanhovet=tama;
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
     for(int i=0;i<tamanhovet;i++)
        {
         cout<< vetor[i] << " " ;
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

