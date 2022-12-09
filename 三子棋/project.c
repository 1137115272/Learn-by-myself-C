#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


void menu()
{
	printf("请选择:\n");
	printf("*******************************************\n");
	printf("*********         1. Play         *********\n");
	printf("*********         0. Exit         *********\n");
	printf("*******************************************\n");
	printf("请输入:");
}

void game()
{
	//存储数据 - 二维数组
	char board[ROW][COL];
	//数组初始化 - 空格
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//玩家开始下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//电脑下棋
		ret = IsWin(board, ROW, COL);

		if (ret != 'C')//判断玩家赢了吗
			break;

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("你赢了！！！\n");
	else if (ret == '#')
		printf("你输了？？？\n");
	else printf("平局\n");
	DisplayBoard(board, ROW, COL);
	printf("\n还玩吗？\n");
}
//玩家赢了 *
//电脑赢了 #
//平局     Q
//继续     C

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("游戏结束");
			return 0;
			break;
		default:printf("有趣，重新输\n");
			break;
		}
	} while (input);
	return 0;
}