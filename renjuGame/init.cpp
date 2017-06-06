#include "renjuGame.h"

void init()
{
	initgraph(1280, 720);

	IMAGE background,board;

	loadimage(&background, L"background.jpg",1280,720);
	putimage(0, 0, &background);
	loadimage(&board, L"board.jpg");
	putimage(500, 80, &board);

	int i, j;
	for (i = 1; i <= 15; i++)
		line(500 + 32, 80 + 33 * i - 1, 500 + 526 - 32, 80 + 33 * i - 1);

	for (j = 1; j <= 15; j++)
		line(500 + 33 * j - 1, 80 + 32, 500 + 33 * j - 1, 80 + 526 - 32);
}