//
//  main.c
//  排序-计数排序
//
//  Created by 程锋 on 15/8/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

/**
 *  计数排序约束条件：所有元素为非负数，并且待排数据的最大值K不能过大
 *  时间复杂度：O(3n+2k) k为最大值
 *  空间复杂度：O(n+k)
 *  注意点：最后一步根据计数确定元素位置时，需要逆序遍历，主要考虑排序的稳定性
 *  因为，当存在多个相同的元素时，计数排序总是先为最后的位置赋值
 */

#include <stdio.h>
#include <stdlib.h>

int findMax(int * a, int n)
{
    int max = a[1];
    for(int i = 2; i <= n; ++i)
        if(a[i] > max)
            max = a[i];
    
    return max;
}

void countSort(int * a, int n)
{
    int max = findMax(a, n);
    
    int * count = (int *) malloc(sizeof(int) * (max+1));
    int * b = (int *) malloc(sizeof(int)*(n+1));
    
    //初始化计数器
    for(int i = 0; i <= max; ++i)
        *(count+i) = 0;
    
    //待排数据每个元素出现的次数
    for(int i = 1; i <= n; ++i)
        (*(count+a[i]))++;
    
    //修改计数器，i上记录不大于i的元素个数
    for(int i = 1; i <= max; ++i)
        *(count+i) += *(count+i-1);
    
    //从1开始，根据计数，确定元素最终位置,逆序遍历，保证稳定性
    for(int i = n; i >= 1; --i)
    {
        *(b + *(count+a[i])) = a[i];
        
        (*(count + a[i]))--;
    }
    
    for(int i = 1; i <= n; ++i)
        a[i] = *(b+i);
    
    free(count);
    free(b);
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/排序-计数排序/排序-计数排序/in", "r", stdin);
    
    int n;
    
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int * a = (int *) malloc(sizeof(int) * (n+1));
        for(int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        
        countSort(a, n);
        
        for(int i = 1; i <= n; ++i)
            printf("%d ", a[i]);
        
    }
    
    return 0;
}
