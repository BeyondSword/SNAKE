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
class node//����ڵ�
{

public:
	node(char b,int x=0,int y=0)
	{
        body=b;
        Pos_x=x;
        Pos_y=y;
        next=NULL;
	}; //���캯��
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

class snake//����
{
public:
    snake()
    {
        head=NULL;
        length=0;
        direction=0;
    }
    ~snake(){};
    void CreatSnake();//������
    void insert_body(node &n);//ͷ��ڵ�
    void delete_tail();//βɾ�ڵ�
    void show_snake();//��ʾ�ߵ���״
    void direction_snake();//�����ߵ��ƶ�����
    void move_snake();//ʹ���ƶ�
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



void Set_cursor_Position(int x, int y);//��λ
void CreatMap();//��ͼ��ʼ��
void PrintSnake (snake *head,int State);
//food*CreatFood(food *apple);
//snake*Move(snake *head,int State,food *apple);
int Control(snake *head);//������Ʋ���������Ϣ���ݸ�Move��������
void CanNotCrossWall(snake *head);
void Start(snake &s);
