/*
 * @Author: xixi_
 * @Date: 2024-10-27 14:51:02
 * @LastEditors: xixi_
 * @LastEditTime: 2026-06-12 23:36:05
 * @FilePath: /CLanguageTeaching/Example/2048Lite/2048Lite.c
 * Copyright (c) 2020-2024 by xixi_ , All Rights Reserved.
 */

/*
    2048 一维数组版 - Gen版本
    Gen版本指经过精简和优化的代码版本，旨在通过最少的循环次数实现核心业务逻辑，同时保持一定的可读性和扩展性。
    这是全网最精简的2048游戏算法，经过极致优化，采用索引数组来处理游戏数据。与传统实现（需要四个移动函数）相比，
    Gen版本去除了大量复杂的逻辑，仅使用三个核心函数和一个辅助函数，总共只需五个循环。每轮合并操作最多只需要20次循环，
    即可完成一次完整的合并操作，极大提升了效率。该版本有效减少了代码量和循环次数，保证了性能和可维护性。
    希望你能享受这款简洁高效的2048游戏！祝你玩得愉快ヾ(•ω•`)o
*/
/*
    开发时间记录：
    2024-10-27 14:51:02 开始开发
    2024-11-20 15:34:26 完善了所有API
*/
#include "2048Lite.h"

int lbrt[64] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, /* 左 */
    12, 8, 4, 0, 13, 9, 5, 1, 14, 10, 6, 2, 15, 11, 7, 3, /* 下 */
    3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, /* 右 */
    0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15  /* 上 */
}; /* 四方向快速索引数组,仅适用于`4*4`尺寸 */

void Print1DTable(int *Grid)
{
    for (int i = 0; i < 16; i++)
    {
        printf("%4d ", Grid[i]);
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
}

void XIXI_2048GenAddRandomNum(int *Grid)
{
    int EmptyIndices[16] = {0}; /* 空索引列表 */
    int EmptyCont = 0;          /* 空索引总数 */
    for (int i = 0; i < 16; i++)
    {
        if (Grid[i] == 0)
        {
            EmptyIndices[EmptyCont++] = i; /* 记录 */
        }
    }
    if (EmptyCont > 0) /* 如果存在空格 */
    {
        int SelectedIndex = EmptyIndices[rand() % EmptyCont]; /* 随机获取空索引 */
        Grid[SelectedIndex] = (rand() % 10 < 3) ? 4 : 2;      /* 工厂模式: 70%几率生成2,30%几率生成4 */
    }
}

bool XIXI_2048GenCombineTiles(int *Tiles, int *NewTiles) /* 模板方法模式 */
{
    int Index = 0; /* 用于跟踪新表中的下一个插入位置 */
    bool CanMove = false;
    bool MergedMark[4] = {false};
    for (int i = 0; i < 4; i++)
    {
        if (Tiles[i] != 0) /* 如果当前格子不为空 */
        {
            if (Index > 0 && NewTiles[Index - 1] == Tiles[i] && !MergedMark[Index - 1])
            {
                NewTiles[Index - 1] *= 2;     /* 合并 */
                MergedMark[Index - 1] = true; /* 标记已合并 */
                CanMove = true;               /* 标记可移动 */
            }
            else
            {
                NewTiles[Index++] = Tiles[i]; /* 将当前数字放入新表并移动到下一个插入的位置 */
            }
        }
        else
        {
            CanMove = true; /* 发现0值,标记可移动 */
        }
    }
    return CanMove; /* 返回移动标志 */
}

void XIXI_2048GenMove(int *Grid, int Direction) /* 策略模式 */
{
    bool HasMoved = false; /* 标记是否发生过移动 */
    for (int i = 0; i < 4; i++)
    {
        int Index = Direction * 16 + i * 4 + 3;                                                                   /* 计算当前处理的方块组的起始索引 */
        int Titles[4] = {Grid[lbrt[Index - 3]], Grid[lbrt[Index - 2]], Grid[lbrt[Index - 1]], Grid[lbrt[Index]]}; /* 拿到当前行/列 */
        int NewTiles[4] = {0};                                                                                    /* 初始化新表 */
        bool CanMove = XIXI_2048GenCombineTiles(Titles, NewTiles);                                                /* 合并方块并获取新状态 */
        if (CanMove)                                                                                              /* 如果可以移动或合并 */
        {
            for (int j = 0; j < 4; j++)
            {
                Grid[lbrt[Index + j - 3]] = NewTiles[j]; /* 更新网格中的方块 */
            }
            HasMoved = true; /* 标记发生过移动 */
        }
    }
    if (!HasMoved)
    {
        printf("当前方向无法移动哦~\n");
    }
    else
    {
        XIXI_2048GenAddRandomNum(Grid); /* 可移动,随机刷新2/4 */
    }
}
