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
	printf("-----ɨ����Ϸ-----\n");

	// ��ӡ�к�
	for (j = 0; j <= col ; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	 //��ӡ����------------------
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);  //��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	// ��ӡ����------------------
	printf("-----ɨ����Ϸ-----\n");










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

// ����xy���긽���׵ĸ���
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
	int win = 0; //�ҵ����׵ĸ���

	while (win<row*col-N)
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d %d", &x, &y);
		// �ж�����Ϸ���
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{	
			// �ж��Ƿ��Ų��
			if (show[x][y] != '*')
			{
				printf("�������Ѿ����Ų����,����������\n");
			}
			else
			{
				//1.������
				if (mine[x][y] != '1')
				{
					win++;
					int count = MineCount(mine, x, y);
					show[x][y] = count + '0'; //������ת��Ϊ�����ַ�
					Display(show, ROW, COL);
				}
				//2.����
				else if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					Display(mine, ROW, COL);
					break;
				}
			}
		}
		else
		{
			printf("��������겻�Ϸ�,����������\n");
		}
	}

	if (win == row * col - N)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		Display(mine, ROW, COL);
	}
	



}