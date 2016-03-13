//
//  main.c
//  排序-基数排序
//
//  Created by 程锋 on 15/8/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  基数排序基于计数排序，由于当序列最大值k较大时，时间和空间复杂度会大幅上升
 *  因此，将待排数据拆分为个位、十位、百位等，分别比较，最后得到排序数列
 *  基数排序基于计数排序的稳定性
 *
 * 基数排序：时间复杂度O(d*(3n+2k)) 空间复杂度：O(n+k)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 *  对所有元素的某一位排序
 *
 *  @param a 数组
 *  @param n 数组最大下标
 *  @param k 最大值，这里为9
 *  @param r 对数组元素的第几位排序
 */
void countSort(int * a, int n, int k, int r)
{
    int * count = (int *) malloc(sizeof(int) * (k+1));
    int * res = (int *) malloc(sizeof(int) * (n+1));
    
    //初始化,memset需要包含string.h头文件
    for(int i = 0; i <= k; ++i)
        count[i] = 0;
    
    //C语言 memset不能为整型数组清空， C++可以，包含在头文件<cstring>中
//    memset(count, 0, k+1);
    
    for(int i = 1; i <= n; ++i)
    {
        int tmp = (a[i] / (int)pow(10, r-1)) % 10;
        count[tmp]++;
    }
    
    for(int i = 1; i <= k; ++i)
        count[i] += count[i-1];
    
    for(int i = n; i >= 1; --i)
    {
        int tmp = (a[i] / (int)pow(10, r-1)) % 10;
        res[count[tmp]] = a[i];
        count[tmp]--;
    }
    
    for(int i = 1; i <= n; ++i)
        a[i] = res[i];
    
                               
}

void radixSort(int * a, int n, int d)
{
    for(int i = 1; i <= d; ++i)
        countSort(a, n, 9, i);
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/排序-基数排序/排序-基数排序/in", "r", stdin);
    
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int * a = (int *) malloc(sizeof(int)*(n+1));
        
        //3位数排序
        for(int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        
        //依次对个位、十位、百位排序
        radixSort(a, n, 3);
        
        for(int i = 1; i <= n; ++i)
            printf("%d ", a[i]);
            
    }
    
    
    return 0;
}




























