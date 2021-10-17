
/**
 * IO_lib - v0.1 - 23/09/2020
 * CoAuthor: Luana Campos Takeishi
 * Matricula: 712171
*/

//lista de dependencias
//para definicoes proprias
#include "io.h"


/**
 * printIntArray - Mostrar arranjo com valores inteiros.
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
void printIntArray(int n, int array[])
{
    // definir dado local
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // mostrar valor
        IO_printf("%2d: %d\n", x, array[x]);
    } // fim repetir
} // printIntArray ( )


/**
 * readIntArray - Ler arranjo com valores inteiros.
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
void readIntArray(int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    chars text = IO_new_chars(STR_SIZE);
    // ler e guardar valores em arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // ler valor
        strcpy(text, STR_EMPTY);
        y = IO_readint(IO_concat(
            IO_concat(text, IO_toString_d(x)), " : "));
        // guardar valor
        array[x] = y;
    } // fim repetir
} // readIntArray ( )


/**
 * fprintIntArray - Gravar arranjo com valores inteiros.
 * @param fileName - nome do arquivo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
void fprintIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    int x = 0;
    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", n);
    // gravar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%d\n", array[x]);
    } // fim repetir
    // fechar arquivo
    fclose(arquivo);
} // fprintIntArray ( )


/**
 * freadArraySize - Ler tamanho do arranjo com valores inteiros.
 * @return quantidade de valores lidos
 * @param fileName - nome do arquivo
*/
int freadArraySize(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // fim se
    // retornar dado lido
    return (n);
} // freadArraySize ( )


/**
 * freadIntArray - Ler arranjo com valores inteiros.
 * @param fileName - nome do arquivo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
void freadIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);
    if (n <= 0 || n > x)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while (!feof(arquivo) && x < n)
        {
            // ler valor
            IO_fscanf(arquivo, "%d", &y);
            // guardar valor
            array[x] = y;
            // passar ao proximo
            x = x + 1;
        } // fim repetir
    }     // fim se
} // freadIntArray ( )



/**
 * copyIntArray - Copiar arranjo com valores inteiros.
 * @param n - quantidade de valores
 * @param copy - copia do grupo de valores inteiros
 * @param array - grupo de valores inteiros
*/
void copyIntArray(int n, int copy[], int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }
    else
    {
        // copiar valores em arranjo
        for (x = 0; x < n; x = x + 1)
        {
            // copiar valor
            copy[x] = array[x];
        } // fim repetir
    }     // fim se
} // copyIntArray ( )



/**
 * sumIntArray - Somar valores em arranjo com inteiros.
 * @return - soma dos valores
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
int sumIntArray(int n, int array[])
{
    // definir dados locais
    int soma = 0;
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        soma = soma + array[x];
    } // fim repetir
    // retornar resposta
    return (soma);
} // sumIntArray ( )



/**
 * isAllZeros - Testar valores inteiros em arranjo.
 * @return - true, se todos os dados forem iguais a zero;
 * false, caso contrario
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
*/
bool isAllZeros(int n, int array[])
{
    // definir dados locais
    bool result = true;
    int x = 0;
    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array[x] == 0);
        // passar ao proximo
        x = x + 1;
    } // fim repetir
    // retornar resposta
    return (result);
} // isAllZeros ( )



/**
 * addIntArray - Somar arranjos com inteiros.
 * @return - arranjo ocm a soma resultante
 * @param n - quantidade de valores
 * @param array3 - soma de grupo de valores inteiros
 * @param array1 - grupo de valores inteiros (1)
 * @param k - constante para multiplicar o segundo arranjo
 * @param array2 - grupo de valores inteiros (2)
*/
void addIntArray(int n, int array3[],
                 int array1[], int k, int array2[])
{
    // definir dados locais
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        array3[x] = array1[x] + k * array2[x];
    } // fim repetir
} // addIntArray ( )



/**
 * isEqual - Testar arranjos com inteiros sao iguais.
 * @return - true, se todos os dados forem iguais;
 * false, caso contrario
 * @param n - quantidade de valores
 * @param array1 - grupo de valores inteiros (1)
 * @param array2 - grupo de valores inteiros (2)
*/
bool isEqual(int n, int array1[], int array2[])
{
    // definir dados locais
    bool result = true;
    int x = 0;
    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array1[x] == array2[x]);
        // passar ao proximo
        x = x + 1;
    } // fim repetir
    // retornar resposta
    return (result);
} // isEqual ( )



