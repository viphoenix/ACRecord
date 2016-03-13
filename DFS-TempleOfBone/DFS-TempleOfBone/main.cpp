//
//  main.cpp
//  DFS-TempleOfBone
//
//  Created by 程锋 on 15/8/16.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

char maze[10][10];
bool mark[10][10];
int N, M, T;
bool flag;

int go[][2] = {
                -1, 0,
                0, -1,
                0, 1,
                1, 0
};


void DFS(int x, int y, int t)
{
    for(int k = 0; k < 4; ++k)
    {
        int nx = x + go[k][0];
        int ny = y + go[k][1];
        
        if(x < 1 || y < 1 || x > N || y > M)
            continue;

        if(mark[nx][ny])
            continue;
        
        if(maze[nx][ny] == 'X')
            continue;
        
        if(maze[nx][ny] == 'D')
        {
            if(t+1 == T)
            {
                flag = true;
                return;
            }
            else
                continue;
        }


        mark[nx][ny] = true;
        
        DFS(nx, ny, t+1);
        mark[nx][ny] =false;
        
        if(flag)
            return;
    }
}


int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/DFS-TempleOfBone/DFS-TempleOfBone/in", "r", stdin);
    
    while (cin >> N >> M >> T && N != 0) {
        //initalize
        flag = false;
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
            {
                mark[i][j] = false;
            }
        
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
            {
                char tmp;
                cin >> tmp;
                maze[i][j] = tmp;
            }
        
        int dx, dy;
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
            {
                if(maze[i][j] == 'D')
                {
                    dx = i;
                    dy = j;
                }
            }

        
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
            {
                if(maze[i][j] == 'S' && (i+j)%2 == ((dx+dy)%2+T%2)%2)
                {
                    mark[i][j] = true;
                    DFS(i, j, 0);
                }
            }
        
        cout << (flag?"YES":"NO") << endl;
    }
    
    return 0;
}
