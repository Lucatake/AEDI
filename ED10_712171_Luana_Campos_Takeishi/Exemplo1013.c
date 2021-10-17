/**
    Exemplo1013 - Versao 0.1 - 29/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1013( )
{
    //identificar
    IO_id("\nEXEMPLO1013 - Programa - v0.1");

    //definir variaveis
    //array A
    int n = freadArraySize("EX1011.txt");
    int array [n];
    freadIntArray("EX1011.txt", n, array);
    //array B = A
    int p = freadArraySize("EXB.txt");
    int arrayB [p];
    freadIntArray("EXB.txt", p, arrayB);
    //array C != A
    int q = freadArraySize("EXC.txt");
    int arrayC [q];
    freadIntArray("EXC.txt", q, arrayC);
    //comparar arrays
    //A e B
    bool resp1 = comparaArray(n, array, p, arrayB);
    IO_printf(resp1 ? "\n A == B: true" : "\n A == B: false");
    //A e C
    bool resp2 = comparaArray(n, array, q, arrayC);
    IO_printf(resp2 ? "\n A == C: true" : "\n A == C: false");
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1013

/**
---------------------------------------------- documentacao complementar
exercicio:
operar a comparacao de dois arranjos.
Para testar, receber dados de arquivos e
aplicar a funcao sobre os arranjos com os valores lidos;
DICA: Verificar, primeiro, se os tamanhos são compativeis.
Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
arranjo2 = lerArquivo ( "DADOS2.TXT" );
resposta = comparar ( arranjo1, arranjo2 );
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
 A == B: true
 arrays com tamanhos diferentes.
 A == C: false

 A == B: true
 A == C: false
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.3       01.   ( OK )  29/10  - Comparar arranjos.
*/