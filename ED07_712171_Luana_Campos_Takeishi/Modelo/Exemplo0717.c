/**
    Exemplo0717 - Versao 0.1 - 10/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * somaPot - somar certa quantidade de
 * valores lidos de um arquivo
 * @param fileRead - nome do arquivo lido
 * @param fileWrite - nome do arquivo escrito
 * @param q - quantidade de valores
*/
void somaPot(chars fileRead, chars fileWrite, int q)
{
  //definir dados
  FILE *arquivoR = fopen(fileRead, "rt");
  FILE *arquivoW = fopen(fileWrite, "at");
  int y = 0;
  double valor = 0, soma = 0;

  //contar as linhas
  while (!feof(arquivoR) && y <= q)
  {
    //tentar ler
    fscanf(arquivoR, "%lf", &valor);
    //somar
    soma = soma + valor;
    //ir para o proximo
    y++;
  } //end while

  if( q >= y )
  {
    IO_fprintf(arquivoW, "quantidade = %d\n", q);
    IO_fprintf(arquivoW, "quantidade maior que o numero de valores existentes\n");
    IO_fprintf(arquivoW, "\n");
  }
  else
  {
    IO_fprintf(arquivoW, "quantidade = %d\n", q);
    IO_fprintf(arquivoW,"soma = %lf\n", soma);
    IO_fprintf(arquivoW, "\n");
  }//end if

  //fechar arquivos (INDISPENSAVEL para gravacao)
  fclose(arquivoR);
  fclose(arquivoW);
} //end somaPot


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0717( )
{
    //identificar
    IO_id("\nEXEMPLO0717 - Programa - v0.1");
    //id_cabecalho( "RESULTADO06.TXT", "0717", "v0.1 - 07/10/20" );
    //ler do teclado
    int n = quantidadesL("\n quantidade: ");
    //chamar funcao
    somaPot("Dados_0714.txt","RESULTADO07.TXT", n);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0717


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado para representar uma quantidade e
calcular a soma de tantos valores quanto os primeiros em valores gravados como
inversos das potencias de 7 do exercício 04 acima.
Gravar em outro arquivo ("RESULTADO07.TXT") cada quantidade e seu resultado.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         10/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.7       01.   ( OK )  10/10  - Somar quantidade de valores (double) de um arquivo e gravar resultado em outro.
*/