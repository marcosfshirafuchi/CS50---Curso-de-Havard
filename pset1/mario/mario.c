/*CC50: Introdução à Ciência da Computação - O Curso de Harvard, no Brasil
Exercício 2: Mario (desafio)
Mundo 1-1
No início de World 1-1 em Super Mario Brothers, da Nintendo, Mario deve pular pirâmides de blocos adjacentes, conforme mostrado abaixo.

Exemplo Jogo Mario World

Vamos recriar essas pirâmides em C, ainda que em texto, usando hashes ( # ) para tijolos, a la a seguir. Cada hash é um pouco mais alto do que largo, então as pirâmides em si também são mais altas do que largas.

      #  #
     ##  ##
    ###  ###
   ####  ####
Código desenvolvido por Marcos Ferreira Shirafuchi.
*/
#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int main(void)
{
    int altura, altura2;
    // get_int é uma função específica da biblioteca do CS50!
    do
    {
        altura = get_int("Digite a altura da piramide? ");

    }while(altura< 1 || altura > 8);
    printf("\n");
    altura2=altura;
    //Altura da pirâmide
    for(int p=0; p<altura;p++)
    {
        //imprimir as hashes
        for(int j=0; j<(altura2);j++)
        {

          //imprimi os pontos/espaço do lado esquedo das hashes
            for(int k=0;k<(altura-1);k++)
            {
                printf(" ");
            }
            altura--;
            // printf("%d",j);
            //Verifica a posição do contador da hashe(j)
            if(j==0)
            {
                //Imprimi a hashe do lado esquerdo
                printf("#");

                //Separe 2 espaço entre hashes do lado esquerdo e direito
                for(int i=0;i<2;i++)
                {
                    printf(" ");
                }
                //Imprimi a hashe do lado direito
                printf("#");
            }
            else
            {

                int m=j;
                //Imprimi 2 ou mais hashes do lado esquerdo
                for(int l=0;l<=m;l++)
                {

                    printf("#");
                }
                //Separe 2 espaço entre hashes do lado esquerdo e direito
                 for(int i=0;i<2;i++)
                {
                    printf(" ");
                }
                //Imprimi 2 ou mais hashes do lado direito
                for(int l=0;l<=m;l++)
                {

                    printf("#");
                }



            }


            printf("\n");


        }


    }

}