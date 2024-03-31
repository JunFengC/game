#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define N 10


// ≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

// œ‘ æ∆Â≈Ã
void Display(char board[ROWS][COLS], int row, int col);

//≤º÷√¿◊
void SetMine(char board[ROWS][COLS], int row, int col);

//≤È’“¿◊
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);