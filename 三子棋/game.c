#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
}

void DisplayBoard(char board[][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)                 //由列控制的每个下的子之间的|
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)              //由列控制的每个换行符---中间的|
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("请输入你要下的位置(两个数字，中间用空格隔开):");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("你想找我的bug？？你下的位置已经有子了\n");
		}
		else printf("输的不对，别妄想找bug,重输\n");
	}
}

void ComputerMove(char board[][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;//没满
		}
	}
	return 1;//满了
}

char IsWin(char board[][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//判断三列
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//判断对角线
	for (i = 0; i < row; i++)
	{
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
			return board[1][1];
	}
	for (i = 0; i < row; i++)
	{
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
			return board[1][1];
	}
	//判断平局(棋盘满了还没输赢就平局)
	int ret = IsFull(board, row, col);
	if (ret == 1)
		return 'Q';
	else return 'C';
}


