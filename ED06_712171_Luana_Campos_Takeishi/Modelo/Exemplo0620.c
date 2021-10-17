/**
    Exemplo0620 - Versao 0.1 - 30/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para contar as letras maiusculas
 * menores que 'N'
*/
int count_MaiuscN( chars cadeia, int c )
{
    //variavel com valor inicial
    int count = 0;
    char carac = '\0';
    //condicao para a recursividade
    if (c > 0)
    {
        //para as comparacoes
        carac = cadeia[c-1];
        //se caractere maiuscula menor que N
        if( carac >= 'A' && carac < 'N' )
        {   
            //fazer de novo com valor absoluto
            count = 1; 
        }//end if  
        //passar para a proxima e contar
        count = count + count_MaiuscN(cadeia, c-1);
    }//end if
    //retornar quantidae
    return(count);
}//end count_MaiuscN

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0620( )
{
    //identificar
    IO_id("\nEXEMPLO0620 - Programa - v0.1");
    //ler do teclado
    chars cadeia = IO_readstring("\ncadeia: ");
    //separar posicoes dos caracteres
    int position = strlen(cadeia);
    //e mostrar resultado, se e' multiplo
    IO_printf("quantidade de maiusculas < 'N' = %d", count_MaiuscN( cadeia, position ));
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0620

/**
---------------------------------------------- documentacao complementar
exercicio:
calcular a quantidade de maiusculas, menores que 'N', em uma cadeia de caracteres.
Testar essa funcao para cadeias de diferentes tamanhos.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
cadeia: ABCabcNOP123opq
quantidade de maiusculas < 'N' = 3

cadeia: 123AbCdefOpQ098DEf
quantidade de maiusculas < 'N' = 4

cadeia: adasg123412
quantidade de maiusculas < 'N' = 0
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         30/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 2.0       01.   ( OK )  30/09  - contar quantidade de maiusculas menores que N
*/