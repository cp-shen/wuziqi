#include "renjuGame.h"
void initResultGUI(int win)
{
	IMAGE white_win, black_win,tie;
	loadimage(&white_win, L"result_white_win.jpg");
	loadimage(&black_win, L"result_black_win.jpg");
	loadimage(&tie, L"result_tie");

	if (win == BLACK_PLAYER)
		putimage(0, 0, &black_win);

	else if (win == WHITE_PLAYER)
		putimage(0, 0, &white_win);

	else if (win == TIE)
		putimage(0, 0, &tie);

	IMAGE button_finish_1, button_replay_1;
	loadimage(&button_finish_1, L"button_finish_1.jpg");
	loadimage(&button_replay_1, L"button_replay_1.jpg");
	
	putimage(0, 300, &button_replay_1);
	putimage(0, 360, &button_finish_1);
}

int runResultGUI()
{
	IMAGE button_finish_1, button_replay_1;
	loadimage(&button_finish_1, L"button_finish_1.jpg");
	loadimage(&button_replay_1, L"button_replay_1.jpg");
	IMAGE button_finish_2, button_replay_2;
	loadimage(&button_finish_2, L"button_finish_2.jpg");
	loadimage(&button_replay_2, L"button_replay_2.jpg");

	MOUSEMSG mouse;
	while (1)
		//开始读取鼠标
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
	}

}
