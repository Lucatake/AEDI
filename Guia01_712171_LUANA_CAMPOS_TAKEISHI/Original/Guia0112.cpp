/*
 Guia0112 - v0.1. - 07 / 08 / 2020
 Author: Luana Campos Takeishi
 Matri'cula: 712171
 Nu'mero de pessoa: 1295943
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0112 ./Guia0112.cpp
 No Windows: g++ -o Guia0112.exe Guia0112.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0112.cpp
 No Windows: Guia0112
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
// colocar marcadores no mundo
world->set ( 3, 3, BEEPER ); 
world->set ( 3, 6, BEEPER ); 
world->set ( 6, 6, BEEPER ); 
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

void Beeper( ) //carregar ou descarregar o marcador
{
 if ( nextToABeeper( ) )
 {
 // ... de tentar carrega-lo
 pickBeeper( );
 } // end if
 // testar se carrega marcador antes ...
 
/*
 if ( nbeepers( ) > 0 )
 {
 // ... de tentar descarrega-lo
 putBeeper( );
 } // end if
 */
}

void parcialTask1( ) //carregar marcador da posicao (6,6)
{
 moveN ( 5 );
 turnLeft( );
 moveN ( 5 ); 
 Beeper( );
}
void parcialTask2( ) //carregar marcador da posicao (3,6)
{
 turnLeft( );
 moveN ( 3 ); 
 Beeper( ); 
}
void parcialTask3( ) //carregar marcador da posicao (3,3)
{
 turnLeft( );
 moveN ( 3 ); 
 Beeper( ); 
}
void parcialTaskR( ) //retornar ao ponto inicial (1,1) e voltar-se para leste
{
 moveN ( 2 );
 turnRight( );
 moveN ( 2 );
 turnLeft( );
 turnLeft( ); 
}

void doTask( )
 {
 // especificar acoes da tarefa
 parcialTask1( );
 parcialTask2( );
 parcialTask3( );
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
 decorateWorld ( "Guia0112.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0112.txt" );// ler configuracao atual para o ambiente
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
-configurar o mundo para conter inicialmente três marcadores ("beepers") nas posições anteriormente indicadas:(3,3), (3,6) e (6,6) nessa ordem;
-o robô deverá partir da posição inicial (coluna=1, linha=1), voltado para leste e nenhum marcador;
-buscar os marcadores nas posições indicadas, na ordem inversa à qual foram colocados; (6,6), (3,6) e (3,3) nessa ordem;
-retornar à posição inicial, voltar-se para o leste e desligar-se.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
0.1 configurar o caminho do Karel
0.2 colocar os marcadores no mundo, erro ao pegar os marcadores (carregou e descarregou em seguida)
0.3 erros corrigidos

Versao Data Modificacao
 0.1 07/08 esboco
 0.2 07/08 esboco
 0.3 07/08 esboco
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
 */