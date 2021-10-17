/**
 * Estudo Dirigido 14 - v0.1. - 27 / 11 / 2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

// dependencias
#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
#include <vector>
#include <sstream>
#include <string>
// outras dependencias
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
// ----------------------------------------------- classes
#include "Erro.hpp" // classe para tratar erros
class MyString : public Erro
{
public:
    /**
* Funcao para obter mensagem
* relativa ao código de erro.
* @return mensagem sobre o erro
*/
    std::string getErroMsg()
    {
        return (NO_ERROR); // COMPLETAR A DEFINICAO
    }                      // end getErroMsg ( )
};                         // fim classe MyString
// ----------------------------------------------- definicoes globais
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
        cout << "ESTUDO DIRIGIDO 14 - Programa - v0.1\n " << endl;
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
 * Funcao para converter conteudo para valor inteiro, se possivel.
 * @return valor inteiro equivalente, se valido;
 * (-1), caso contrario
*/
int getInt(std::string str)
{
    bool verifica = true;
    int num = -1;
    //verificar se string contem somente numeros
    //sendo possivel a conversao
    int i = 0;
    while (i < str.length() && verifica)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            verifica = false;
        } //end if
        i++;
    }//end while
    //se possivel, entao converte
    if (verifica)
    {
        num = std::stoi(str); 
    }//end if
    //retorna valor
    return(num);
} //end getInt

