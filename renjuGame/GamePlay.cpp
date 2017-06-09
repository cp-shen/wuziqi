#include "renjuGame.h"

void battle()
{
	struct inst instruction;

	int turn = 0;
	int *turn_p = &turn;
	int win = NONE;

	struct renju *head = (struct renju *)malloc(LEN);
	head->next = NULL;

	while (win == NONE)
	{
		turn++;
		instruction = getInst();

		if (turn % 2 == 1 && instruction.operation== GO)
			play(head, WHITE_PLAYER,turn_p, instruction);
		else if (turn % 2 == 0 && instruction.operation == GO)
			play(head, BLACK_PLAYER,turn_p, instruction);

		draw(head);
		
		win = isWin(head);
	}

	while (head->next->next != NULL)
		head = head->next;

	head->next = NULL;
	//ɾ��β���սڵ�

}

void play(struct renju *head,int player, int *turn_p,struct inst instruction)
{
	int i = instruction.x;
	int j = instruction.y;
		
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
		return;//��ʱ�ô��Ѿ�������(���һ���ڵ�)
	}

	head->x = i;
	head->y = j;
	head->player = player;
	head->turn = *turn_p;

	head->next = (struct renju *)malloc(LEN);
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

	solidcircle(99 + 33 * head->x , 99 + 33 * head->y ,12);
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

	//�����������¼��
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

	//����Ƿ�ƽ��
	if (last->turn == 225)
		return TIE;


	return NONE;
}

void regret(struct renju *head, int *turn_p)
{
}



