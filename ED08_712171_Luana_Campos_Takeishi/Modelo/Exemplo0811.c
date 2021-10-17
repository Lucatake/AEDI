/**
    Exemplo0811 - Versao 0.1 - 15/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * makeArray( ) - metodo para montar um array
 * a partir de certa quantidade
 * garantir somente valores pares*
*/
int makeArray( )
{
    //definir variaveis
    int n, teste = 0;
    int array[n];
    chars a = "\0";

    //ler do teclado
    n = quantidadesL("\n tamanho: ");

    //montar array
    for (int i = 0; i < n; i++)
    {
        //ate que o valor seja positivo e par
        do
        {
            array[i] = IO_readint("\n valor: ");
            teste = array[i];
        } while ( ! ((teste > 0) && (teste % 2 == 0)) );

        a = IO_concat( a, IO_concat(IO_toString_d(array[i]), ", ") );
    }//end for
    
    //mostrar array
    IO_printf("\n array: %s", a);
}


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0811( )
{
    //identificar
    IO_id("\nEXEMPLO0811 - Programa - v0.1");
    //id_cabecalho( "Dados_0811.txt", "0811", "v0.1 - 14/10/20" );
    //ler do teclado

    //chamar funcao
    makeArray( );
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0811

/**
---------------------------------------------- documentacao complementar
exercicio:
ler o tamanho de um arranjo para inteiros do teclado,
bem como todos os seus elementos, garantindo que so tenha valores positivos e pares.
Verificar se as dimensoes nao sao nulas ou negativas.
Para testar, ler diferentes quantidades de dados.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 tamanho: 5
 valor: 2
 valor: 3
 valor: 2
 valor: 4
 valor: 6
 valor: 5
 valor: 5
 valor: 5
 valor: 8
 array: 2, 2, 4, 6, 8,

 tamanho: 8
 valor: -10
 valor: 2
 valor: 9
 valor: 12
 valor: 22
 valor: 58
 valor: 76
 valor: 98
 valor: 46
 valor: 12
 array: 2, 12, 22, 58, 76, 98, 46, 12,
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         15/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.1       01.   ( OK )  15/10  - Montar array do teclado com int positivos pares.
*/