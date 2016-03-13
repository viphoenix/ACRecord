//
//  main.cpp
//  PrimeRing
//
//  Created by 程锋 on 15/8/16.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43};
int ans[30];
int n;
bool mark[30];

bool judge(int x)
{
    int size = sizeof(prime)/sizeof(int);
    
    for(int i = 0; i < size; ++i)
        if(x == prime[i])
            return true;
    
    return false;
}

void check()
{
    if(judge(ans[n] + ans[1]))
    {
        for(int i = 1; i <= n; ++i)
            cout << (i == 1 ? "" : " ") << ans[i] ;
        cout << endl;
    }
}

void DFS(int num)
{
    if(num == n)
    {
        check();
        return;
    }
    
    for(int k = 2; k <= n; ++k)
    {
        //cout << k << " ";
        
        if(mark[k] == false && judge(k + ans[num]))
        {
            mark[k] = true;
            
            ans[num+1] = k;
            
            DFS(num+1);
            mark[k] = false;
            
        }
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PrimeRing/PrimeRing/in", "r", stdin);
    
    int Case = 0;
    while(cin >> n && n != 0)
    {
        Case++;
        
        for(int i = 1; i <= n; ++i)
            mark[i] = false;
        ans[1] = 1;
        mark[1] = true;
        
        cout << "Case " << Case << ":" << endl;
        DFS(1);
    }
    
    
    return 0;
}
