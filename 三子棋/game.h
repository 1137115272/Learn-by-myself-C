#pragma once

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

//行列数的定义
#define ROW 3
#define COL 3



//函数的声明
void InitBoard(char board[][COL], int row, int col);

void DisplayBoard(char board[][COL], int row, int col);

void PlayerMove(char board[][COL], int row, int col);

void ComputerMove(char board[][COL], int row, int col);

char IsWin(char board[][COL], int row, int col);