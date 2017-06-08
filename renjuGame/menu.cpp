#include "renjuGame.h"

int menu()
{
	initgraph(720, 720);
	IMAGE background, button_start_1, button_start_2, button_exit_1, button_exit_2;
	
	loadimage(&background, L"C:\\Users\\29093\\Desktop\\wuziqi\\background.jpg", 720, 720);
	loadimage(&button_start_1, L"C:\\Users\\29093\\Desktop\\wuziqi\\button_start_1.jpg", 180, 90);
	loadimage(&button_start_2, L"C:\\Users\\29093\\Desktop\\wuziqi\\button_start_2.jpg", 180, 90);
	loadimage(&button_exit_1, L"C:\\Users\\29093\\Desktop\\wuziqi\\button_exit_1.jpg", 180, 90);
	loadimage(&button_exit_2, L"C:\\Users\\29093\\Desktop\\wuziqi\\button_exit_2.jpg", 180, 90);

	putimage(0, 0, &background);
	putimage(270, 200, &button_start_1);
	putimage(270, 300, &button_exit_1);

	

	getchar();
	return 0;
}