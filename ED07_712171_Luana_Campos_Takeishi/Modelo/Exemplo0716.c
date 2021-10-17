/**
    Exemplo0716 - Versao 0.1 - 10/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * somaFile - somar certa quantidade de
 * valores lidos de um arquivo
 * @param fileRead - nome do arquivo lido
 * @param fileWrite - nome do arquivo escrito
 * @param q - quantidade de valores
*/
void somaFile(chars fileRead, chars fileWrite, int q)
{
  //definir dados
  FILE *arquivoR = fopen(fileRead, "rt");
  FILE *arquivoW = fopen(fileWrite, "at");
  int y = 0;
  double valor = 0, soma = 0;

  //contar as linhas
  while (!feof(arquivoR) && y != q)
  {
    //tentar ler
    fscanf(arquivoR, "%lf", &valor);
    //somar
    soma = soma + valor;
    //ir para o proximo
    y++;
  } //end while

  if( q <= y )
  {
    IO_fprintf(arquivoW, "quantidade = %d\n", q);
    IO_fprintf(arquivoW,"soma = %lf\n", soma);
    IO_fprintf(arquivoW, "\n");
  }
  else
  {
    IO_fprintf(arquivoW, "quantidade = %d\n", q);
    IO_fprintf(arquivoW, "quantidade maior que o numero de valores existentes\n");
     IO_fprintf(arquivoW, "\n");
    
  }//end if

  //fechar arquivos (INDISPENSAVEL para gravacao)
  fclose(arquivoR);
  fclose(arquivoW);
} //end somaFile

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0716( )
{
    //identificar
    IO_id("\nEXEMPLO0716 - Programa - v0.1");
    //id_cabecalho( "RESULTADO06.TXT", "0716", "v0.1 - 07/10/20" );
    //ler do teclado
    int n = quantidadesL("\n quantidade: ");
    //chamar funcao
    somaFile("Dados_0715.txt","RESULTADO06.TXT", n);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0716


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado para representar certa quantidade de parcelas
a serem somadas dentre os primeiros valores gravados no exercicio anterior.
Testar essa função para quantidades diferentes.
Gravar em outro arquivo ("RESULTADO06.TXT") cada quantidade e seu resultado.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         10/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.6       01.   ( OK )  10/10  - Somar quantidade de valores (double) de um arquivo e gravar resultado em outro.
*/