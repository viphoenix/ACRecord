//
//  main.cpp
//  LIS-合唱队形
//
//  Created by 程锋 on 15/8/17.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  题目描述：
 N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。
 合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，
 则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。
 你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
 输入：
 输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。
 第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。
 输出：
 可能包括多组测试数据，对于每组数据，
 输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
 样例输入：
 8
 186 186 150 200 160 130 197 220
 样例输出：
 4
 */

#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/LIS-合唱队形/LIS-合唱队形/in", "r", stdin);
    
    int n;
    while (cin >> n && n != 0) {
        
        int * buf = (int *)malloc(sizeof(int) * n);
        int * dp1 = (int *)malloc(sizeof(int) * n);
        int * dp2 = (int *)malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
            dp1[i] = dp2[i] = 1;
        }
        
        for(int i  = 1; i < n; ++i)
        {
            int tmax = 1;
            
            for(int j = 0; j < i; ++j)
            {
                //不能相等，注意题目描述
                if(buf[j] < buf[i])
                    tmax = max(tmax, dp1[j]+1);
            }
            
            dp1[i] = tmax;
        }
        
        for(int i = n-2; i >= 0; --i)
        {
            int tmax = 1;
            for(int j = n-1; j > i; --j)
            {
                if(buf[j] < buf[i])
                    tmax = max(tmax, dp2[j] + 1);
            }
            
            dp2[i] = tmax;
        }
        /*
        for(int i = 0; i < n; ++i)
        {
            cout << buf[i] << " " << dp1[i] << " " << dp2[i] << endl;
        }
        */
        int res = 0;
        for(int i = 0; i < n; ++i)
            res = max(res, dp1[i]+dp2[i]-1);
        
        free(buf);
        free(dp1);
        free(dp2);
        
        cout << n-res << endl;
        
    }
    
    
    return 0;
}
