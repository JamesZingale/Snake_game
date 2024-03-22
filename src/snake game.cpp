#include "snake game.hpp"

void snakegame::debug_displayheadtailpos()
{
    std::cout << "head y, x: " << this->head->y_pos << " " << this->head->x_pos << std::endl;
    std::cout << "tail y, x: " << this->tail->y_pos << " " << this->tail->x_pos << std::endl;
}

snakegame::snakegame()
{
    currentHeadDir = 2;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
         gamearr[i][j].data = BACKCHAR;
        }
    }
    snakeLenght = 1;
    head = &gamearr[row/2][col/2];

    head->x_pos = col/2;
    head->y_pos = row/2;

    gamearr[head->y_pos][head->x_pos].data = SNAKECHAR;
    tail = head;
}

snakegame::~snakegame()
{

}
void snakegame::push_snakehead()
{
    int newxpos, newypos;
    switch(currentHeadDir)
    {
    case 1: // up
        newypos = head->y_pos - 1;
        newxpos = head->x_pos;
        break;
    case 2: //right
        newypos = head->y_pos;
        newxpos = head->x_pos + 1;
        break;
    case 3: //down
        newypos = head->y_pos + 1;
        newxpos = head->x_pos;
        break;
     case 4: //left
        newypos = head->y_pos;
        newxpos = head->x_pos - 1;
        break;
    }
    if(newypos >= 0 && newypos < row && newxpos >= 0 && newxpos < col)
    {
        switch(gamearr[newypos][newxpos].data)
       {
       case SNAKECHAR:
        gameover = 1;
        break;
       case FOODCHAR:
        doPopTail = 0;
        score += 3 * snakeLenght;
        snakeLenght++;
        break;
       }
        snakenode* new_head = &gamearr[newypos][newxpos];
        new_head->data = SNAKECHAR;

        new_head->y_pos = newypos;
        new_head->x_pos = newxpos;

        head->prev = new_head;
        new_head->next = head;
        new_head->prev = nullptr;

        head = new_head;

    }else{
    gameover = 1;
    }
}
void snakegame::pop_snaketail()
{
    if( gameover == 0 ) // so if not over
    {
        tail->data = BACKCHAR;
        tail = tail->prev;
        tail->next = nullptr;
    }
}
void snakegame::displayframe()
{
    //check width of int score
    int outputwidth = 10;
    switch(score)
    {
        case 0 ... 9:
            outputwidth = 10;
            break;
        case 10 ... 99:
        outputwidth = 11;
            break;
        case 100 ... 999:
            outputwidth = 12;
            break;
        case 1000 ... 9999:
        outputwidth = 13;
            break;
        case 10000 ... 99999:
            outputwidth = 14;
            break;
        case 100000 ... 999999:
        outputwidth = 15;
            break;
        case 1000000 ... 9999999:
        outputwidth = 16;
            break;
        case 10000000 ... 99999999:
        outputwidth = 17;
            break;
    }
    //header and score part
    std::cout << "\n \n \n|";
    for(int t = 0; t < col ; t++){
        std::cout << "-";
    }
    std::cout << "|\n|  Score: " << score;

    for(int t = 0; t < col - outputwidth ; t++){
        std::cout << ' ';
    }
    std::cout << "|\n|";
    for(int t = 0; t < col ; t++){
        std::cout << "-";
    }
    std::cout << "|\n";


    //output of the array
    for(int i = 0; i < row; i++)
    {
        std::cout << "|";
        for(int j = 0; j < col; j++)
        {
         std::cout << gamearr[i][j].data;
        }
        std::cout << "|\n";
    }

    //output of the footer
    std::cout << "|";
    for(int t = 0; t < col ; t++)
    {
        std::cout << "-";
    }
    std::cout << "|" << std::endl;
}
void snakegame::displayGameOver()
{
    std::cout << "|----------------------------------------------------------------------------------|\n"
                 "|  GGGGGG       A       M     M   EEEEEE       OOOOO   V       V  EEEEEE   RRRRRR  |\n"
                 "| G            A A      MM   MM   E           O     O   V     V   E        R     R |\n"
                 "| G   GGG     AAAAA     M M M M   EEEEE       O     O    V   V    EEEEE    RRRRRR  |\n"
                 "| G     G    A     A    M  M  M   E           O     O     V V     E        R    R  |\n"
                 "|  GGGGG    A       A   M     M   EEEEEE       OOOOO       V      EEEEEE   R     R |\n"
                 "|----------------------------------------------------------------------------------|\n"
                 "| score and final length                                                           |\n"
                 "|----------------------------------------------------------------------------------|\n"
                 "| Score:" << score << "\n"
                 "| Length:" << snakeLenght << "\n"
                 "|----------------------------------------------------------------------------------|\n";
}
void snakegame::addapple()
{
    int rand_rownum, rand_colnum;
    do
    {
        rand_rownum  = rand() % row ;
        rand_colnum  = rand() % col ;

    }while(gamearr[rand_rownum][rand_colnum].data != BACKCHAR);

    apple = &gamearr[rand_rownum][rand_colnum];
    apple->data  = FOODCHAR;
    apple->x_pos = rand_colnum;
    apple->y_pos = rand_rownum;
}
void snakegame::removeapple()
{
    apple = nullptr;
}
int snakegame::getCurrentHeadDir()
{
    return currentHeadDir;
}
void snakegame::setCurrentHeadDir(int dir)
{
    currentHeadDir = dir;
}
bool snakegame::getGameOver()
{
  return gameover;
}
bool snakegame::getDoPopTail()
{
    return doPopTail;
}
void snakegame::setDoPopTail(bool val)
{
    doPopTail = val;
}
