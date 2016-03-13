//
//  main.cpp
//  多重背包
//
//  Created by 程锋 on 15/9/11.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

struct Node{
    int price, weight;
}list[2002];

int dp[105];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/Review/多重背包/多重背包/in", "r", stdin);
    
    int cases;
    
    while (scanf("%d", &cases) != EOF)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        
        int size = 0;
        for(int i = 0; i < m; ++i)
        {
            int p, w, num;
            scanf("%d%d%d", &p, &w, &num);
            
            int base = 1;
            while (num - base > 0)
            {
                num -= base;
                
                list[++size].price = base * p;
                list[size].weight = base * w;
                
                base *= 2;
            }
            
            list[++size].price = num * p;
            list[size].weight = num * w;
        }
        
        for(int i = 0; i <= n; ++i)
            dp[i] = 0;
        
        for(int i = 1; i <= size; ++i)
            for(int j = n; j >= list[i].price; --j)
                dp[j] = max(dp[j], dp[j-list[i].price]+list[i].weight);
        
        printf("%d\n", dp[n]);
        
    }
    
    
    return 0;
}














