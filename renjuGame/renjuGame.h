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
	//����������Ϣ
{
	int x;
	int y;
	int turn;
	int player;
	struct renju *next;
};
struct inst
	//��GUI��ȡ���û�������Ϣ
{
	int operation;
	int x;//���������Ӻ�����
	int y;//����������������
};

int menu();
void battle();
void play(struct renju *head,int player,int *turn_p, struct inst instruction);
void regret(struct renju *head, int *turn_p);
void draw(struct renju *head);
int isWin(struct renju *head);
struct renju *search(struct renju *head, int x, int y);
struct inst getInst();

#endif // !renju_h