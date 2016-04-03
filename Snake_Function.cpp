#include"snake.h"

void CreatMap()//生成地图
{
	system("mode con cols=80 lines=30");//设定命令框大小
	int i;
	for (i=0; i < 70; i+=2)//设定上下边框
	{
		Set_cursor_Position(i, 0);
		printf("#");
		Set_cursor_Position(i, 20);
		printf("#");
	}
	for (i = 1; i < 20; i++)
	{
		Set_cursor_Position(0, i);
		printf("#");
		Set_cursor_Position(68, i);
		printf("#");
	}
}

void Set_cursor_Position(int x, int y)////定义光标位置
{
	COORD coord;  //COORD类
	coord.X = x;  //设定行
	coord.Y = y;  //设定列
				  //获取控制台缓冲区句柄
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置
	SetConsoleCursorPosition(ConsoleHandle, coord);
}

void snake::CreatSnake()//创建蛇,蛇长为5节,
{
    node s[100];
    for(int i=0;i<5;i++)//插入五个节点构成蛇的身体
    {
        s[i]=node('*',6+2*i,5);
        this->insert_body(s[i]);
    }
    length=5;
}
/*
*/
//产生一个随机位置的事物
void snake::creat_food()
{
  srand((unsigned)time(NULL));
  apple_x=rand()%70;
  apple_y=rand()%20;
}

void snake::show_food()
{
    Set_cursor_Position(apple_x,apple_y);
    cout<<'*';
}

//void snake::eat_apple()
//{
  //  Set_cursor_Position(apple_x,apple_y);
   // cout<<' ';
//}
//void CanNotCrossWall(snake *head)
//{
	//system("cls");
	//SetPosition(34, 10);
	//printf("你死了\n");
	//system("pause");
//}


void snake::insert_body(node &n)
{
    node *new_head=new node;//n已经存在了
    *new_head=n;
    new_head->next=this->head;
    this->head=new_head;
}

void snake::delete_tail()//删去尾巴
{
    node *p=head;
    node *q;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    delete(p);
}

void snake::show_snake()
{
    node *p=head;
    for(int i=0;i<length;i++)
    {
        Set_cursor_Position(p->Pos_x,p->Pos_y);
        if(p->next==NULL)
            cout<<' ';
        else
            cout<<(p->body);
        p=p->next;
    }
}



void snake::move_snake()
{
    if(direction!=0)
    {
        if(direction==UP){node n('*',head->Pos_x,head->Pos_y-1); insert_body(n);}
        else if(direction==DOWN){node n2('*',head->Pos_x,head->Pos_y+1); insert_body(n2);}
        else if(direction==LEFT){node n3('*',head->Pos_x-2,head->Pos_y); insert_body(n3);}
        else if(direction==RIGHT){node n4('*',head->Pos_x+2,head->Pos_y); insert_body(n4);}

        if(head->Pos_x!=apple_x||head->Pos_y!=apple_y)//判断是否吃苹果
        delete_tail();
        else
        creat_food();
        show_food();
    }
}
void snake::direction_snake()
{
		if ((GetAsyncKeyState(VK_UP)) && 0x8000 && (direction != DOWN))//不能掉头行动
		{
			direction = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x8000 && direction != UP)
		{
			direction = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x8000 && direction != RIGHT)
		{
			direction = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && 0x8000 && direction != LEFT)
		{
			direction = RIGHT;
		}
		//apple = CreatFood(apple);

		/*if ((head->Pos_x == apple->Pos_x) && (head->Pos_y == apple->Pos_y))//吃到苹果的情况
		{
			free(apple);
			apple = NULL;
		}
		else if (head->Pos_x == 0 || head->Pos_x == 68 || head->Pos_y == 0 || head->Pos_y == 20)//撞墙的情况
		{
			CanNotCrossWall(head);
			return 0;
		}
		q = head;
		for (i = 0; i < head->length; i++)
		{
			q = q->next;
			if ((q->Pos_x == head->Pos_x) && (q->Pos_y == head->Pos_y))
			{
				system("cls");
				printf("你死了\n");
				system("pause");
				return 0;
			}
		}
		//进行移动*/
}
void Start(snake &s)
{
    s.creat_food();
    s.show_food();
    while(1)
    {
        s.direction_snake();
        Sleep(250);
        s.show_snake();
        s.move_snake();

    }
}
