/**
    Exemplo1012 - Versao 0.1 - 28/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio1012( )
{
    //identificar
    IO_id("\nEXEMPLO1012 - Programa - v0.1");
    //definir variaveis
    //array
    int n = freadArraySize("EX1011.txt");
    int array [n];
    freadIntArray("EX1011.txt", n, array);
    //entrar com valor procurado do teclado
    int procurado = IO_readint("\n valor procurado: ");
    //procurar valor
    bool achou = aProcura ( procurado, 0, n, array );
    if (achou)
    {
        IO_print(" valor encontrado.");
    } else
    {
        IO_print(" valor NAO encontrado.");
    }//end if
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio1012

/**
---------------------------------------------- documentacao complementar
exercicio:
procurar certo valor em um arranjo.
Para testar, receber um nome de arquivo como parametro e
aplicar a funcao sobre o arranjo com os valores lidos;
Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
menor = procurar ( arranjo );
---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
 valor procurado: 12
 valor encontrado.

 valor procurado: 45
 valor NAO encontrado
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         28/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.2       01.   ( OK )  28/10  - Procurar valor em arranjo.
*/