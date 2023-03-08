/*CC50: Introdução à Ciência da Computação - O Curso de Harvard, no Brasil
Lab 1: População
Laboratório 1: crescimento populacional
Determine quanto tempo leva para uma população atingir um determinado tamanho.

$ ./population
Start size: 100
End size: 200
Years: 9
Background
Digamos que temos uma população de n lhamas. A cada ano, nascem n / 3 novas lhamas e n / 4 morrem.

Por exemplo, se começarmos com n = 1.200 lhamas, no primeiro ano, 1.200 / 3 = 400 novas lhamas nascerão e
1.200 / 4 = 300 lhamas morrerão. No final daquele ano, teríamos 1.200 + 400 - 300 = 1.300 lhamas.

Para tentar outro exemplo, se começarmos com n = 1000 lhamas, no final do ano teremos 1000/3 = 333,33 novas lhamas.
Não podemos ter uma parte decimal de uma lhama, entretanto, vamos truncar o decimal para que 333 novas lhamas nasçam.
1000/4 = 250 lhamas passarão, então terminaremos com um total de 1000 + 333 - 250 = 1083 lhamas no final do ano.
Código desenvolvido por Marcos Ferreira Shirafuchi.
*/
#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int main(void)
{
    int popinicial, popfinal,contador_anos=0,n;
    // get_int é uma função específica da biblioteca do CS50!
    do
    {
        // TODO: Solicite o valor inicial ao usuário
        popinicial = get_int("Digite o tamanho da população inicial? ");

    }while(popinicial< 9);
    printf("\n");

    do
    {
        // TODO: Solicite o valor final ao usuário
        popfinal = get_int("Digite o tamanho da população final? ");

    }while(popfinal< popinicial);
    printf("\n");

    do
    {
        n = popinicial;
        // TODO: Calcule o número de anos até o limite
        popinicial = n + (n / 3) - (n / 4);
        contador_anos++;
    }while(popinicial<popfinal);

    // TODO: Imprima o número de anos
    printf("O número é %d ano(s)\n", contador_anos);

}