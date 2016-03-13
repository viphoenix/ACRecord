//
//  main.cpp
//  DP-搬宿舍
//
//  Created by 程锋 on 15/9/10.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/Review/DP-搬宿舍/DP-搬宿舍/in", "r", stdin);
    
    int n, k, a[1000];
    int dp[500][1000];
    
    while(cin >> n >> k)
    {
        for(int i = 1; i <= n; ++i)
        {
            int t;
            cin >> t;
            a[i] = t;
        }
        
        sort(a+1, a+n+1);
        
        for(int i = 1; i <= n; ++i)
            dp[0][i] = 0;
        
        for(int i = 1; i <= k; ++i)
            for(int j = 2*i; j <= n; ++j)
            {
                if(j > 2*i)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = INF;
                
                if(dp[i][j] > dp[i-1][j-2] + (a[j]-a[j-1])*(a[j]-a[j-1]))
                    dp[i][j] = dp[i-1][j-2] + (a[j]-a[j-1])*(a[j]-a[j-1]);
            }
        
        cout << dp[k][n];
        
    }
    
    
    return 0;
}
