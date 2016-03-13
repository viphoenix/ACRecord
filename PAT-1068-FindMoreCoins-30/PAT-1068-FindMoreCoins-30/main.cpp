//
//  main.cpp
//  PAT-1068——FindMoreCoins-30
//
//  Created by 程锋 on 15/9/9.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.
     
     Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].
     
     Sample Input 1:
     8 9
     5 9 8 7 2 3 4 1
     Sample Output 1:
     1 3 5
     Sample Input 2:
     4 8
     7 2 4 3
     Sample Output 2:
     No Solution
 */

#include <iostream>
#include <algorithm>
#include <vector>
#define N 10005
#define M 105

using namespace std;

int n, m;
int list[N];
int dp[M];  //不超过面值M所能达到的最大值
int mark[N][M];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1068-FindMoreCoins-30/PAT-1068-FindMoreCoins-30/in", "r", stdin);
    
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                mark[i][j] = false;
        
        for(int i = 1; i <= n; ++i)
            scanf("%d", &list[i]);
        
        for(int i = 0; i <= m; ++i)
            dp[i] = 0;
        
        sort(list+1, list+n+1);
        
        for(int i = 1; i <= n; ++i)
            for(int j = m; j >= list[i]; --j)
            {
                if(dp[j-list[i]] + list[i] >= dp[j])
                {
                    dp[j] = dp[j-list[i]] + list[i];
                    mark[i][j] = true;
                }
            }
        
        for(int i = 1; i <= n; ++i)
            printf("%d ", list[i]);
        printf("\n");
        
        if(dp[m] == m)
        {
            int pos = 1;
            while (m)
            {
                while(!mark[pos][m] && pos <= n)
                    pos++;
                printf("%d ", list[pos]);
                m -= list[pos];
                pos++;
                if(pos > n)
                    break;
            }
            
            
        }
        else
        {
            printf("No Solution");
        }
    }
    
    return 0;
}


























