/**
 * Estudo Dirigido 12 - v0.1. - 14 / 11 / 2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "mymatrix.hpp"
using namespace std;
// ----------------------------------------------- lista de exercicios
void Exercicio01( );
void Exercicio02( );
void Exercicio03( );
void Exercicio04( );
void Exercicio05( );
void Exercicio06( );
void Exercicio07( );
void Exercicio08( );
void Exercicio09( );
void Exercicio10( );
void ExercicioE1( );
void ExercicioE2( );
// ----------------------------------------------- lista de funcoes e metodos
void Parar();
// ----------------------------------------------- acao principal

/**
 * Funcao principal.
 * @return codigo de encerramento
*/
int main(int argc, char **argv)
{
    //definir dado
        //definir variavel com valor inicial
        int x = 0; 
    //identificar
        cout << "ESTUDO DIRIGIDO 12 - Programa - v0.1\n " << endl;
    // repetir até desejar parar
    do
    {
    //mostrar opcoes
        cout << "Opcoes: " << endl;
        cout << " 0 - Parar." << endl;
        cout << " 1 - Exercicio01\t 2 - Exercicio02\t 3 - Exercicio03 " << endl;
        cout << " 4 - Exercicio04\t 5 - Exercicio05\t 6 - Exercicio06 " << endl;
        cout << " 7 - Exercicio07\t 8 - Exercicio08\t 9 - Exercicio09 " << endl;
        cout << "10 - Exercicio10\t11 - ExercicioE1\t12 - ExercicioE2 " << endl;
    //ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
    //escolher acao
        switch (x)
        {
        case 0:
            Parar();
            break;
        case 1:
            Exercicio01();
            break;
        case 2:
            Exercicio02();
            break;
        case 3:
            Exercicio03();
            break;
        case 4:
            Exercicio04();
            break;
        case 5:
            Exercicio05();
            break;
        case 6:
            Exercicio06();
            break;
        case 7:
            Exercicio07();
            break;
        case 8:
            Exercicio08();
            break;
        case 9:
            Exercicio09();
            break;
        case 10:
            Exercicio10();
            break;
        case 11:
            ExercicioE1();
            break;
        case 12:
            ExercicioE2();
            break;
        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        }//end switch case
    } while (x != 0);
//encerrar
    pause("Apertar ENTER para terminar");
    return (0);
}//end main( )

// ---------------------------------------------- exercicios

/**
 * Parar - nao faz nada.
*/
void Parar( )
{
    //nao faz nada
}//end Parar( )

/**
 * Exercicio01:
 * ler a quantidade de elementos ( MxN ) a serem gerados;
 * gerar essa quantidade ( MxN ) de valores aleatorios
 * dentro do intervalo e armazena-los em matriz;
 * grava-los, um por linha, em um arquivo ("DADOS.TXT").
 * A primeira linha do arquivo devera informar a quantidade
 * de numeros aleatorios ( N ) que serao gravados em seguida.
 * DICA: Usar a funcao rand( ), mas tentar limitar valores muito grandes.
 * Exemplo: matrix.gerarInt ( inferior, superior );
*/
void Exercicio01()
{
    // identificar
    cout << "\nEXEMPLO1211 - Exercicio01 - v0.1\n" << endl;
    //definir dados
    int n = 0;
    int m = 0;
    int valor = 0;
    //ler quantidade de valores a serem gerados (linhasXcolunas)
    cout << "\n quantidade de valores (linhas): "; cin >> n; cout << endl;
    cout << "\n quantidade de valores (colunas): "; cin >> m; cout << endl;
    //criar matriz
    Matrix<int> matrix(n, m);
    //gerar aleatorios e armazenar em arquivo
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //gera aleatorio impar no intervalo
            valor = matrix.geraInt(1,100);
            //armazena no array
            matrix.set(i,j,valor);
        }//end for 
    }//end for
    //armazenar dados
    matrix.print();
    matrix.fprint("DADOS1211.txt");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio01 ( )

