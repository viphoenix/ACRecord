//
//  main.c
//  PAT-1007-MaximumSubsequenceSum
//
//  Created by 程锋 on 15/8/21.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
 
     Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
     
     Input Specification:
     
     Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.
     
     Output Specification:
     
     For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.
     
     Sample Input:
     10
     -10 1 2 3 4 -5 -23 3 7 -21
     Sample Output:
     10 1 4
 
    看清题意：最后输出的是连续序列的第一个和最后一个值，不是下标
    最大值为0的情况：全为0，或者，0和负数
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1007-MaximumSubsequenceSum/PAT-1007-MaximumSubsequenceSum/in", "r", stdin);
    
    int n;
    
    //int start = 0, end = 0;
    
    while (scanf("%d", &n) != EOF)
    {
        int * buf = (int *) malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &buf[i]);
        
        int start = 0, end, sum = 0, tmp = 0;
        int max = -1;
        end = n -1;
        
        for(int i = 0; i < n; ++i)
        {
            sum += buf[i];
            if(sum < 0)
            {
                sum = 0;
                tmp = i + 1;
            }
            else if(sum > max)
            {
                max = sum;
                start = tmp;
                end = i;
            }
        }
        if(max < 0)
            max = 0;
        printf("%d %d %d\n", max, buf[start], buf[end]);
        
    }
    
    return 0;
}

//有一个测试点不能通过
int main1(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1007-MaximumSubsequenceSum/PAT-1007-MaximumSubsequenceSum/in", "r", stdin);
    
    int n;
    
    //int start = 0, end = 0;
    
    while (scanf("%d", &n) != EOF)
    {
        
        int * buf = (int *) malloc(sizeof(int) * n);
        //以某个下标结束的最大连续子数组和
        int * dp = (int *) malloc(sizeof(int) * n);
        //标记可能的开始位置
        int * flag = (int *) malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &buf[i]);
            dp[i] = 0;
            flag[i] = 0;
        }
        
        dp[0] = buf[0];
        for(int i = 1; i < n; ++i)
        {
            if(buf[i] > dp[i-1] + buf[i])
            {
                dp[i] = buf[i];
                flag[i] = 1;
            }
            else
                dp[i] = dp[i-1] + buf[i];
        }
        
        int min = 0;
        int start = 0, end = 0;
        for(int i = 0; i < n; ++i)
        {
            if(dp[i] > min)
            {
                min = dp[i];
                end = i;
            }
        }
        
        for(int i = end; i >= 0; --i)
            if(flag[i] == 1)
            {
                start = i;
                break;
            }
       
        printf("%d %d %d\n", (dp[end]<0?0:dp[end]), (dp[end]<0?buf[0]:buf[start]), (dp[end]<0?buf[n-1]:buf[end]));
        
        //注意释放的时刻
         free(buf);
         free(dp);
         free(flag);
         
    }
    
    return 0;

}

























