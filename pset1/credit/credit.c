/*CC50: Introdução à Ciência da Computação - O Curso de Harvard, no Brasil
Exercício 4: Crédito (desafio))
Um cartão de crédito (ou débito), é claro, é um cartão de plástico com o qual você pode pagar por bens e serviços.
Impresso nesse cartão está um número que também é armazenado em um banco de dados em algum lugar, de modo que, quando o
cartão for usado para comprar algo, o credor saiba a quem cobrar. Há muitas pessoas com cartões de crédito no mundo,
então esses números são bem longos: American Express usa números de 15 dígitos, MasterCard usa números de 16 dígitos e
Visa usa números de 13 e 16 dígitos. E esses são números decimais (0 a 9), não binários, o que significa, por exemplo,
que a American Express poderia imprimir até 10 ^ 15 = 1.000.000.000.000.000 de cartões exclusivos! (Isso é, hum, um
quatrilhão.)

Na verdade, isso é um pouco exagerado, porque os números de cartão de crédito têm alguma estrutura. Todos os números
American Express começam com 34 ou 37; a maioria dos números do MasterCard começa com 51, 52, 53, 54 ou 55 (eles também
têm alguns outros números iniciais potenciais com os quais não nos preocupamos neste problema); e todos os números Visa
começam com 4. Mas os números de cartão de crédito também têm um “checksum” embutido, uma relação matemática entre pelo
menos um número e outros. Essa soma de verificação permite que os computadores (ou humanos que gostam de matemática)
detectem erros de digitação (por exemplo, transposições), se não números fraudulentos, sem ter que consultar um banco de
dados, que pode ser lento. É claro que um matemático desonesto certamente poderia criar um número falso que, no entanto,
respeite a restrição matemática, portanto, uma pesquisa no banco de dados ainda é necessária para verificações mais
rigorosas.

Algoritmo de Luhn
Então, qual é a fórmula secreta? Bem, a maioria dos cartões usa um algoritmo inventado por Hans Peter Luhn, da IBM. De
acordo com o algoritmo de Luhn, você pode determinar se um número de cartão de crédito é (sintaticamente) válido da
seguinte maneira:

Multiplique cada segundo digito por 2, começando com o penúltimo dígito do número e, em seguida, some os dígitos desses
produtos.
Adicione essa soma à soma dos dígitos que não foram multiplicados por 2.
Se o último dígito do total for 0 (ou, mais formalmente, se o módulo total 10 for congruente com 0), o número é válido!
Isso é meio confuso, então vamos tentar um exemplo com o cartão Visa do David: 4003600000000014.

1- Para fins de discussão, vamos primeiro sublinhar todos os outros dígitos, começando com o penúltimo dígito do número:

4003600000000014

Ok, vamos multiplicar cada um dos dígitos sublinhados por 2:

1 • 2 + 0 • 2 + 0 • 2 + 0 • 2 + 0 • 2 + 6 • 2 + 0 • 2 + 4 • 2

Isso nos dá:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Agora vamos adicionar os dígitos desses produtos (ou seja, não os próprios produtos):

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

2- Agora vamos adicionar essa soma (13) à soma dos dígitos que não foram multiplicados por 2 (começando do final):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

3- Sim, o último dígito dessa soma (20) é 0, então o cartão de David é legítimo!

Portanto, validar números de cartão de crédito não é difícil, mas se torna um pouco tedioso manualmente. Vamos escrever
um programa.

Em um arquivo chamado credit.c em um diretório ~/pset1/credit/, escreva um programa que solicite ao usuário um número de
cartão de crédito e, em seguida, informe (via printf ) se é um número de cartão American Express, MasterCard ou Visa
válido , de acordo com as definições de formato de cada um neste documento. Para que possamos automatizar alguns testes
do seu código, pedimos que a última linha de saída do seu programa seja AMEX\n ou MASTERCARD\n ou VISA\n ou INVALID\n ,
nada mais, nada menos. Para simplificar, você pode assumir que o input do usuário será inteiramente numérica (ou seja,
sem hífens, como pode ser impresso em um cartão real). Mas não presuma que o input do usuário caberá em um int ! Melhor
usar get_long da biblioteca do CS50 para obter o input dos usuários. (Por que?)

Considere o seguinte exemplo de como seu próprio programa deve se comportar quando um número de cartão de crédito válido
é fornecido (sem hífens).

$ ./credit
Número: 4003600000000014
VISA
Agora, get_long em si rejeitará hífens (e mais) de qualquer maneira:

$ ./credit
Número: 4003-6000-0000-0014
Número: foo
Número: 4003600000000014
VISA
Mas depende de você pegar entradas que não sejam números de cartão de crédito (por exemplo, um número de telefone), mesmo
que sejam numéricos:

$ ./credit
Número: 6176292929
INVALID
Teste seu programa com um monte de entradas, válidas e inválidas. (Certamente o faremos!) Aqui estão alguns números de
cartão que o PayPal recomenda para teste.

Se o seu programa se comporta incorretamente com alguns inputs(ou não compila), é hora de depurar!

Como testar seu código no IDE do CS50?
Execute o seguinte para avaliar se seu código está correto usando check50. Mas certifique-se de compilar e testar você
mesmo!

check50 cs50/problems/2021/x/credit
Execute o seguinte para avaliar o style do seu código usando style50.

style50 credit.c

Código desenvolvido por Marcos Ferreira Shirafuchi.
*/
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    bool res;
    string numero;
    int cont2=0;
    //O laço de repetição do-while verifica se a variavel boleana res igual falso para continuar o laço
    do{
        //Usuário digite o numero do cartão
        numero= get_string("Número: ");
        //O contador cont2 conta o tamanho do vetor numero[p]
        for(int p=0; numero[p]!='\0';p++)
        {
            cont2++;
        }
        string numero2[cont2];
        //Verificação do número digitado
        for(int p=0; p<cont2;p++)
        {
            //Verifica se o usuário digitou somente número
            //Se digitou apenas número, a váriavel boleana 'res' recebe true.
            if(numero[p]>='0'&&numero[p]<='9')
            {
               numero2[p]=&numero[p];
             //  printf("%s",numero2[p]);
               res=true;
            }//Se não, a váriavel boleana 'res' recebe false e a variável p recebe o valor do contador cont2.
            else if(numero[p]=='-'||(numero[p]>='A'&&numero[p]<='Z')||(numero[p]>='a'&&numero[p]<='z'))
            {
                res= false;
                p=cont2;
            }
          /* else if(numero[p]==' ')
            {
                for(int i=p+1; numero!='';i++)
                {
                    numero2[p]=numero[i];
                    printf("%s\n",numero2[p]);
                }


            }*/

     }
    }while(res==false);
    printf("\n");
    //Depois de garantir que foi apenas digitado número
    int cont=0;

    //Laço de repetição para contar o tamanho do ve
    for(int q=0; numero[q]!='\0';q++)
    {
        cont++;
    }
    //Criação de 4 vetores do tipo longo com o contador cont
    long digito[cont];
    long digito2[cont];
    long digito3[cont];
    long digito4[cont];

    //Transformação de string para inteira em cada vetor

    for(int j=0; numero[j]!='\0';j++)
    {
        digito[j]=numero[j]-48;
    }
    printf("\n");
    int l=0;
    /*1- Para fins de discussão, vamos primeiro sublinhar todos os outros dígitos,
    começando com o penúltimo dígito do número:
    4003600000000014

    Ok, vamos multiplicar cada um dos dígitos sublinhados por 2:

    1 • 2 + 0 • 2 + 0 • 2 + 0 • 2 + 0 • 2 + 6 • 2 + 0 • 2 + 4 • 2

    Isso nos dá:

    2 + 0 + 0 + 0 + 0 + 12 + 0 + 8
*/
    for(int k=cont-2; k>=0 ;k-=2)
    {

        digito2[l]=digito[k]*2;
        l++;
    }
    int n=0,soma=0;

  /*Agora vamos adicionar os dígitos desses produtos (ou seja, não os próprios produtos):

    2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
   */
    for(int m=0; m<=l;m++)
    {
        //Se o numero for maior que 9, Divide o numero por 10 e depois tira o resto da visão
        //variavel soma os digitos do vetor
        if(digito2[m]>9)
        {
            digito3[n]=digito2[m]/10;
            soma=soma+digito3[n];
            n++;
            digito3[n]=digito2[m]%10;
            soma=soma+digito3[n];
            n++;
        }
        else if(digito2[m]>=0 && digito2[m]<=9)
        {
            digito3[n]=digito2[m];
            soma=soma+digito3[n];
            n++;
        }

    }
    int o=1;
    int aux3=0;
    //O vetor digito4 posição 0 recebe a várivel soma
    digito4[0]=soma;
    aux3=soma;
    /*2- Agora vamos adicionar essa soma (13) à soma dos dígitos que não foram multiplicados por 2 (começando do final):

        13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
    */
    for(int p=cont-1; p>=0 ;p-=2)
    {
        digito4[o]=digito[p];
        aux3=aux3+digito4[o];
        o++;

    }
    /*3- Sim, o último dígito dessa soma (20) é 0, então o cartão de David é legítimo!*/
    if(aux3%10==0)
    {
        //Verifica os tipos de cartão
        if((digito[0]==3&&digito[1]==4) || (digito[0]==3&&digito[1]==7))
        {
            printf("AMEX\n");

        }
        else if((digito[0]==5&&digito[1]==1)|| (digito[0]==5&&digito[1]==2)|| (digito[0]==5&&digito[1]==3)|| (digito[0]==5&&digito[1]==4)|| (digito[0]==5&&digito[1]==5))
        {
            printf("MASTERCARD\n");

        }
        else if(digito[0]==4)
        {
            printf("VISA\n");

        }
    }//Cartão inválido
    else
    {
        printf("INVALID\n");
    }
}