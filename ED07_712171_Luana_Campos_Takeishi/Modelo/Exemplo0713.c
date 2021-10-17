/**
    Exemplo0713 - Versao 0.1 - 07/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * writeM5i - gravar em arquivo certa 
 * quantidade de valores multiplos de 5.
 * @param fileName - nome do arquivo
 * @param q - quantidade de valores
*/
void writeM5i( chars fileName, int q )
{
  //definir dados
    FILE *arquivo = fopen(fileName, "at");
  //gravar quantidade de valores
    IO_fprintf(arquivo, " quantidade: %d\n", q);
  //repetir 'q' vezes
   //para o primeiro valor
    IO_fprintf(arquivo, "1\n");
   //para os demais valores
    for (int i = 1; i <= (q * 2) - 3; i = i + 2)
    {
      //calcular valor
      //e gravar valor
        IO_fprintf(arquivo, "%d\n", i * 5 );
    }//end for
  //fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
}//end writeM5i

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0713( )
{
    //identificar
    IO_id("\nEXEMPLO0713 - Programa - v0.1");
    id_cabecalho( "Dados_0713.txt", "0713", "v0.1 - 07/10/20" );
    //ler do teclado
    int q = quantidadesL("\n valor inteiro: ");
    //chamar funcao
    writeM5i("Dados_0713.txt", q);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0713


/**
---------------------------------------------- documentacao complementar
exercicio:
ler um valor inteiro do teclado e
gravar essa quantidade em valores 
da sequencia: 1 5 15 25 35 ...
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         07/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.3       01.   ( OK )  07/10  - Gravar certa quantidade de multiplos de 5. (crescente)
*/