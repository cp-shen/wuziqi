#include"renjuGame.h"

void replay(renju *head)
{
	int flag;
	int win = NONE;
	initReplayGUI();

	renju *head2 = (renju *)malloc(LEN);
	renju *workp = head2;
	//保留新链表头指针，因为rebattle需要它
	workp->next = NULL;

	while (win == NONE)
	{
		flag = runReplayGUI();
		switch (flag)
		{
		case REPLAY:
			workp->player = head->player;
			workp->turn = head->turn;
			workp->x = head->x;
			workp->y = head->y;

			drawFirst(workp);

			workp->next = (renju *)malloc(LEN);
			workp = workp->next;
			workp->next = NULL;

			head = head->next;
			
			win = isWin(head2);
			break;
		case REBATTLE:
			rebattle(head2);
			win = isWin(head2);
			break;
		}
		if (flag == FINISH)
			break;
	}

	if (win != NONE)
	{
		initResultGUI(win);

		switch (runResultGUI())
		{
		case REPLAY:
			replay(head2);
			break;
		case FINISH:
			break;
		}
	}
}



void rebattle(renju *head)
{
	initRebattleGUI();
	struct inst instruction;
	renju *workp = head;
	int win = NONE;
	int turn;
	int *turn_p = &turn;

	if (workp->next == NULL)
		turn = 1;
	else
	{
		while (workp->next->next != NULL)
			workp = workp->next;
			
		turn = workp->turn + 1;
		workp = workp->next;
	}
	while (win == NONE)
	{
			
		instruction = runGameplayGUI();
		//接收GUI读取的用户指令

		if (turn % 2 == 1 && instruction.operation == GO)
		{
			play(head, WHITE_PLAYER, turn_p, instruction);
			drawLast(head);
		}
		else if (turn % 2 == 0 && instruction.operation == GO)
		{
			play(head, BLACK_PLAYER, turn_p, instruction);
			drawLast(head);
		}
		else if (instruction.operation == REGRET)
		{
			regret(&head, turn_p);
			redraw(head);
		}

		win = isWin(head);
	}
	//链表最后一个节点为空节点
}

void drawFirst(struct renju *head)
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
}