/**
    Exemplo0820 - Versao 0.1 - 23/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * aProcuraVezes - funcao para procurar valor 
 * a partir de uma posicao
 * @param procurado - numero procurado
 * @param posicao - posicao inicial
 * @param n - tamanho arranjo
 * @param array - arranjo
 * @return vezes - quantidade de vezes
*/
int aProcuraVezes ( int procurado, int posicao, int n, int array[])
{
    //variaveis com valor iniciaa
    int vezes = 0;
    //varrer arranjo
    for (int i = posicao; i < n; i++)
    {
        //se valor achado
        if (array[i]==procurado)
        {
            //conta as vezes
            vezes+=1;
        }//end if
    }//end for
    return(vezes);
}//end aProcura

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0820( )
{
    //identificar
    IO_id("\nEXEMPLO0820 - Programa - v0.1");
    //id_cabecalho( "Dados_0820.txt", "0820", "v0.1 - 14/10/20" );
    //ler dados
    int n = freadArraySize("Array_0820.txt");
    //definir array
    int array[n];
    //ler array do arquivo
    readIntArray("Array_0820.txt", n, array);
    //ler do teclado o valor
    int valor = IO_readint("\n valor procurado: ");
    //posicao inicial menor que o tamanho do array
    /*int posicao = 0;
    do
    {
        posicao = IO_readint("\n posicao inicial: ");
    } while (posicao <= n);*/
    //chamar metodo de procura
    int vezes = aProcuraVezes ( valor, 0, n, array );
    //mostrar resultado
    if (vezes>5)
    {
        IO_printf("\n quantidade de vezes (%d) e' maior que 5", vezes);
    }
    else
    {
        IO_printf("\n vezes: %d", vezes);
    }
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0820

/**
---------------------------------------------- documentacao complementar
exercicio:
procurar por determinado valor em arranjo e
dizer quantas vezes esse valor pode ser encontrado,
indicada a posicao inicial para começar a procura.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar se a quantidade de vezes o valor procurado aparece no arranjo,
se houver, e' maior que 5.
Exemplo: lerArquivo ( "DADOS.TXT", n, arranjo );
vezes = acharQuantos ( procurado, 0, n, arranjo );
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
valor procurado: 23
 quantidade de vezes (6) e' maior que 5
(23 - 6 vezes)
valor procurado: 45
 vezes: 2
(45 - 2 vezes)
valor procurado: 109
 vezes: 0
(109 nao existe)
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 2.0       01.   ( OK )  23/10  - Quantidades de vezes um valor esta em um arranjo e se >5.
*/