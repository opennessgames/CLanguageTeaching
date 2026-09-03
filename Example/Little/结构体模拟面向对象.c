/*
 * @Author: xixi_
 * @Date: 2026-09-03 21:41:20
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-03 21:58:04
 * @FilePath: /CLanguageTeaching/Example/Little/结构体模拟面向对象.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * 用C语言模拟面向对象，
 * Linux内核的代码以及很多库都用这样的方式去模拟面向对象
 **/

/* 基类 */
typedef struct BaseClass
{
    /* 虚函数 */
    void (*DoSome)(struct BaseClass *This);
    void (*Free)(void *This); /* 析构函数 */
} BaseClass;

/* 子类 */
typedef struct SubClass
{
    BaseClass Parent; /* 继承父类 */
    int Data;
} SubClass;

void SubClassDoSome(struct BaseClass *This)
{
    SubClass *Sc = (SubClass *)This;
    printf("Call SubClssDoSome, Data is %d\n", Sc->Data);
}

void SubClassInit(SubClass *Sc)
{
    Sc->Parent.DoSome = SubClassDoSome;
    Sc->Parent.Free = free;

    /* override */
    Sc->Data = 114514;
}

int main()
{
    SubClass *Sc = calloc(1, sizeof(SubClass)); /* 注意这一步不等于new */
    SubClassInit(Sc);
    /* calloc + Init, 这两步组合起来才是new */

    /* 向上转型 */
    BaseClass *Bs = (BaseClass *)Sc;
    Bs->DoSome(Bs); /* 调用 */

    Bs->Free(Bs);
    Sc = NULL;
    return 0;
}
