//
//  main.cpp
//  整除问题
//
//  Created by 程锋 on 15/8/5.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int prime[1000];
bool mark[1001];
int size;

void init()
{
    size = 0;
    
    for(int i = 0; i < 1001; ++i)
        mark[i] = false;
    for(int i = 2; i < 1001; ++i)
    {
        if(mark[i])
            continue;
        prime[size++] = i;
        for(int j = i*i; j < 1001; j+=i)
            mark[j] = true;
    }
    
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/整除问题/整除问题/in", "r", stdin);
    
    int n, a;
    while(cin >> n >> a)
    {
        init();
        int nRes[1000], aRes[1000];
        memset(nRes, 0, 1000);
        memset(aRes, 0, 1000);
        int nSize =0;
        
        for(int i = 0; i < size; ++i)
        {
            int tmp = n;
            while(tmp != 0)
            {
                nRes[nSize] += tmp/prime[i];
                tmp /= prime[i];
            }
            if(n / prime[i])
                nSize++;
        }
        
        int min = 999999;
        for(int i = 0; i < size; ++i)
        {
            while(a % prime[i] == 0)
            {
                aRes[i]++;
                a /= prime[i];
            }
            
            if(aRes[i] == 0)
                continue;
            if(nRes[i] / aRes[i] < min)
                min = nRes[i] / aRes[i];
        }
        
        cout << min << endl;
        
    }
    
    return 0;
}
