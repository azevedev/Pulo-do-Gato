# Pulo do Gato
  ## Resolvendo problemas computacionais usando Recursividade e Programação Dinâmica

 Link do problema original: https://olimpiada.ic.unicamp.br/pratique/pj/2018/f3/pulo/
 

 ### O problema
   O gato Obinho gosta de brincar atravessando filas de lajotas no chão de um prédio. Ele sempre começa na primeira lajota, da esquerda para a direita, e sempre para na última lajota da fila. Obinho é muito preguiçoso, e só irá saltar até duas lajotas por vez. Outra caracteristica de Obinho é que ele gosta de pular somente em lajotas pretas e ignora as lajotas brancas podendo até mesmo desistir de brincar por causa delas.  

   ![Obinho](https://github.com/azevedomath/Pulo-do-Gato/blob/Coding/2018f3pj_pulo.png)
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
  Primeiro, vamos declarar nossas variáveis:
  > #define MAX 10005
  >
  > int lajotas [MAX];
  
  > int tamanho;
  
 

  
  
