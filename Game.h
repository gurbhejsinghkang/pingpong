#pragma once
#include "Map.h"
#include"Player1.h"
#include "Ball.h"
#include"ConsoleReader.h"
#include"ConsoleWriter.h"



class Game
{
private:
    Map map;
    Player1 player1, player2;
    Ball ball;
         
    utility::ConsoleWriter writer;
    utility::ConsoleReader reader;



public:
    Game();
    void start();



private:
    void update();
    void updateInput();
    void updateBallMovement();
    void updatePlayer1Movement();
    void updatePlayer2Movement();
    void drawPlayer1(char character);
    void drawPlayer2(char character);
    void drawBall(char character);
    void eraseBall(char character);
    void erasePlayer1(char character);
    void erasePlayer2(char character);
};