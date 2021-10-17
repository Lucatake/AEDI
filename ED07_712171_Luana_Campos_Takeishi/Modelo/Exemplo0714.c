/**
    Exemplo0714 - Versao 0.1 - 07/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * writeR1P7 - gravar em arquivo certa 
 * quantidade de valores resultados da
 * razao de 1 por potencias de 7.
 * @param fileName - nome do arquivo
 * @param q - quantidade de valores
*/
void writeR1P7( chars fileName, int q )
{
  //definir dados
    FILE *arquivo = fopen(fileName, "at");
    double razao = 0.0, pot = 0.0;
  //gravar quantidade de valores
    //IO_fprintf(arquivo, " quantidade: %d\n", q);
  //repetir 'q' vezes
    for (int i = q; i > 0; i--)
    {
      //calcular valor
        pot =  pow(7,i);
        razao = (double) ( 1.0 / pot );
      //e gravar valor
        //IO_fprintf(arquivo, "[1/%.lf] = %.6lf\n", pot, razao );
        IO_fprintf(arquivo, "%lf\n", razao );
    }//end for
  //fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}//end writeR1P7

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0714( )
{
    //identificar
    IO_id("\nEXEMPLO0714 - Programa - v0.1");
    //id_cabecalho( "Dados_0714.txt", "0714", "v0.1 - 07/10/20" );
    //ler do teclado
    int q = quantidadesL("\n valor inteiro: ");
    //chamar funcao
    writeR1P7("Dados_0714.txt", q);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0714


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e
gravar essa quantidade em valores 
decrescentes da sequencia: ... 1/343 1/49 1/7 1.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         07/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.4       01.   ( OK )  07/10  - Gravar certa quantidade divisoes de 1/7^n . (decrescente)
*/