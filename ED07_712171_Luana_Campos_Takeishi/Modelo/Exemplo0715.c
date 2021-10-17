/**
    Exemplo0715 - Versao 0.1 - 07/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * writeR1Px - gravar em arquivo certa 
 * quantidade de valores resultados da
 * razao de 1 por potencias de 7.
 * @param fileName - nome do arquivo
 * @param q - quantidade de valores
*/
void writeR1Px( chars fileName, int q, double x)
{
  //definir dados
    FILE *arquivo = fopen(fileName, "at");
    double razao = 0.0, pot = 0.0;
  //gravar quantidade de valores
    //IO_fprintf(arquivo, " quantidade: %d\n", q);

  //repetir 'q' vezes
   //para o primeiro valor
    //IO_fprintf(arquivo, "[1/1.00] = 1.000000\n");
    IO_fprintf(arquivo, "1.000000\n");
   //para o os demais valores
    for (int i = 1; i <=((q * 2) - 3); i =  i + 2)
    {
      //calcular valor
        pot =  pow( x, i );
        razao = 1.0 / pot;
      //e gravar valor
        //IO_fprintf(arquivo, "[1/%.2lf] = %.6lf\n", pot, razao );
        IO_fprintf(arquivo, "%lf\n", razao );
    }//end for

  //fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}//end writeR1Px

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0715( )
{
    //identificar
    IO_id("\nEXEMPLO0715 - Programa - v0.1");
    //id_cabecalho( "Dados_0715.txt", "0715", "v0.2 - 07/10/20" );
    //ler do teclado
    int n = quantidadesL("\n quantidade: ");
    double x = IO_readdouble("\n valor real: ");
    //chamar funcao
    writeR1Px("Dados_0715.txt", n, x);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0715


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado (n) e outro valor real (x),
gravar essa quantidade (n) em valores reais da sequencia: 1 1/x 1/x3 1/x5 ...
DICA: Usar pow ( x, y ) da biblioteca <math.h> para calcular a potencia.
---------------------------------------------- notas / observacoes / comentarios
mudanca para melhor execucao da questao 6.
---------------------------------------------- previsao de testes
15
0.87
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         07/10          esboco
0.2         10/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.5       01.   ( OK )  07/10  - Gravar certa quantidade divisoes de 1/x^n . (crescente)
*/