/**
 * Exercicio01:
 * teste do getInt.
*/
void Exercicio01()
{
    // identificar
    cout << "\nEXEMPLO1411 - Exercicio01 - v0.1\n" << endl;
    // definir dados
    std::string str;
    cout << "String a ser convertida para Int: "; cin >> str; cout << endl;
    int num = getInt(str);
    cout << "String: " << str << "\tNum: " << num << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio01 ( )

/**
 * Funcao para converter conteudo para valor real, se possivel.
 * @return valor real equivalente, se valido;
 * (0.0), caso contrario
*/
double getDouble(std::string str)
{
    bool verifica = true;
    double num = 0.0;
    int pto = 0;
    //verificar se string contem somente numeros e um ponto
    //sendo possivel a conversao
    int i = 0;
    while (i < str.length() && verifica)
    {
        if (!(str[i] >= '0' && str[i] <= '9' || str[i] == '.'))
        {           
            verifica = false;
        } //end if
        if (str[i] == '.')
        {           
            pto++;
        } //end if
        i++;
    }//end while
    //se possivel, entao converte
    if (verifica && pto < 2)
    {
        num = std::stod(str); 
    }//end if
    //retorna valor
    return(num);
} //end getDouble

/**
 * Exercicio02:
 * teste do getDouble.
*/
void Exercicio02()
{
    //identificar
    cout << "EXEMPLO1412 - Exercicio02 - v0.1" << endl;
    // definir dados
    std::string str;
    cout << "String a ser convertida para Double: "; cin >> str; cout << endl;
    double num = getDouble(str);
    cout << "String: " << str << "\tNum: " << num << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio02 ( )

/**
 * Funcao para converter conteudo para valor lógico, se possivel.
 * Nota: Considerar validos: { true, false, T, F, 0, 1 }
 * @return valor logico equivalente, se valido;
 * false, caso contrario
*/
bool getBoolean(std::string str)
{
    bool trueFalse = false;
    //testar os casos
    if (str == "true" || str == "T" || str =="1")
    {
        trueFalse = true;
    } else if (str == "false" || str == "F" || str =="0")
    {
        trueFalse = false;
    }
    //retornar valor
    return(trueFalse);
}//end getBoolean

/**
 * Exercicio03;
 * teste do getBoolean.
*/
void Exercicio03()
{
    // identificar
    cout << "EXEMPLO1413 - Exercicio03 - v0.1" << endl;
    // definir dados
    std::string str;
    cout << "String a ser convertida para Bool: "; cin >> str; cout << endl;
    bool num = getBoolean(str);
    cout << "String: " << str << "\tBool: " << num << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio03 ( )

/**
 * Funcao para verificar se o parametro esta’ contido no conteudo.
 * @return true , se contiver (em qualquer posicao);
 * false, caso contrario
*/
bool contains (std::string str, char texto)
{
    bool contain = false;
    //verificar a existencia em qualquer posicao
    int i = 0;
    while (i < str.length() && !contain)
    {
        if (str[i] == texto)
        {           
            contain = true;
        } //end if
        i++;
    }//end while
    //retornar valor
    return(contain);
} //end contains

/**
 * Exercicio04:
 * teste do contains.
*/
void Exercicio04()
{
    // identificar
    cout << "EXEMPLO1414 - Exercicio04 - v0.1" << endl;
    // definir dados
    std::string str;
    char cont;
    cout << "String: "; cin >> str; cout << endl;
    cout << "Conteudo: "; cin >> cont; cout << endl;
    bool num = contains(str, cont);
    cout << "String: " << str << "\tContem: " << num << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio04 ( )

/**
 * Funcao para converter letras para maiusculas.
 * @return valor equivalente em maiusculas, se houver;
 * o proprio valor, caso contrario
*/
std::string toUpperCase(std::string str)
{
    //aplicar funcao
    int i = 0;
    while (i < str.length())
    {
        int letter = str[i];
        str[i] = toupper(letter);
        i++;
    }//end while
    //retornar valor
    return(str);
}//end toUpperCase

/**
 * Exercicio05:
 * teste do toUpperCase.
*/
void Exercicio05()
{
    //identificar
    cout <<  "EXEMPLO1415 - Exercicio05 - v0.1" << endl;
    // definir dados
    std::string str;
    cout << "String: "; cin >> str; cout << endl;
    std::string upper = toUpperCase(str);
    cout << "String: " << str << "\tUpperCase: " << upper << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio05 ( )

/**
 * Funcao para converter letras para minusculas.
 * @return valor equivalente em minusculas, se houver;
 * o proprio valor, caso contrario
*/
std::string toLowerCase(std::string str)
{
    //aplicar funcao
    int i = 0;
    while (i < str.length())
    {
        int letter = str[i];
        str[i] = tolower(letter);
        i++;
    }//end while
    //retornar valor
    return(str);
} //end toLowerCase 

/**
 * Exercicio06:
 * teste do toLowerCase.
*/
void Exercicio06()
{
    //identificar
    cout <<  "EXEMPLO1416 - Exercicio06 - v0.1" << endl;
    // definir dados
    std::string str;
    cout << "String: "; cin >> str; cout << endl;
    std::string lower = toLowerCase(str);
    cout << "String: " << str << "\tLowerCase: " << lower << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio06 ( )

/**
 * Funcao para trocar todas as ocorrencias de certo caractere por outro novo.
 * @return valor com substituicoes, se houver;
 * o proprio valor, caso contrario
*/
std::string replace ( std::string str, char original, char novo )
{
    //aplicar funcao
    int i = 0;
    size_t pos;
    while (i < str.length())
    {
        if (str[i] == original)
        {
            str[i] = novo;
        }//end if       
        i++;
    }//end while
    //retornar valor
    return(str);
} //end replace

/**
 * Exercicio07:
 * reste do replace.
*/
void Exercicio07()
{
    //identificar
    cout << "EXEMPLO1417 - Exercicio07 - v0.1" << endl;
    // definir dados
    std::string str;
    char original, novo;
    cout << "String: "; cin >> str; cout << endl;
    cout << "Char Original: "; cin >> original; cout << endl;
    cout << "Char Novo: "; cin >> novo; cout << endl;
    std::string rep = replace(str, original, novo);
    cout << "String: " << str << "\tReplaced: " << rep << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio07 ( )

/**
 * Funcao para separar todas as sequencias de caracteres separadas por espaços em branco.
 * @param sequencia - arranjo para armazenar possiveis cadeias de caracteres identificadas
 * @return quantidade de sequencias de caracteres identificadas, se houver;
 * zero, caso contrario
*/
int split (std::string str)
{
    int i = 0;
    int j = 0;
    vector<string> cadeias;
    while (j < str.length())
    {
        if (str[j] == ' ')
        {
            i++;
        }//end if       
        j++;
      }//end while
    return(i);
}//end split

/**
 * Exercicio08:
 * teste split.
 * OBS: nao esta funcionando
*/
void Exercicio08()
{
    //identificar
    cout <<  "EXEMPLO1418 - Exercicio08 - v0.1" << endl;
    // definir dados
    std::string str;
    cout << "String: ";
    cin.ignore();
    getline( cin, str );
    int quantidade = split(str);
    cout << "String: " << str << "\tQuantidade de cadeias: " << quantidade << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio08 ( )

/**
 * Funcao para codificar o conteudo segundo a cifra de Cesar (pesquisar).
 * @return valor equivalente codificado, se houver;
 * o proprio valor, caso contrario
*/
std::string encrypt (std::string str)
{
	int i = 0;
	while(i < str.length())
	{
        //para A a W
        if ((int)str[i] >= 65 && (int)str[i] <= 87)
        {
            str[i] = (char)((int)str[i]+3);
        } else
        //para XYZ
        if ((int)str[i] >= 88 && (int)str[i] <= 90)  
        {
            str[i] = (char)((int)str[i]-23);
        } else
        //para a a w
        if ((int)str[i] >= 97 && (int)str[i] <= 119)
        {
            str[i] = (char)((int)str[i]+3);
        } else
        //para xyz
        if ((int)str[i] >= 120 && (int)str[i] <= 122)   
        {
            str[i] = (char)((int)str[i]-23);
        }
		i++;
	}//end while
    return(str);
}//end encrypt

/**
 * Exercicio09:
 * teste encrypt.
*/
void Exercicio09( )
{
    //identificar
    cout << "EXEMPLO1419 - Exercicio09 - v0.1" << endl;
    // definir dados
    std::string str;
    cout << "String: "; cin >> str; cout << endl;
    std::string cifra = encrypt(str);
    cout << "String: " << str << "\tCriptografada: " << cifra << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio09 ( )

/**
 * Funcao para decodificar o conteudo previamente cifrado pela funcao acima.
 * @return valor equivalente decodificado, se houver;
 * o proprio valor, caso contrario
*/
std::string decrypt (std::string str)
{
    int i = 0;
	while(i < str.length())
	{
        //para A a W
        if ((int)str[i] >= 68 && (int)str[i] <= 90)
        {
            str[i] = (char)((int)str[i]-3);
        } else
        //para XYZ
        if ((int)str[i] >= 65 && (int)str[i] <= 67)  
        {
            str[i] = (char)((int)str[i]+23);
        } else
        //para a a w
        if ((int)str[i] >= 100 && (int)str[i] <= 122)
        {
            str[i] = (char)((int)str[i]-3);
        } else
        //para xyz
        if ((int)str[i] >= 96 && (int)str[i] <= 99)   
        {
            str[i] = (char)((int)str[i]+23);
        }
		i++;
	}//end while
    return(str);
}//end decrypt

/**
 * Exercicio10:
 * teste decrypt
*/
void Exercicio10()
{
    //identificar
    cout << "EXEMPLO1420 - Exercicio10 - v0.1" << endl;
    // definir dados
    std::string str;
    cout << "String: "; cin >> str; cout << endl;
    std::string cifra = decrypt(str);
    cout << "String: " << str << "\tDescriptografada: " << cifra << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio10 ( )

/**
 * ExercicioE1:
 * teste do metodo para fragmentar conteudo.
 * Acrescentar um método (e testes) para fragmentar o conteúdo usando um delimitador à escolha,
diferente de espaço em branco.
*/
void ExercicioE1( )
{
    //identificar
    cout << "EXEMPLO14E1 - ExercicioE1 - v0.1" << endl;
   
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE1 ( )

/**
 * ExercicioE2:
 * teste do metodo para inverter ordem dos simbolos na cadeia de caracteres.
 * Acrescentar um método (e testes) para inverter a ordem dos símbolos na cadeia de caracteres.
*/
void ExercicioE2( )
{
    //identificar
    cout << "EXEMPLO14E2 - ExercicioE2 - v0.1" << endl;

    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE2 ( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes e testes
Exercicio01: Exemplo1411
    -Teste 1:   String a ser convertida para Int: asaa
                String: asaa    Num: -1
    -Teste 2:   String a ser convertida para Int: 1234
                String: 1234    Num: 1234
    -Teste 3:   String a ser convertida para Int: 1as4
                String: 1as4    Num: -1 


Exercicio02: Exemplo1412
    -Teste 1:   String a ser convertida para Double: asc
                String: asc     Num: 0
    -Teste 2:   String a ser convertida para Double: 232.432
                String: 232.432 Num: 232.432
    -Teste 3:   String a ser convertida para Double: 23.43.5rd
                String: 23.43.5rd       Num: 0
    -Teste 4:   String a ser convertida para Double: 32.45.43
                String: 32.45.43        Num: 0
    -Teste 5:   String a ser convertida para Double: 43
                String: 43      Num: 43

Exercicio03: Exemplo1413
    -Teste 1:   String a ser convertida para Bool: true
                String: true    Bool: 1
    -Teste 2:   String a ser convertida para Bool: false
                String: false   Bool: 0
    -Teste 3:   String a ser convertida para Bool: T
                String: T       Bool: 1
    -Teste 4:   String a ser convertida para Bool: F
                String: F       Bool: 0
    -Teste 5:   String a ser convertida para Bool: 0
                String: 0       Bool: 0
    -Teste 6:   String a ser convertida para Bool: 1
                String: 1       Bool: 1
    -Teste 7:   String a ser convertida para Bool: 3432
                String: 3432    Bool: 0
    -Teste 8:   String a ser convertida para Bool: dasf
                String: dasf    Bool: 0

Exercicio04: Exemplo1414
    -Teste 1:   String: abc123
                Conteudo: c
                String: abc123  Contem: 1
    -Teste 2:   String: abc123
                Conteudo: 4
                String: abc123  Contem: 0

Exercicio05: Exemplo1415
    -Teste 1:   String: AbacO
                String: AbacO   UpperCase: ABACO
    -Teste 2:   String: luana
                String: luana   UpperCase: LUANA
      
Exercicio06: Exemplo1416  
    -Teste 1:   String: LUANA
                String: LUANA   LowerCase: luana
    -Teste 2:   String: aBACo
                String: aBACo   LowerCase: abaco

Exercicio07: Exemplo1417
    -Teste 1:   String: Luana
                Char Original: a
                Char Novo: u
                String: Luana   Replaced: Luunu
    -Teste 2:   String: luana
                Char Original: o
                Char Novo: p
                String: luana   Replaced: luana
    -Teste 3:   String: aaaabbccdd
                Char Original: a
                Char Novo: E
                String: aaaabbccdd      Replaced: EEEEbbccdd

Exercicio08: Exemplo1418
    -Teste 1:   
   
Exercicio09: Exemplo1419
    -Teste 1:   String: abcdefghijklmnopqrstuvwxyz      Criptografada: defghijklmnopqrstuvwxyzabc
    -Teste 2:   String: ABCDEFGHIJKLMNOPQRSTUWXYZ       Criptografada: DEFGHIJKLMNOPQRSTUVWXZABC
    -Teste 3:   String: lUanA   Criptografada: oXdqD

Exercicio10: Exemplo1420
    -Teste 1:   String: oXdqD   Descriptografada: lUanA
    -Teste 2:   String: defghijklmnopqrstuvwxyzabc      Descriptografada: abcdefghijklmnopqrstuvwxyz
    -Teste 3:   String: DEFGHIJKLMNOPQRSTUVWXZABC       Descriptografada: ABCDEFGHIJKLMNOPQRSTUWXYZ
    
ExercicioE1: Exemplo14E1 (extra1)
    -Teste 1: 

ExercicioE1: Exemplo14E1 (extra1)
    -Teste 1:

OBS: acredito que eram para serem postas em uma classe de um objeto criado std::string porem acabei
comecando os exercicios fora e como estava confusa sobre o local, decidi deixar assim.   
---------------------------------------------- historico
Versao  Data     Modificacao
 1.0    26/11    versao semi
 1.1    27/11    versao final
*/