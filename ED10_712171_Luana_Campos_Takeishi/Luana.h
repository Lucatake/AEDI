
/**
 * IO_lib - v0.1 - 23/09/2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

//dependencias
#include "io.h" //para definicoes proprias

/**
 * Parar( ) - nao faz nada
*/
void Parar()
{
    //nao faz nada
} //end Parar

/**
 * quantidade( ) - Metodo para testar se quantidade valida
 * @return quantidade - numero de vezes a testar
*/
int quantidades(chars texto)
{
    //definir dados com valor inicial
    int quantidade = 0, x = 0;

    do
    {
        //entrar com a quantidade de valores a serem testados
        quantidade = IO_readint(texto);
        //testar se maior que zero
        if (quantidade > 0)
        {
            //se sim, sair do procedimento
            x = 1;
        }
        else
        {
            //se nao, retornar invalido
            IO_println("Valor invalido.");
            //e repetir o procedimento
            x = 0;
        } //end if
    } while (x == 0);

    //retornar quantidade de vezes a ser repetido
    return (quantidade);
} //end quantidade

/**
 * multiplos( ) - metodo para mostrar quantidade de valores multiplos de N
 * @return valor inteiro 
 * @param quantidade - numero de vezes a repetir o procedimento
 * @param multiplo - numero a ser o multiplo
 * @param modelo - para inverso (i) ou nao (m)
*/
int multiplos(int quantidade, int multiplo, char c)
{
    //definir variaveis com valor inicial
    int valor = 0;
    double inverso = 0.0;
    char v = '0';

    //se a opcao escolhida for multiplo
    if (v == 'm')
    {
        //repetir o numero de vezes pedido
        for (int i = 0; i < quantidade; i++)
        {
            //alterar o valor para um multiplo
            valor = multiplo * i;
            //mostrar o valor
            IO_printf("\n[%d]", valor);
        } //end for
    }
    else
    {
        //se a opcao escolhida for multiplo inverso
        if (v == 'i')
        {
            //repetir o numero de vezes pedido
            for (int i = 1; i <= quantidade; i++)
            {
                //alterar o valor para um multiplo
                valor = i * 4;
                //calcular os inversos
                inverso = 1.0 / valor;
                //mostrar o valor
                IO_printf("\n1/%d = [%lf]", valor, inverso);
            } //end for
        }
        else //se opcoes invalidas
        {
            IO_println("Entrada de opcoes invalida.");
        } //end if
    }     //enf if
} //end multiplos( )

/**
 * invervalo - metodo para gerar intervalo valido
 * @param a - valor inferior do intervalo
 * @param b - valor superior do intervalo
*/
void intervalo(int *a, int *b)
{
    *a = quantidades("\n digite um valor para ser o intervalo inferior: ");
    do
    {
        *b = quantidades("\n digite um valor para ser o intervalo superior: ");
    } while (*b <= *a);
} //end intervalo

/**
 * randomicos - metodo para gerar um numero
 * @param a , b - intevalo escolhido
 * @param tipo - se intervalo e' fecahdo ou aberto
 * @param n - quantidade de valores gerados
*/
int randomicos(int *a, int *b, chars tipo, int n, int array[])
{
    //dados com valor inicial
    int valor = 0;
    int controle = 0;

    //acoes
    srand(time(NULL)); // escolher a semente aleatoria dependente do tempo

    //tipo FF - gerar numero aleatorio no intervalo [a,b]
    if (tipo = "FF")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
            } while (!((valor >= *a) && (valor <= *b)));
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end FF
    else
        //tipo AA - gerar numero aleatorio no intervalo (a,b)
        if (tipo = "AA")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
            } while (!((valor > *a) && (valor < *b)));
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end AA
    else
        //tipo AF - gerar numero aleatorio no intervalo (a,b]
        if (tipo = "AF")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
            } while (!((valor > *a) && (valor <= *b)));
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end AF
    else
        //tipo FA - gerar numero aleatorio no intervalo [a,b)
        if (tipo = "FA")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
            } while (!((valor >= *a) && (valor < *b)));
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end FA
} //end randomicos

/**
 * ImPar - verificar se numero e' par ou impar
 * @param valor - numero a ser testado
 * @return resultado - true para par e false para impar
*/
bool ImPar( int valor )
{
    if (valor % 2 == 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }//end if
}//end ImPar

/**
 * randomicosPar - metodo para gerar um numero
 * @param a , b - intevalo escolhido
 * @param tipo - se intervalo e' fecahdo ou aberto
 * @param n - quantidade de valores gerados
*/
int randomicosPar(int *a, int *b, chars tipo, int n, int array[])
{
    //dados com valor inicial
    int valor = 0;
    int controle = 0;
    bool imPar = false;

    //acoes
    srand(time(NULL)); // escolher a semente aleatoria dependente do tempo

    //tipo FF - gerar numero aleatorio no intervalo [a,b]
    if (tipo = "FF")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
                imPar = ImPar(valor);
            } while (!((valor >= *a) && (valor <= *b) && imPar) );
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end FF
    else
        //tipo AA - gerar numero aleatorio no intervalo (a,b)
        if (tipo = "AA")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
                imPar = ImPar(valor);
            } while (!((valor > *a) && (valor < *b) && imPar) );
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end AA
    else
        //tipo AF - gerar numero aleatorio no intervalo (a,b]
        if (tipo = "AF")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
                imPar = ImPar(valor);
            } while (!((valor > *a) && (valor <= *b) && imPar));
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end AF
    else
        //tipo FA - gerar numero aleatorio no intervalo [a,b)
        if (tipo = "FA")
    {
        while (controle < n)
        {
            do
            {
                valor = rand();
                imPar = ImPar(valor);
            } while (!((valor >= *a) && (valor < *b) && imPar));
            //adicionar no array
            array[controle] = valor;
            //passar para o proximo
            controle++;
        } //end while
    }     //end FA
} //end randomicosPar



