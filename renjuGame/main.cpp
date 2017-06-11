#include "renjuGame.h"

int main()
{
	int run = 1;
	while (run == 1)
	{
		initMenuGUI();
		switch (runMenuGUI())
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
