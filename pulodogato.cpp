#include <iostream>

using namespace std;
#define MAX 10005

int lajotas [MAX];
int tamanho;
int menorPulo(int index){

	if(index >= tamanho-1)//nesse caso, O
		return 0;
	if(lajotas[index] == 0)
		return tamanho;
	return 1 + min(menorPulo(index+1), menorPulo(index+2));
}

int main(){
	
	scanf("%d", &tamanho);
	for(int i = 0; i < tamanho; i++)
		scanf("%d", &lajotas[i]);
	int resultado = menorPulo(0);
	if(resultado >= tamanho)
		resultado = -1;
	printf("%d", resultado);

	return 0;
}