/**
 * searchArray - Procurar valor em arranjo com inteiros.
 * @return - true, se encontrar;
 * false, caso contrario
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
 * @param value - valor a ser procurado
*/
bool searchArray(int n, int array[], int value)
{
    // definir dados locais
    bool result = false;
    int x = 0;
    // mostrar valores no arranjo
    x = 0;
    while (x < n && !result)
    {
        // testar valor
        result = (value == array[x]);
        // passar ao proximo
        x = x + 1;
    } // fim repetir
    // retornar resposta
    return (result);
} // searchArray ( )





/**
 * printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
 * @param lines - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param matrix - grupo de valores inteiros
*/
void printIntMatrix(int lines, int columns, int matrix[][columns])
{
    // definir dado local
    int x = 0;
    int y = 0;
    // mostrar valores na matriz
    for (x = 0; x < lines; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            // mostrar valor
            IO_printf("%3d\t", matrix[x][y]);
        } // fim repetir
        IO_printf("\n");
    } // fim repetir
} // printIntMatrix ( )


/**
 * readIntMatrix - Ler arranjo bidimensional com valores inteiros.
 * @param lines - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param matrix - grupo de valores inteiros
*/
void readIntMatrix(int lines, int columns, int matrix[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    chars text = IO_new_chars(STR_SIZE);
    // ler e guardar valores em arranjo
    for (x = 0; x < lines; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            // ler valor
            strcpy(text, STR_EMPTY);
            z = IO_readint(IO_concat(
                IO_concat(IO_concat(text, IO_toString_d(x)), ", "),
                IO_concat(IO_concat(text, IO_toString_d(y)), " : ")));
            // guardar valor
            matrix[x][y] = z;
        } // fim repetir
    }     // fim repetir
} // readIntMatrix ( )


/**
 * fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 * @param fileName - nome do arquivo
 * @param lines - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param matrix - grupo de valores inteiros
*/
void fprintIntMatrix(chars fileName, int lines, int columns, int matrix[][columns])
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    int x = 0;
    int y = 0;
    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", lines);
    IO_fprintf(arquivo, "%d\n", columns);
    // gravar valores no arquivo
    for (x = 0; x < lines; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            // gravar valor
            IO_fprintf(arquivo, "%d\n", matrix[x][y]);
        } // fim repetir
    }     // fim repetir
    // fechar arquivo
    fclose(arquivo);
} // fprintIntMatrix ( )


/**
 * freadMatrixRows - Ler tamanho (linhas) da matriz com valores inteiros.
 * @return quantidade de linhas da matriz
 * @param fileName - nome do arquivo
*/
int freadMatrixRows(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    ints array = NULL;
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // fim se
    // retornar dado lido
    return (n);
} // freadMatrixRows ( )


/**
 * freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros.
 * @return quantidade de colunas da matriz
 * @param fileName - nome do arquivo
*/
int freadMatrixColumns(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    IO_fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // fim se
    // retornar dado lido
    return (n);
} // freadMatrixColumns ( )


/**
 * freadIntMatrix - Ler arranjo bidimensional com valores inteiros.
 * @param fileName - nome do arquivo
 * @param lines - quantidade de valores
 * @param columns - quantidade de valores
 * @param matrix - grupo de valores inteiros
*/
void freadIntMatrix(chars fileName, int lines, int columns, int matrix[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);
    IO_fscanf(arquivo, "%d", &y);
    if (lines <= 0 || lines > x ||
        columns <= 0 || columns > y)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while (!feof(arquivo) && x < lines)
        {
            y = 0;
            while (!feof(arquivo) && y < columns)
            {
                // ler valor
                IO_fscanf(arquivo, "%d", &z);
                // guardar valor
                matrix[x][y] = z;
                // passar ao proximo
                y = y + 1;
            } // fim repetir
            // passar ao proximo
            x = x + 1;
        } // fim repetir
    }     // fim se
} // freadIntMatrix ( )


/**
 * copyIntMatrix - Copiar matriz com valores inteiros.
 * @param lines - quantidade de valores
 * @param columns - quantidade de valores
 * @param matrix - grupo de valores inteiros
*/
void copyIntMatrix(int lines, int columns,
                   int matrix2[][columns], int matrix1[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    if (lines <= 0 || columns <= 0)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // copiar valores em matriz
        for (x = 0; x < lines; x = x + 1)
        {
            for (y = 0; y < columns; y = y + 1)
            {
                // copiar valor
                matrix2[x][y] = matrix1[x][y];
            } // fim repetir
        }     // fim repetir
    }         // fim se
} // copyIntMatrix ( )


/**
 * transposeIntMatrix - Transpor valores inteiros em matriz.
 * @param lines - quantidade de valores
 * @param columns - quantidade de valores
 * @param matrix2 - grupo de valores inteiros (transposto)
 * @param matrix1 - grupo de valores inteiros
*/
void transposeIntMatrix(int lines, int columns,
                        int matrix2[][lines], int matrix1[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    // percorrer a matriz
    for (x = 0; x < lines; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            matrix2[y][x] = matrix1[x][y];
        } // fim repetir
    }     // fim repetir
} // transposeIntMatrix ( )


