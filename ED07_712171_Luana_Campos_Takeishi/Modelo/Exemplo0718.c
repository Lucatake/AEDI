/**
    Exemplo0718 - Versao 0.1 - 10/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao para achar o termo 'n' da sequencia de Fibonacci
 * (recursividade nao e' vantajosa nesse caso)
*/
void fibonacci (chars fileName, int n)
{
    //variavel com valor inicial
    int fibo = 1, f = 0;
    FILE *arquivo = fopen(fileName, "wt");
    //verificar o termo
    //se nao for o primeiro ou segundo termo
    if( n > 2 )
    {
        for( int i = 0; i < n; i = i + 2 )
        {
            f = f + fibo;       //termo 1
            IO_fprintf(arquivo,"%d\n", f);
            fibo = fibo + f;    //termo 2
            IO_fprintf(arquivo,"%d\n", fibo);
        }//end for
    }//end if
}//end fibonacci

/**
 * somaFibo - somar certa quantidade de
 * valores lidos de um arquivo
 * @param fileRead - nome do arquivo lido
 * @param fileWrite - nome do arquivo escrito
 * @param q - quantidade de valores
*/
void somaFibo(chars fileWrite, int q)
{
  //definir dados
  FILE *arquivoR = fopen("Fibonacci.txt", "rt");
  FILE *arquivoW = fopen(fileWrite, "at");
  int valor = 0, soma = 0, i = q;

  while (!feof(arquivoR) && i > 0)
  {
    //tentar ler
    IO_fscanf(arquivoR, "%d", &valor);
    //IO_printf( " %d\n", valor);
    //somar
    soma = soma + valor;
    //ir para o proximo
    i--;
  }//end while

    IO_fprintf(arquivoW, "quantidade = %d\n", q);
    IO_fprintf(arquivoW,"soma = %d\n", soma);


  //fechar arquivos (INDISPENSAVEL para gravacao)
  fclose(arquivoR);
  fclose(arquivoW);
} //end somaFibo


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0718( )
{
    //identificar
    IO_id("\nEXEMPLO0718 - Programa - v0.1");
    //id_cabecalho( "RESULTADO06.TXT", "0718", "v0.1 - 07/10/20" );
    //chamar funcao
    //ler do teclado
    int n = quantidadesL("\n quantidade: ");
    //fibonacci ("Fibonacci.txt", n );
    somaFibo("RESULTADO08.TXT", n);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0718


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado para representar uma quantidade e
gravar tantos valores quanto os correspondentes aos primeiros termos pares da serie de Fibonacci.
Gravar em outro arquivo ("RESULTADO08.TXT") cada quantidade e seu resultado.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         10/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.8       01.   ( OK )  10/10  - Somar quantidade de valores (double) de Fibonacci e gravar em arquivo.
*/