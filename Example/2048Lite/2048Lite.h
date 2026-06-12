/*
 * @Author: xixi_
 * @Date: 2024-10-27 17:35:39
 * @LastEditors: xixi_
 * @LastEditTime: 2026-06-12 23:36:02
 * @FilePath: /CLanguageTeaching/Example/2048Lite/2048Lite.h
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */

#ifndef XIXI_2048_GEN_H
#define XIXI_2048_GEN_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * @brief 在控制台输出棋盘
     *
     * @param Grid 游戏棋盘的`1D`数组表示
     * @return 无
     * @note 暂无备注
     */
    void Print1DTable(int *Grid);

    /**
     * @brief 随机在棋盘的空格位置添加数字2或4
     *
     * @param Grid 游戏棋盘的`1D`数组表示
     * @return 无
     * @note 在棋盘中随机选择一个空格，并在其中填入数字2或4
     */
    void XIXI_2048GenAddRandomNum(int *Grid);

    /**
     * @brief 合并一行中相邻的相同数字
     *
     * @param Tiles 当前一行的数字数组
     * @param NewTiles 合并后的数字
     * @return `true` 当前方向可以合并或移动; `false` 当前方向无法合并或移动
     * @note 检查目标的移动方向是否存在相邻的相同数字，并尝试将它们合并
     */
    bool XIXI_2048GenCombineTiles(int *Tiles, int *NewTiles);

    /**
     * @brief 处理棋盘的数字移动
     *
     * @param Grid 当前2048游戏棋盘的`1D`数组表示
     * @param Direction 移动方向，可用参数如下：
     *                  `0`: 向左移动
     *                  `1`: 向下移动
     *                  `2`: 向右移动
     *                  `3`: 向上移动
     * @return 无
     * @note 根据指定的方向移动棋盘上的数字，并进行必要的合并操作
     */
    void XIXI_2048GenMove(int *Grid, int Direction);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // XIXI_2048_GEN_H