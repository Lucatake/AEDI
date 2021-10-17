/*
Guia_0205 -v0.2. - 12 / 08 / 2020
Author: Luana Campos Takeishi
Matri'cula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux:     gcc -o Guia0205      ./Guia0205.cpp
No Windows:   gcc -o Guia0205.exe    Guia0205.cpp
Para executar em uma janela de comandos (terminal):
No Linux:     ./Guia0205.cpp
No Windows:     Guia0205
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

/**
 pickBeepers - Metodo para coletar marcadores (todos)
*/
    int pickBeepers( )
    {
        //definir dado local
        int n = 0;
        //repetir (com teste no inicio)
        //enquanto houver marcador proximo
        while( nextToABeeper( ) )
        {
            //coletar um carcador
            pickBeeper( );
            //contar mais um marcador coletado
            n = n + 1;
        }//end while
        //retornar quantidade de marcadores coletados
        return( n );
    }//end pickBeepers( )


/**
 doSquare - Metodo para especificar outro percurso.
*/
    void doSquare( )
    {
        //definir dado local
        int step = 1;
        int n = 0;

        //especificar acoes da tarefa
        while( step<=4 )
        {
            //realizar uma parte da tarefa
            moveN( 3 );
            n = pickBeepers( );

            //testar se a quantidade e maior que zero
            if( n>0 )
            {
                //montar mensagem pra saida
                sprintf( msg_txt, "Recolhidos = %d", n );
                //agendar exibicao
                has_Text = true;
            }//end if

            turnRight( );
            //tentar passar a proxima
            step = step + 1;
        }//end while

        turnOff( );
    }//end doSquare( )

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
    decorateWorld( "Guia0205.txt");
    world->show( );

    //preparar o ambiente para uso
    world->reset( );                //limpar configurações
    world->read ("Guia0205.txt");   //ler configuracao atual para o ambiente
    world->show( );                 //mostrar a configuracao atual

    //definir velocidade padrao
    set_Speed( 3 );  

    //criar robo
    MyRobot*robot = new MyRobot( );

    //posicionar robo no ambiente (situacao inicial):
    //posicao (x=1,y=1), voltada para cima, com zero marcadores, nome escolhido
    robot->create ( 1 , 1 , NORTH , 0 , "Karel" );

    //executar tarefa
    robot->doSquare( );

    //encerrar programa
    getchar( );
    return( 0 );
    
}//end main

// -------------------------------------------testes
/*--------------------------------------------documentacao complementar
----------------------------------------------notas / observacoes / comentarios
Versão 0.1
programa executado (com mais de um marcador), Karel carrega os marcadores e para
Versão 0.2
programa executado (com um marcador apenas)
OBS: Karel nao retorna a sua posicao inicial (1,1) mas mosta a quantidade certa
----------------------------------------------previsao de testes
carregar um beeper e mostrar na tela o valor carregado = x
retornar a posicao inicial
modificacoes: pickBeepers - conta e retorna o valor dos marcadores
----------------------------------------------historico
Versao
Data Modificacao 0.1 12/08 esboco
Data Modificacao 0.2 12/08 esboco
---------------------------------------------testes
Versao Teste 0.1 01. ( OK ) teste inicial
Versao Teste 0.2 01. ( OK ) teste da repeticao para virar a direita
Versao Teste 0.3 01. ( OK ) teste da repeticao para percorrer um quadrado
Versao Teste 0.4 01. ( OK ) teste para carregar os marcadores
Versao Teste 0.5 02. ( OK ) teste para carregar os marcadores e retornar a quantidade
*/
