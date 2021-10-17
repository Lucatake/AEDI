/**
    Exemplo0619 - Versao 0.1 - 30/09/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * Funcao recursiva para contar quantos digitos impares
 * esistem dentro de uma cadeia de caracteres
*/
int count_impares( chars cadeia, int c )
{
    //variavel com valor inicial
    int count = 0, value = 0;
    char carac = '\0';
    //condicao para a recursividade
    if (c > 0)
    {
        //typedef dos tipos para as comparacoes
        carac = cadeia[c-1];
        value = (int) carac;
        //se caractere esta entre os digitos e e' impar
        if( (carac >= '0' && carac <= '9') && ((value % 2) != 0) )
        {   
            //fazer de novo com valor absoluto
            count = 1; 
        }//end if  
        //passar para a proxima e contar
        count = count + count_impares(cadeia, c-1);
    }//end if
    //retornar quantidae
    return(count);
}//end count_impares

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0619( )
{
    //identificar
    IO_id("\nEXEMPLO0619 - Programa - v0.1");
    //ler do teclado
    chars cadeia = IO_readstring("\ncadeia: ");
    //separar posicoes dos caracteres
    int position = strlen(cadeia);
    //e mostrar resultado, se e' multiplo
    IO_printf("quantidade de impares = %d", count_impares( cadeia, position ));
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
}//end Exercicio0619

/**
---------------------------------------------- documentacao complementar
exercicio:
contar os digitos com valores impares em uma cadeia de caracteres.
Testar essa funcao para cadeias de diferentes tamanhos.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
cadeia: 1234567
quantidade de impares = 4

123acb456def789
quantidade de impares = 5
---------------------------------------------- historico
Versao       Data        Modificacao
0.1         30/09          esboco
---------------------------------------------- testes
Exercicio Versao Teste   Data    Descricao
 1.9       01.   ( OK )  30/09  - contar digitos impares em uma cadeia de caracteres
*/