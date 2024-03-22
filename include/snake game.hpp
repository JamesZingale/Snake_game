#ifndef SNAKE GAME_HPP
#define SNAKE GAME_HPP
#include <iostream>
#include<stdlib.h>

const char SNAKECHAR = 'O';
const char BACKCHAR = '#';
const char FOODCHAR = 'A';
const int ROWNUM = 20;
const int COLNUM = 30;


struct snakenode
{
    snakenode* next = nullptr;
    snakenode* prev = nullptr;
    char data;
    int x_pos, y_pos;
};

class snakegame
{
    public:
        snakegame();
        ~snakegame();
        void push_snakehead();
        void pop_snaketail();
        void displayframe();
        void displayGameOver();
        void addapple();
        void removeapple();
        void debug_displayheadtailpos();
        int getCurrentHeadDir();
        void setCurrentHeadDir(int);
        bool getGameOver();
        bool getDoPopTail();
        void setDoPopTail(bool);

    private:
        bool gameover = 0;
        bool doPopTail = 1;
        int snakeLenght;
        int score = 0;
        int currentHeadDir;
        const static int row = ROWNUM;
        const static int col = COLNUM;
        snakenode gamearr[row][col];
        snakenode* head;
        snakenode* tail;
        snakenode* apple;
};

#endif // SNAKE GAME_HPP
