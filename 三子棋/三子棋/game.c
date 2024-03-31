#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

// ��ʼ������
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

// ��ӡ����1
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{	
//		// ��ӡ����
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		// ��ӡ�ָ���
//		if (i<row-1)
//			printf("---|---|---\n");
//	}
//}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		// ��ӡ�ָ���
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


// ����ƶ�
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("�������:>\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d %d", &x, &y);
		// ���귶Χ�Ϸ����ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// �ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ò������壬��ѡ������λ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col)
{	
	printf("��������:>\n");
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


//�ж���Ӯ
//���Ӯ   '*'
//����Ӯ   '#'
//ƽ��     'Q'
//����     'C'
char IsWin(char board[ROW][COL], int row, int col)
{	
	// �ж�ÿ�� �Ƿ���N�������ĸ�����ͬ
	int i = 0;

	for (i = 0; i < row; i++)
	{
		int n = 0;
		for (n = 0; n < col - N + 1; n++) //N����  ÿ����Ҫ�ж�col-N+1��
		{
			int num1 = 0;  //'*'�ĸ���
			int num2 = 0;  //'#'�ĸ���
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
	// �ж�ÿ�� �Ƿ���N�������ĸ�����ͬ
	for (i = 0; i < col; i++)
	{
		int n = 0;
		for (n = 0; n < row - N + 1; n++) //N����  ÿ����Ҫ�ж�row-N+1��
		{
			int num1 = 0;  //'*'�ĸ���
			int num2 = 0;  //'#'�ĸ���
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
	// �ж����жԽ��� �Ƿ���N�������ĸ�����ͬ row*col
	int min = row < col ? row : col;
	int n = 0;
	int x = 0;
	// �ж������������Խ���  ���ж�min-N+1��
	for (x = 0; x <= min - N; x++) 
	{
		for (n = 0+x; n < min - N + 1; n++) //N����  ���Ҫ�ж�min(row,col)-N+1��   ÿ����һ��
		{
			int num1 = 0;  //'*'�ĸ���
			int num2 = 0;  //'#'�ĸ���
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
	// �ж������������Խ���  ���ж�min-N+1��
	for (x = 0; x <= min - N; x++)
	{
		for (n = 0 + x; n < min - N + 1; n++) //N����  ���Ҫ�ж�min(row,col)-N+1��   ÿ����һ��
		{
			int num1 = 0;  //'*'�ĸ���
			int num2 = 0;  //'#'�ĸ���
			int j = 0;
			for (j = n; j < n + N; j++)
			{
				if (board[j-x][j] == '*')  //ÿ�����Ͻ��ƶ�һ�£��б��ж��x
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
	// �ж��������¸��Խ���  ���ж�min-N+1��
	for (x = 0; x <= min - N; x++)
	{
		for (n = 0 + x; n < min - N + 1; n++) //N����  �Խ�����Ҫ�ж�min(row,col)-N+1��   ÿ����һ��
		{
			int num1 = 0;  //'*'�ĸ���
			int num2 = 0;  //'#'�ĸ���
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
	// �ж��������ϸ��Խ���  ���ж�min-N+1��
	for (x = 0; x <= min - N; x++)
	{
		for (n = 0 + x; n < min - N + 1; n++) //N����  �Խ�����Ҫ�ж�min(row,col)-N+1��   ÿ����һ��
		{
			int num1 = 0;  //'*'�ĸ���
			int num2 = 0;  //'#'�ĸ���
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
	


	// �ж��Ƿ�ƽ��
	if (IsFull(board, row, col))
		return 'Q';
	// ��Ϸ����
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int num = 0;  // ' '�ĸ���
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



