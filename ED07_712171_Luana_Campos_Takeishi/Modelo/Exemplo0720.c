/**
    Exemplo0720 - Versao 0.1 - 10/10/2020
    Author: Luana Campos Takeishi
    Matricula: 712171
*/

//para metodos proprios
#include "io.h"

/**
 * digitoArq - contar digitos maiores que 5 em 
 * cadeias de caracteres de um arquivo txt
 * @param fileRead - nome do arquivo lido
 * @param fileWrite - nome do arquivo escrito
*/
void digitoArq(chars fileRead, chars fileWrite)
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
            if (str[i] > '5' && str[i] <= '9')
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
} //end digitoArq

/**
 * Metodo principal para a chamada dos procedimentos
*/
void Exercicio0720()
{
    //identificar
    IO_id("\nEXEMPLO0720 - Programa - v0.1");
    //id_cabecalho( "RESULTADO06.TXT", "0720", "v0.1 - 07/10/20" );
    //chamar funcao
    digitoArq("Digitos.txt", "RESULTADO10.TXT");
    //encerrar
    IO_pause("\nApertar ENTER para continuar");
} //end Exercicio0720

/**
---------------------------------------------- documentacao complementar
exercicio:
para contar digitos maiores que 5 em certa cadeia de caracteres passada como parametro.
Ler um arquivo texto que possa conter numeros e letras, cujo nome devera ser fornecido e
gravar em outro arquivo ("RESULTADO10.TXT") cada cadeia de caracteres e o resultado
da aplicação da função.
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao       Data        Modificacao
0.1         10/10          esboco
---------------------------------------------- testes
Exercicio Versao  Teste   Data    Descricao
 2.0       01.   ( OK )  10/10  - Contar digitos maiores que 5 em cadeias de caracteres de um arquivo txt.
*/