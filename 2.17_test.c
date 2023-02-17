#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

//uint32_t reverseBits(uint32_t n)
//{
//    uint32_t val = 0;
//    int move1 = 31;
//    int move2 = 1;
//
//    for (uint32_t i = 0; i < 32; i++)
//    {
//        uint32_t tmp = n & ((uint32_t)1 << i);
//        if (i <= 15)
//        {
//            val |= tmp << move1;
//            move1 -= 2;
//        }
//        else
//        {
//            val |= tmp >> move2;
//            move2 += 2;
//        }
//    }
//    return val;
//}

uint32_t reverseBits(uint32_t n)
{
    uint32_t val = 0;
    uint32_t move = 31;

    for (uint32_t i = 0; i < 32; i++)
    {
        uint32_t bit = (uint32_t)1 & (n >> i);
        val |= bit << move--;
    }
    return val;
}

int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
    //¶¯Ì¬¹æ»®
    int row = gridSize;
    int col = *gridColSize;

    int** left = (int**)malloc(sizeof(int*) * (row + 1));
    for (int i = 0; i < row + 1; i++) {
        left[i] = (int*)calloc(col + 1, sizeof(int));
    }
    int** up = (int**)malloc(sizeof(int*) * (row + 1));
    for (int i = 0; i < row + 1; i++) {
        up[i] = (int*)calloc(col + 1, sizeof(int));
    }

    int maxBorder = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (grid[i - 1][j - 1] == 1)
            {
                left[i][j] = left[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
                int border = left[i][j] < up[i][j] ? left[i][j] : up[i][j];
                while (left[i - border + 1][j] < border || up[i][j - border + 1] < border)
                {
                    border--;
                }
                maxBorder = border > maxBorder ? border : maxBorder;
            }
        }
    }
    return maxBorder * maxBorder;
}

int main()
{
    reverseBits(0b11111111111111111111111111111101);
    int n = 0;
    return 0;
}