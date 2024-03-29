# Pulo do Gato
  ## Resolvendo problemas computacionais usando Recursividade e Programação Dinâmica

 Link do problema original: https://olimpiada.ic.unicamp.br/pratique/pj/2018/f3/pulo/
 

 ### O problema
   O gato Obinho gosta de brincar atravessando filas de lajotas no chão de um prédio. Ele sempre começa na primeira lajota, da esquerda para a direita, e sempre para na última lajota da fila. Obinho é muito preguiçoso, e só irá saltar até duas lajotas por vez. Outra caracteristica de Obinho é que ele gosta de pular somente em lajotas pretas e ignora as lajotas brancas podendo até mesmo desistir de brincar por causa delas.  

   ![Obinho](https://github.com/azevedomath/Pulo-do-Gato/blob/Coding/images/2018f3pj_pulo.png)
**Pergunta:**  Dada uma fila de lajotas, qual o número mínimo de pulos que Obinho deve executar para chegar ao final da fila?


Agora que sabemos como Obinho se comporta, vamos ver como o programa deve se comportar.
### Entradas:
- A primeira linha é um inteiro X, que representa o tamanho da fila de lajotas que Obinho irá percorrer.
- A segunda linha é uma lista de inteiros "1" ou "0", representando as cores das lajotas. Caso 1, a lajota é preta; Caso 0, a lajota é branca.
### Saídas:
 - O programa deve retornar uma única saída, o número mínimo de movimentos que Obinho deve realizar para chegar até o final; Caso não seja possível chegar ao final, o programa deve retornar -1.
### Restrições:
- 0 < X < 10^4 + 1
- Tempo Limite de Execuçao: 200ms
- A primeira e a última lajota sempre serão pretas.

## Implementando
 Vou implementar duas formas de resolver esse problema.
 A primeira, mais intuitiva, utiliza recursividade; A segunda utiliza Programação Dinâmica.
 
 ### Resolução por Recursividade:
 
  Fiz o código em C++, mas pode ser aplicado a outras linguagens.
  Esse código não é a versão final. É uma versão mais simplificada do problema. 
  Para ver a versão final, pule para a próxima secção.
  
  Vamos lá! Primeiro, vamos declarar nossas variáveis:
  
  	#include <iostream>
  	using namespace std;
  	#define MAX 10005
 
  	int lajotas [MAX]; <br>
  	int tamanho;
  
  Todas elas são globais, pois vamos usar num escopo de recursividade.
  
  Agora, vamos ler os inputs dentro da função _main_:
  
  	int main(){
  	   scanf("%d", &tamanho);
  	   for(int i = 0; i < tamanho; i++)
  	   scanf("%d", &lojotas[i]);
  
  	   return 0;
  	}//end main()
  
  Depois, vamos implementar a função para calcular os pulos.
  O macete aqui é notar que esse problema pode ser resolvido de forma recursiva.
  Se divirmos uma função que, dado um índice (que represente uma lajota), consiga retornar a quantidade de pulos a partir de   sí mesmo, temos uma recursividade! \o/
  
  Assim, temos:
  
  	int calculaPulos(int index){
  	    return 1 + calculaPulos(index + 1);
  	}
  
  Essa é a função base. Ela sempre retorna o valor de pulos atuais (1) somados aos outros pulos restantes (index + 1).
  Temos que criar as condições de parada dessa função.
  A primeira é bem intuitiva: 
  > quando não houver mais lajotas para pular, a função para. 
  
  Então:
  
  	int calculaPulos(int index){
  	    if(index >= tamanho - 1)
  	    	return 0;
		
  	    return 1 + calculaPulos(index + 1);
  	}
	
  "tamanho" é a quantidade de lajotas. "index" começa em 0, por isso precisamos do "tamanho - 1".
  O "return 0;" está ali pois se não existem mais lajotas para pular, então não é possível aumentar o número de movimentos de Obinho, logo retornamos 0.
  
  Certo, agora a próxima condição de parada é sobre as lajotas brancas:
   > ele gosta de pular somente em lajotas pretas e ignora as lajotas brancas podendo até mesmo desistir de brincar por causa delas.  
   
   Então, se temos uma lajota branca, temos que parar a recursividade.
   Lá vai:
   
   	int calculaPulos(int index){
  	   if(index >= tamanho - 1)
  	      return 0;
  	   
  	   if(lajotas[index] == 0)
  	      return tamanho;
  	   
  	   return 1 + calculaPulos(index + 1);
  	}
	
  Se _lajotas[index] == 0_, então estamos em uma lajota branca. O motivo de retornarmos _tamanho_ se deve ao objetivo do programa, que é **_minimizar_** a quantidade de movimentos. Ao retornarmos _tamanho_, estamos dizendo que aquele caminho (pela lajota branca) possui a maior quantidade de movimentos possíveis, que é o próprio tamanho da fila. O algoritmo logo logo irá descartar esse caminho pois este é muito grande. Outro motivo para retornarmos _tamanho_ se deve a possibilidade de não existir um caminho válido até o final da fila de lajotas. Quando a recursividade terminar, podemos simplesmente checar a quantidade de movimentos, e se esta for maior ou igual a _tamanho_, sabemos que não existe um caminho válido. 
 
Para implementarmos isso, basta usar um if, dentro da main:
  
  	int main(){
  	   scanf("%d", &tamanho);
  	   for(int i = 0; i < tamanho; i++)
  	      scanf("%d", &lojotas[i]);
	      
  	   int resultado = calculaPulos(0);
  	   if (resultado >= tamanho)
  	      resultado = -1;
	      
           printf("%d", resultado);
 
  	   return 0;
  	}//end main()
	
  Prontinho. Agora só precisamos terminar nossa função que calcula os pulos.
  
  Mais um detalhe sobre os pulos de Obinho:
  > Obinho é muito preguiçoso, e só irá saltar até duas lajotas por vez
  
  Ou seja, precisamos adicionar a opção de Obinho escolher se vai saltar **_apenas uma_** ou **_duas_** lajotas.
  Além disso, temos que **_minimizar_** a quantidade de movimentos de Obinho.
  Para isso, fazemos o seguinte:
  
  	int calculaPulos(int index){
      	   if(index >= tamanho - 1)
              return 0;
	      
      	   if(lajotas[index] == 0)
              return tamanho;
	      
      	   return 1 + min(calculaPulos(index + 1), calculaPulos(index + 2));
         }

  Parece que complicou ainda mais o código, mas é bem simples:
  - Primeiro, temos a função "min". Ela recebe dois argumentos, x e y, e retorna o _menor_ deles.
  Assim, temos certeza que a recursividade vai sempre retornar o menor dos caminhos possíveis.
  - Os dois argumentos da função min (x e y) são justamente os dois tipos de pulos que Obinho pode realizar.
  Assim, colocamos a opção de Obinho escolher quantas lajotas irá pular, e a função vai retornar o menor caminho.
  
  Então, o código completo fica assim:
  
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
  
  E pronto! Terminamos o código.
  Eles já está funcionando _quase_ como deve, mas ainda temos um pequeno probleminha nesse código: complexidade. 
  Usando recursividade, temos uma complexidade de  **O(2^n)**, sendo _n_ o maior número de iterações possíveis, nesse caso o   maior número possível para n é 10^4. 
  Isso resulta em 10^8 iterações, no pior dos casos.
  Essa complexidade exige um tempo de execução maior que 200ms, logo não é a solução mais adequada para este problema. 

Hora de optimizar esse código!

### Resolução por Programação Dinâmica
 Podemos usar Programação Dinâmica (DP) para resolver esse problema.
 DP nada mais é que uma forma mais ágil de abordar recursividade.
 O problema do código anterior é que calculamos todas as possibilidades de caminhos a serem seguidos a partir de todas as lajotas em que Obinho podia pular.
 Isso resulta em funções recursivas calculando o mesmo valor ou mesmo caminho várias vezes, o que é um desperdício de memória e de tempo de processamento.
 A árvore abaixo representa o código anterior em execução:

![Tree](https://github.com/azevedomath/Pulo-do-Gato/blob/Coding/images/tree-viz.png)

Repare que, os _nós_ com cores vermelhas, amarelas e verdes são, na verdade, o mesmo nó, que resultam nos mesmos caminhos. 
O algoritmo anterior calcula esses nós mais de uma vez, o que causa o _delay_ no tempo de execução.
O que podemos fazer para solucionar esse problema é _salvar_ os caminhos que já foram calculados, assim, quando a recursividade requerir novamente o cálculo daquele nó, simplesmente retornamos o valor que já foi calculado anteriormente. 
Pra isso funcionar, precisamos adicionar algumas linhas de código.

Primeiro, uma váriavel para salvar todos os caminhos já calculados:
	
  	#include <iostream> 
	#include <cstring> 
  	using namespace std;
  	#define MAX 10005
 
  	int lajotas [MAX];
	int calculados[MAX];// <--
  	int tamanho;
	
Essa váriavel tem o mesmo tamanho que as lajotas, pois este é número o máximo de caminhos.
Também adicionei outro #include logo acima. A biblioteca _<cstring>_ nos permite usar a função _memset()_.
Vamos usar essa função somente para setar como -1 todos os valores dentro da array _calculados_.
Poderia ser qualquer número negativo, usamos isso apenas para saber quais valores já foram calculados ou não.
	
Assim:

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
  
  Agora vamos adicionar a última condição de parada da recursividade: caso o valor do _index_ já tenha sido calculado, retornamos o valor guardado na array _calculados_.
  
  Logo:
  
  	int calculaPulos(int index){
  	
	    if(index >= tamanho-1)
		return 0;
  
	    if(lajotas[index] == 0)
		return tamanho;
            
	    if(calculados[index] != -1)
	    	return calculados[index];
	    
	    return 1 + min(calculaPulos(index+1), calculaPulos(index+2));
  	}//end calculaPulos()
  
  Por fim, basta atualizar o valor de _calculados_ no índice atual e depois retornar seu valor, dessa forma:
  
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
  
  Colocando tudo junto, temos:
  
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
  
  E é isso! \o/
  
 Nosso programinha está pronto e optimizado!
 
 Teste dentro do site do problema original:
 ![Resultado](https://github.com/azevedomath/Pulo-do-Gato/blob/Coding/images/result.png)
