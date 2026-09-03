/*
 * @Author: xixi_
 * @Date: 2026-09-03 21:30:07
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-03 21:36:28
 * @FilePath: /CLanguageTeaching/Example/Little/判断奇数偶数.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include <stdio.h>

/* 第一次写 */

int main(int Argc, char **Argv)
{
    printf("请输入一个数字:");

    int InputNum = 0;
    scanf("%d", &InputNum);

    /* Tip：位运算更快，比 % 2要快很多 */
    printf("数字 %d 是 %s\n", InputNum, InputNum & 1 ? "奇数" : "偶数");
    return 0;
}