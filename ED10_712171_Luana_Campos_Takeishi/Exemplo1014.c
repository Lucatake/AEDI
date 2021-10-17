/**
    Exemplo1014 - Versao 0.1 - 29/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

chars somaArray( int n, int array1[], int k, int m, int array2[])
{
    //definir variaveis
    chars soma = "\0";
    int s = 0;
    int p = 0;
    int array3[p];

    //testar se sao do mesmo tamanho
    if (n == m)
    {
        //multiplicar arranjo 2 pela constante
        for (int i = 0; i < m; i++)
        {
            array3[i]= array2[i]*k;
        }
        //somar array
        for (int q = 0; q < n; q++)
        {
            s = array3[q]+array1[q];
            soma = IO_concat(soma, IO_concat(IO_toString_d(s), "   "));
        }
    } else
    {
        IO_printf("\n arrays com tamanhos diferentes.");
    }
    
    return(soma);
}

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1014( )
{
    //identificar
    IO_id("\nEXEMPLO1014 - Programa - v0.1");

    //definir variaveis
    //array A
    int n = freadArraySize("EX1011.txt");
    int array [n];
    freadIntArray("EX1011.txt", n, array);
    //array B
    int p = freadArraySize("EXC.txt");
    int arrayB [p];
    freadIntArray("EXC.txt", p, arrayB);
    //somar arranjos
    chars soma = somaArray( n, array, 2, p, arrayB);
    IO_printf("\n soma dos arranjos: %s", soma);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1014

/**
---------------------------------------------- documentacao complementar
exercicio:
operar a soma de dois arranjos, com o segundo escalado por uma constante (k).
Para testar, receber dados de arquivos e
aplicar a funcao sobre os arranjos com os valores lidos;
DICA: Verificar, primeiro, se os tamanhos sao compativeis.
Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
arranjo2 = lerArquivo ( "DADOS2.TXT" );
soma = somar ( arranjo1, k, arranjo2 );
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
 soma dos arranjos: 44   36   84   148   140
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.4       01.   ( OK )  29/10  - Somar dois arranjos e um deles multiplicado por constante.
*/