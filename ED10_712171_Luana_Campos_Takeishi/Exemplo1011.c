/**
    Exemplo1011 - Versao 0.1 - 28/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1011( )
{
    //identificar
    IO_id("\nEXEMPLO1011 - Programa - v0.1");
    //definir variaveis
    //intervalo
    int *a = 0;
    int *b = 0;
    intervalo(&a,&b);
    //array
    int n = quantidades("\n quantidades de valores a serem gerados: ");
    int array [n];
    randomicosPar(&a,&b,"FF", n, array);
    //gravar em arquivo
    fprintIntArray("EX1011.txt", n, array);
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1011

/**
---------------------------------------------- documentacao complementar
exercicio:
gerar um valor inteiro aleatoriamente dentro de um intervalo,
cujos limites de inicio e de fim serao recebidos como parametros.
Para para testar, ler os limites do intervalo do teclado;
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatorios pares
dentro do intervalo e armazena-los em arranjo;
grava-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo devera informar a quantidade
de numeros aleatorios ( N ) que serao gravados em seguida.
DICA: Usar a funcao rand( ), mas tentar limitar valores muito grandes.
---------------------------------------------- notas / observacoes / comentarios
 digite um valor para ser o intervalo inferior: 2

 digite um valor para ser o intervalo superior: 30

 quantidades de valores a serem gerados: 5
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         28/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.1       01.   ( OK )  28/10  - Gravar array de numeros aleatorios em arquivo.
*/