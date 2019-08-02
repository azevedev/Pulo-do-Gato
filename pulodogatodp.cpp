#include <iostream> 
#include <cstring> 
using namespace std;
#define MAX 10005

int lajotas [MAX];
int calculados[MAX];
int tamanho;

int calculaPulos(int index){

    if(index >= tamanho-1)
	return 0;

    if(lajotas[index] == 0)
	return tamanho;
        
    if(calculados[index] != -1)
    	return calculados[index];
	
    calculados[index] = 1 + min(calculaPulos(index+1), calculaPulos(index+2));

    return calculados[index];	    
}//end calculaPulos()	

int main(){
   memset(calculados, -1, sizeof(calculados));
   scanf("%d", &tamanho);
   for(int i = 0; i < tamanho; i++)
   	 scanf("%d", &lajotas[i]);
	 
   int resultado = calculaPulos(0);
   if(resultado >= tamanho)
  	 resultado = -1;
	 
   printf("%d", resultado);

   return 0;
}//end main()