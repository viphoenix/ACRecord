//
//  main.cpp
//  PAT-1049-CountingOnes-30
//
//  Created by 程锋 on 15/8/25.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.
 
     Input Specification:
     
     Each input file contains one test case which gives the positive N (<=230).
     
     Output Specification:
     
     For each test case, print the number of 1's in one line.
     
     Sample Input:
     12
     Sample Output:
     5
 
    算法思想：分别求个位数、十位数、百位数......为1的个数
            个位数为1的个数
 
 118
 */

#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1049-CountingOnes-30/PAT-1049-CountingOnes-30/in", "r", stdin);
    
    //每位上是1的个数取决于该位的前一位和后一位
    
    int n;
    
    while(cin >> n)
    {
        int weight = 1;
        int ans = 0;
        
        while(n / weight != 0)
        {
            int right = n % weight;
            int left = n / (weight*10);
            int cur = n / weight % 10;
            
            if(cur == 0) // 只和高位有关
                ans += left * weight;
            else if(cur == 1) //和高位、地位都有关
                ans += (left * weight + right + 1);
            else
                ans += (left + 1) * weight;
            
            weight *= 10;
        }
        
        cout << ans;
    }

    return 0;
}

int main1(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1049-CountingOnes-30/PAT-1049-CountingOnes-30/in", "r", stdin);
    
    char num[12];
    
    while(cin >> num)
    {
        int weight = 1;
        int n = 0;
        int len = (int)strlen(num);
        
        for(int i = len - 1; i >= 0; --i)
        {
            n += (num[i] - '0') * weight;
            weight *= 10;
        }
        
        
        //小于2位的情况
        if(len < 2)
        {
            cout << "1";
            return 0;
        }
        
        //大于2位的情况
        int sum = 0;
        
        int base = 1;
        
        weight = 10;
        
        int cnt;
        
        for(int i = 0; i < len; ++i)
        {
            cnt = (n / weight) * base;
            
            sum += cnt;
            
            if((n % weight) / (weight / 10) > 1)
                sum += base;
            else
                sum += (n % weight - base + 1);
            
            weight *= 10;
            base *= 10;
        }
        
        cout << sum << endl;
    }
    
    
    return 0;
}









