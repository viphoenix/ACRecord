//
//  main.cpp
//  PAT-1091-AcuteStroke-30
//
//  Created by 程锋 on 15/9/7.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int go[][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};

int m, n, k, t;
int maze[65][1300][150];
int volume = 0;
int totalVolume = 0;

struct Point{
    int z, x, y;
    Point(int _z, int _x, int _y):z(_z),x(_x),y(_y){}
};

void dfs(int p, int i, int j)
{
    for(int i = 0; i < 6; ++i)
    {
        int nz = p + go[i][0];
        int nx = i + go[i][1];
        int ny = j + go[i][2];
        
        if(nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= k)
            continue;
        
        if(maze[nz][nx][ny] == 0)
            continue;
        
        volume++;
        
        maze[nz][nx][ny] = 0;
        
        dfs(nz, nx, ny);
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1091-AcuteStroke-30/PAT-1091-AcuteStroke-30/in", "r", stdin);
    
    
    while(cin >> m >> n >> k >> t)
    {
        for(int p = 0; p < k; ++p)
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < n; ++j)
                {
                    int tmp;
                    cin >> tmp;
                    
                    maze[p][i][j] = tmp;
                }
        
        
        for(int p = 0; p < k; ++p)
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < n; ++j)
                {
                    //volume = 0;
                    if(maze[p][i][j] == 1)
                    {
                        volume = 1;
                        maze[p][i][j] = 0;
                        
                        dfs(p, i, j);
                        
                        cout << volume << endl;
                        
                        if(volume >= t)
                            totalVolume += volume;
                    }
                }
        
        cout << totalVolume;
        
    }
    
    
    return 0;
}

/*

#include <iostream>
#include <queue>

using namespace std;

int go[][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};

int m, n, k, t;
int maze[65][1300][150];
int volume = 0;
int totalVolume = 0;

struct Point{
    int z, x, y;
    Point(int _z, int _x, int _y):z(_z),x(_x),y(_y){}
};

void dfs(int p, int i, int j)
{
    if (maze[p][i][j] == 0) // 起点都是 0  可以退出了
        return;
    queue<Point> q;
    q.push(Point(p,i,j));
    while (!q.empty())
    {
        Point nowP = q.front();
        q.pop();
        int z = nowP.z;
        int x = nowP.x;
        int y = nowP.y;
        if (maze[z][x][y] == 1)
        {
            maze[z][x][y] = 0; // 需要将其置为0,这个不能没有
            volume++;
            if (z > 0)
                q.push(Point(z - 1, x, y)); //下
            if (z + 1 < k)
                q.push(Point(z + 1, x, y)); // 上
            if (x > 0)
                q.push(Point(z, x - 1, y)); // 左
            if (x + 1 < m)
                q.push(Point(z, x + 1, y));// 右
            if (y > 0)
                q.push(Point(z, x, y - 1)); // 前
            if (y + 1 < n)
                q.push(Point(z, x, y + 1)); // 后
        }
    }
}

int main(int argc, const char * argv[]) {
    
    // freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1091-AcuteStroke-30/PAT-1091-AcuteStroke-30/in", "r", stdin);
    
    
    while(cin >> m >> n >> k >> t)
    {
        for(int p = 0; p < k; ++p)
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < n; ++j)
                {
                    int tmp;
                    cin >> tmp;
                    
                    maze[p][i][j] = tmp;
                }
        
        
        for(int p = 0; p < k; ++p)
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < n; ++j)
                {
                    
                    volume = 0;
                    
                    dfs(p, i, j);
                    if(volume >= t)
                        totalVolume += volume;
                }
        
        cout << totalVolume;
    }
    
    
    
    
    return 0;
}
*/












