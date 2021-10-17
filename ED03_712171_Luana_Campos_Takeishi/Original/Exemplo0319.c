/**
    Exemplo0319 - Versao 0.1 - 08/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0319      exemplo0319.c
    Windows:    gcc -o exemplo0319.exe  exemplo0319.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0319
    Windows:    exemplo0319
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * valorReal09( ) - Metodo para ler valores inteiros
 * contar e mostrar os que sao multiplos de 3 e nao 5 
 * e pertencem ao intervalo definido
*/
void valorReal09( )
{
    //definir variaveis com valor inicial
    double intervaloA = 0.0, intervaloB = 0.0, valores = 0.0;
    int quantidade = 0, count = 0, x = 0, total = 0, impar = 0;

    //identificar
    IO_id("\nEXEMPLO0319 - Programa - v0.1");

    //para receber um intervalo válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readdouble("\nEntre com um valor real para ser o inicio do intervalo: ");
        intervaloB = IO_readdouble("Entre com um valor real para ser o fim do intervalo: ");
        //testar se o intervalo e' valido
        if ( intervaloA < intervaloB )
        {
            x ++;
        }
        else
        {
            IO_println("Intervalo invalido.");
            x = 0;
        }//end if
    } while ( x == 0 );

    //para receber uma quantidade valida > 0
    do{
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint("\nEntre com um valor inteiro para ser a quantidade de valores a serem testados: ");
        //testar se maior que zero
        if ( quantidade > 0 )
        {
            x --;
        }
        else
        {
            IO_println("Valor invalido.");
            x = 1;
        }//end if
    } while ( x == 1 );

    //repetir o numero de vezes requisitado no passo anterior
    for (count = 0; count < quantidade; count++)
    {
        //entrar com valores reais a serem testados (1 por vez)
        valores = IO_readdouble("\nEntre com um valor a ser testado: ");
        //isolar a parte inteira
        impar = (int) valores;
        //testar se estao no intervalo e se sua parte inteira e' impar
        if ((valores >= intervaloA) && (valores <= intervaloB) && (impar % 2 != 0))
        {
            IO_printf("%f pertence ao intervalo e sua parte inteira (%d) e' impar.\n", valores, impar);
            total++;
        }
        else
        {
            IO_printf("%f NAO atende todas as especificacoes.\n", valores);
        }//end if
    }//end for

    //mostrar o total de valores
    if (total != 0)
    {
        IO_printf("\nTotal de %d valores que pertencem ao intervalo [%f, %f] E tem a parte inteira impar.", total, intervaloA, intervaloB);
    }
    else
    {
        IO_println("\nNenhum dos valores estao dentro das especificacoes.");
    }//end if
}//end valorReal09


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    valorReal09( );

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler dois valores reais, o primeiro menor que o segundo, confirmadamente,
para definirem um intervalo;
- ler a quantidade de valores reais a serem testados, e
ler outros tantos valores quantos os indicados por essa quantidade;
- contar e mostrar todos os valores lidos, pertencentes ao do intervalo,
cujas partes inteiras forem numeros impares.
DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),
antes de testar se e par (ver Exemplo0110).
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 10.998  20.567    3    6.78  10.93  17.94
b.)  1.832  50.145   10   25.75  36.99 -19.83 101.56 45.42 15.88 30.21 42.777 10.85 21.12
c.) 90 20   -3
d.)-20 90   2 -19.56 -1.777
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         08/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste
 0.1       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do comeco
 0.2       01.   ( OK )  - letras maiusculas de uma palavra maior que 'N' do comeco
 0.3       01.   ( OK )  - letras maiusculas de uma palavra menor que 'N' do fim
 0.4       01.   ( OK )  - letras dentro de uma cadeia de caracteres 
 0.5       01.   ( OK )  - digitos dentro de uma cadeia de caracteres do fim
 0.6       01.   ( OK )  - nao digitos e nao letra minuscula dentro de uma cadeia de caracteres
 0.7       01.   ( OK )  - certa quantidade de valores inteiros dentro de um intervalo e multiplos de 2 E 3
 0.8       01.   ( OK )  - certa quantidade de valores inteiros dentro de um intervalo e multiplos de 3 E NAO 5
 0.9       01.   ( OK )  - certa quantidade de valores reais dentro de um intervalo e impares

*/