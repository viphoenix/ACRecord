//
//  main.cpp
//  PAT-1029-Median
//
//  Created by 程锋 on 15/8/25.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
 
     Given two increasing sequences of integers, you are asked to find their median.
     
     Input
     
     Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.
     
     Output
     
     For each test case you should output the median of the two given sequences in a line.
     
     Sample Input
     4 11 12 13 14
     5 9 10 15 16 17
     Sample Output
     13
 
    算法思想：归并，求中位数下标对应的数
    陷阱：因为输入较多数据，使用scanf，使用cin超时； 注意输入数据是long int scanf时，需要%ld
         注意两个序列没有交叉的的情况
 
 */

#include <stdio.h>
#define MAX 1000000

long int a[MAX];
long int b[MAX];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1029-Median/PAT-1029-Median/in", "r", stdin);
    
    int m, n;
    int sum = 0;
    
    while(scanf("%d", &m) != EOF)
    {
        sum += m;
        
        for(int i = 0; i < m; ++i)
            scanf("%ld", &a[i]);
            
        while (scanf("%d", &n) != EOF)
        {
            sum += n;
            for(int i = 0; i < n; ++i)
                scanf("%ld", &b[i]);
                
        }
        
        int pos = (sum-1) / 2;
        
        if(m == 0)
        {
            printf("%ld", b[pos]);
            return 0;
        }
        
        if(n == 0)
        {
            printf("%ld", a[pos]);
            return 0;
        }
        
        int cnt = 0;
        
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            if(a[i] <= b[j])
            {
                if(cnt == pos)
                    printf("%ld", a[i]);
                
                i++;
                cnt++;
            }
            else
            {
                if(cnt == pos)
                    printf("%ld", b[j]);
                
                j++;
                cnt++;
            }
        }
        
        for(int k = i; k < m; ++k)
        {
            if(cnt == pos)
                printf("%ld", a[k]);
            
            cnt++;
        }
        
        for(int k = j; k < n; ++k)
        {
            if(cnt == pos)
                printf("%ld", b[k]);
            
            cnt++;
        }
    }
    
    return 0;
}





















