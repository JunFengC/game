#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----扫雷游戏-----\n");

	// 打印列号
	for (j = 0; j <= col ; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	 //打印数据------------------
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);  //打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	// 打印数据------------------
	printf("-----扫雷游戏-----\n");










}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = N;
	while (count)
	{
		int x = rand() % row + 1;   //1~9
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

// 计算xy坐标附件雷的个数
int MineCount(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
			board[x][y - 1] + board[x][y + 1] +
			board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]
			- 8 * '0');
}





void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0; //找到非雷的个数

	while (win<row*col-N)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		// 判断坐标合法性
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{	
			// 判断是否被排查过
			if (show[x][y] != '*')
			{
				printf("该坐标已经被排查过了,请重新输入\n");
			}
			else
			{
				//1.不是雷
				if (mine[x][y] != '1')
				{
					win++;
					int count = MineCount(mine, x, y);
					show[x][y] = count + '0'; //将个数转换为数字字符
					Display(show, ROW, COL);
				}
				//2.是雷
				else if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					Display(mine, ROW, COL);
					break;
				}
			}
		}
		else
		{
			printf("输入的坐标不合法,请重新输入\n");
		}
	}

	if (win == row * col - N)
	{
		printf("恭喜你，排雷成功\n");
		Display(mine, ROW, COL);
	}
	



}