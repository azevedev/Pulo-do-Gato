#include <iostream>

using namespace std;
#define MAX 10005

int lajotas [MAX];
int tamanho;
int calculaPulos(int index){

    if(index >= tamanho-1)
	return 0;

    if(lajotas[index] == 0)
	return tamanho;

    return 1 + min(calculaPulos(index+1), calculaPulos(index+2));
}//end calculaPulos()

int main(){

   scanf("%d", &tamanho);
   for(int i = 0; i < tamanho; i++)
   	 scanf("%d", &lajotas[i]);
	 
   int resultado = calculaPulos(0);
   if(resultado >= tamanho)
  	 resultado = -1;
	 
   printf("%d", resultado);

   return 0;
}//end main()