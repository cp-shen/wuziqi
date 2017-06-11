#include "renjuGame.h"

void initGameplayGUI()
{
	IMAGE board, button_regret_1;
	loadimage(&board, L"board.jpg");
	loadimage(&button_regret_1, L"button_regret_1.jpg", 100, 50);

	putimage(100, 100, &board);
	putimage(0, 300, &button_regret_1);

	int i, j;
	for (i = 1; i <= 15; i++)
		line(99 + 33 * i, 132, 99 + 33 * i, 594);

	for (j = 1; j <= 15; j++)
		line(132, 99 + 33 * j, 594, 99 + 33 * j);
}


struct inst runGameplayGUI()
{
	IMAGE button_regret_1, button_regret_2;
	loadimage(&button_regret_1, L"button_regret_1.jpg", 100, 50);
	loadimage(&button_regret_2, L"button_regret_2.jpg", 100, 50);

	struct inst instruction;
	//要返回的结构体变量

	MOUSEMSG mouse = GetMouseMsg();
	while (1)
	//读取鼠标位置
	{
		mouse = GetMouseMsg();
		if (mouse.mkLButton == true && mouse.x > 115 && mouse.x < 610 && mouse.y>115 && mouse.y < 610)
		{
			instruction.operation = GO;
			instruction.x = (mouse.x - 100 + 16) / 33;
			instruction.y = (mouse.y - 100 + 16) / 33;

			return instruction;
		}

		if ( mouse.x > 0 && mouse.x < 100 && mouse.y>300 && mouse.y < 350)
		{
			putimage(0, 300, &button_regret_2);
			if (mouse.mkLButton == true)
			{
				instruction.operation = REGRET;
				return instruction;
			}
		}
		else 
			putimage(0, 300, &button_regret_1);


	}
}
