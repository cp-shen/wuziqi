#include "renjuGame.h"

int main()
{
	int run = 1;
	int flag;

	while (run == 1)
	{
		initMenuGUI();
		flag = runMenuGUI();
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
