//
//  main.cpp
//  lc53-MaximumSubarray
//
//  Created by 程锋 on 15/8/9.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

//前缀和法

int main(int argc, const char * argv[]) {
    
    
    freopen("/Users/chengfeng/Dev/Algorithm/lc53-MaximumSubarray/lc53-MaximumSubarray/in", "r", stdin);
    
    int n;
    while (cin >> n && n != 0) {
        int * buf = (int *) malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
        }
        
        int answer = buf[0], sum = buf[0];
        int minSum = min(0, buf[0]);  //输入1，2时，最小的前缀和应该是0
        
        for(int i = 1; i < n; ++i)
        {
            sum += buf[i];
            answer = max(answer, sum-minSum);
            minSum = min(minSum, sum);
        }
        
        cout << answer << endl;
        
        free(buf);
    }
    
    
    return 0;
}

//动态规划法
int main1(int argc, const char * argv[]) {
    
    
    freopen("/Users/chengfeng/Dev/Algorithm/lc53-MaximumSubarray/lc53-MaximumSubarray/in", "r", stdin);
    
    int n;
    while (cin >> n && n != 0) {
        int * buf = (int *) malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
        }
        
        int answer = buf[0], sum = buf[0];
        
        for(int i = 1; i < n; ++i)
        {
            //没有包含，则重新开始
            sum = max(sum+buf[i], buf[i]);   //sum = max(sum+buf[i], sum);
            answer = max(answer, sum);
        }
        
        cout << answer << endl;
        
        free(buf);
    }
    
    
    return 0;
}
