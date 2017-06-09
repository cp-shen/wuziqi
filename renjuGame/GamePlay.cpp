#include "renjuGame.h"

void battle()
{
	battleInit();

	int turn = 0;
	int *turn_p = &turn;

	int win = NONE;

	struct renju *head = (struct renju *)malloc(LEN);
	head->next = NULL;

	while (win == NONE)
	{
		turn++;

		if (turn % 2 == 1)
			play(head, WHITE_PLAYER,turn_p);
		else
			play(head, BLACK_PLAYER,turn_p);

		draw(head);
		

		win = isWin(head);
	}

	while (head->next->next != NULL)
		head = head->next;

	head->next = NULL;
	//删除尾部空节点

}

void play(struct renju *head,int player, int *turn_p)
{
	MOUSEMSG mouse = GetMouseMsg();
	
	while (!(mouse.uMsg == WM_LBUTTONDOWN && mouse.x > 516 && mouse.x < 1010 && mouse.y>96 && mouse.y < 590))
		//若没有发生有效点击，就一直检测鼠标
		mouse = GetMouseMsg();

	
	int i, j;
	
	i = (mouse.x + 1 - 500+16) / 33;
	j = (mouse.y + 1 - 80+16) / 33;


	while (head->next != NULL)
	{
		if (head->x == i&&head->y == j)
		{
			(*turn_p)--;
			return;//此时该处已经有棋子
		}
		head = head->next;
	}

	if (head->x == i&&head->y == j)
	{
		(*turn_p)--;
		return;//检测最后一个节点的棋子是否在点击处
	}


	head->x = i;
	head->y = j;
	head->player = player;
	head->turn = *turn_p;


	head->next= (struct renju *)malloc(LEN);
	//申请新节点
	head = head->next;
	head->next = NULL;

}

void draw(struct renju*head)
{
	while (head->next->next != NULL)
		//尾部为空节点，故最后一个棋子在倒数第二个节点
		head = head->next;

	if (head->player == WHITE_PLAYER)
		setfillcolor(WHITE);
	else
		setfillcolor(BLACK);

	solidcircle(500 + 33 * head->x - 1, 80 + 33 * head->y - 1,12);
}

struct renju *search(struct renju *head ,int x,int y)
{
	do
	{
		if (head->x == x && head->y == y)
			return head;

		else head = head->next;
	} while (head!=NULL);

	return NULL;
	//没找到该节点
}
int isWin(struct renju *head)
{
	struct renju *last = head;
	while (last->next->next != NULL)
		last = last->next;
	//找到最后一个落子的节点

	int i, j;//循环变量
	int x, y;
	x = last->x;
	y = last->y;

	//自左向右检查
	i = x-4;
	j = y;
	for (i = x-4; i <= x; i++)
	{
		if (search(head, i, j) != NULL && search(head, i, j)->player == last->player
			&& search(head, i + 1, j) != NULL && search(head, i + 1, j)->player == last->player
			&& search(head, i + 2, j) != NULL && search(head, i + 2, j)->player == last->player
			&& search(head, i + 3, j) != NULL && search(head, i + 3, j)->player == last->player
			&& search(head, i + 4, j) != NULL && search(head, i + 4, j)->player == last->player)

			return last->player;
	}

	//自上向下检查
	i = x;
	j = y-4;
	for (j = y-4; j <= y; j++)
	{
		if (search(head, i, j) != NULL && search(head, i, j)->player == last->player
			&& search(head, i, j + 1) != NULL && search(head, i, j + 1)->player == last->player
			&& search(head, i, j + 2) != NULL && search(head, i, j + 2)->player == last->player
			&& search(head, i, j + 3) != NULL && search(head, i, j + 3)->player == last->player
			&& search(head, i, j + 4) != NULL && search(head, i, j + 4)->player == last->player)

			return last->player;

	}

	//自左上向右下检查
	i = x-4;
	j = y-4;

	while (!(i == x && j == y))
	{
		if (search(head, i, j) != NULL && search(head, i, j)->player == last->player
			&&search(head, i + 1, j + 1) != NULL && search(head, i + 1, j + 1)->player == last->player
			&&search(head, i + 2, j + 2) != NULL && search(head, i + 2, j + 2)->player == last->player
			&&search(head, i + 3, j + 3) != NULL && search(head, i + 3, j + 3)->player == last->player
			&&search(head, i + 4, j + 4) != NULL && search(head, i + 4, j + 4)->player == last->player)

			return last->player;

		else
		{
			i++;
			j++;
		}
	}

	//自右上向坐下检查
	i = x+4;
	j = y-4;

	while (!(i == x && j == y))
	{
		if (search(head, i, j) != NULL && search(head, i, j)->player == last->player
			&&search(head, i - 1, j + 1) != NULL && search(head, i - 1, j + 1)->player == last->player
			&&search(head, i - 2, j + 2) != NULL && search(head, i - 2, j + 2)->player == last->player
			&&search(head, i - 3, j + 3) != NULL && search(head, i - 3, j + 3)->player == last->player
			&&search(head, i - 4, j + 4) != NULL && search(head, i - 4, j + 4)->player == last->player)

			return last->player;

		else
		{
			i--;
			j++;
		}
	}

	//检查是否平局
	if (last->turn == 225)
		return TIE;


	return NONE;
}





void battleInit()
{
	IMAGE board;
	loadimage(&board, L"C:\\Users\\29093\\Desktop\\wuziqi\\board.jpg");
	putimage(100, 100, &board);

	int i,j;
	for (i = 1; i <= 15; i++)
		line(99 + 33 * i, 132, 99 + 33 * i , 594);

	for (j = 1; j <= 15; j++)
		line(132, 99 + 33 * j, 594, 99 + 33 * j);
}

