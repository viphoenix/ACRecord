//
//  main.cpp
//  DFS-素数环
//
//  Created by 程锋 on 15/9/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int n;
int a[1000] = {0};
bool mark[1000];

bool checkPrime(int x)
{
    for(int i = 2; i <= (int)sqrt(x); ++i)
    {
        if(x % i == 0)
            return false;
    }
    
    return true;
}

void dfs(int num)
{
    
    if(num == n)
    {
        if(checkPrime(a[num] + a[1]))
        {
            for(int i = 1; i <= num; ++i)
                cout << a[i] << " ";
            cout << endl;
        }
        else
            return;
    }
    
    for(int i = 2; i <= n; ++i)
    {
        if(mark[i] == false && checkPrime(a[num] + i))
        {
            mark[i] = true;
            
            a[num+1] = i;
            
            dfs(num + 1);
            
            mark[i] = false;
        }
    }
}


int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/Review/DFS-素数环/DFS-素数环/in", "r", stdin);
    
    int cnt = 1;
    
    while(cin >> n)
    {
        cout << "Case " << cnt++ << ":" << endl;
        
        for(int i = 0; i < 1000; ++i)
            mark[i] = false;
        
        a[1] = 1;
        mark[1] = true;
        dfs(1);
        
    }
    
    return 0;
}
