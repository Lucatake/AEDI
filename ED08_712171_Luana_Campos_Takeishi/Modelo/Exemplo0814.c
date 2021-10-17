/**
    Exemplo0814 - Versao 0.1 - 22/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * menorPar - funcao para achar o menor numero par
 * em um arranjo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
int menorPar( int n, int array[] )
{
    //definir variaveis com valor inicial
    int menor = 0;

    for (int i = 0; i < n; i++)
    {
        //para o prmeiro valor
        if(i==0)
        {
            menor = array[i];
        }
        //para os demais valores
        if (array[i] < menor && (array[i] % 2 == 0))
        {
            menor = array[i];
        }  
    }
    //retornar valor
    return(menor);
}

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0814( )
{
    //identificar
    IO_id("\nEXEMPLO0814 - Programa - v0.1");
    //id_cabecalho( "Dados_0814.txt", "0814", "v0.1 - 14/10/20" );
    //ler dados
    int n = freadArraySize("Array_0814.txt");
    //definir array
    int array[n];
    //ler array
    readIntArray("Array_0814.txt", n, array);
    //achar menor valor
    int menor = menorPar( n, array );
    //mostrar valor
    if (menor != 0)
    {
        IO_printf("\n Menor par = %d", menor);
    }
    else
    {
        IO_printf("\n Invalido");
    }
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0814

/**
---------------------------------------------- documentacao complementar
exercicio:
procurar o menor valor par em um arranjo.
Para testar, receber um nome de arquivo como parametro e
aplicar a funcao sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor da tabela como referencia inicial
para o menor valor.
Exemplo: lerArquivo ( "DADOS.TXT", n, arranjo );
menor = acharMenorPar ( n, arranjo );
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 Menor par = 2
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         22/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.4       01.   ( OK )  22/10  - Achar menor par em um array de arquivo.
*/