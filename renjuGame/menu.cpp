#include "renjuGame.h"

int menu()
{
	IMAGE button_start, button_exit, button_start_2, button_exit_2;

	loadimage(&button_start, L"button_start.jpg",160,122);
	loadimage(&button_exit, L"button_exit.jpg",160,122);
	loadimage(&button_start_2, L"button_start_2.jpg",160,122);
	loadimage(&button_exit_2, L"button_exit_2.jpg",160,122);

	MOUSEMSG mouse;
	
	while (1)
	{
		mouse = GetMouseMsg();
		
		if (mouse.x > 300 && mouse.x < 460 && mouse.y>250 && mouse.y < 372)
			putimage(300, 250, &button_start_2);
		else
			putimage(300, 250, &button_start);

		if (mouse.x > 300 && mouse.x < 460 && mouse.y>400 && mouse.y < 522)
			putimage(300, 400, &button_exit_2);
		else
			putimage(300, 400, &button_exit);

		if ( (mouse.x > 300 && mouse.x < 460 && mouse.y>250 && mouse.y < 372) && (mouse.mkLButton) )
			return START;

		if ((mouse.x > 300 && mouse.x < 460 && mouse.y>400 && mouse.y < 522) && (mouse.mkLButton))
			return EXIT;
	}

}