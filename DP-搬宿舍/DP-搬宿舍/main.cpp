//
//  main.cpp
//  DP-搬宿舍
//
//  Created by 程锋 on 15/8/18.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][2001];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/DP-搬宿舍/DP-搬宿舍/in", "r", stdin);
    
    int n, k;
    
    while(cin >> n >> k && n != 0)
    {
        int * buf = (int *)malloc(sizeof(int) * n);
        
        int tmp;
        for(int i = 1; i <= n; ++i)
        {
            cin >> tmp;
            buf[i] = tmp;
        }
        
        sort(buf+1, buf+n+1);
        
        for(int i = 1; i <= n; ++i)
            dp[0][i] = 0;
        
        for(int i = 1; i <= k; ++i)
            for(int j = 2*i; j <= n; ++j)
            {
                if(j > 2 * i)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = 0x7fffffff;
                int value = (buf[j]-buf[j-1])*(buf[j]-buf[j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-2]+value);
            }
        
        cout << dp[k][n] << endl;
        
    }
    
    
    return 0;
}
