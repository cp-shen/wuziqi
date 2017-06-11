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

	getchar();
}

int runResultGUI()
{
	return 0;
}
