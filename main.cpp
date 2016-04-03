#include"snake.h"

int main()
{
    int cou=0;
    snake s;
    CreatMap();
    s.CreatSnake();
    Start(s);
    getchar();
    return 0;
}
