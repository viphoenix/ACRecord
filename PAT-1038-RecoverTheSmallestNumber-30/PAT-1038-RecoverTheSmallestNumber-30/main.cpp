//
//  main.cpp
//  PAT-1038-RecoverTheSmallestNumber-30
//
//  Created by 程锋 on 15/8/31.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.
 
     Input Specification:
     
     Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print the smallest number in one line. Do not output leading zeros.
     
     Sample Input:
     5 32 321 3214 0229 87
     Sample Output:
     22932132143287
 
 
    自定义排序算法的理解，只需确定两个数的排序规则
 
    坑：注意全为0的情况
 */

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string s[10005];

bool cmp(string a, string b)
{
    string tmpa = a;
    string tmpb = b;
    
    tmpa.append(a);
    tmpb.append(b);
    
    return tmpa < tmpb;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1038-RecoverTheSmallestNumber-30/PAT-1038-RecoverTheSmallestNumber-30/in", "r", stdin);
    
    int n;
    
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            string t;
            cin >> t;
            s[i] = t;
        }
        
        sort(s, s+n, cmp);
        
        bool flag = false; //全为0
        
        for(int i = 0; i < n; ++i)
            for(int j = 0;j < s[i].size(); ++j)
            {
                if(!flag && s[i][j] != '0')
                    flag = true;
                
                if(flag)
                    cout << s[i][j];
            }
        
        if(!flag)
            cout << 0;
    }
    
    
    
    return 0;
}
