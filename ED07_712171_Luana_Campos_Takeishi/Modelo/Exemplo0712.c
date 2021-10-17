/**
    Exemplo0712 - Versao 0.1 - 07/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * writeM3I - gravar em arquivo certa 
 * quantidade de valores pares multiplos de 3.
 * @param fileName - nome do arquivo
 * @param q - quantidade de valores
*/
void writeM3I( chars fileName, int q )
{
  //definir dados
    FILE *arquivo = fopen(fileName, "at");
  //gravar quantidade de valores
    IO_fprintf(arquivo, " quantidade: %d\n", q);
  //repetir 'q' vezes
    for (int i = (q * 2) - 1; i > 0; i = i - 2)
    {
      //calcular valor
      //e gravar valor
        IO_fprintf(arquivo, "%d\n", i * 3 );
    }//end for
  //fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}//end writeM3I

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0712( )
{
    //identificar
    IO_id("\nEXEMPLO0712 - Programa - v0.1");
    id_cabecalho( "Dados_0712.txt", "0712", "v0.1 - 07/10/20" );
    //ler do teclado
    int q = quantidadesL("\n valor inteiro: ");
    //chamar funcao
    writeM3I("Dados_0712.txt", q);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0712


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e
gravar essa quantidade em multiplos de 3, 
impares, em ordem decrescente encerrando em 3.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         07/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.2       01.   ( OK )  07/10  - Gravar certa quantidade de impares multiplos de 3. (decrescente)
*/