//
//  main.cpp
//  BFS-大逃亡
//
//  Created by 程锋 on 15/9/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct State{
    int x, y, z, t;
    
    State(int _x, int _y, int _z, int _t):x(_x), y(_y), z(_z), t(_t){};
};

int cases, a, b, c, T;
int maze[55][55][55];

queue<State> qu;

int go[][3] = {
    
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};

int bfs(int a, int b, int c)
{
    while(!qu.empty())
    {
        State nowP = qu.front();
        qu.pop();
        
        for(int i = 0; i < 6; ++i)
        {
            /**
             *  局部变量
             */
            int nx = nowP.x + go[i][0];
            int ny = nowP.y + go[i][1];
            int nz = nowP.z + go[i][2];
            int nt = nowP.t + 1;
            
            if(nx < 0 || ny < 0 || nz < 0 || nx >= a || ny >= b || nz >= c)
                continue;
            
            if(maze[nx][ny][nz] == 1)
                continue;
            
            qu.push(State(nx, ny, nz, nt));
            
            maze[nx][ny][nz] = 1;
            
            if(nx == a-1 && ny == b-1 && nz == c-1 && nt <= T)
                return nt;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Review/BFS-大逃亡/BFS-大逃亡/in", "r", stdin);
    
    while(cin >> cases)
    {
        while(cases--)
        {
            cin >> a >> b >> c >> T;
            
            for(int i = 0; i < a; ++i)
                for(int j = 0; j < b; ++j)
                    for(int k = 0; k < c; ++k)
                    {
                        int tmp;
                        cin >> tmp;
                        maze[i][j][k] = tmp;
                    }
            
            qu.push(State(0,0,0,0));
            maze[0][0][0] = 1;
            
            int res = bfs(a, b, c);
            
            cout << res << endl;
        }
    }
    
    
    
    
    return 0;
}

















