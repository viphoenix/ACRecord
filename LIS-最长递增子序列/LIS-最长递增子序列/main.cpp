//
//  main.cpp
//  LIS-最长递增子序列
//
//  Created by 程锋 on 15/8/17.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/LIS-最长递增子序列/LIS-最长递增子序列/in", "r", stdin);
    
    int n;
    
    while(cin >> n && n != 0)
    {
        int * buf = (int *) malloc(sizeof(int) * n);
        int * dp = (int *) malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
            dp[i] = 1;
        }
        
        for(int i = 0; i < n; ++i)
        {
            int tmax = 1;
            for(int j = 0; j < i; ++j)
            {
                if(buf[j] >= buf[i])
                    tmax = max(tmax, dp[j]+1);
            }
            
            dp[i] = tmax;
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, dp[i]);
        
        cout << ans << endl;
        
        
    }
    
    
    return 0;
}
