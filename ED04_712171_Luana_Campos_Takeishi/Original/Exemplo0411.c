/*
    Exemplo0411 - Versao 0.1 - 14/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0411      exemplo0411.c
    Windows:    gcc -o exemplo0411.exe  exemplo0411.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0411
    Windows:    exemplo0411
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * valorReal01( ) - Metodo para ler valores reais
 * contar quantos sao pares dentro do intervalo 
 * e quantos estao fora dele
*/
void valorReal01( )
{
    //definir variaveis com valor inicial
    double intervaloA = 0.0, intervaloB = 0.0, valores = 0.0;
    chars pares = "";
    int quantidade = 0, count = 0, x = 0, totalD = 0, totalF = 0, inteiro = 0;

    //para receber um intervalo de precisao válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readdouble("\nEntre com um valor real para ser o inicio do intervalo: ");
        intervaloB = IO_readdouble("Entre com um valor real para ser o fim do intervalo: ");
        //testar se o intervalo e' valido
        if (intervaloA < intervaloB )
        {
            //se sim, sair do procedimento
            x ++;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Intervalo invalido.");
            //e repetir o procedimento
            x = 0;
        }//end if
    } while ( x == 0 );

    //para receber uma quantidade valida > 0
    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint("\nEntre com a quantidade de valores a serem testados (inteiro): ");
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            //se sim, sair do procedimento
            x --;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Valor invalido.");
            //e repetir o procedimento
            x = 1;
        }//end if
    } while ( x == 1 );

    //repetir o numero de vezes requisitado no passo anterior
    for (count = 0; count < quantidade; count++)
    {
        //entrar com os valores reais separados por espaco
        valores = IO_readdouble("\nEntre com valores reais: ");
        //separar parte inteira
        inteiro = (int) valores;
        //se esta' dentro do intevalo
        if(valores >= intervaloA && valores <= intervaloB)
        {
            //se parte inteira e' par
            if(inteiro % 2 == 0)
            {
                //concatenar valores
                pares = IO_concat(IO_concat(pares, IO_toString_f(valores)), ", ");
                //contar quantidade de valores dentro
                totalD++;
            }//end if
        }
        else
        {
            //contar quantidade de valores fora
            totalF++;
        }
        //end if
    }//end for

    //mostrar o total de valores
    if (totalD != 0)
    {
        IO_printf("\n%ssao %d valores pares dentro do intervalo [%f, %f]", pares, totalD, intervaloA, intervaloB);
        IO_printf("\n e %d valores estao fora do intervalo [%f, %f].", totalF, intervaloA, intervaloB);
    }
    else
    {
        IO_println("\nNenhum dos valores estao dentro do intervalo.");
    }//end if
}//end valorReal01

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //identificar
    IO_id("\nEXEMPLO0411 - Programa - v0.1");

    //chamar funcao
    valorReal01( );

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}

/**
---------------------------------------------- documentacao complementar
exercicio: 
- ler dois valores reais para definir um intervalo fechado;
- ler certa quantidade de valores reais e
- contar quantos desses valores sao pares e estao dentro do 
intervalo, e quantos estao fora dele.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) -5.674  10.7843      4       3.567 -9.879 10.234 26.0134
b.) 5.674   10.7843      5       3.567 -9.879 10.234 6.0134 7.345
c.) 15.674  10.7843
d.) 6.983   23.745      -10
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         14/09          esboco
---------------------------------------------- testes
Exercicio    Versao  Teste
 0.1  14/09 - 01.   ( OK )  - quantidade de valores reais pares dentro de um intervalo real e fora.

*/

