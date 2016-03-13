//
//  main.cpp
//  0-1背包
//
//  Created by 程锋 on 15/9/10.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

struct Node{
    int t, v;
}data[105];

int dp[1005];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Review/0-1背包/0-1背包/in", "r", stdin);
    
    int T, M;
    scanf("%d%d", &T, &M);
    for(int i = 1; i <= M; ++i)
        scanf("%d%d", &data[i].t, &data[i].v);
    
    for(int i = 0; i <= T; ++i)
        dp[i] = 0;
    
    for(int i = 1; i <= M; ++i)
        for(int j = T; j >= data[i].t; --j)
            dp[j] = max(dp[j], dp[j-data[i].t]+data[i].v);
    
    printf("%d\n", dp[T]);
    
    
    return 0;
}
