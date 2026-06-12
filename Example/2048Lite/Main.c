/*
 * @Author: xixi_
 * @Date: 2024-10-31 20:25:36
 * @LastEditors: xixi_
 * @LastEditTime: 2026-06-12 23:36:14
 * @FilePath: /CLanguageTeaching/Example/2048Lite/Main.c
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "2048Lite.h"
#include <signal.h>

void handle_signal(int signal)
{
    printf("\033[H\033[J"); /* 清屏 */
    exit(0);
}

int DirMap[4][3] = {
    {'W', 'w', 3},
    {'A', 'a', 0},
    {'S', 's', 1},
    {'D', 'd', 2},
}; /* 方向索引映射 */

int main(int argc, char *argv[], char *envp[])
{
    signal(SIGINT, handle_signal);                 /* 处理 Ctrl+C */
    signal(SIGTSTP, handle_signal);                /* 处理 Ctrl+Z */
    int GameBoard[16] = {0};                       /* 棋盘状态 */
    int DirMapSize = sizeof(DirMap) / (4 * 4) + 1; /* 获取映射表大小 */
    char DirectionInput = '\0';                    /* 输入方向 */
    XIXI_2048GenAddRandomNum(GameBoard);           /* 随机添加一个数字 */
    while (true)
    {
        printf("\033[H\033[J");  /* 清屏 */
        Print1DTable(GameBoard); /* 打印当前棋盘状态 */
        printf("请输入移动方向 (W: 上, A: 左, S: 下, D: 右 Q: 退出): ");
        scanf(" %c", &DirectionInput); /* 读取用户输入，跳过前导空白字符 */
        for (int i = 0; i < DirMapSize; i++)
        {
            if (DirMap[i][0] == DirectionInput || DirMap[i][1] == DirectionInput)
            {
                XIXI_2048GenMove(GameBoard, DirMap[i][2]);
                break;
            }
        }
        if (DirectionInput == 'q' || DirectionInput == 'Q')
        {
            exit(0);
        }
    }
}