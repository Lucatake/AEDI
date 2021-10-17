/**
    Exemplo0711 - Versao 0.1 - 07/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * writeM3P - gravar em arquivo certa 
 * quantidade de valores pares multiplos de 3.
 * @param fileName - nome do arquivo
 * @param q - quantidade de valores
*/
void writeM3P( chars fileName, int q )
{
  //definir dados
    FILE *arquivo = fopen(fileName, "at");
  //gravar quantidade de valores
    IO_fprintf(arquivo, " quantidade: %d\n", q);
  //repetir 'q' vezes
    for (int i = 1; i <= q; i++)
    {
      //calcular valor
      //e gravar valor
        IO_fprintf(arquivo, "%d\n", i * 6 );
    }//end for
  //fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}//end writeM3P

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0711( )
{
    //identificar
    IO_id("\nEXEMPLO0711 - Programa - v0.1");
    id_cabecalho( "Dados_0711.txt", "0711", "v0.1 - 07/10/20" );
    //ler do teclado
    int q = quantidadesL("\n valor inteiro: ");
    //chamar funcao
    writeM3P("Dados_0711.txt", q);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0711

/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e
gravar essa quantidade em multiplos de 3, 
pares, em ordem crescente, comecando em 6.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         07/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.1       01.   ( OK )  07/10  - Gravar certa quantidade de pares multiplos de 3. (crescente)
*/