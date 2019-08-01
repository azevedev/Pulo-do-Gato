#include <iostream>
#include <cstring> 

using namespace std;
#define MAX 10005

int lajotas [MAX];
int dp[MAX];
int tamanho;
int menorPulo(int index){

	if(dp[index]!=-1)
		return dp[index];
	if(index >= tamanho-1)//nesse caso, O
		return 0;
	if(lajotas[index] == 0)
		return tamanho;
	dp[index] = 1 + min(menorPulo(index+1), menorPulo(index+2));
	return dp[index];
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &tamanho);
	for(int i = 0; i < tamanho; i++)
		scanf("%d", &lajotas[i]);
	int resultado = menorPulo(0);
	if(resultado >= tamanho)
		resultado = -1;
	printf("%d", resultado);

	return 0;
}