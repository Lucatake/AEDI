/**
 * Estudo Dirigido 11 - v0.1. - 06 / 11 / 2020
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
#include "myarray.hpp"
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
        cout << "ESTUDO DIRIGIDO 11 - Programa - v0.1\n " << endl;
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
 * ler a quantidade de elementos ( N ) a serem gerados;
 * gerar essa quantidade ( N ) de valores aleatorios impares
 * dentro do intervalo e armazena-los em arranjo;
 * grava-los, um por linha, em um arquivo ("DADOS.TXT").
 * A primeira linha do arquivo devera informar a quantidade
 * de numeros aleatorios ( N ) que serao gravados em seguida.
 * DICA: Usar a função rand( ), mas tentar limitar valores muito grandes.
 * Exemplo: valor = arranjo.gerarInt ( inferior, superior );
*/
void Exercicio01()
{
    // identificar
    cout << "\nEXEMPLO1111 - Exercicio01 - v0.1\n" << endl;
    //definir dados
    int n = 0;
    int valor = 0;
    int i = 0;
    //ler quantidade de valores a serem gerados
    cout << "\n quantidade de valores: "; cin >> n; cout << endl;
    //criar array
    Array<int> int_array(n);
    //gerar aleatorios e armazenar em arquivo
    do
    {
        do
        {
            //gera aleatorio impar no intervalo
            valor = int_array.geraInt(1,100);
        } while (valor % 2 == 0);
        //armazena no array
        int_array.set(i,valor);
        i++;
    } while (i < n);
    //armazenar dados
    int_array.print();
    int_array.fprint("DADOS1111.txt");
    //reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio01 ( )

/**
 * Exercicio02:
 * procurar o maior valor par em um arranjo.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre o arranjo com os valores lidos;
 * DICA: Usar o primeiro valor como referencia inicial.
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * maior = arranjo.acharMaior ( );
*/
void Exercicio02()
{
    //identificar
    cout << "EXEMPLO1112 - Exercicio02 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //chamar funcao para procurar maior par
    int maiorP = int_array.maiorIntPar( );
    //mostrar resultado
    if (maiorP != 0)
    {
        cout << "\n maior valor par: " << maiorP << endl;
    } else
    {
        cout << "\n NAO ha maior valor par." << endl;
    }//end if    
    //reciclar espaco
    int_array.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio02 ( )

/**
 * Exercicio03;
 * procurar o menor valor multiplo de 3 em um arranjo.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre o arranjo com os valores lidos;
 * DICA: Usar o maior valor como referencia inicial.
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * menor = arranjo.acharMenor ( );
*/
void Exercicio03()
{
    // identificar
    cout << "EXEMPLO1113 - Exercicio03 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //chamar funcao para achar menor multiplo de 3
    int menor = int_array.menorMultiploN(3);
    //mostrar resultado
    if (menor != 0)
    {
        cout << "\n menor multiplo de 3: " << menor << endl;
    } else
    {
        cout << "\n NAO ha multiplo de 3." << endl;
    }//end if 
    //reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio03 ( )

/**
 * Exercicio04:
 * somar todos os valores impares em um arranjo.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre o arranjo com os valores lidos;
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * soma = arranjo.somarValores ( );
*/
void Exercicio04()
{
    //identificar
    cout << "EXEMPLO1114 - Exercicio04 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //chamar funcao para somar os impares
    int soma = int_array.somaImpares( );
    cout << "\n soma dos impares: " << soma << endl;
    //reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio04 ( )

/**
 * Exercicio05:
 * achar a media dos valores pares em um arranjo.
 * Para testar, receber um nome de arquivo como parametro e
 * aplicar a funcao sobre o arranjo com os valores lidos;
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * media = arranjo.mediaValores( );
*/
void Exercicio05()
{
    //identificar
    cout <<  "EXEMPLO1115 - Exercicio05 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //chamar funcao para achar a media dos valores pares
    double media = int_array.mediaPares( );
    cout << "\n media dos valores pares: " << media << endl;
    //reciclar espaco
    int_array.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio05 ( )

/**
 * Exercicio06:
 * verificar se todos os valores sao diferentes de zero em um arranjo.
 * Para testar, ler o arquivo ("DADOS.TXT")
 * armazenar os dados em um arranjo.
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * teste = arranjo.zeros ( );
*/
void Exercicio06()
{
    //identificar
    cout <<  "EXEMPLO1116 - Exercicio06 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //chamar funcao verificar se sao todos valores nao nulos
    cout << "\n 0 - pelo menos um nulo \t 1 - todos nao nulos " << endl;
    bool zeros = int_array.saoZeros( );
    cout << "\n todos os valores sao nao nulos? " << zeros << endl;
    //reciclar espaco
    int_array.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio06 ( )

/**
 * Exercicio07:
 * dizer se esta ordenado, ou nao, em ordem decrescente.
 * DICA: Testar se nao esta desordenado, ou seja,
 * se existe algum valor que seja menor que o seguinte.
 * Não usar break !
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * teste = arranjo.decrescente ( );
*/
void Exercicio07()
{
    //identificar
    cout << "EXEMPLO1117 - Exercicio07 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //chamar funcao verificar se sao todos valores nao nulos
    cout << "\n 0 - nao ordenado decrescente\t 1 - ordenado decrescente " << endl;
    bool decres = int_array.decrescente( );
    cout << "\n ordem decrescente? " << decres << endl;
    //reciclar espaco
    int_array.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio07 ( )

/**
 * Exercicio08:
 * dizer se determinado valor esta presente em arranjo,
 * entre duas posicoes indicadas.
 * Para testar, ler o arquivo ("DADOS.TXT"),
 * e armazenar os dados em arranjo;
 * ler do teclado um valor inteiro para ser procurado;
 * determinar se o valor procurado existe no arranjo.
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * existe = arranjo.acharValor ( procurado, 5, 10 );
*/
void Exercicio08()
{
    //identificar
    cout <<  "EXEMPLO1118 - Exercicio08 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //ler valor procurado do teclado
    int procurado = 0;
    cout << "\n valor procurado: "; cin >> procurado;
    //chamar funcao verificar se sao todos valores nao nulos
    cout << "\n 0 - nao existe valor \t 1 - existe valor " << endl;
    bool existe = int_array.achaValor(procurado, 4, 9);
    cout << "\n " << procurado << " ? " << existe << endl;
    //reciclar espaco
    int_array.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio08 ( )

/**
 * Exercicio09:
 * escalar o arranjo, multiplicando cada valor por uma constante.
 * Para testar, ler o arquivo ("DADOS.TXT"),
 * e armazenar os dados em arranjo;
 * ler do teclado um valor inteiro para indicar a constante.
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * novo = arranjo.escalar( constante );
*/
void Exercicio09()
{
    //identificar
    cout << "EXEMPLO1119 - Exercicio09 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    Array<int> int_arrayE(n);
    int_array.fread("DADOS1112.txt");
    //ler valor constante
    int cte = 0;
    cout << "\n constante: "; cin >> cte;
    //chamar funcao para escalar
    int_arrayE = int_array;
    int_arrayE.escalar(cte);
    int_arrayE.print( );
    //reciclar espaco
    int_array.free();
    int_arrayE.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio09 ( )

/**
 * Exercicio10:
 * colocar valores em arranjo em ordem decrescente,
 * mediante trocas de posicoes, ate ficar totalmente ordenado.
 * Para testar, ler o arquivo ("DADOS.TXT"),
 * e armazenar os dados em arranjo.
 * Exemplo: arranjo = lerArquivo ( "DADOS.TXT" );
 * arranjo.ordenar ( );
*/
void Exercicio10()
{
    //identificar
    cout << "EXEMPLO1120 - Exercicio10 - v0.1" << endl;
    //ler arranjo de arquivo
    int n = 0;
    Array<int> int_array(n);
    int_array.fread("DADOS1112.txt");
    //chamar funcao para ordenar
    int_array.ordenarDecrescente( );
    int_array.print( );
    //reciclar espaco
    int_array.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio10 ( )

/**
 * ExercicioE1:
 * Incluir em um programa (Exemplo11E1) um operador (!=) para  
 * dizer se dois arranjos sao diferentes, pelo menos em uma posicao.
*/
void ExercicioE1( )
{
    //identificar
    cout << "EXEMPLO11E1 - ExercicioE1 - v0.1" << endl;
    //ler arranjos de arquivo
    Array<int> int_array1(10);
    int_array1.fread("DADOS1111.txt");
    Array<int> int_array2(10);
    int_array2.fread("DADOS1112.txt");
    Array<int> int_array3(10);
    int_array3.fread("DADOS1113.txt");
    //mostrar dados
    cout << "Array_1" << endl; int_array1.print();
    cout << "Array_2" << endl; int_array2.print();
    //chamar comparacao
    cout << "Diferentes != " << (int_array1 != int_array2) << "\n" << endl;
    //mostrar dados
    cout << "Array_2" << endl; int_array2.print();
    cout << "Array_3" << endl; int_array3.print();
    //chamar comparacao
    cout << "Diferentes != " << (int_array2 != int_array3) << endl;
    //reciclar espaco
    int_array1.free();
    int_array2.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE1 ( )

/**
 * ExercicioE2:
 * Incluir em um programa (Exemplo11E2) um operador (-) para
 * calcular as diferencas entre dois arranjos numericos, posicao por posicao.
*/
void ExercicioE2( )
{
    //identificar
    cout << "EXEMPLO11E2 - ExercicioE2 - v0.1" << endl;
    //ler arranjos de arquivo
    Array<int> int_array1(10);
    int_array1.fread("DADOS1111.txt");
    Array<int> int_array2(10);
    int_array2.fread("DADOS1112.txt");
    Array<int> int_array3(10);
    int_array3.fread("DADOS1113.txt");
    Array<int> int_array4(10);
    //subtrair dados
    int_array4 = int_array1 - int_array2;
    //mostrar dados
    cout << "Array_1" << endl; int_array1.print();
    cout << "Array_2" << endl; int_array2.print();
    //mostrar resultado
    cout << "Subtracao [array1-array2]:" << endl; int_array4.print();
    //subtrair dados
    int_array4 = int_array2 - int_array3;
    //mostrar dados
    cout << "Array_2" << endl; int_array2.print();
    cout << "Array_3" << endl; int_array3.print();
    //mostrar resultado
    cout << "Subtracao [array2-array3]:" << endl; int_array4.print();
    //reciclar espaco
    int_array1.free();
    int_array2.free();
    int_array3.free();
    int_array4.free();
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE2 ( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes e testes

Exercicio01: Exemplo1111
    -Teste 1: 4     0:41  1:67  2:69  3:5
    -Teste 2: 10    0:45  1:81  2:27  3:61  4:91  5:95  6:27  7:91  8:53  9:21
    -Teste 3: 15    0:95  1:47  2:71  3:69  4:67  5:99  6:35  
                    7: 3  8:11  9:33 10:73 11:41 12:11 13:53 14:47

Exercicio02: Exemplo1112
    -Teste 1: [10] 24 78 58 62 64 5 45 81 27 61
     maior valor par: 64
    -Teste 2: [10] 23 77 57 63 61 5 45 81 27 61
     NAO ha maior valor par.
    -Teste 3: [15] 23 298 77 57 100 63 61 5 76 45 81 27 32 61 158
     maior valor par: 248
     
Exercicio03: Exemplo1113
    -Teste 1: [15] 23 298 77 57 100 63 61 5 76 45 81 27 32 61 158
     menor multiplo de 3: 27
    -Teste 2: [10] 1 2 98 4 46 78 43 37 95 31
     NAO ha multiplo de 3.
    -Teste 3: [15] 12 9 3 56 72 15 90 30 31 78 65 151 243 96 4
     menor multiplo de 3: 3

Exercicio04: Exemplo1114
    -Teste 1: [15] 12 9 3 56 72 15 90 30 31 78 65 151 243 96 4
     soma dos impares: 517
    -Teste 2: [10] 0 2 4 6 8 10 12 18 24 30
     soma dos impares: 0
    -Teste 3: [10] 15 2 7 6 8 11 12 19 24 3
     soma dos impares: 55

Exercicio05: Exemplo1115
    -Teste 1: [10] 15 2 7 6 8 11 12 19 24 3 
     media dos valores pares: 10.4
    -Teste 2: [10] 2 2 7 6 8 16 12 108 24 3
     media dos valores pares: 22.25
    -Teste 3: [10] 19 7 91 53 81 11 109 25 3
     media dos valores pares: nan
    -Teste 4: [5] 101 35 8 5 11
     media dos valores pares: 8

Exercicio06: Exemplo1116
    0 - pelo menos um nulo          1 - todos nao nulos
    -Teste 1: [5] 0 0 0 0 0
     todos os valores sao nao nulos? 0
    -Teste 2: [5] 52 109 6 15 0
     todos os valores sao nao nulos? 0
    -Teste 3: [5] 0 52 109 6 15
     todos os valores sao nao nulos? 0
    -Teste 4: [5] 94 52 109 6 15
     todos os valores sao nao nulos? 1

Exercicio07: Exemplo1117
    -Teste 1: [5] 94 52 109 6 15
     ordem decrescente? 0
    -Teste 2: [5] 109 94 52 15 6
     ordem decrescente? 1

Exercicio08: Exemplo1118
    arranjo: [5] 109 94 52 15 6       posicoes: 4 - 9
             0 - nao existe valor    1 - existe valor
    -Teste 1: valor procurado: 94     94 ? 0   
    -Teste 2: valor procurado: 45     45 ? 1
    -Teste 3: valor procurado: 6       6 ? 1
    -Teste 4: valor procurado: 1       1 ? 1

Exercicio09: Exemplo1119
    arranjo: [10] 109 94 52 15 45 89 23 1 0 6
    -Teste 1: constante: 2
      0:218  1:188  2:104  3:30  4:90  5:178  6:46  7:2  8:0  9:12
    -Teste 2: constante: 0
      0:0  1:0  2:0  3:0  4:0  5:0  6:0  7:0  8:0  9:0
    -Teste 3: constante: 10
      0:1090  1:940  2:520  3:150  4:450  5:890  6:230  7:10  8:0  9:60

Exercicio10: Exemplo1120
    -Teste 1: arranjo: [10] 109 94 52 15 45 89 23 1 0 6
      0:109  1:94  2:89  3:52  4:45  5:23  6:15  7:6  8:1  9:0
    -Teste 2: arranjo: [10] 0 1 2 3 4 5 6 7 8 9 
      0:9  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
    -Teste 3: [10] 10 56 43 29 63 68 01 24 68 63
      0:68  1:68  2:63  3:63  4:56  5:43  6:29  7:24  8:10  9: 1

ExercicioE1: Exemplo11E1 (extra1)
    -Teste 1: ERRO!NAO IDENTIFICADO O MOTIVO - quando os dois arrays diferentes iniciam com o mesmo valor
    o programa indica que eles sao iguais.
        OBS:  Array_1   0:0  1:1  2:2  3:3  4:4  5:5  6:6  7:7  8:8  9:9
              Array_2   0:0  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
            Diferentes != 0
        CORRIGIDO: inicia o valor em falso e comprar com !false, ao encontrar um diferente que seja
        sai da repeticao pois !true sera falso.
    -Teste 2: Array_1  0:9  1:1  2:2  3:3  4:4  5:5  6:6  7:7  8:8  9:0
              Array_2  0:9  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
            Diferentes != 1
              Array_2  0:9  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
              Array_3  0:9  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
            Diferentes != 0

ExercicioE1: Exemplo11E1 (extra1)
    -Teste 1: Array_1  0:9  1:1  2:2  3:3  4:4  5:5  6:6  7:7  8:8  9:0
              Array_2  0:9  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
            Subtracao [array1-array2]:
                       0:0  1:-7  2:-5  3:-3  4:-1  5:1  6:3  7:5  8:7  9:0
              Array_2  0:9  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
              Array_3  0:9  1:8  2:7  3:6  4:5  5:4  6:3  7:2  8:1  9:0
            Subtracao [array2-array3]:
                       0:0  1:0  2:0  3:0  4:0  5:0  6:0  7:0  8:0  9:0

---------------------------------------------- historico
Versao Data  Modificacao
 0.1   06/11 esboco
---------------------------------------------- testes
Versao   Teste   Data     Descricao
1.1 01. ( OK )  05/11   - Gerar 'n' valores aleatorios e armazenar em arquivo.
1.2 01. ( OK )  05/11   - Procurar maior valor par de arranjo de arquivo.
1.3 01. ( OK )  05/11   - Procurar menor multiplo de 3 de arranjo de arquivo.
1.4 01. ( OK )  05/11   - Somar valores impares de arranjo de arquivo.
1.5 01. ( OK )  06/11   - Calcular a media dos valores pares.
1.6 01. ( OK )  06/11   - Verificar se todos os valores sao nao nulos.
1.7 01. ( OK )  06/11   - Verificar se arranjo esta em ordem decrescente.
1.8 01. ( OK )  06/11   - Verificar se existe valor 'n' entre as posicoes [a,b] do arranjo.
1.9 01. ( OK )  06/11   - Escalar arranjo por uma constante.
2.0 01. ( OK )  06/11   - Ordenar arranjo de maneira decrescente.
E.1 01. ( OK )  06/11   - Operador!=. Comparar se dois arranjos sao diferentes.
E.2 01. ( OK )  06/11   - Operador-. Subtrair dois arranjos.
*/