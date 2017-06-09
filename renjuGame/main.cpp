#include "renjuGame.h"

int main()
{
	int run = 1;
	int flag;

	while (run == 1)
	{
		menuInit();
		flag = menu();
		Sleep(100);//防止按住鼠标的连续读取

		switch (flag)
		{
		case START:
			battle();
			break;
		case EXIT:
			run = 0;
			break;
		}
	}
	return 0;
}
