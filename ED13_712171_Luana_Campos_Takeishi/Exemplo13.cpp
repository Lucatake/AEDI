/**
 * Estudo Dirigido 13 - v0.1. - 21 / 11 / 2020
 * Author: Luana Campos Takeishi
 * Matricula: 712171
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres

// ----------------------------------------------- classes
#include "Contato.hpp" // classe para tratar dados de pessoas
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
        cout << "ESTUDO DIRIGIDO 13 - Programa - v0.1\n " << endl;
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
 * para ler do teclado e atribuir um valor ao nome 
 * (atributo de certo objeto).
 * Incluir um metodo para testar essa nova caracteristica.
 * DICA: Testar se o nome nao esta vazio.
 * Exemplo: contato1.readNome ( “Nome: ” );
*/
void Exercicio01()
{
    // identificar
    cout << "\nEXEMPLO1311 - Exercicio01 - v0.1\n" << endl;
    // definir dados locais
    Contato pessoa;
    // ler do teclado o nome
    pessoa.readNome("Nome: ");
    // verificar o novo metodo
    cout << "pessoa: " << pessoa.toString() << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio01 ( )

/**
 * Exercicio02:
 * para ler do teclado e atribuir um valor ao telefone 
 * (atributo de certo objeto).
 * Incluir um metodo para testar essa nova caracteristica.
 * DICA: Testar se o telefone não está vazio.
 * Exemplo: contato1.readFone ( “Fone: ” );
*/
void Exercicio02()
{
    //identificar
    cout << "EXEMPLO1312 - Exercicio02 - v0.1" << endl;
    // definir dados locais
    Contato pessoa;
    // ler do teclado o nome
    pessoa.readFone("Fone: ");
    // verificar o novo metodo
    cout << "pessoa: " << pessoa.toString() << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio02 ( )

/**
 * Exercicio03;
 * para testar se o valor de um telefone e' valido, ou nao.
 * Incluir um metodo para testar essa nova caracteristica.
 * DICA: Testar se as posicoes contem apenas algarismos e o simbolo ‘-‘.
*/
void Exercicio03()
{
    // identificar
    cout << "EXEMPLO1313 - Exercicio03 - v0.1" << endl;
    // definir dados locais
    Contato pessoa;
    // ler do teclado o nome
    cout << "0 - invalido\t 1 - valido" << endl;
    pessoa.readFone("Fone: ");
    // testar se fone e' valido
    int valido = pessoa.validoFone( );
    cout << "Fone valido: " << valido << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio03 ( )

/**
 * Exercicio04:
 * para ler dados de arquivo, dado o nome do mesmo,
 * e armazenar em um objeto dessa classe.
 * Incluir um metodo para testar essa nova caracteristica.
 * Exemplo: contato1.fromFile ( “Pessoa1.txt” );
*/
void Exercicio04()
{
    // identificar
    cout << "EXEMPLO1314 - Exercicio04 - v0.1" << endl;
    // definir dados locais
    Contato pessoa;
    //ler pessoa de arquivo
    pessoa.fromFile("PESSOAS.TXT");
    cout << "pessoa: " << pessoa.toString() << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio04 ( )

/**
 * Exercicio05:
 * para gravar dados de uma pessoa em arquivo,
 * dado o nome do mesmo.
 * Incluir um metodo para testar essa nova caracteristica.
 * DICA: Gravar o tamanho tambem do arquivo, primeiro, antes dos outros dados.
 * Exemplo: contato.toFile ( “Pessoa1.txt” );
*/
void Exercicio05()
{
    //identificar
    cout <<  "EXEMPLO1315 - Exercicio05 - v0.1" << endl;
    // definir dados locais
    Contato pessoa;
    //cout << "quantidade de pessoas: "; cin >> n; cout << endl;
    //ler pessoa de arquivo
    pessoa.readNome("Nome: ");
    pessoa.readFone("Fone: ");
    cout << "pessoa: " << pessoa.toString() << endl;
    pessoa.toFile("PESSOAS.TXT");
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio05 ( )

/**
 * Exercicio06:
 * um novo atributo para um segundo telefone e modificar os construtores para lidar com isso.
 * Incluir um metodo para testar essa nova caracteristica.
 * Exemplo: contato1 = new Contato ( “nome1”, “1111-1111”, “2222-2222” );
*/
void Exercicio06()
{
    //identificar
    cout <<  "EXEMPLO1316 - Exercicio06 - v0.1" << endl;
    // definir dados locais
    Contato *pessoa[1];
    pessoa[0] = new Contato("Luana", "3221-7765", "99986-6754", "", "");
    // mostrar resultado
    cout << "pessoa: " << pessoa[0]->toString() << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio06 ( )

/**
 * Exercicio07:
 * um novo atributo para indicar quantos telefones estao associados a cada objeto.
 * Incluir um metodo para obter essa informaçao.
 * Incluir um metodo para testar essa nova caracteristica.
 * Exemplo: int n = contato1.telefones ( );
*/
void Exercicio07()
{
    //identificar
    cout << "EXEMPLO1317 - Exercicio07 - v0.1" << endl;
    // definir dados locais
    Contato *pessoa[3];
    pessoa[0] = new Contato("Luana", "3221-7765", "99986-6754", "", "");
    pessoa[1] = new Contato("Maria", "", "", "", "");
    pessoa[2] = new Contato("Joana", "" , "99986-6754", "", "");
    // mostrar pessoas
    for (int i = 0; i < 3; i++)
    {
        cout << "pessoa" << i << ": " << pessoa[i]->toString() << endl;
    }//end for
    // chaamr funcao e mostrar resultados
    cout << "pessoa0:" << pessoa[0]->telefones() << endl;
    cout << "pessoa1:" << pessoa[1]->telefones() << endl;
    cout << "pessoa2:" << pessoa[2]->telefones() << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio07 ( )

/**
 * Exercicio08:
 * para atribuir o valor do segundo telefone.
 * Incluir um metodo para testar essa nova caracteristica.
 * DICA: Se o contato so tiver um telefone, perguntar se 
 * quer acrescentar mais um numero,
 * e mudar automaticamente a quantidade deles, se assim for desejado.
 * Exemplo: contato.setFone2a ( “3333-3333” );
*/
void Exercicio08()
{
    //identificar
    cout <<  "EXEMPLO1318 - Exercicio08 - v0.1" << endl;
    // definir dados locais
    string res;
    Contato *pessoa[4];
    pessoa[0] = new Contato("Luana", "3221-7765", "", "", "");
    pessoa[1] = new Contato("Maria", "", "", "", "");
    pessoa[2] = new Contato("Joana", "" , "99986-6754", "", "");
    pessoa[3] = new Contato("MJ", "3221-7765" , "99986-6754", "", "");
    //definir segundo telefone
    for (int i = 0; i < 4; i++)
    {
        //se pessoa nao tem telefone
        if (pessoa[i]->telefones() == 0)
        {
            cout << "\npessoa" << i << ": " << pessoa[i]->toString() << endl;
            pessoa[i]->readFone("Fone: "); 
            cout << "Deseja adicionar mais um telefone? sim/nao "; cin >> res; cout << endl;
            if (res == "sim")
            {
                pessoa[i]->readTel("Tel: ");
            }//end if
        } else 
        //se pessoa tem so' um telefone
        if (pessoa[i]->telefones() == 1)
        {
            cout << "\npessoa" << i << ": " << pessoa[i]->toString() << endl;
            cout << "Deseja adicionar mais um telefone? sim/nao "; cin >> res; cout << endl;
            if (res == "sim")
            {
                if ( pessoa[i]->getTel( ) == "" )
                {
                    pessoa[i]->readTel("Tel: ");
                } else
                {
                    pessoa[i]->readFone("Fone: ");
                }//end if  
            }//end if
        } else
        {
            cout << "\npessoa" << i << ": " << pessoa[i]->toString() << endl;
            cout << "Ja possui dois telefones." << endl;
        }//end if
    }//end for
    //mostrar pessoas
    for (int i = 0; i < 4; i++)
    {
        cout << "\npessoa" << i << ": " << pessoa[i]->toString() << endl;
    }
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio08 ( )

/**
 * Exercicio09:
 * para alterar o valor apenas do segundo telefone.
 * Incluir um metodo para testar essa nova caracteristica.
 * DICA: Se o contato nao tiver dois telefones, uma situacao de erro devera ser indicada.
 * Exemplo: contato.setFone2b ( “3333-3333” );
*/
void Exercicio09( )
{
    //identificar
    cout << "EXEMPLO1319 - Exercicio09 - v0.1" << endl;
    // definir dados locais
    cout << "erro 3: inexistencia de telefones." << endl;
    Contato *pessoa[2];
    pessoa[0] = new Contato("Luana", "", "3221-7765", "", "");
    cout << "\npessoa0: " << pessoa[0]->toString() << endl;
    pessoa[1] = new Contato("Maria", "", "", "", "");
    cout << "\npessoa1: " << pessoa[1]->toString() << endl;
    // alterar telefone dois
    for (int i = 0; i < 2; i++)
    {
        if (pessoa[i]->telefones()==0)
        {
            int err = pessoa[i]->getErro( );
            cout << "\nerro: " << err << endl;
            cout << "pessoa" << i << ": " << pessoa[i]->toString() << endl;
        } else
        {
            pessoa[i]->readTel(" \nAlterar Tel: "); 
            cout << "pessoa" << i << ": " << pessoa[i]->toString() << endl;
        }//end if
    }//end for
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio09 ( )

/**
 * Exercicio10:
 * para remover apenas o valor do segundo telefone.
 * Incluir um metodo para testar essa nova caracteristica.
 * DICA: Se o contato so tiver um telefone, uma situacao de erro devera ser indicada.
 * Exemplo: contato.setFone2c ( "" );
*/
void Exercicio10()
{
    //identificar
    cout << "EXEMPLO1320 - Exercicio10 - v0.1" << endl;
    // definir dados locais
    Contato *pessoa[2];
    pessoa[0] = new Contato("Luana", "3456-9765", "3221-7765", "", "");
    cout << "\npessoa: " << pessoa[0]->toString() << endl;
    // chamar funcao para retirar sefundo fone
    pessoa[0]->setTel(" ");
    cout << "\npessoa: " << pessoa[0]->toString() << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim Exercicio10 ( )

/**
 * ExercicioE1:
 * para lidar com qualquer quantidade de telefones, menor que 10.
 * Incluir testes para essa nova caracteristica.
 * DICA: Guardar a quantidade de telefones e, separadamente, os telefones em arranjo.
*/
void ExercicioE1( )
{
    //identificar
    cout << "EXEMPLO13E1 - ExercicioE1 - v0.1" << endl;
   
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE1 ( )

/**
 * ExercicioE2:
 * para lidar tambem com enderecos (residencial e profissional).
 * Incluir testes para essa nova caracteristica.
 * DICA: Guardar separadamente o endereco residencial e o profissional.
*/
void ExercicioE2( )
{
    //identificar
    cout << "EXEMPLO13E2 - ExercicioE2 - v0.1" << endl;
    // dados locais
    Contato *pessoa[2];
    pessoa[1] = new Contato("Luana", "3456-9765", "3221-7765", "Av Joa Paulo", "Rua Antonio");
    cout << "\npessoa: " << pessoa[1]->toString() << endl;
    pessoa[0] = new Contato("", "", "", "", "");
    //cadastrar pessoa
    cout << "\n cadastrar pessoa: " << endl;
    pessoa[0]->readNome(" Nome: ");
    pessoa[0]->readFone(" Fone Residencial: ");
    pessoa[0]->readTel(" Telefone Celular: ");
    pessoa[0]->readEndResid(" Endereco Residencial: ");
    pessoa[0]->readEndProf(" Endereco Profissional: ");
    //mostrar pessoa
    cout << "\npessoa: " << pessoa[0]->toString() << endl;
    //encerrar
    pause("Apertar ENTER para continuar");
} // fim ExercicioE2 ( )

/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes e testes
Exercicio01: Exemplo1311
    -Teste 1:
        Nome: Luana
        pessoa:  { Luana,  }
    -Teste 2: 
        Nome: Catake
        pessoa:  { Catake,  }

Exercicio02: Exemplo1312
    -Teste 1: 
        Fone: 35991442610
        pessoa: { , 35991442610 }
    -Teste 2:
        Fone: 34348840
        pessoa: { , 34348840 }

Exercicio03: Exemplo1313
    0 - invalido     1 - valido
    -Teste 1: 
        Fone: 3221-6646
        Fone valido: 1
    -Teste 2: 
        Fone: 67755-6543
        Fone valido: 0
    -Teste 3: 
        Fone: 99867543
        Fone valido: 0
OBS: limitacao da formatacao do numero XXXX-XXXX

Exercicio04: Exemplo1314
    -Teste 1: PESSOAS.TXT 1
                        Luana
                        9989-0556
        pessoa: { Luana, 9989-0556 }
OBS: limitacao de uma pessoa por arquivo

Exercicio05: Exemplo1315
    -Teste 1: 
        Nome: Luana
        Fone: 4545-6678
    pessoa: { Luana, 4545-6678 }
    PESSOAS.TXT 1
              Luana
              4545-6678
OBS: limitacao de uma pessoa por arquivo
tentei por uma nova caracteristica em pessoas "n", para indicar quantas pessoas
possuem dentro do objeto, mas ainda nao funcionou
      
Exercicio06: Exemplo1316  
    -Teste 1: pessoa: { Luana, 3221-7765, 99986-6754 }

Exercicio07: Exemplo1317
    -Teste 1:
    pessoa0: { Luana, 3221-7765, 99986-6754 }
    pessoa1: { Maria, ,  }
    pessoa2: { Joana, , 99986-6754 }
            pessoa0:2
            pessoa1:0
            pessoa2:1
OBS: limitado ao numero de 2 telefones

Exercicio08: Exemplo1318
    -Teste 1:   
    pessoa0: { Luana, 3221-7765,  }
        Deseja adicionar mais um telefone? sim/nao sim
            Tel: 99988-6565
    pessoa1: { Maria, ,  }
        Fone: 9865-4434
        Deseja adicionar mais um telefone? sim/nao sim
            Tel: 43224-5443
    pessoa2: { Joana, , 99986-6754 }
        Deseja adicionar mais um telefone? sim/nao sim
            Fone: 3232-4454
    pessoa3: { MJ, 3221-7765, 99986-6754 }
        Ja possui dois telefones.
                pessoa0: { Luana, 3221-7765, 99988-6565 }
                pessoa1: { Maria, 9865-4434, 43224-5443 }
                pessoa2: { Joana, 3232-4454, 99986-6754 }
                pessoa3: { MJ, 3221-7765, 99986-6754 }

Exercicio09: Exemplo1319
    -Teste 1: erro 3: inexistencia de telefones.
        pessoa0: { Luana, , 3221-7765 }
    pessoa1: { Maria, ,  }
        Alterar Tel: 9854-3245
        pessoa0: { Luana, , 9854-3245 }
    erro: 3
    pessoa1: { Maria, ,  }

Exercicio10: Exemplo1320
    -Teste 1:
    pessoa: { Luana, 3456-9765, 3221-7765 }
    pessoa: { Luana, 3456-9765,   }

ExercicioE1: Exemplo13E1 (extra1)
    -Teste 1: 

ExercicioE1: Exemplo13E1 (extra1)
    -Teste 1:
        pessoa: { Luana, 3456-9765, 3221-7765, Av Joa Paulo, Rua Antonio }
            cadastrar pessoa:
            Nome: Joana
            Fone Residencial: 3232-4355
            Telefone Celular: 96543-5444
            Endereco Residencial: AvJoaoPedro
            Endereco Profissional: RuaAugustoLima
        pessoa: { Joana, 3232-4355, 96543-5444, AvJoaoPedro, RuaAugustoLima }
---------------------------------------------- historico
Versao  Data     Modificacao
 1.0    21/11    versao final

*/