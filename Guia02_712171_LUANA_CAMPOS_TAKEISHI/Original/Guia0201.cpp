/*
Guia_0201 -v0.1. - 11 / 08 / 2020
Author: Luana Campos Takeishi
Matri'cula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux:     gcc -o Guia0201      ./Guia0201.cpp
No Windows:   gcc -o Guia0201.exe    Guia0201.cpp
Para executar em uma janela de comandos (terminal):
No Linux:     ./Guia0201.cpp
No Windows:     Guia0201
*/

// lista de dependencias
#include "karel.hpp"

//---------------------------definicoes de metodos

/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar um marcador no mundo
    world->set ( 4, 4, BEEPER );
// salvar a configuracao atual do mundo
    world->save( fileName );
} // decorateWorld ( )

/** Classe para definir robo particular (MyRobot),
  a partir do modelo generico (Robot)
    Nota: Todas as definicoes irao valer para qualquer outro robo
  criado a partir dessa nova descricao de modelo.
 */

class MyRobot : public Robot
{
    public:

 //turnRight - procedimento para virar a direita.
    void turnRight( )
    {
        //definir dado local
        int step = 0;

        //testar se o robo esta ativo
        if (checkStatus( ))
        {
            //o agente devera executar esse metodo
            //virar tres vezes a esquerda
            for ( step=1 ; step<=3 ; step=step+1 )
            {
                turnLeft( );
            }//end for
        }//end if
    }//end turnRight( )

/** 
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passosa serem dados.
*/
    void moveN( int steps )
    {
        //definir dado local
        int step = 0;

        //testar se a quantidade de passos e maior que zero
        for ( step=steps; step>0 ; step=step-1 )
        {
            //dar um passo
            move( );
        }//end for
    }//end moveN( )

/**
 doPartialTask - Metodo para especificar parte de uma tarefa
*/
    void doPartialTask( )
    {
        //especificar acoes dessa parte da tarefa
        moveN( 3 );
        turnLeft( );
    }//end doPartialTask( )

/**
 doTask - Relação de acoes para o robo executar
*/
    void doTask( )
    {
        //definir dado local
        int step = 4;

        //especificar acoes da tarefa
        while( step>0 )
        {
            //realizar parte da tarefa
            doPartialTask( );
            //tentar passar para a proxima
            step = step - 1;
        }//end while

        //encerrar
        turnOff( );
    }//end doTask( )

};//end class MyRobot



//---------------------------acao principal
/**
 acao principal: executar a tarefa descrita acima
*/

int main( )
{
    //definir contexto

    //criar o ambiente e decorar com objetos
    //obs: executar pelo menos uma vez,
    //     antes de qualquer coisa
    //     (depois de criado, podera ser comentado)
    world->create("");              //criar mundo
    decorateWorld( "Guia0201.txt");
    world->show( );

    //preparar o ambiente para uso
    world->reset( );                //limpar configurações
    world->read ("Guia0201.txt");   //ler configuracao atual para o ambiente
    world->show( );                 //mostrar a configuracao atual

    //definir velocidade padrao
    set_Speed( 3 );  

    //criar robo
    MyRobot*robot = new MyRobot( );

    //posicionar robo no ambiente (situacao inicial):
    //posicao (x=1,y=1), voltada para a direita, com zero marcadores, nome escolhido
    robot->create ( 1 , 1 , EAST , 0 , "Karel" );

    //executar tarefa
    robot->doTask( );

    //encerrar programa
    getchar( );
    return( 0 );
    
}//end main

// -------------------------------------------testes
/*--------------------------------------------documentacao complementar
----------------------------------------------notas / observacoes / comentarios
Versão 0.1
o mundo foi criado corretamente e o Karel realiza o percurso sem carregar o beeper.
----------------------------------------------previsao de testes
----------------------------------------------historico
Versao
Data Modificacao 0.1 11/08 esboco
---------------------------------------------testes
Versao Teste 0.1 01. ( OK ) teste inicial
*/
