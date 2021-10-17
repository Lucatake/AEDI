#include "io.hpp"
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

class Erro
{
  protected:
    int  erro;

    Erro ( )
    { erro = 0; }

    int  getErro ( )
    {   return ( erro ); }

    void setErro ( int valor )
    {   erro = valor; }
};

class Quadro : Erro
{
  private:
    int matriz [8][80];
    int tamanho;
    int x, y;
    std::string loja;

  public:
    void init ( )
    { // inicializar atributos da classe
      // definir valores iniciais
      //this->tamanho = 0;
      //this->x = 0;
      //this->y = 0;
      // definir tamanhos
      /*cout << "Nome da loja: "; cin >> this->loja; cout << endl;
      cout << "Quantidade de funcionarios: "; cin >> this->tamanho; cout << endl;
      this->matriz[8][this->tamanho];*/

      //zerar matriz
      for (this->x = 0; this->x < 8; this->x+=1)
      {
        for (this->y = 0; this->y < this->tamanho; this->y+=1)
        {
            this->matriz[this->x][this->y] = 0;
        }
      }
    } // end init ( )

    Quadro ( )
    { // construtor padrao
    // definir valores iniciais
      this->tamanho = 0;
      this->x = 0;
      this->y = 0;
    } // end constructor

    Quadro ( std::string nome, int n )
    { // construtor com o nome da loja e quantidade de usuarios
    // definir valores iniciais
      this->loja = nome;
      this->tamanho = n;
      this->matriz[8][this->tamanho];
      this->x = 0;
      this->y = 0;      
    } // end constructor

    void print ( )
    { // mostrar a planilha conforme o modelo
       int x=0, y=0;

       std::cout << "\nQuadro de Horarios: "
                 << loja << " (" << tamanho << "):\n\n";
       std::cout << "\t";
       for ( y=0; y<tamanho; y=y+1 )
       {
           std::cout << (y+1) << "\t";
       }
       for ( x=0; x<7; x=x+1 )
       {
           if ( x == 4 || x == 5 )
           {
             std::cout << std::endl;
           }
           std::cout << std::endl << (x+1) << "\t";
           for ( y=0; y<tamanho; y=y+1 )
           {
               std::cout << std::setw(4) << std::setfill('0')
                         << matriz[x][y] << "\t";
           }
       }
       std::cout << std::endl;
    } // end print ( )

    void fread ( std::string filename )
    { // ler dados de arquivo e guardar na planilha
      int a = 0;
      int lixo = 0;
      ifstream afile;
      afile.open(filename);
      //para colunas
      for (this->y = 0; this->y < this->tamanho; this->y= this->y + 1)
      {
        //para linhas
        for (this->x = 0; this->x < 8; this->x = this->x + 1)
        {
          //armazenar dados
          if ((a == 0) || (a%5 == 0))
          {
            afile >> lixo;
            lixo = 0;
            this->x-=1;
          } else
          {
            //guardar dados
            afile >> this->matriz[this->x][this->y];
          }//end if
          if (this->x > 3)
          {
            this->matriz[this->x][this->y] = 0;
          }//end if
          a++;
          cout << a<<endl;
        }
      }
    } // end fread ( )


    int add_hours ( int x, int y )
    { // calcular soma      de horas e minutos
      int hours = 0;
      int mins = 0;
      int hx = 0;
      int hy = 0;
      int mx = 0;
      int my = 0;

      //separar horas e minutos 
      hx = x / 100;
      mx = x - (hx * 100);
      hy = y / 100;
      my = y - (hy * 100);

      //calcular somas
      mins = mx + my;
      if (mins >= 60)
      {
        mins = mins - 60;
        hours = ((hx+hy)*100) + 100 + mins ;
      } else
      {
        hours = ((hx+hy)*100) + mins ;
      }     
        return ( hours );
    }

