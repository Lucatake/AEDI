/**
    Exemplo0719 - Versao 0.1 - 10/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * minusculasAqr - contar letras minusculas em 
 * cadeias de caracteres de um arquivo txt
 * @param fileRead - nome do arquivo lido
 * @param fileWrite - nome do arquivo escrito
*/
void minusculasAqr(chars fileRead, chars fileWrite)
{
    //definir dados
    FILE *arquivoR = fopen(fileRead, "rt");
    FILE *arquivoW = fopen(fileWrite, "wt");
    int min = 0;
    char str[100];

    //enquanto nao chegar ao fim
    while (!feof(arquivoR))
    {
        //pegar string
        fgets(str, 100, arquivoR);
        //contar quantos caracteres
        int count = strlen(str);
        //avaliar todos os caracteres
        for (int i = 0; i < count; i++)
        {
            //se minuscula menor que 'n'
            if (str[i] >= 'a' && str[i] < 'n')
            {
                //conta mais 1
                min++;
            } //end if
        }     //end for
        //mostrar resultados
        IO_fprintf(arquivoW, "\n\ncadeia = %s", str);
        IO_fprintf(arquivoW, "\n\tquantidade = %d\n", min);
        //zerar contagem
        min = 0;
    } //end while

    //fechar arquivos (INDISPENSAVEL para gravacao)
    fclose(arquivoR);
    fclose(arquivoW);
} //end minusculasAqr

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0719()
{
    //identificar
    IO_id("\nEXEMPLO0719 - Programa - v0.1");
    //id_cabecalho( "RESULTADO06.TXT", "0719", "v0.1 - 07/10/20" );
    //chamar funcao
    minusculasAqr("Cadeias.txt", "RESULTADO09.TXT");
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
} //end Exercicio0719

/**
---------------------------------------------- documentacao complementar
exercicio:
para calcular a quantidade de minusculas, menores que 'n', em cadeia de caracteres
de um arquivo texto, cujo nome sera fornecido como parametro.
Gravar em outro arquivo ("RESULTADO09.TXT") cada cadeia de caracteres e seu resultado.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         10/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 1.9       01.   ( OK )  10/10  - Contar minusculas menores que n em cadeias de caracteres de um arquivo txt.
*/