/**
    Exemplo0815 - Versao 0.1 - 22/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * maiorImpar - funcao para achar o maior numero impar
 * em um arranjo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
int maiorImpar( int n, int array[] )
{
    //definir variaveis com valor inicial
    int maior = 0;

    for (int i = 0; i < n; i++)
    {
        //para o prmeiro valor
        if(i==0)
        {
            maior = array[i];
        }
        //para os demais valores
        if (array[i] > maior && (array[i] % 2 != 0))
        {
            maior = array[i];
        }  
    }
    //retornar valor
    return(maior);
}


/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0815( )
{
    //identificar
    IO_id("\nEXEMPLO0815 - Programa - v0.1");
    //id_cabecalho( "Dados_0815.txt", "0815", "v0.1 - 14/10/20" );
    //ler dados
    int n = freadArraySize("Array_0814.txt");
    //definir array
    int array[n];
    //ler array
    readIntArray("Array_0814.txt", n, array);
    //achar maior valor
    int maior = maiorImpar( n, array );
    //mostrar valor
    if (maior != 0)
    {
        IO_printf("\n maior impar = %d", maior);
    }
    else
    {
        IO_printf("\n Invalido");
    }
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0815

/**
---------------------------------------------- documentacao complementar
exercicio:
procurar o maior valor impar em um arranjo.
Para testar, receber um nome de arquivo como parametro e
aplicar a funcao sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor da tabela como referencia inicial.
Exemplo: lerArquivo ( "DADOS.TXT", n, arranjo );
maior = acharMaiorImpar ( n, arranjo );
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
 maior impar = 87
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         22/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.5       01.   ( OK )  22/10  - Achar maior impar em um array de arquivo.
*/