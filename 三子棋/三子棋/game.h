#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 6
#define COL 6
#define N 3


// ��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

// ��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

// ����ƶ�
void PlayerMove(char board[ROW][COL], int row, int col);

// ��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

// �ж������Ƿ�����---ƽ��
int IsFull(char board[ROW][COL], int row, int col);