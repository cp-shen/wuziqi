#include"renjuGame.h"
void initRebattleGUI()
{
	IMAGE title_rebattle;
	loadimage(&title_rebattle, L"title_rebattle.jpg");
	putimage(0, 0, &title_rebattle);

}


void initReplayGUI()
{
	IMAGE board;
	//回放模式下重新绘制空棋盘
	loadimage(&board, L"board.jpg");
	putimage(100, 100, &board);

	int i, j;
	for (i = 1; i <= 15; i++)
		line(99 + 33 * i, 132, 99 + 33 * i, 594);
	for (j = 1; j <= 15; j++)
		line(132, 99 + 33 * j, 594, 99 + 33 * j);

	IMAGE title_replay, button_replay_1, button_finish_1, button_rebattle_1;

	loadimage(&title_replay, L"title_replay.jpg");
	loadimage(&button_finish_1, L"button_finish_1.jpg");
	loadimage(&button_replay_1, L"button_replay_1.jpg");
	loadimage(&button_rebattle_1, L"button_rebattle_1.jpg");

	putimage(0, 0, &title_replay);
	putimage(0, 240, &button_rebattle_1);
	putimage(0, 300, &button_replay_1);
	putimage(0, 360, &button_finish_1);

}

int runReplayGUI()
{
	IMAGE  button_replay_1, button_replay_2, button_finish_1, button_finish_2, button_rebattle_1, button_rebattle_2;
	loadimage(&button_finish_1, L"button_finish_1.jpg");
	loadimage(&button_replay_1, L"button_replay_1.jpg");
	loadimage(&button_rebattle_1, L"button_rebattle_1.jpg");
	loadimage(&button_finish_2, L"button_finish_2.jpg");
	loadimage(&button_replay_2, L"button_replay_2.jpg");
	loadimage(&button_rebattle_2, L"button_rebattle_2.jpg");

	MOUSEMSG mouse;
	while (1)
	{
		mouse = GetMouseMsg();
		
		if (mouse.x > 0 && mouse.x < 100 && mouse.y>300 && mouse.y < 350)
		{
			putimage(0, 300, &button_replay_2);
			if (mouse.uMsg == WM_LBUTTONUP)
				return REPLAY;
		}
		else
			putimage(0, 300, &button_replay_1);
		
		if (mouse.x > 0 && mouse.x < 100 && mouse.y>360 && mouse.y < 410)
		{
			putimage(0, 360, &button_finish_2);
			if (mouse.uMsg == WM_LBUTTONUP)
				return FINISH;
		}
		else putimage(0, 360, &button_finish_1);
		
		if (mouse.x > 0 && mouse.x < 100 && mouse.y>240 && mouse.y < 290)
		{
			putimage(0, 240, &button_rebattle_2);
			if (mouse.uMsg == WM_LBUTTONUP)
				return REBATTLE;
		}
		else 
			putimage(0, 240, &button_rebattle_1);

	}
}