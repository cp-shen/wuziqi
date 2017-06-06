#include "renjuGame.h"

void battle()
{
	battleMenu();

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
	//ɾ��β���սڵ�

	showWinner(win);
}

void play(struct renju *head,int player, int *turn_p)
{
	MOUSEMSG mouse = GetMouseMsg();
	
	while (!(mouse.uMsg == WM_LBUTTONDOWN && mouse.x > 516 && mouse.x < 1010 && mouse.y>96 && mouse.y < 590))
		//��û�з�����Ч�������һֱ������
		mouse = GetMouseMsg();

	
	int i, j;
	
	i = (mouse.x + 1 - 500+16) / 33;
	j = (mouse.y + 1 - 80+16) / 33;


	while (head->next != NULL)
	{
		if (head->x == i&&head->y == j)
		{
			(*turn_p)--;
			return;//��ʱ�ô��Ѿ�������
		}
		head = head->next;
	}

	if (head->x == i&&head->y == j)
	{
		(*turn_p)--;
		return;//������һ���ڵ�������Ƿ��ڵ����
	}


	head->x = i;
	head->y = j;
	head->player = player;
	head->turn = *turn_p;


	head->next= (struct renju *)malloc(LEN);
	//�����½ڵ�
	head = head->next;
	head->next = NULL;

}

void draw(struct renju*head)
{
	while (head->next->next != NULL)
		//β��Ϊ�սڵ㣬�����һ�������ڵ����ڶ����ڵ�
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
	//û�ҵ��ýڵ�
}
int isWin(struct renju *head)
{
	struct renju *last = head;
	while (last->next->next != NULL)
		last = last->next;
	//�ҵ����һ�����ӵĽڵ�

	int i, j;//ѭ������
	int x, y;
	x = last->x;
	y = last->y;

	//�������Ҽ��
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

	//�������¼��
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

	//�����������¼��
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

	//�����������¼��
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

	//����Ƿ�ƽ��
	if (last->turn == 225)
		return TIE;


	return NONE;
}

void showWinner(int win)
{
	IMAGE black, white, tie,notice;
	loadimage(&black, L"black_win.jpg");
	loadimage(&white, L"white_win.jpg");
	loadimage(&tie, L"tie.jpg");
	loadimage(&notice, L"notice.jpg");

	switch (win)
	{
	case BLACK_PLAYER:
		putimage(500, 0, &black);
		break;
	case WHITE_PLAYER:
		putimage(500, 0, &white);
		break;
	case TIE:
		putimage(500, 0, &tie);
	}

	putimage(700, 0, &notice);

	while (1)
	{
		if (GetMouseMsg().mkRButton == true)
			break;
	}
}

void battleMenu()
{
	IMAGE button_regret,button_regret_2;
	loadimage(&button_regret, L"button_regret.jpg",160,122);
	loadimage(&button_regret_2, L"button_regret_2.jpg",160,122);

	putimage(1050, 80, &button_regret);
}