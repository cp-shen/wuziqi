#include "renjuGame.h"

int main()
{
	int run = 1;
	int flag;

	while (run == 1)
	{
		initMenu();
		flag = runMenu();
		Sleep(500);//��ֹ��ס����������ȡ

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