/**
 * aProcura - funcao para procurar valor 
 * a partir de uma posicao
 * @param procurado - numero procurado
 * @param posicao - posicao inicial
 * @param n - tamanho arranjo
 * @param array - arranjo
 * @return existe - booleano true ou false
*/
bool aProcura ( int procurado, int posicao, int n, int array[])
{
    bool resultado = false;
    //varrer arranjo
    for (int i = posicao; i < n; i++)
    {
        //se valor achado
        if (array[i]==procurado)
        {
            resultado = true;
        }//end if
    }//end for
    //retornar resultado
    return(resultado);
}//end aProcura

/**
 * comparaArray - funcao para comparar dois arrays
 * @param n - tamanho arranjo1
 * @param array1 - arranjo1
 * @param m - tamanho arranjo2
 * @param array2 - arranjo2
 * @return - bool true or false
*/
bool comparaArray ( int n, int array1[], int m, int array2[])
{
    int confirma = 0;
    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            if (array1[i]==array2[i])
            {
                confirma++;
            }//end if
        }//end for
        if (confirma == n)
        {
            return(true);
        } else
        {
            return(false);
        }//end if
    } else
    {
        IO_printf("\n arrays com tamanhos diferentes.");
        return(false);
    }//end if
}//end compara

/**
 * decrescente - verifica se array esta ordenado de forma decrescente
 * @param n - tamanho arranjo
 * @param array - arranjo
*/
bool decrescente( int n, int array[] )
{
    //criar variaveis
    int variavel = array[0];
    int confirma = 0;
    //testar ordem
    for (int i = 1; i < n; i++)
    {

        if ( variavel > array[i])
        {
            variavel = array[i];
            confirma++;
        }//end if
    }//end for
    //retornar resultado
    if (confirma == (n-1))
    {
        return(true);
    } else
    {
        return(false);
    }    
}//end decrescente

/**
 * matrixZerada - testar se matriz e' inteira de zeros.
 * @return - true, se todos os dados forem iguais a zero;
 * false, caso contrario
 * @param linhas - linhas das matrizes
 * @param colunas - colunas das matrizes
 * @param matrix - matrizes comparadas
*/
bool matrixZerada(int linhas, int colunas, int matrix[][colunas])
{
    // definir dados locais
    bool resultado = true;
    int x = 0;
    int z = 0;
    //mostrar valores no arranjo
    x = 0;
    z = 0;
    while (x < linhas && resultado)
    {
        while (z < colunas && resultado)
        {
            //testar valor
            resultado = resultado && (matrix[x][z] == 0);
            //passar ao proximo
            z++;
        }//end while
        z = 0;
        //passar ao proximo
        x++;
    }//end while
    //retornar resposta
    return (resultado);
}//end matrixZerada



/**
 * eTransposta - verificar se matrizes sao transpostas uma da outra
 * @param l, linhas - linhas das matrizes
 * @param c, colunas - colunas das matrizes
 * @param matrix2, matrix1 - matrizes comparadas
*/
bool eTransposta( int l, int c, int matrix2[][c], int linhas, int colunas, int matrix1[][colunas])
{
    //dados
    int confirma = 0;
    if ((l==colunas)&&(c==linhas))
    {
        //fazer a transposta
        int matrixT [linhas][colunas];
        transposeIntMatrix(linhas, colunas, matrixT, matrix1);
        for (int i = 0; i < l; i++)
        {
            for (int q = 0; q < c; q++)
            {
                if (matrix2[i][q] == matrixT[q][i])
                {
                    confirma++;
                }//end if 
            }//end for
        }//end for
    }//end if
    //retornar resultado
    if (confirma == (l*c))
    {
        return(true);
    } else
    {
        return(false);
    }//end if    
}//end eTransposta


/**
 * comparaMatriz - verifica se uma matriz e' igual a outra
 * @param l, linhas - linhas das matrizes
 * @param c, colunas - colunas das matrizes
 * @param matrix2, matrix1 - matrizes comparadas
*/
bool comparaMatriz( int l, int c, int matrix2[][c], int linhas, int colunas, int matrix1[][colunas] )
{
    //dados
    int confirma = 0;
    //comparar matrizes
    if (l == linhas && c == colunas)
    {
        for (int i = 0; i < l; i++)
        {
            for (int q = 0; q < c; q++)
            {
                if (matrix1[i][q] == matrix2[i][q])
                {
                    confirma++;
                }//end if
            }//end for
        }//end for
    } else
    {
        IO_printf("\n nao podem ser comparadas.");
    }//end if
    if (confirma == (l*c))
    {
        return(true);
    } else
    {
        return(false);
    }//end if  
}//end comparaMatriz