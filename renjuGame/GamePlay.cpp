#include "renjuGame.h"

void battle()
{
	initGameplayGUI();
	struct inst instruction;

	int turn = 1;
	int *turn_p = &turn;
	int win = NONE;

	struct renju *head = (struct renju *)malloc(LEN);
	head->next = NULL;

	while (win == NONE)
	{

		instruction = runGameplayGUI();
		//接收GUI读取的用户指令
		Sleep(100);
		//防止按住鼠标的连续读取

		if (turn % 2 == 1 && instruction.operation == GO)
		{
			play(head, WHITE_PLAYER, turn_p, instruction);
			draw(head);
		}
		else if (turn % 2 == 0 && instruction.operation == GO)
		{
			play(head, BLACK_PLAYER, turn_p, instruction);
			draw(head);
		}
		else if (instruction.operation == REGRET)
		{
			regret(&head, turn_p);
			redraw(head);
		}
		
		win = isWin(head);
	}
	
	while (head->next!=NULL && head->next->next != NULL)
		head = head->next;
	head->next = NULL;
	//删除尾部空节点

	initResultGUI(win);

}

void play(struct renju *head,int player, int *turn_p,struct inst instruction)
{
	int i = instruction.x;
	int j = instruction.y;
		
	while (head->next != NULL)
	{
		if (head->x == i&&head->y == j &&(head->player == BLACK_PLAYER||head->player==WHITE_PLAYER) )
			return;//此时该处已经有棋子
		
		head = head->next;
	}

	if (head->x == i&&head->y == j && (head->player == BLACK_PLAYER || head->player == WHITE_PLAYER))
		return;//此时该处已经有棋子(最后一个节点)
	
	head->x = i;
	head->y = j;
	head->player = player;
	head->turn = *turn_p;

	head->next = (struct renju *)malloc(LEN);
	//申请新节点
	head = head->next;
	head->next = NULL;

	(*turn_p)++;
}

void draw(struct renju*head)
{
	while (head->next != NULL && head->next->next != NULL)
		//尾部为空节点，故最后一个棋子在倒数第二个节点
		head = head->next;

	if (head->player == WHITE_PLAYER)
	{
		setfillcolor(WHITE);
		solidcircle(99 + 33 * head->x, 99 + 33 * head->y, 12);
	}
	else if (head->player == BLACK_PLAYER)
	{
		setfillcolor(BLACK);
		solidcircle(99 + 33 * head->x, 99 + 33 * head->y, 12);
	}
}

void redraw(struct renju *head)
{
	initGameplayGUI();

	while (head != NULL)
	{
		if (head->player == WHITE_PLAYER)
		{
			setfillcolor(WHITE);
			solidcircle(99 + 33 * head->x, 99 + 33 * head->y, 12);
		}
		else if (head->player == BLACK_PLAYER)
		{
			setfillcolor(BLACK);
			solidcircle(99 + 33 * head->x, 99 + 33 * head->y, 12);
		}
		head = head->next;
	}
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
	if (head->next == NULL)
		return NONE;
	//此时未下子
	
	struct renju *headcpy = head;
	//不改变isWIn中头指针的值，由于search需要
	while ( headcpy->next->next != NULL)
		headcpy = headcpy->next;
	struct renju *last = headcpy;
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

	while (!(i == x+1 && j == y+1))
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

	while (!(i == x-1 && j == y+1))
	{
		if (  search(head, i, j) != NULL && search(head, i, j)->player == last->player
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

void regret(struct renju **headPointer,int *turn_p)
{
	if ((*headPointer)->next == NULL)
		//此时还未下子，只有一个空节点，悔棋无效
		return;

	else if ((*headPointer)->next->next == NULL)
		//此时只有一个子，有两个节点
	{
		(*headPointer) = (struct renju*)malloc(LEN);
		(*headPointer)->next = NULL;
		//重置为只有一个空节点，改变头指针
		(*turn_p)--;
	}

	else
		//此时至少有两个子，有至少三个节点
	{
		struct renju *headcpy = *headPointer;
		//创建一个指针为头指针的复制，避免头指针被改变
		while (headcpy->next->next->next != NULL)
			headcpy = headcpy->next;
			//找到倒数第二次落子的节点，即倒数第三个节点

		headcpy->next = (struct renju*)malloc(LEN);
		headcpy->next->next = NULL;
		//将最后一次落子，即倒数第二个节点变为空节点
		(*turn_p)--;
	}
}