/**
 * Exercicio02:
 * escalar uma matriz, multiplicando todos os seus valores por uma constante (k).
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre a matriz com os valores lidos;
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * matrix2 = matrix1.scale ( k );
*/
void Exercicio02()
{
    //identificar
    cout << "EXEMPLO1212 - Exercicio02 - v0.1" << endl;
    //ler matriz de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix(n, m);
    Matrix<int> matrixE(n, m);
    matrix.fread("DADOS1212.txt");
    //ler valor constante
    int cte = 0;
    cout << "\n constante: "; cin >> cte; cout << endl;
    //chamar funcao para escalar
    matrixE = matrix;
    matrixE.escalar(cte);
    matrixE.print( );
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio02 ( )

/**
 * Exercicio03;
 * testar se uma matriz e' a identidade.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre a matriz com os valores lidos;
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * teste = matrix1.isIdentity ( );
*/
void Exercicio03()
{
    // identificar
    cout << "EXEMPLO1213 - Exercicio03 - v0.1" << endl;
    //ler matriz de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix(n, m);
    matrix.fread("DADOS1212.txt");
    //testar se e' identidade
    bool teste = matrix.eIdentidade( );
    //mostrar resultado
    cout << "0 - NAO e' identidade\t 1- e' identidade" << endl;
    cout << "e' identidade? " << teste << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio03 ( )

/**
 * Exercicio04:
 * testar se duas matrizes de mesmo tamanho sao diferentes.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre o arranjo com os valores lidos;
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * matrix2 = lerArquivo ( "DADOS2.TXT" );
 * teste = (matrix1 == matrix2);
*/
void Exercicio04()
{
    //identificar
    cout << "EXEMPLO1214 - Exercicio04 - v0.1" << endl;
    //ler matrizes de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix1(n, m);
    matrix1.fread("DADOS1211.txt");
    int o = 0;
    int p = 0;
    Matrix<int> matrix2(o, p);
    matrix2.fread("DADOS1212.txt");
    //testar se sao iguais
    string testeI = (matrix1 == matrix2) ? "sim" : "nao";
    //string testeD = (matrix1 != matrix2) ? "sim" : "nao";
    //mostrar resultados
    cout << "sao iguais? " << testeI << endl;
    //cout << "sao diferentes? " << testeD << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio04 ( )

/**
 * Exercicio05:
 * somar duas matrizes.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre o arranjo com os valores lidos;
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * matrix2 = lerArquivo ( "DADOS2.TXT" );
 * soma = matrix1 + matrix2;
*/
void Exercicio05()
{
    //identificar
    cout <<  "EXEMPLO1215 - Exercicio05 - v0.1" << endl;
    //ler matrizes de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix1(n, m);
    matrix1.fread("DADOS1211.txt");
    int o = 0;
    int p = 0;
    Matrix<int> matrix2(o, p);
    matrix2.fread("DADOS1212.txt");
    int a = 0;
    int b = 0;
    Matrix<int> matrixSoma(a, b);
    //mostrar matrizes
    cout << "MATRIZ 1 " << endl;
    matrix1.print( );
    cout << "MATRIZ 2 " << endl;
    matrix2.print( );
    //fazer a operacao de soma
    matrixSoma = matrix1 + matrix2;
    //mostrar resultado
    cout << "MATRIZ SOMA " << endl;
    matrixSoma.print( );
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio05 ( )

/**
 * Exercicio06:
 * operar duas linhas da matriz, guardando no lugar da primeira,
 * a soma da primeira com a segunda multiplicada por uma constante (k).
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * matrix1.addRows ( 0, 1, (-1) ); // k = -1
 * ERRO: nao esta funcionando. motivo na logica nao indentificado.
*/
void Exercicio06()
{
    //identificar
    cout <<  "EXEMPLO1216 - Exercicio06 - v0.1" << endl;
    //ler matriz de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix(n, m);
    matrix.fread("DADOS1211.txt");
    cout << "MATRIZ" << endl; 
    matrix.print();
    //chamar funcao
    matrix.addRows(0,1,(-1));
    //mostrar resultado
    cout << "NOVA MATRIZ" << endl;
    matrix.print( );
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio06 ( )

/**
 * Exercicio07:
 * operar duas colunas da matriz, guardando no lugar da primeira,
 * a diferenca da primeira com a segunda multiplicada por uma constante (k).
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * matrix1.subRows ( 0, 1, (2) ); // k = 2
 * ERRO: ainda nao fiz, por ser similar a anterior.
*/
void Exercicio07()
{
    //identificar
    cout << "EXEMPLO1217 - Exercicio07 - v0.1" << endl;
   
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio07 ( )

/**
 * Exercicio08:
 * dizer em qual linha da matriz se encontra certo valor, se houver.
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * teste = matrix1.searchRows ( procurado );
*/
void Exercicio08()
{
    //identificar
    cout <<  "EXEMPLO1218 - Exercicio08 - v0.1" << endl;
    //ler matriz de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix(n, m);
    matrix.fread("DADOS1211.txt");
    cout << "MATRIZ" << endl; 
    matrix.print();
    //ler valor procurado
    int valor = 0;
    cout << "valor: "; cin >> valor; cout << endl;
    //chamar funcao para procurar valor
    int linha = matrix.searchRows(valor);
    //mostrar resultado
    cout << "linha: " << linha << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio08 ( )

/**
 * Exercicio09:
 * dizer em qual coluna da matriz se encontra certo valor, se houver.
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * teste = matrix1.searchColumns ( procurado );
*/
void Exercicio09( )
{
    //identificar
    cout << "EXEMPLO1219 - Exercicio09 - v0.1" << endl;
    //ler matriz de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix(n, m);
    matrix.fread("DADOS1211.txt");
    cout << "MATRIZ" << endl; 
    matrix.print();
    //ler valor procurado
    int valor = 0;
    cout << "valor: "; cin >> valor; cout << endl;
    //chamar funcao para procurar valor
    int linha = matrix.searchColumns(valor);
    //mostrar resultado
    cout << "coluna: " << linha << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio09 ( )

/**
 * Exercicio10:
 * transpor os dados em uma matriz.
 * Exemplo: matrix1 = lerArquivo ( "DADOS1.TXT" );
 * matrix1.transpose ( );
 * ERRO: nao esta funcionando. motivo na logica nao indentificado.
*/
void Exercicio10()
{
    //identificar
    cout << "EXEMPLO1220 - Exercicio10 - v0.1" << endl;
    //ler matriz de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix(n, m);
    matrix.fread("DADOS1211.txt");
    cout << "MATRIZ" << endl; 
    matrix.print();
    //chamar funcao para transposta
    Matrix<int> matrixT(m, n);
    cout << "MATRIZ TRANSPOSTA" << endl; 
    matrixT = matrix.transpose();
    matrixT.print();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio10 ( )

/**
 * ExercicioE1:
 * dizer se uma matriz apresenta a caracteristica abaixo.
 *                             1    2   3   4
 *             1   2   3       5    6   7   8
 * 1   2       4   5   6       9   10  11  12
 * 3   4       7   8   9       13  14  15  16
*/
void ExercicioE1( )
{
    //identificar
    cout << "EXEMPLO12E1 - ExercicioE1 - v0.1" << endl;
    //ler matriz de arquivo
    int n = 0;
    int m = 0;
    Matrix<int> matrix(n, m);
    matrix.fread("DADOS1211.txt");
    cout << "MATRIZ" << endl; 
    matrix.print();
    //testar resultado
    cout << "0 - nao apresenta\t 1- apresenta" << endl; 
    bool teste = matrix.MatrizCLin( );
    cout << "tem as caracteristicas? " << teste << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE1 ( )

/**
 * ExercicioE2:
 * montar uma matriz com a caracteristica abaixo.
 *                             1    5   9   13
 *             1   4   7       2    6  10   14
 * 1   3       2   5   8       3    7  11   15
 * 2   4       3   6   9       4    8  12   16
*/
void ExercicioE2( )
{
    //identificar
    cout << "EXEMPLO12E2 - ExercicioE2 - v0.1" << endl;
    //gerar matriz
    int n = 0;
    int m = 0;
    //entrar com a quantidade de linhas e colunas
    cout << "digite um valor (linhas): "; cin >> n; cout << endl;
    cout << "digite um valor (colunas): "; cin >> m; cout << endl;
    //criar matriz
    Matrix<int> matrix(n, m);
    
    //gerar matriz
    matrix.geraMatrizCCol();
    //mostrar e gravar resultados
    cout << "MATRIZ GERADA" << endl; 
    matrix.print();
    matrix.fprint("DADOSE2.TXT");
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE2 ( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
OBS: nao consegui fazer todos os exercicios ainda (06/07/10). nao entendi muito bem os 
marcados como erro, como devo fazer, como altera o tamanho de linhas e colunas.
---------------------------------------------- previsao de testes e testes
OBS: pretendo ainda alterar no .hpp a existencia da variavel i(x) j(y) para todos os metodos,
como indicado em aula, sem a necessidade de redeclara-la toda vez. 

Exercicio01: Exemplo1211
    -Teste 1:  quantidade de valores (linhas): 2
               quantidade de valores (colunas): 3
                    67      34      69
                    24      78      58
    -Teste 2:  quantidade de valores (linhas): 3
               quantidade de valores (colunas): 2
                        62      64
                        5       45
                        81      27
    -Teste 3:  quantidade de valores (linhas): 4
               quantidade de valores (colunas): 4
                61      91      95      42
                27      36      91      4
                2       53      92      82
                21      16      18      95

Exercicio02: Exemplo1212
    -Teste 1: Constante: 3
     Martiz 1:           Matriz escalada: 
    61  91  95  42      183     273     285     126
    27  36  91  4       81      108     273     12
    2   53  92  82      6       159     276     246
    21  16  18  95      63      48      54      285
    -Teste 2: Constante: 10
     Martiz 1:           Matriz escalada: 
    1   2   3   4       10      20      30      40
    4   3   2   1       40      30      20      10
    1   2   3   4       10      20      30      40
    -Teste 3: Constante: 52
     Martiz 1:           Matriz escalada: 
    1   2   3   4       52      104     156     208
    4   3   2   1       208     156     104     52
    1   2   3   4       52      104     156     208

Exercicio03: Exemplo1213
    0 - NAO e' identidade    1- e' identidade
    -Teste 1: 
                61      91      95      42
                27      36      91      4
                2       53      92      82
                21      16      18      95
                            e' identidade? 0
    -Teste 2:
                61      91      95      42
                27      36      91      4
                2       53      92      82
                            ERROR: Invalid.
                            e' identidade? 0
    -Teste 3: 
                1   0   0   0
                0   1   0   0
                0   0   1   0
                0   0   0   1
                            e' identidade? 1

Exercicio04: Exemplo1214
    OBS: teste de igualdade e diferenca feitos separados, pois juntos (em seguida), 
    aparentemente sobrecarrega o programa.
    -Teste 1: 
         matriz 1 = matriz 2
            61  91  95  42
            27  36  91  4 
            2   53  92  82
            21  16  18  95
        sao iguais? sim
        sao diferentes? nao
    -Teste 2: 
         matriz 1           matriz 2
         1  2  3             1  2
         1  2  3             3  1
                             2  3
        ERROR: Missing data.
    -Teste 3: 
         matriz 1           matriz 2
         1  2  3            3  2  1
         1  2  3            3  2  1
        sao iguais? nao
        sao diferentes? sim

Exercicio05: Exemplo1215
    -Teste 1: 
        MATRIZ 1
    1       2       3
    1       2       3
        MATRIZ 2
    3       2       1
    3       2       1
        MATRIZ SOMA
    4       4       4
    4       4       4
    -Teste 2: 
        MATRIZ 1
    1       2       3
    1       2       3
    1       2       3
        MATRIZ 2
    3       2       1
    3       2       1
        ERROR: Missing data.
    -Teste 3:
        MATRIZ 1
    1       2       3
    1       2       3
    1       2       3
        MATRIZ 2
    1       2       3
    1       2       3
    1       2       3
        MATRIZ SOMA
    2       4       6
    2       4       6
    2       4       6

Exercicio06: Exemplo1216  
    -Teste 1: 
    -Teste 2: 

Exercicio07: Exemplo1217
    -Teste 1: 
    -Teste 2: 

Exercicio08: Exemplo1218
    matriz:
        1       2       3
        4       5       6
        7       8       9
    -Teste 1: valor: 3      linha: 0 
    -Teste 2: valor: 5      linha: 1
    -Teste 3: valor: 0      linha: 1878006336 (valor que nao existe)
    seria melhor colocar NULL como valor inicial? neste caso o retorno = 0;
    ou entao uma condicao no metodo? no entanto so' ha' possibilidade deetorno de inteiros...
    -Teste 4: valor: 7      linha: 2

Exercicio09: Exemplo1219
    matriz:
        1       2       3
        4       5       6
        7       8       9
    -Teste 1: valor: 1      coluna: 0
    -Teste 2: valor: 0      coluna: 1878006336 (mesma questao anterior)
    -Teste 3: valor: 5      coluna: 1
    -Teste 4: valor: 9      coluna: 2

Exercicio10: Exemplo1220
    -Teste 1:
    -Teste 2: 
    -Teste 3: 

ExercicioE1: Exemplo12E1 (extra1)
        0 - nao apresenta        1- apresenta
    -Teste 1: 
    1       2
    3       4
    5       6
        ERROR: Invalid.
        tem as caracteristicas? 0
    -Teste 2: 
    1       2
    3       4
        tem as caracteristicas? 1
    -Teste 3: 
    4       3
    2       1
        tem as caracteristicas? 0

ExercicioE1: Exemplo12E1 (extra1)
    -Teste 1:
    digite um valor (linhas): 2
    digite um valor (colunas): 2
        MATRIZ GERADA
        1       3
        2       4
    -Teste 2:
    digite um valor (linhas): 2
    digite um valor (colunas): 3
        ERROR: Invalid.
        MATRIZ GERADA
        16154536        16122048        50397186
        16153256        16122048        1163152965
    -Teste 3:
    digite um valor (linhas): 4
    digite um valor (colunas): 4
        MATRIZ GERADA
        1       5       9       13
        2       6       10      14
        3       7       11      15
        4       8       12      16

---------------------------------------------- historico
Versao Data  Modificacao
 0.1   14/11 esboco
---------------------------------------------- testes
Versao   Teste   Data     Descricao
1.1 01. ( OK )  10/11   - Gerar 'n' valores aleatorios e armazenar em arquivo.
1.2 01. ( OK )  10/11   - Escalar matriz por uma constante.
1.3 01. ( OK )  10/11   - Verificar se matriz e' identidade.
1.4 01. ( OK )  10/11   - Verifica se duas matrizes sao diferentes/iguais.
1.5 01. ( OK )  10/11   - Operador soma de matrizes.
1.6 01. ( OK )  00/11   - .
1.7 01. ( OK )  00/11   - .
1.8 01. ( OK )  12/11   - Procurar e retornar a linha onde encontrase certo valor.
1.9 01. ( OK )  12/11   - Procurar e retornar a coluna onde encontrase certo valor.
2.0 01. ( OK )  00/11   - .
E.1 01. ( OK )  14/11   - Dizer se matriz apresenta as caracteristicas.
E.2 01. ( OK )  14/11   - Montar uma matriz com as caracteristicas.
*/