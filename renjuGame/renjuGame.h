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

#define LEN sizeof(struct renju)

struct renju
{
	int x;
	int y;
	int turn;
	int player;
	struct renju *next;
};

void init();
int menu();
void battle();
void battleMenu();
void play(struct renju *head,int player,int *turn_p);
void draw(struct renju *head);
int isWin(struct renju *head);
struct renju *search(struct renju *head, int x, int y);
void showWinner(int win);
#endif // !renju_h