/**
 * isIdentity - Testar se matriz identidade.
 * @return - true, se todos os dados forem iguais a zero;
 * false, caso contrario
 * @param lines - quantidade de valores
 * @param columns - quantidade de valores
 * @param matrix - grupo de valores inteiros
*/
bool isIdentity(int lines, int columns, int matrix[][columns])
{
    // definir dados locais
    bool result = true;
    int x = 0;
    int y = 0;
    // testar condicao de existencia
    if (lines <= 0 || columns <= 0 ||
        lines != columns)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // testar valores na matriz
        x = 0;
        while (x < lines && result)
        {
            y = 0;
            while (y < columns && result)
            {
                // testar valor
                if (x == y)
                {
                    result = result && (matrix[x][y] == 1);
                }
                else
                {
                    result = result && (matrix[x][y] == 0);
                } // fim se
                // passar ao proximo
                y = y + 1;
            } // fim repetir
            // passar ao proximo
            x = x + 1;
        } // fim repetir
    }     // fim se
    // retornar resposta
    return (result);
} // isIdentity ( )


/**
 * isEqual - Testar se matrizes iguais.
 * @return - true, se todos os dados forem iguais;
 * false, caso contrario
 * @param lines - quantidade de valores
 * @param columns - quantidade de valores
 * @param matrix1 - grupo de valores inteiros (1)
 * @param matrix2 - grupo de valores inteiros (2)

bool isEqual(int lines, int columns,
             int matrix1[][columns], int matrix2[][columns])
{
    // definir dados locais
    bool result = true;
    int x = 0;
    int y = 0;
    // mostrar valores na matriz
    x = 0;
    while (x < lines && result)
    {
        y = 0;
        while (y < columns && result)
        {
            // testar valor
            result = result &&
                     (matrix1[x][y] == matrix2[x][y]);
            // passar ao proximo
            y = y + 1;
        } // fim repetir
        // passar ao proximo
        x = x + 1;
    } // fim repetir
    // retornar resposta
    return (result);
} // isEqual ( )*/


/**
 * addIntMatrix - Somar matrizes com inteiros.
 * @param lines - quantidade de valores
 * @param columns - quantidade de valores
 * @param matrix3 - grupo de valores inteiros resultante
 * @param matrix1 - grupo de valores inteiros (1)
 * @param k - constante para multiplicar o segundo termo
 * @param matrix2 - grupo de valores inteiros (2)
*/
void addIntMatrix(int lines, int columns,
                  int matrix3[][columns],
                  int matrix1[][columns], int k, int matrix2[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    // mostrar valores na matriz
    for (x = 0; x < lines; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            // somar valores
            matrix3[x][y] = matrix1[x][y] + k * matrix2[x][y];
        } // fim repetir
    }     // fim repetir
} // addIntMatrix ( )


/**
 * mulIntMatrix - Multiplicar matrizes com inteiros.
 * @param lines3 - quantidade de linhas da matriz (3)
 * @param columns3 - quantidade de colunas da matriz (3)
 * @param matrix3 - grupo de valores inteiros resultante
 * @param lines1 - quantidade de linhas da matriz (1)
 * @param columns1 - quantidade de colunas da matriz (1)
 * @param matrix1 - grupo de valores inteiros (1)
 * @param lines2 - quantidade de linhas da matriz (2)
 * @param columns2 - quantidade de colunas da matriz (2)
 * @param matrix2 - grupo de valores inteiros (2)
*/
void mulIntMatrix(int lines3, int columns3,
                  int matrix3[][columns3],
                  int lines1, int columns1,
                  int matrix1[][columns1],
                  int lines2, int columns2,
                  int matrix2[][columns2])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    int soma = 0;
    if (lines1 <= 0 || columns1 == 0 ||
        lines2 <= 0 || columns2 == 0 ||
        lines3 <= 0 || columns3 == 0 ||
        columns1 != lines2 ||
        lines1 != lines3 ||
        columns2 != columns3)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // percorrer valores na matriz resultante
        for (x = 0; x < lines3; x = x + 1)
        {
            for (y = 0; y < columns3; y = y + 1)
            {
                // somar valores
                soma = 0;
                for (z = 0; z < columns1; z = z + 1)
                {
                    soma = soma + matrix1[x][z] * matrix2[z][y];
                } // fim repetir
                // guardar a soma
                matrix3[x][y] = soma;
            } // fim repetir
        }     // fim repetir
    }         // fim se
} // mulIntMatrix ( )





