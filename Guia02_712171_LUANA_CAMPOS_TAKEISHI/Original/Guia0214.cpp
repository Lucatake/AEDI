/*
Guia_0214 -v0.6. - 14 / 08 / 2020
Author: Luana Campos Takeishi
Matri'cula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux:     gcc -o Guia0214      ./Guia0214.cpp
No Windows:   gcc -o Guia0214.exe    Guia0214.cpp
Para executar em uma janela de comandos (terminal):
No Linux:     ./Guia0214.cpp
No Windows:     Guia0214
*/

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

//---------------------------definicoes de metodos

/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar marcadores no mundo
    world->set ( 3, 3, BEEPER );
    world->set ( 3, 3, BEEPER );
    world->set ( 3, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 3, 4, BEEPER );
    world->set ( 3, 4, BEEPER );
    world->set ( 4, 4, BEEPER );
    world->set ( 4, 4, BEEPER );
    world->set ( 3, 5, BEEPER );

//paredes vertical externa esquerda
    world->set ( 2, 3, VWALL);
    world->set ( 2, 4, VWALL);
    world->set ( 2, 5, VWALL);
    world->set ( 2, 6, VWALL);
    world->set ( 2, 7, VWALL);
    world->set ( 2, 8, VWALL);
//paredes vertical externa direita
    world->set ( 5, 3, VWALL);
    world->set ( 5, 4, VWALL);
    world->set ( 5, 5, VWALL);
    world->set ( 5, 6, VWALL);
    world->set ( 5, 7, VWALL);
    world->set ( 5, 8, VWALL);
//paredes verticais interna esquerda
    world->set ( 3, 3, VWALL);
    world->set ( 3, 4, VWALL);
    world->set ( 3, 5, VWALL);
    world->set ( 3, 6, VWALL);
    world->set ( 3, 7, VWALL);
//paredes verticais interna direita
    world->set ( 4, 3, VWALL);
    world->set ( 4, 4, VWALL);
    world->set ( 4, 5, VWALL);
    world->set ( 4, 6, VWALL);
    world->set ( 4, 7, VWALL);
//paredes horizontais 
    world->set ( 3, 2, HWALL);
    world->set ( 4, 2, HWALL);
    world->set ( 5, 2, HWALL);
    world->set ( 3, 8, HWALL);
    world->set ( 5, 8, HWALL);

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
 pickBeepers - Metodo para carregar marcadores
*/
    void pickBeepers ( int n ) //carregar N marcadores
    {
        for ( int b = 0; b != n; b++)
        {
                        if ( nextToABeeper( ) )
            {
            // ... de tentar carrega-lo
            pickBeeper( );
            //funcao opara guardar as coordenadas dos marcadores
            coordBeepers( "Tarefa0214.txt" );
            } //end if
        }//end for
    }//end pickBeepers( )

/**
 putBeepers - Metodo para descarregar marcadores
*/
     void putBeepers ( int n ) //descarregar N marcadores no local
    {
        for ( int b = 0; b != n; b++)
        {
            //se estiver na posicao desejada
            if ( areYouHere(7,1) )          
            {
                if ( beepersInBag( ) )
                {
                    // ... de tentar descarrega-lo
                    putBeeper( );
                }//end if
            }//end if
        }//end for
    }//end putBeepers ( )

/**
 doSquare - Metodo para especificar outro percurso.

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
            //n = pickBeepers(  );

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
*/

/**
 moveLeft - Metodo para virar a esquerda e andar N passos
*/
    void moveLeft( int p )
    {
        if ( leftIsClear( ) )
        {
            turnLeft( );
            moveN( p );
        }//end if
    }//end moveLeft( )
/**
 moveRight - Metodo para virar a direita e andar N passos
*/
    void moveRight( int p )
    {
        if ( rightIsClear( ) )
        {
            turnRight( );
            moveN( p );
        }//end if
    }//end moveRight( )

/**
 recordActions - Metodo para mover o robot interativamente
 e aguardar a descricao da tarefa em arquivo.
 @param fileName - nome do arquivo

    void recordActions( const char *fileName )
    {
        //definir dados
        int action;
        //definir arqui onde gravar comandos
        std::ofstream archive ( fileName );

        //ler opcao
            action = IO_readint( "Command?" );
        //repetir enquanto for maior ou igual a zero
        while( action!=0 )
        {
            //testar se opcao e valida
            if ( 0 <= action&&action <=9 )
            {
                //executar comando
                execute( action );
                
                //guardar o comando earquivo
                archive<<action<<"\n";
            }//end if
            //ler opcao
            action = IO_readint( "Command?" );
        }//end while
        
        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        archive.close( );        
    }//end recordActions( )
*/


/**
 taskE( ) - Metodo para fazer a tarefa do exercicio
*/
    void taskE( )
    {
        //iniciar somente se estiver na posicao (1,1)
        if ( areYouHere(1,1) )
        {
            //chegar a borda do comodo
            turnLeft( );
            moveN( 8 );
            moveRight( 3 );
            //mover e carregar 1 beeper (3,5)
            moveRight( 1 );
            moveRight( 1 );
            moveLeft( 3 );
            pickBeepers( 1 );
            //mover e carregar 2 beepers (3,4)
            moveN( 1 );
            pickBeepers( 2 );
            //mover e carregar 2 beepers (4,4)
            turnLeft( );
            moveLeft( 4 );
            moveRight( 1 );
            moveRight( 4 );
            pickBeepers( 2 );
            //mover e carregar 3 beepers (4,3)
            moveN( 1 );
            pickBeepers( 3 );
            //mover e carregar 3 beepers (3,3)
            turnLeft( );
            moveLeft( 5 );
            moveLeft( 1 );
            moveLeft( 5 );
            pickBeepers( 3 );
            //mover e carregar 3 beepers (5,3)
            turnLeft( );
            moveLeft( 5 );
            moveRight( 2 );
            moveRight( 5 );
            pickBeepers( 3 );          
            //sair do comodo e descarregar os beepers
            turnLeft( );
            moveLeft( 5 );
            moveLeft( 1 );
            moveRight( 1 );
            moveRight( 3 );
            moveRight( 8 );
            putBeepers( 14 );

            //retornar ao ponto inicial
            moveRight( 6 );
            turnLeft( );
            turnLeft( );
        }//end if
              
    }//end taskE( )

