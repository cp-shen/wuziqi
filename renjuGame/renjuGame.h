#ifndef renju_h
	#define renju_h

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

#define START 0
#define EXIT 1

#define WHITE_PLAYER 2
#define BLACK_PLAYER 3
#define TIE 4
#define NONE 5

#define GO 6
#define REGRET 7

#define LEN sizeof(struct renju)

struct renju
	//保存落子信息
{
	int x;
	int y;
	int turn;
	int player;
	struct renju *next;
};
struct inst
	//由GUI获取的用户操作信息
{
	int operation;
	int x;//棋盘上落子横坐标
	int y;//棋盘上落子纵坐标
};

//GUI模块
int runMenu();
void initMenu();
struct inst runInterface();
void initInterface();

//GamePlay模块
void battle();
void play(struct renju *head,int player,int *turn_p, struct inst instruction);
void regret(struct renju **head, int *turn_p);
void redraw(struct renju *head);
void draw(struct renju *head);
int isWin(struct renju *head);
struct renju *search(struct renju *head, int x, int y);


#endif // !renju_h