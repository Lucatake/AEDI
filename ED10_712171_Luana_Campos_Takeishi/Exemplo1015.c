/**
    Exemplo1015 - Versao 0.1 - 29/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1015( )
{
    //identificar
    IO_id("\nEXEMPLO1015 - Programa - v0.1");

    //definir variaveis
    //array NAO decrescente
    int n = freadArraySize("EX1011.txt");
    int array [n];
    freadIntArray("EX1011.txt", n, array);
    //array decrescente 
    int p = freadArraySize("EXD.txt");
    int arrayB [p];
    freadIntArray("EXD.txt", p, arrayB);
    //verificar ordenacao
    bool decresce = decrescente( n, array);
    IO_printf(decresce ? "\n decrescente" : "\n NAO decrescente");
    decresce = decrescente( p, arrayB);
    IO_printf(decresce ? "\n decrescente" : "\n NAO decrescente");

    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1015

/**
---------------------------------------------- documentacao complementar
exercicio:
dizer se um arranjo está em ordem decrescente.
Para testar, receber um nome de arquivo como parametro e
aplicar a função sobre o arranjo com os valores lidos.
Exemplo: arranjo1 = lerArquivo ( "DADOS1.TXT" );
resposta = ordenado ( arranjo );
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
 NAO decrescente
 decrescente
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         29/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.5       01.   ( OK )  29/10  - Verificar se arranjo esta ordenado decrescente.
*/