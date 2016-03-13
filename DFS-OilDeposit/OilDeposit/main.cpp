//
//  main.cpp
//  OilDeposit
//
//  Created by 程锋 on 15/8/16.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

char maze[101][101];
bool mark[101][101];

int m, n;

int go[][2] = {0, 1,
            1, 0,
            0, -1,
            -1, 0,
            -1, -1,
            1, 1,
            1, -1,
            -1, 1
};

void DFS(int x, int y)
{
    for(int k = 0; k < 8; ++k)
    {
        int nx = x + go[k][0];
        int ny = y + go[k][1];
        
        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        
        if(maze[nx][ny] == '@' && mark[nx][ny] == false)
        {
            mark[nx][ny] = true;
            DFS(nx, ny);
        }
    }
    
//    return;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/DFS-OilDeposit/OilDeposit/in", "r", stdin);
    
    
    while(cin >> m >> n && m != 0)
    {
        //initialize
        for(int i = 0; i < 101; ++i)
            for(int j = 0; j < 101; ++j)
                mark[i][j] = false;
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                char tmp;
                cin >> tmp;
                maze[i][j] = tmp;
            }
    
        int cnt = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(maze[i][j] == '@' && mark[i][j] == false)
                {
                    mark[i][j] = true;
                    DFS(i, j);
                    cnt++;
                }
            }
        
        cout << cnt << endl;
    }
    
    
    
    return 0;
}
