//
//  main.cpp
//  完全背包
//
//  Created by 程锋 on 15/9/11.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#define INF 0x7fffffff

struct Node{
    int p, w;
}data[505];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/Review/完全背包/完全背包/in", "r", stdin);
    
    int cases;
    int dp[10005];
    
    while (scanf("%d", &cases) != EOF)
    {
        while (cases--)
        {
            int empty, full, s;
            scanf("%d%d", &empty, &full);
            
            s = full - empty;
            
            int n;
            scanf("%d", &n);
            
            for(int i = 1; i <= n; ++i)
                scanf("%d%d", &data[i].p, &data[i].w);
            
            
            for(int i = 0; i <= s; ++i)
                dp[i] = INF;
            
            dp[0] = 0;
            
            for(int i = 1; i <= n; ++i)
                for(int j = data[i].w; j <= s; ++j)
                {
                    if(dp[j-data[i].w] != INF)
                        dp[j] = min(dp[j], dp[j-data[i].w]+data[i].p);
                }
            
            if(dp[s] != INF)
                printf("The minimum amount of money in the piggy-bank is %d.\n", dp[s]);
            else
                printf("This is impossible.\n");
        }
    }
    
    return 0;
}


















