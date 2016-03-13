//
//  main.cpp
//  Floyd算法
//
//  Created by 程锋 on 15/8/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int edge[101][101];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Floyd算法/Floyd算法/in", "r", stdin);
    
    int n, m;
    
    while(cin >> n >> m && n != 0)
    {
        for(int i = 1; i < 101; ++i)
            for(int j = 1; j < 101; ++j)
                edge[i][j] = -1;
        
        for(int i = 0; i < m; ++i)
        {
            int a, b, cost;
            cin >> a >> b >> cost;
            edge[a][b] = edge[b][a] = cost;
        }
        
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                {
                    if(edge[i][k] == -1 || edge[k][j] == -1)
                        continue;
                    if(edge[i][j] == -1 || edge[i][j] > edge[i][k] + edge[k][j])
                        edge[i][j] = edge[i][k] + edge[k][j];
                }
        
        cout << edge[1][n] << endl;
    }
    
    return 0;
}
