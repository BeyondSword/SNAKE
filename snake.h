#include<string>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define QUIT 'q'
#define REPLAY 'r'
using namespace std;
class node//链表节点
{

public:
	node(char b,int x=0,int y=0)
	{
        body=b;
        Pos_x=x;
        Pos_y=y;
        next=NULL;
	}; //构造函数
	node()
	{
        body=' ';
        Pos_x=0;
        Pos_y=0;
        next=NULL;
	}
	~node()
	{
	    if(!next)
            delete next;
        next=NULL;
	}
	node *next;
    char body;
	int  Pos_x;
    int  Pos_y;
};

class snake//链表
{
public:
    snake()
    {
        head=NULL;
        length=0;
        direction=0;
    }
    ~snake(){};
    void CreatSnake();//创建蛇
    void insert_body(node &n);//头插节点
    void delete_tail();//尾删节点
    void show_snake();//显示蛇的形状
    void direction_snake();//决定蛇的移动方向
    void move_snake();//使蛇移动
    void control_snake();
    void creat_food();
    void show_food();
    void eat_food();

private:
    node *head;
    int length;
    int direction;
    int apple_x;
	int apple_y;
};



void Set_cursor_Position(int x, int y);//定位
void CreatMap();//地图初始化
void PrintSnake (snake *head,int State);
//food*CreatFood(food *apple);
//snake*Move(snake *head,int State,food *apple);
int Control(snake *head);//定义控制并将按键信息传递给Move（）函数
void CanNotCrossWall(snake *head);
void Start(snake &s);
