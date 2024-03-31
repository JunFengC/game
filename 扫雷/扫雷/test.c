#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("******1.play*************\n");
	printf("******0.exi**************\n");
	printf("*************************\n");
}


void game()
{
	char mine[ROWS][COLS] = {0};  //存放布置好的雷的信息
	char show[ROWS][COLS] = {0};  //存放排查出的雷的信息
	// 初始化数组内容为指定内容
	
	// mine数组在没有布置雷时，都是'0'
	InitBoard(mine, ROWS, COLS, '0');
	// show数组在没有排查雷时，都是'*'
	InitBoard(show, ROWS, COLS, '*');
	// 布置雷
	SetMine(mine, ROW, COL);

	Display(mine, ROW, COL);
	Display(show, ROW, COL);

	FindMine(mine, show, ROW, COL);




}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}




	} while (input);

	return 0;








}