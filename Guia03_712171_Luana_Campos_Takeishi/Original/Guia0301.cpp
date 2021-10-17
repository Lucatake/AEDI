/*
Guia0301 - v0.5. - 19 / 08 / 2020
Author: Luana Campos Takeishi
Matr'icula: 712171
Para compilar em uma janela de comandos (terminal):
No Linux :      g++ -o Guia0301         ./Guia0301.cpp
No Windows:     g++ -o Guia0301.exe     Guia0301.cpp
Para executar em uma janela de comandos (terminal):
No Linux :      ./Guia0301.cpp
No Windows:     Guia0301
*/

// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

// --------------------------- definicoes de metodos

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
    // definir dado local
        int step = 0;
    // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
        // o agente que executar esse metodo
        // devera' virar tres vezes 'a esquerda
            for ( step = 1; step <= 3; step = step + 1 )
            {
                turnLeft( );
            } // end for
        } // end if
    } // end turnRight ( )

/**
moveN - Metodo para mover certa quantidade de passos.
@param steps - passos a serem dados.
*/
    void moveN( int steps )
    {
    // definir dado local
        int step = 0;
    // testar se a quantidade de passos e' maior que zero
        for ( step = steps; step > 0; step = step - 1 )
        {
        // dar um passo
            move( );
        } // end if
    } // end moveN( )

/**
countCommands - Metodo para contar comandos de arquivo.
@param fileName - nome do arquivo
*/
    void countCommands( const char *fileName )
    {
    // definir dados
        int x = 0;
        int length = 0;
        msg_txt [0] = '\0';
        std::ifstream archive ( fileName );

    // repetir enquanto houver dados
        archive >> x;
        while ( ! archive.eof ( ) )
        {
        // contar mais um comando
            length = length + 1;
        // tentar ler a proxima linha
            archive >> x;
        } // end while

    // fechar o arquivo
        archive.close( );
        
    // informar a quantidade de comandos guardados
        sprintf ( msg_txt, "Commands = %d", length );
        has_Text = true;
        show_Text ( msg_txt );
        
    } // end countCommands( )

}; // end class MyRobot

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
    decorateWorld ( "Guia0301.txt" );
    world->show ( );

    // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0301.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 1 ); // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot( );
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, NORTH, 0, "Karel" );

    // executar tarefa de contar comando
    robot->countCommands ( "Tarefa0301.txt" );
  
    
    // encerrar operacoes no ambiente
    world->close ( );
    // encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )

// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
instrucoes: 
- programa para contar a quantidade de comandos em um arquivo e mostrar na tela
---------------------------------------------- notas / observacoes / comentarios
Versao 0.1
o programa nao mostra nada
Versao 0.2
o programa so inicia apos dar enter e ainda nao mostra a quantidade de comandos
foi adicionado o playActions depois de countCommands, ainda nao mostra a contagem
Versao 0.3
no countCommands //show_Text ( msg_txt ); foi retidado
apos a modificacao ele roda correntamente, mostrando a quantidade de comandos, 
porem pula o primeiro comando, foi percebido que o programa somente printa em 
tela o comando quando executado as acoes depois
Versao 0.4
erro corrigido: 
msg_txt ja havia sido utilizada, mudanca para message 
pois o Karel ja utilizava a msm_txt, gerando conflito 
e zerando a variavel ao utiliza-la em outra funcao
Versao 0.5
mudanca de karel e uso do msg_txt
---------------------------------------------- previsao de testes
ao iniciar, o programa mostra qqqos comandos (linhas escritas) 
foram lidos dentro do arquivo Tarefa0301.txt
---------------------------------------------- historico
Versao Data Modificacao
0.1 17/08 esboco
0.2 17/08 esboco
0.3 17/08 esboco
0.4 18/08 esboco
0.5 19/08 esboco
---------------------------------------------- testes
Versao Teste
0.1 05. ( OK ) identificacao de programa
*/