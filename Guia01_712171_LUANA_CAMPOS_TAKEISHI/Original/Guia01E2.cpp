/*
 Guia01E2 - v0.0. - 07 / 08 / 2020
 Author: Luana Campos Takeishi
 Matri'cula: 712171
 Nu'mero de pessoa: 1295943
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia01E2 ./Guia01E2.cpp
 No Windows: g++ -o Guia01E2.exe Guia01E2.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia01E2.cpp
 No Windows: Guia01E2
*/

// lista de dependencias
#include "karel.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar 6 marcadores no mundo
for (int b = 1; b <= 6; b++)
{
 world->set ( 5, 3, BEEPER ); 
}
//colocar paredes no mundo
world->set ( 3, 2, HWALL );
world->set ( 4, 2, HWALL );
world->set ( 5, 2, HWALL ); //base
world->set ( 3, 6, HWALL );
world->set ( 4, 6, HWALL );
world->set ( 5, 6, HWALL ); //topo
world->set ( 2, 3, VWALL );
world->set ( 2, 4, VWALL );
world->set ( 2, 5, VWALL );
world->set ( 2, 6, VWALL ); //lateral esquerda
world->set ( 5, 3, VWALL );
world->set ( 5, 4, VWALL );
world->set ( 5, 5, VWALL ); //lateral direita

// salvar a configuracao atual do mundo
 world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/

class MyRobot : public Robot
{
 public:
 /**
 turnRight - Procedimento para virar 'a direita.
 */
 void turnRight ( )
 {
 // testar se o robo esta' ativo
 if ( checkStatus ( ) )
 {
 // o agente que executar esse metodo
 // devera' virar tres vezes 'a esquerda
 turnLeft ( );
 turnLeft ( );
 turnLeft ( );
 } // end if
 } // end turnRight ( )
 /**
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passos a serem dados.
 */
  void moveN( int steps )
 {
 // testar se a quantidade de passos e' maior que zero
 while ( steps > 0 ) // forma alternativa
 {
 // dar um passo
 move( );
 // tentar fazer de novo, com menos um passo
 steps = steps - 1;
 } // end while
 } // end moveN( ) 

public: void putBeepers ( int n ) //descarregar N marcadores no local
{
     for ( int b = 0; b < n; b++)
 {
   if ( nbeepers( ) > 0 )
  {
   // ... de tentar descarrega-lo
   putBeeper( );
  } 
 }
}// end putBeepers ( )

public: void pickBeepers ( int n ) //carregar N marcadores
{
 for ( int b = 0; b < n; b++)
 {
     if ( nextToABeeper( ) )
  {
  // ... de tentar carrega-lo
  pickBeeper( );
  } // end if
 } 
}// endputBeepers ( )


void parcialTask1( ) //carregar os 6 marcadores da posicao (5,3)
{
 moveN ( 5 );
 turnLeft( );
 moveN ( 5 ); 
 turnLeft( );
 moveN ( 1 );
 turnLeft( );
 moveN ( 3 );
 pickBeepers ( 6 );
}
void parcialTask2( ) //descarregar 3 marcadores da posicao (5,2)
{
 turnLeft( );
 turnLeft( );
 moveN ( 3 );
 turnRight( );
 moveN ( 1 ); 
 turnRight( );
 moveN ( 4 ); 
 turnRight( );
 moveN ( 1 ); 
 putBeepers ( 3 );
}
void parcialTask3( ) //descarregar 2 marcadores da posicao (2,3)
{
 moveN ( 3 ); 
 turnRight( );
 moveN ( 1 );
 putBeepers ( 2 );
}
void parcialTask4( ) //descarregar 1 marcador na posicao (3,7)
{
 moveN ( 4 ); 
 turnRight( );
 moveN ( 1 );
 putBeepers ( 1 );
}

void parcialTaskR( ) //retornar ao ponto inicial (1,1) e voltar-se para leste
{
 turnLeft( );
 turnLeft( );
 moveN ( 1 );
 turnLeft( );
 moveN ( 6 );
 turnRight( );
 moveN ( 1 );
 turnLeft( );
 turnLeft( );
}

void doTask( )
 {
 // especificar acoes da tarefa
 //buscando os 6 marcadores em (5,3)
 parcialTask1( );
 //descarregando os marcadores em (5,2), (2,3) e (3,7) respectivamente
 parcialTask2( );
 parcialTask3( );
 parcialTask4( );
 //retornar ao ponto inicial
 parcialTaskR( );

 // encerrar
 turnOff ( );
 }

 }; // end doTask( )
 // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
 world->create ( "" ); // criar o mundo
 decorateWorld ( "Guia01E2.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia01E2.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 3 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" ); //inicia com 0 marcadores
// executar tarefa
 robot->doTask ( );
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )
// ---------------------------------------------- testes
/**
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
instrucoes gerais 
Redefinir as repetições em um programa Guia01E2 para usar variações crescentes ao invés de decrescentes
---------------------------------------------- previsao de testes
---------------------------------------------- historico
01. teste nas posicoes do exercicio 5 Guia_0115
Versao Data Modificacao
 0.1 07/08 esboco

---------------------------------------------- testes
Versao Teste
 0.1 0.1 ( OK ) teste inicial
 0.2 0.1 ( OK ) teste da tarefa
 0.3 0.1 ( OK ) teste da tarefa parcial
 0.4 0.1 ( OK ) teste do apanhar marcador
 0.5 0.1 ( OK ) teste do colocar marcador
0.6 01. ( OK ) teste da repeticao do movimento
0.7 01. ( OK ) teste com marcador na posicao (4,4)
02. ( OK ) teste sem marcador na posicao (4,4)
 0.8 01. ( OK ) teste com a quantidade de marcadores
 0.9 01. ( OK ) teste com outra forma de repeticao
 1.0 01. ( OK ) teste com outra forma de alternativa
 1.1 03. ( OK ) teste Karel com 3 marcadores
 1.2 03. ( OK ) teste 3 marcadores no mundo para Karel buscar
 1.3 02. ( OK ) teste 3 marcadores para Karel mudar de lugar
 1.4 04. ( OK ) teste 3 marcadores e paredes 
 1.5 02. ( OK ) teste 6 marcadores e paredes
 E.1 03. ( OK ) funcao para carregar e descarregar mais de um marcador
 E.2 01. ( OK ) funcao para carregar e descarregar mais de um marcador
 */