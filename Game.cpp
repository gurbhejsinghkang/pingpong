#include "Game.h"
#include "Game.h"
using namespace utility;



Game::Game() // TODO: Initialize all instance variables
    : map(Coordinate(0, 0), Coordinate(80, 20)),
    player1(Coordinate(5, 6), Coordinate(5, 9), Direction::Down),
    player2(Coordinate(75, 6), Coordinate(75, 9), Direction::Down),
    ball(Coordinate(75, 10), Direction::Up, Direction::left),
    /*snake(Coordinate(20, 12), Direction::Right),*/
    writer(),
    reader()
{
}

void Game::start()
{
    std::cout<<"player1's Score :"<<0;
    std::cout<<"\t\t player2's Score :"<<0;
    writer.drawRectangle(map.getTopLeft().X,map.getTopLeft().Y+1, map.getBottomRight().X,map.getBottomRight().Y);
    writer.setWindowSize(map.getSize());
    drawPlayer1('|');
    drawPlayer2('|');
    drawBall('*');
    /*writer.setCharacterAtPosition(player1.getPosition().X,player1.getPosition().Y, 'X');*/
    while (!reader.isEscapePressed())
    {
        update();
    }
}

void Game::update()
{
 

    for (int i = 0; i < 200; i++)
    {

        updateInput();
        updateBallMovement();
        Sleep(100); // Sleep for 20 milliseconds
    }

    //    updateInput();

}
void Game::drawPlayer1(char character)
{
    writer.fillRegion(character, player1.getHeadPosition().X, player1.getHeadPosition().Y,
        player1.getTailPosition().X, player1.getTailPosition().Y);

}

void Game::drawPlayer2(char character) {
    writer.fillRegion(character, player2.getHeadPosition().X, player2.getHeadPosition().Y,
        player2.getTailPosition().X, player2.getTailPosition().Y);
}

void Game::updatePlayer1Movement()
{
    player1.move();

}

void Game::updatePlayer2Movement()
{
    player2.move();
}

void Game::erasePlayer1(char character) {
    if (player1.getDirection() == Direction::Up)
    {
        writer.setCharacterAtPosition(player1.getTailPosition().X, player1.getTailPosition().Y + 1, character);
    }
    else if (player1.getDirection() == Direction::Down)
    {
        writer.setCharacterAtPosition(player1.getHeadPosition().X, player1.getHeadPosition().Y - 1, character);
    }

}



void Game::erasePlayer2(char character) {

    if (player2.getDirection() == Direction::Up)
    {
        writer.setCharacterAtPosition(player2.getTailPosition().X, player2.getTailPosition().Y + 1, character);
    }
    else if (player2.getDirection() == Direction::Down)
    {
        writer.setCharacterAtPosition(player2.getHeadPosition().X, player2.getHeadPosition().Y - 1, character);
    }
}



void Game::drawBall(char character)
{
    writer.setCharacterAtPosition(ball.getPosition().X, ball.getPosition().Y, character);
}



void Game::eraseBall(char character)
{
    switch (ball.getHorizontalDirection()) {
    case Direction::left:
        switch (ball.getVerticalDirection())
        {
        case Direction::Down:
            writer.setCharacterAtPosition(ball.getPosition().X + 1, ball.getPosition().Y - 1, character);
            break;
        case Direction::Up:
            writer.setCharacterAtPosition(ball.getPosition().X + 1, ball.getPosition().Y + 1, character);
            break;
        }
        break;
    case Direction::right:
        switch (ball.getVerticalDirection())
        {
        case Direction::Down:
            writer.setCharacterAtPosition(ball.getPosition().X - 1, ball.getPosition().Y - 1, character);
            break;
        case Direction::Up:
            writer.setCharacterAtPosition(ball.getPosition().X - 1, ball.getPosition().Y + 1, character);
            break;
        }
        break;
    }
}



void Game::updateInput()
{
    if (reader.isKeyPressed('W'))
    {
        if (player1.getHeadPosition().Y != map.getTopLeft().Y + 2) {
            player1.setDirection(Direction::Up);
            updatePlayer1Movement();
            drawPlayer1('|');
            erasePlayer1(' ');
        }
    }
    if (reader.isKeyPressed('S'))
    {
        if (player1.getTailPosition().Y != map.getBottomRight().Y - 1) {
            player1.setDirection(Direction::Down);
            updatePlayer1Movement();
            drawPlayer1('|');
            erasePlayer1(' ');
        }
    }
    if (reader.isDownArrowPressed()) {
        if (player2.getTailPosition().Y != map.getBottomRight().Y - 1) {
            player2.setDirection(Direction::Down);
            updatePlayer2Movement();
            drawPlayer2('|');
            erasePlayer2(' ');
        }
    }

    if (reader.isUpArrowPressed()) {
        if (player2.getHeadPosition().Y != map.getTopLeft().Y + 2) {
            player2.setDirection(Direction::Up);
            updatePlayer2Movement();
            drawPlayer2('|');
            erasePlayer2(' ');
        }
    }
}
void Game::updateBallMovement()
{
    ball.move();
    if (ball.getPosition().Y == map.getTopLeft().X + 3)
    {
        eraseBall(' ');


        ball.setVerticalDirection(Direction::Down);
    }
    else if (ball.getPosition().Y == map.getBottomRight().Y - 2)
    {
        eraseBall(' ');


        ball.setVerticalDirection(Direction::Up);
    }



    if (player1.getHeadPosition().X == ball.getPosition().X )
    {
        eraseBall(' ');
        ball.setHorizontalDirection(Direction::right);
       
     
    }
   
    
    if (player2.getHeadPosition().X == ball.getPosition().X)
    {
        eraseBall(' ');
        ball.setHorizontalDirection(Direction::left);
        
    }
    
    drawBall('*');
    eraseBall(' ');
}