/**
 coordBeepers - Metodo para arquivar posicoes dos marcadores carregados
 @param fileName - nome do arquivo
*/
    void coordBeepers( const char *fileName )
    {
        //definir dados
        int x, y;
        //definir arquivo onde gravar comandos
        FILE *archive;
        archive = fopen ("Tarefa0214.txt", "a" );
        //leitura da posicao
        x= xAvenue( );      //obter posicao atual (avenue)
        y= yStreet( );      //obter posicao atual (street)
        //arquivar a posicao
        fprintf( archive, "\n%d\n", x );
        fprintf( archive, "%d\n", y );
        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        fclose( archive );   

        //archive.close( );   
        
    }//end coordBeepers

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
    decorateWorld( "Guia0214.txt");
    world->show( );

    //preparar o ambiente para uso
    world->reset( );                //limpar configurações
    world->read ("Guia0214.txt");   //ler configuracao atual para o ambiente
    world->show( );                 //mostrar a configuracao atual

    //definir velocidade padrao
    set_Speed( 7 );  

    //criar robo
    MyRobot*robot = new MyRobot( );

    //posicionar robo no ambiente (situacao inicial):
    //posicao (x=1,y=1), voltada para cima, com zero marcadores, nome escolhido
    robot->create ( 1 , 1 , EAST , 0 , "Karel" );

    //executar tarefa
    robot->taskE( );
    

    //encerrar programa
    getchar( );
    return( 0 );
    
}//end main

// -------------------------------------------testes
/*--------------------------------------------documentacao complementar
instrucoes gerais:
-definir um robô na posição (1,1), voltado para leste, sem marcadores;
-buscar os marcadores nas posições indicadas, na ordem crescente das quantidades;
-descarregar os marcadores na posição indicada (X);
-retornar à posição inicial, voltar-se para leste e desligar-se;
-todas as posições visitadas pelo robô que tiverem marcadores
deverão ser guardadas em arquivo, cujo nome deverá ser Tarefa0214.txt.
----------------------------------------------notas / observacoes / comentarios
Versão 0.1
construcao do mundo e alocamento dos marcadores
Versao 0.2
programando Karel para carregar e descarregar os marcadores
Versao 0.3
corrigir movimentos Karel
Versao 0.4
programar para arquivar as posicoes dos marcadores no arquivo Tarefa0214.txt
funcao coordBeepers( ) para salvar as coordenadas - dentro de pickBeepers( )
Versão 0.5 / 0.6
tentativas de usar os comandos listados no Guia02
Karel busca os marcadores nas posicoes indicadas e salva suas coordenadas
x e y em linhas separadas no arquivo Tarefa0214.txt  
a cada marcador ela salva uma coordenada, sendo assim nas coordenadas
com mais de um marcador, salva-se mais de uma vez
----------------------------------------------previsao de testes
----------------------------------------------historico
Versao 1.0
Data Modificacao 0.1 13/08 esboco
Versao 2.0
Data Modificacao 0.1 13/08 esboco
Versao 3.0
Data Modificacao 0.1 13/08 esboco
erro: erro nos comandos de movimentar
Versao 4.0
Data Modificacao 0.1 13/08 esboco
erro: so arquiva a primeira coordenada, codigos do Guia02
não consegui utilizar, mostra erro de variavel
Versao 5.0
Data Modificacao 0.1 14/08 esboco
erro: arquiva e apaga constantemente os valores das coordenadas
so salvando a ultima
Versao 6.0
Data Modificacao 0.1 14/08 esboco
programa executado como o esperado --- salva as posicoes a quantidade de marcadores que tem
---------------------------------------------testes
Versao Teste 0.1 01. ( OK ) teste inicial
Versao Teste 0.2 01. ( OK ) teste da repeticao para virar a direita
Versao Teste 0.3 01. ( OK ) teste da repeticao para percorrer um quadrado
Versao Teste 0.4 01. ( OK ) teste para carregar os marcadores
Versao Teste 0.5 02. ( OK ) teste para carregar os marcadores e retornar a quantidade
Versao Teste 0.6 01. ( OK ) teste para comando do Karel interativo
Versao Teste 0.7 01. ( OK ) teste Karel arquivando os comandos 
Versao Teste 0.8 02. ( OK ) teste Karel realizando acoes arquivadas
Versao Teste 0.9 01. ( OK ) teste Karel com comandos arquivados escritos
Versao Teste 0.9 01. ( OK ) teste Karel com comandos escritos
Versao Teste 1.0 02. ( OK ) teste Karel arquiva, traduz, adiciona e realiza os comandos
Versao Teste 1.1 06. ( OK ) teste Exercicio 01 (escada)
Versao Teste 1.2 04. ( OK ) teste Exercicio 02 ("labirinto" X)
Versao Teste 1.3 02. ( OK ) teste Exercicio 03 (comodos e 6 marcadores)
Versao Teste 1.4 06. ( OK ) teste Exercicio 04 (comodos, 14 marcadores e arquivamento 
                                                            de posicoes dos marcadores)
*/