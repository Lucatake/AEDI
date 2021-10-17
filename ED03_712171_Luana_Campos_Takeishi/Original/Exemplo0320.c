/**
    Exemplo0320 - Versao 0.1 - 08/09/2020
    Author: Luana Campos Takeishi
    Matr'icula: 712171

    Para compilar em terminal (janela de comandos):
    Linux:      gcc -o exemplo0320      exemplo0320.c
    Windows:    gcc -o exemplo0320.exe  exemplo0320.c
    Para executar em terminal (janela de comandos):
    Linux:      ./exemplo0320
    Windows:    exemplo0320
*/

//dependencias
#include "io.h"     //para definicoes proprias

/**
 * valorReal10( ) - Metodo para ler valores reais
 * contar e mostrar os que estao dentro do intervalo 
 * real de precisao 
*/
void valorReal10( )
{
    //definir variaveis com valor inicial
    double intervaloA = 0.0, intervaloB = 0.0, valores = 0.0, fracao = 0.0;
    int quantidade = 0, count = 0, x = 0, total = 0, inteiro = 0;

    //identificar
    IO_id("\nEXEMPLO0320 - Programa - v0.1");

    //para receber um intervalo de precisao válido
    do{
        //entrar com os valores dos intervalos
        intervaloA = IO_readdouble("\nEntre com um valor real > 0 para ser o inicio do intervalo: ");
        intervaloB = IO_readdouble("Entre com um valor real < 1 para ser o fim do intervalo: ");
        //testar se o intervalo e' valido
        if ((intervaloA > 0.0) && (intervaloB < 1.0) && (intervaloA < intervaloB ))
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
        valores = IO_readdouble("\nEntre com um valor real a ser testado: ");
        //parte interia
        inteiro = (int) valores;
        //isolar a parte fracionaria
        fracao = valores - inteiro;
        //testar se parte fracionaria esta dentro do intervalo de precisao 
        if ((fracao >= intervaloA) && (fracao <= intervaloB))
        {
            IO_printf("%f parte fracionaria de %f esta dentro do intervalo de precisao.\n", fracao, valores);
            total++;
        }
        else
        {
            IO_printf("%f NAO esta' dentro do intervalo de precisao.\n", valores);
        }//end if
    }//end for

    //mostrar o total de valores
    if (total != 0)
    {
        IO_printf("\nTotal de %d valores dentro do intervalo [%f, %f] de precisao.", total, intervaloA, intervaloB);
    }
    else
    {
        IO_println("\nNenhum dos valores estao dentro do inteervalo de precisao.");
    }//end if
}//end valorReal10


/*
 * Funcao principal.
 * @return codigo de encerramento
*/
int main( )
{
    //chamar funcao
    valorReal10( );

    //encerrar
    IO_pause("\nApertar <enter> para terminar");
    return (0);
}//end main

/*
---------------------------------------------- documentacao complementar
exercicio:
- ler dois valores reais, maiores que 0 e menores que 1, confirmadamente,
para definirem um intervalo de precisao;
- ler uma quantidade de valores reais a serem testados, e
ler outros tantos valores quantos os indicados por essa quantidade;
- contar e mostrar todos os valores lidos
que tenham suas partes fracionarias dentro do intervalo de precisao.
DICA: Usar conformacao de tipo (type casting) para isolar a parte inteira (int),
e obter a parte fracionaria mediante a subtracao da parte inteira, antes de testar.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0.456  0.998    3    6.463  8.999  1.267
b.) 0.142  0.565    4    9.954  3.143  5.555  0.143
c.) -0.984 0.222   
d.) 0.298  0.199   -3
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
 1.0       01.   ( OK )  - certa quantidade de valores reais dentro de um intervalo de precisao

*/