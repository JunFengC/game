#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

// 打印棋盘1
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{	
//		// 打印数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		// 打印分隔符
//		if (i<row-1)
//			printf("---|---|---\n");
//	}
//}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		// 打印分隔符
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


// 玩家移动
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家下棋:>\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		// 坐标范围合法性判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// 判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用不能下棋，请选择其它位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col)
{	
	printf("电脑下棋:>\n");
	int x = 0;
	int y = 0;

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


//判断输赢
//玩家赢   '*'
//电脑赢   '#'
//平局     'Q'
//继续     'C'
char IsWin(char board[ROW][COL], int row, int col)
{	
	// 判断每行 是否有N个连续的格子相同
	int i = 0;

	for (i = 0; i < row; i++)
	{
		int n = 0;
		for (n = 0; n < col - N + 1; n++) //N子棋  每行需要判断col-N+1次
		{
			int num1 = 0;  //'*'的个数
			int num2 = 0;  //'#'的个数
			int j = 0;
			for (j = n; j < n + N; j++)
			{
				if (board[i][j] == '*')
					num1 += 1;
				if (board[i][j] == '#')
					num2 += 1;
			}
			if (num1 == N)
				return '*';
			if (num2 == N)
				return '#';
		}
	}
	// 判断每列 是否有N个连续的格子相同
	for (i = 0; i < col; i++)
	{
		int n = 0;
		for (n = 0; n < row - N + 1; n++) //N子棋  每列需要判断row-N+1次
		{
			int num1 = 0;  //'*'的个数
			int num2 = 0;  //'#'的个数
			int j = 0;
			for (j = n; j < n + N; j++)
			{
				if (board[j][i] == '*')
					num1 += 1;
				if (board[j][i] == '#')
					num2 += 1;
			}
			if (num1 == N)
				return '*';
			if (num2 == N)
				return '#';
		}
	}
	// 判断所有对角线 是否有N个连续的格子相同 row*col
	int min = row < col ? row : col;
	int n = 0;
	int x = 0;
	// 判断所有左下主对角线  共判断min-N+1次
	for (x = 0; x <= min - N; x++) 
	{
		for (n = 0+x; n < min - N + 1; n++) //N子棋  最多要判断min(row,col)-N+1次   每次少一次
		{
			int num1 = 0;  //'*'的个数
			int num2 = 0;  //'#'的个数
			int j = 0;
			for (j = n; j < n + N; j++)
			{
				if (board[j][j-x] == '*')
					num1 += 1;
				if (board[j][j-x] == '#')
					num2 += 1;
			}
			if (num1 == N)
				return '*';
			if (num2 == N)
				return '#';
		}
	}
	// 判断所有右上主对角线  共判断min-N+1次
	for (x = 0; x <= min - N; x++)
	{
		for (n = 0 + x; n < min - N + 1; n++) //N子棋  最多要判断min(row,col)-N+1次   每次少一次
		{
			int num1 = 0;  //'*'的个数
			int num2 = 0;  //'#'的个数
			int j = 0;
			for (j = n; j < n + N; j++)
			{
				if (board[j-x][j] == '*')  //每往右上角移动一下，列比行多大x
					num1 += 1;
				if (board[j-x][j] == '#')
					num2 += 1;
			}
			if (num1 == N)
				return '*';
			if (num2 == N)
				return '#';
		}
	}
	// 判断所有右下副对角线  共判断min-N+1次
	for (x = 0; x <= min - N; x++)
	{
		for (n = 0 + x; n < min - N + 1; n++) //N子棋  对角线需要判断min(row,col)-N+1次   每次少一次
		{
			int num1 = 0;  //'*'的个数
			int num2 = 0;  //'#'的个数
			int j = 0;
			for (j = n; j < n + N; j++)
			{
				if (board[j][col - j + x] == '*')
					num1 += 1;
				if (board[j][col - j + x] == '#')
					num2 += 1;
			}
			if (num1 == N)
				return '*';
			if (num2 == N)
				return '#';
		}
	}
	// 判断所有左上副对角线  共判断min-N+1次
	for (x = 0; x <= min - N; x++)
	{
		for (n = 0 + x; n < min - N + 1; n++) //N子棋  对角线需要判断min(row,col)-N+1次   每次少一次
		{
			int num1 = 0;  //'*'的个数
			int num2 = 0;  //'#'的个数
			int j = 0;
			for (j = n; j < n + N; j++)
			{
				if (board[j-x][col-j-1] == '*')
					num1 += 1;
				if (board[j-x][col-j-1] == '#')
					num2 += 1;
			}
			if (num1 == N)
				return '*';
			if (num2 == N)
				return '#';
		}
	}
	


	// 判断是否平局
	if (IsFull(board, row, col))
		return 'Q';
	// 游戏继续
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int num = 0;  // ' '的个数
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				num += 1;
		}
	}
	if (num == 0)
		return 1;
	else
		return 0;
}



