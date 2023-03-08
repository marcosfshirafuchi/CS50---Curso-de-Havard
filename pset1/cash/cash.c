/*CC50: Introdução à Ciência da Computação - O Curso de Harvard, no Brasil
Exercício 3: Dinheiro (versão fácil)
Algoritmos Gulosos ou Algoritmos Ambiciosos
Centavos de dólares

Ao dar o troco, é provável que você queira minimizar o número de moedas que está distribuindo para cada cliente,
para não acabar com o estoque (ou irritar o cliente!). Felizmente, a ciência da computação deu aos caixas
em todos os lugares maneiras de minimizar o número de moedas devidas: algoritmos ambiciosos, também conhecidos
como gulosos ou gananciosos.

De acordo com o Instituto Nacional de Padrões e Tecnologia (NIST), um algoritmo ambicioso é aquele
“que sempre pega a melhor solução imediata, ou local, enquanto encontra uma resposta. Algoritmos ambiciosos encontram
a solução geral ou globalmente ideal para alguns problemas de otimização, mas podem encontrar soluções menos do que
ideais para algumas instâncias de outros problemas.”

O que tudo isso significa? Bem, suponha que um caixa deva a um cliente algum troco e na gaveta desse caixa estejam
moedas de 25, 10, 5 e 1 centavo(s). O problema a ser resolvido é decidir quais moedas e quantas de cada uma entregar
ao cliente. Pense em um caixa “ganancioso” como alguém que quer tirar o maior proveito possível desse problema com
cada moeda que tira da gaveta. Por exemplo, se algum cliente deve pagar 41 centavos, a maior “mordida”(ou seja, melhor
“mordida” imediata ou local) que pode ser feita é 25 centavos. (Essa mordida é "melhor" na medida em que nos deixa mais
perto de 0 ¢ mais rápido do que qualquer outra moeda faria.) Observe que uma mordida desse tamanho reduziria o que era um
problema de 41 ¢ a um problema de 16 ¢, já que 41 - 25 = 16. Ou seja, o restante é um problema semelhante, mas menor.
Desnecessário dizer que outra mordida de 25 centavos seria muito grande (supondo que o caixa prefere não perder dinheiro),
e assim nosso caixa ganancioso mudaria para uma mordida de 10 centavos, deixando-o com um problema de 6 centavos. Nesse
ponto, a ganância pede uma mordida de 5 centavos seguida de uma mordida de 1 centavo, ponto em que o problema é resolvido.
O cliente recebe um quarto, um centavo, um centavo e um centavo: quatro moedas no total. Acontece que essa abordagem
gananciosa (do algoritmo) não é apenas ótima localmente, mas também globalmente para a moeda dos Estados Unidos (e também
da União Europeia). Ou seja, desde que o caixa tenha o suficiente de cada moeda, essa abordagem do maior para o menor
renderá o menor número possível de moedas. Quão menor? Bem, diga-nos você!

Código desenvolvido por Marcos Ferreira Shirafuchi.
*/
#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50
#include <math.h>
int main(void)
{
    float cash;
    int moedas25=0;
    int moedas10=0;
    int moedas5=0;
    int moedas1=0;
    do
    {

	    cash=get_float("Insira seu troco: ");

    }while(cash<=0);

    //converter float para int
    int centavos = round(cash*100);

    //Contar moedas de 25 centavos
    while(centavos >=25)
    {
	    centavos = centavos - 25;
	    moedas25++;
    }

    //Contar moedas de 10 centavos
    while(centavos >=10)
    {
	    centavos = centavos - 10;
	    moedas10++;
    }

    //Contar moedas de 5 centavos
    while(centavos >=5)
    {
    	centavos = centavos - 5;
    	moedas5++;
    }

    //Contar moedas de 1 centavo
    while(centavos >=1)
    {
	    centavos = centavos - 1;
	    moedas1++;
    }
    int total = moedas1 + moedas5 +moedas10 +moedas25;
    printf("%i\n", total);
}