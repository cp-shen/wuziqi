#include"renjuGame.h"

void replay(renju *head)
{
	initReplayGUI();

	switch(runReplayGUI())
	{
	case REPLAY:
		break;
	case CONTINUE:
		break;
	case FINISH:
		break;
	}
}