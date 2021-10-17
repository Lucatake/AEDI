/**
    Exemplo0317 - Versao 0.1 - 08/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0317      exemplo0317.c
    Windows:    gcc -o exemplo0317.exe  exemplo0317.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0317
    Windows:    exemplo0317
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * valorInt07( ) - Metodo para ler valores inteiros
 * contar e mostrar os que sao multiplos de 2 e 3 e
 * pertencem ao intervalo definido
*/
void valorInt07( )
{
    //definir variaveis com valor inicial
    int intervaloA = 0, intervaloB = 0, quantidade = 0, 
    valores = 0, count = 0, x = 0, total = 0;

    //identificar
    IO_id("\nEXEMPLO0317 - Programa - v0.1");

    //para receber um intervalo válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readint("\nEntre com um valor inteiro para ser o inicio do intervalo: ");
        intervaloB = IO_readint("Entre com um valor inteiro para ser o fim do intervalo: ");
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
        //entrar com valores a serem testados (1 por vez)
        valores = IO_readint("\nEntre com um valor a ser testado: ");
        //testar se sao multiplos de 2 e 3 e estao no intervalo
        if ((valores % 2 == 0) && (valores % 3 == 0) && (valores >= intervaloA) && (valores <= intervaloB))
        {
            IO_printf("%d e' multiplo de 2 E 3 E pertence ao intervalo.\n", valores);
            total++;
        }
        else
        {
            IO_printf("%d NAO atende todas as especificacoes.\n", valores);
        }//end if
    }//end for

    //mostrar o total de valores
    if (total != 0)
    {
        IO_printf("\nTotal de %d valores multiplos de 2 E 3 E pertencem ao intervalo.", total);
    }
    else
    {
        IO_println("\nOs valores nao estao dentro das especificacoes.");
    }//end if
}//end valorInt07


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    valorInt07( );

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler dois valores inteiros, limites para definirem um intervalo;
- ler uma quantidade de valores inteiros a serem testados;
- ler outros tantos valores quantos os indicados pela quantidade, um por vez;
- contar e mostrar dentre esses valores lidos os que forem multiplos de 2 e de 3, ao mesmo tempo,
e pertençam ao intervalo.
---------------------------------------------- notas / observacoes / comentarios
obs: nao sei se a solucao para mostrar os valores e depois a quantidade contada esta boa
---------------------------------------------- previsao de testes
a.) 10 20    3     6 12  18
b.)  1 50   10    24 36 -19 100 55 48 63 98 15 22
c.) 90 20
d.) 20 90   -3
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

*/