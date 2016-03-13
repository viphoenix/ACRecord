//
//  main.cpp
//  Dijkstra算法
//
//  Created by 程锋 on 15/8/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int next;
    int cost;
};

vector<Edge> edge[101];

int dist[101];
bool mark[101];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Dijkstra算法/Dijkstra算法/in", "r", stdin);
    
    int n, m;
    while(cin >> n >> m && n != 0)
    {
        for(int i = 1; i <= n; ++i)
            edge[i].clear();
        
        int a, b, cost;

        while(m--)
        {
            cin >> a >> b >> cost;
            Edge tmp;
            tmp.next = b;
            tmp.cost = cost;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        
        for(int i = 1; i <= n; ++i)
        {
            dist[i] = -1;
            mark[i] = false;
        }
        
        dist[1] = 0;
        mark[1] = true;
        
        //上次加入集合的结点
        int newNode = 1;
        
        for(int i = 1; i <= n-1; ++i)
        {
            for(int j = 0; j < edge[newNode].size(); ++j)
            {
                int next = edge[newNode][j].next;
                int cost = edge[newNode][j].cost;
                if(mark[next])
                    continue;
                if(dist[next] == -1 || dist[next] > dist[newNode]+cost)
                    dist[next] = dist[newNode] + cost;
            }
            
            int min = 999999;
            for(int i = 1; i <= n; ++i)
            {
                if(mark[i] == true)
                    continue;
                if(dist[i] == -1)
                    continue;
                if(dist[i] < min)
                {
                    min = dist[i];
                    newNode = i;
                }
            }
            
            mark[newNode] = true;
            
        }
        
        cout << dist[n] << endl;
    }
    
    
    return 0;
}






























