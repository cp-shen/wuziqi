#include "renjuGame.h"
void initMenuGUI()
{
	initgraph(720, 720);
	IMAGE background, button_start_1, button_exit_1;

	loadimage(&background, L"background.jpg");
	loadimage(&button_start_1, L"button_start_1.jpg");
	loadimage(&button_exit_1, L"button_exit_1.jpg");

	putimage(0, 0, &background);
	putimage(270, 250, &button_start_1);
	putimage(270, 350, &button_exit_1);
}

int runMenuGUI()
{
	IMAGE  button_start_1, button_start_2, button_exit_1, button_exit_2;
	
	loadimage(&button_start_1, L"button_start_1.jpg");
	loadimage(&button_start_2, L"button_start_2.jpg");
	loadimage(&button_exit_1, L"button_exit_1.jpg");
	loadimage(&button_exit_2, L"button_exit_2.jpg");

	MOUSEMSG mouse;
	while(1)
	{
		mouse = GetMouseMsg();


		if (mouse.x > 270 && mouse.x < 450 && mouse.y >250 && mouse.y < 340)
		{
			putimage(270, 250, &button_start_2);
			if (mouse.uMsg == WM_LBUTTONUP)
				return START;
		}
		else
			putimage(270, 250, &button_start_1);


		if (mouse.x > 270 && mouse.x < 450 && mouse.y >350 && mouse.y < 440)
		{
			putimage(270, 350, &button_exit_2);
			if (mouse.uMsg == WM_LBUTTONUP)
				return EXIT;
		}
		else
			putimage(270, 350, &button_exit_1);

	}

}