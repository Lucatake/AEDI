/**
    Exemplo0818 - Versao 0.1 - 23/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * aProcuraImpar - funcao para procurar valor 
 * a partir de uma posicao
 * @param procurado - numero procurado
 * @param posicao - posicao inicial
 * @param n - tamanho arranjo
 * @param array - arranjo
 * @return existe - booleano true ou false
*/
bool aProcuraImpar ( int procurado, int posicao, int n, int array[])
{
    //variaveis com valor iniciaa
    bool existe = false;
    bool impar = false;
    int p = 0;
    //varrer arranjo
    for (int i = posicao; i < n; i++)
    {
        //se valor achado
        if (array[i]==procurado)
        {
            existe = true;
            //guardar posicao
            p = i-1;
            //validar repeticao
            i = n;
        }//end if
    }//end for
    //testar se posicao e' impar
    if( existe && p % 2 != 0)
    {
        impar = true;
    }
    return(impar);
}//end aProcura

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0818( )
{
    //identificar
    IO_id("\nEXEMPLO0818 - Programa - v0.1");
    //id_cabecalho( "Dados_0818.txt", "0818", "v0.1 - 14/10/20" );
    //ler dados
    int n = freadArraySize("Array_0814.txt");
    //definir array
    int array[n];
    //ler array do arquivo
    readIntArray("Array_0814.txt", n, array);
    //ler do teclado o valor
    int valor = IO_readint("\n valor procurado: ");
    //posicao inicial menor que o tamanho do array
    /*int posicao = 0;
    do
    {
        posicao = IO_readint("\n posicao inicial: ");
    } while (posicao <= n);*/
    //chamar metodo de procura
    bool existe = aProcuraImpar ( valor, 0, n, array );
    //mostrar resultado
    IO_printf(existe ? "true" : "false");
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0818

/**
---------------------------------------------- documentacao complementar
exercicio:
procurar por determinado valor em arranjo e
dizer se esse valor pode ser nele encontrado,
indicada a posicao inicial para se comecar a procura.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar se o valor procurado existe no arranjo, em uma posicao impar,
a partir daquela indicada para iniciar a busca.
Exemplo: lerArquivo ( "DADOS.TXT", n, arranjo );
existe = acharValor ( procurado, 0, n, arranjo );
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 valor procurado: 4
true
(4 está na posicao 3)
 valor procurado: 5
false
(5 esta na posicao 2)
 valor procurado: 109
false
(109 nao existe)
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         23/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.8       01.   ( OK )  23/10  - Achar valor certo valor em arranjo de arquivo.
*/