//
//  main.cpp
//  畅通工程
//
//  Created by 程锋 on 15/8/5.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int Tree[1001];

int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/畅通工程/畅通工程/in", "r", stdin);
    
    int n, m;
    
    while(cin >> n >> m && n != 0)
    {
        for(int i = 1; i <= n; ++i)
            Tree[i] = -1;
        int a, b;
        for(int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            a = findRoot(a);
            b = findRoot(b);
            
            if(a != b)
                Tree[a] = b;
        }
        
        int res = 0;
        for(int i = 1; i <= n; ++i)
            if(Tree[i] == -1)
                res++;
        
        cout << res-1 << endl;
    }
    
    return 0;
}
