//
//  main.cpp
//  DFS-OilDeposit
//
//  Created by 程锋 on 15/9/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

char maze[105][105];

int m, n;

int go[][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1,
    1, 1,
    -1, -1,
    1, -1,
    -1, 1
};

void dfs(int x, int y)
{
    for(int i = 0; i < 8; ++i)
    {
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        
        if(nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
        
        if(maze[nx][ny] == '*')
            continue;
        
        maze[nx][ny] = '*';
        dfs(nx, ny);
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Review/DFS-OilDeposit/DFS-OilDeposit/in", "r", stdin);
    
    
    while(cin >> m >> n && m != 0)
    {
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                char tc;
                cin >> tc;
                maze[i][j] = tc;
            }
        
        int cnt = 0;
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(maze[i][j] == '@')
                {
                    maze[i][j] = '*';
                    dfs(i, j);
                    cnt++;
                }
            }
        
        cout << cnt << endl;
    }
    
    
    
    return 0;
}
