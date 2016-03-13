//
//  main.cpp
//  找素数
//
//  Created by 程锋 on 15/8/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  输出小于n且个位数为1的所有素数
 */

#include <iostream>
#include <math.h>
#define MAX 10001

using namespace std;

int prime[MAX];
bool mark[MAX];
int size;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/找素数/找素数/in", "r", stdin);
    
        int n;
    while (cin >> n) {
        
        if(n == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        
        for(int i = 0; i <= n; ++i)
            mark[i] = false;
        
        size = 0;
        prime[size++] = 2;
        for(int i = 2; i <= n; ++i)
        {
            if(mark[i] == true)
                continue;
            prime[size++] = i;
            for(int j = i*i; j <= n; j+=i)
                mark[j] = true;
        }
        
        for(int i = 0; i < size; ++i)
            if(prime[i] % 10 == 1)
                cout << prime[i] << (i == size-1 ? "": " ");
        
        cout << endl;
        
        
        
    }
    
    
    return 0;
}
