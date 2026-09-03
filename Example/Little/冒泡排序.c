/*
 * @Author: xixi_
 * @Date: 2026-09-03 22:00:22
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-03 22:10:02
 * @FilePath: /CLanguageTeaching/Example/Little/冒泡排序.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include <stdio.h>

void XixiSwapNumber(int *NumA, int *NumB)
{
    *NumA = *NumA ^ (*NumB);
    *NumB = *NumA ^ (*NumB);
    *NumA = *NumA ^ (*NumB);
}

void XixiBubbleSort(int Arr[], int Len)
{
    for (int i = 0; i < Len - 1; i++)
    {
        for (int j = 0; j < Len - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                XixiSwapNumber(&Arr[j], &Arr[j + 1]);
            }
        }
    }
}

int main()
{
    int Arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int Len = sizeof(Arr) / sizeof(Arr[0]);
    printf("----排序前----\n");
    for (int i = 0; i < Len; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");

    /* 执行排序 */
    XixiBubbleSort(Arr, Len);

    printf("----排序后----\n");
    for (int i = 0; i < Len; i++)
    {
        printf("%d ", Arr[i]);
    }
    return 0;
}