    int sub_hours ( int x, int y )
    { // calcular diferenca de horas e minutos
      int hours = 0;
      int mins = 0;
      int hx = 0;
      int hy = 0;
      int mx = 0;
      int my = 0;

      //separar horas e minutos 
      hx = x / 100;
      mx = x - (hx * 100);
      hy = y / 100;
      my = y - (hy * 100);

      //calcular somas
      mins = mx - my;
      if (mins < 0)
      {
        hours = ((hx-hy)*100) - 100 + (60 + mins) ; 
      } else
      {
        hours = ((hx-hy)*100) + mins ; 
      }
        return ( hours );
    }

    int lunch_break ( int y )
    { // calcular o tempo de descanso/intervalo
      this->matriz[4][this->y] = sub_hours(this->matriz[2][this->y], this->matriz[1][this->y]);
       return ( this->matriz[4][this->y] );
    }

    int labour_hours ( int y )
    { // calcular o valor bruto das horas trabalhadas no dia
      this->matriz[5][this->y] = sub_hours(sub_hours(this->matriz[3][this->y], this->matriz[0][this->y]), lunch_break(this->y));
       return ( this->matriz[5][this->y] );
    }

    void eval ( )
    { // avaliar as horas trabalhadas, condicoes e gerar resumo

      for (this->y = 0; this->y < this->tamanho; this->y+=1)
      {
        lunch_break(this->y);
        labour_hours(this->y);
      //advertencia 1
        if (sub_hours(this->matriz[0][this->y], this->matriz[1][this->y]) > 600 ||
            sub_hours(this->matriz[2][this->y], this->matriz[3][this->y]) > 600)
        {
          cout << 1 << endl;
        }//end if

      //advertencia 2
        if (this->matriz[5][this->y] > 800)
        {
          cout << 2 << endl;
          if (sub_hours(labour_hours(this->y), 800) > 100)
          {
            this->matriz[6][this->y] = 100;
          } else
          {
            this->matriz[6][this->y] = sub_hours(labour_hours(this->y), 800);
          }//end if         
        }//end if

      //advertencia 3
        if (this->matriz[5][this->y] < 800)
        {
          cout << 3 << endl;
          this->matriz[6][this->y] = sub_hours(800, labour_hours(this->y));        
        }//end if

      //horario descanso > 1h
        if (lunch_break(this->y) > 100)
        {
          this->matriz[6][this->y] = add_hours(100, sub_hours(lunch_break(this->y), this->matriz[6][this->y]));
        }//end if

      //horario descanso de 50-1h
        if (lunch_break(this->y) < 100)
        {
          if (sub_hours(100, lunch_break(this->y)) < 50)
          {
            this->matriz[6][this->y] = add_hours(this->matriz[6][this->y], 10);
          } else
          {
            this->matriz[6][this->y] = add_hours(sub_hours(lunch_break(this->y), 100), this->matriz[6][this->y]);
          }//end if
        }//end if

      }//end for
     
    }

    void test ( )
    { // testar definicoes
       Quadro *tabela = new Quadro ( "Matriz", 4 );

       std::cout << "\n1.Teste\n";
       tabela->print( );

       std::cout << "\n2.Teste\n";
       std::cout << "\n0830+0120 = " << add_hours ( 830, 120 );
       std::cout << "\n0830+0130 = " << add_hours ( 830, 130 );
       std::cout << "\n0830+0140 = " << add_hours ( 830, 140 );
       std::cout << "\n";
       std::cout << "\n0830-0120 = " << sub_hours ( 830, 120 );
       std::cout << "\n0830-0130 = " << sub_hours ( 830, 130 );
       std::cout << "\n0830-0140 = " << sub_hours ( 830, 140 );
       std::cout << "\n";

       std::cout << "\n3.Teste\n";
       tabela->fread( "M1.txt" );
       tabela->print( );

       std::cout << "\n4.Teste\n";
       tabela->eval ( );
       tabela->print( );
    } // end test ( )

}; // end class

int main ( void )
{
    Quadro a;
    a.init( );
    a.test( );

    return ( 0 );
} // end main ( )

/*
  Testes e anotacoes
  OBS: nao sei porque esta pulando duas colunas.
*/
