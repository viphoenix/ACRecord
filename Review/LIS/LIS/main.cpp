//
//  main.cpp
//  LIS
//
//  Created by 程锋 on 15/9/10.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Review/LIS/LIS/in", "r", stdin);
    
    int n, a[1000], dp[1000];
    
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            
            dp[i] = 1;
        }
        
        for(int i = 1; i < n; ++i)
        {
            int tmax = 1;
            for(int j = 0; j < i; ++j)
            {
                if(a[i] <= a[j])
                    tmax = max(tmax, dp[j]+1);
            }
            
            dp[i] = tmax;
        }
        
        printf("%d\n", dp[n-1]);
        
        
    }
    
    
    return 0;
}
