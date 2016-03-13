//
//  main.cpp
//  BFS-大逃亡
//
//  Created by 程锋 on 15/8/7.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <queue>
#define N 51

using namespace std;

int BFS(int, int, int, int);

struct Node {
    int x, y, z;
    int t;
};

int go[][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};

int maze[N][N][N];
bool mark[N][N][N];
queue<Node> qu;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/BFS-大逃亡/BFS-大逃亡/in", "r", stdin);
    
    int n;
    
    while (cin >> n && n != 0) {
        while(n--)
        {
            //初始化
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    for(int k = 0; k < N; ++k)
                    {
                        maze[i][j][k] = 0;
                        mark[i][j][k] = false;
                    }
            
            while (!qu.empty()) {
                qu.pop();
            }
            
            int A, B, C, T;
            cin >> A >> B >> C >> T;
            
            int tmp;
            for(int i = 0; i < A; ++i)
                for(int j = 0; j < B; ++j)
                    for(int k = 0; k < C; ++k)
                    {
                        cin >> tmp;
                        maze[i][j][k] = tmp;
                    }
            
            Node startNode;
            startNode.x = startNode.y = startNode.z = startNode.t = 0;
            qu.push(startNode);
            
            mark[0][0][0] = true;
            
            int rt = BFS(A, B, C, T);
            
            cout << rt << endl;
            
        }
    
    return 0;
    }

}


int BFS(int A, int B, int C, int T)
{
    
    while(!qu.empty())
    {
        Node tmpNode = qu.front();
        qu.pop();
        
        for(int i = 0; i < 6; ++i)
        {
            Node newNode;
            int nx = tmpNode.x + go[i][0];
            int ny = tmpNode.y + go[i][1];
            int nz = tmpNode.z + go[i][2];
            int nt = tmpNode.t + 1;
            
            if(nx < 0 || nx >= A || ny < 0 || ny >= B || nz < 0 || nz >= C)
                continue;
            
            if(mark[nx][ny][nz])
                continue;
            if(maze[nx][ny][nz] == 1)
                continue;
            
            if(nx == A-1 && ny == B-1 && nz == C-1 && nt < T)
                return nt;
            
            newNode.x = nx;
            newNode.y = ny;
            newNode.z = nz;
            newNode.t = nt;
            
            mark[nx][ny][nz] = true;
            qu.push(newNode);
            
        }
    }
    
    return -1;
    
}











































