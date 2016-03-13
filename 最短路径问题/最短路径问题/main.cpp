//
//  main.cpp
//  最短路径问题
//
//  Created by 程锋 on 15/8/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int next;
    int dist;
    int cost;
};

vector<Edge> edge[1001];

int Dist[1001];
int Cost[1001];
bool Mark[1001];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/最短路径问题/最短路径问题/in", "r", stdin);
    
    int n, m, src, dst;
    
    while(cin >> n >> m && n != 0)
    {
        while(m--)
        {
            int a, b, d, c;
            cin >> a >> b >> d >> c;
            Edge tmp;
            tmp.next = b;
            tmp.dist = d;
            tmp.cost = c;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        
        cin >> src >> dst;
        
        for(int i = 1; i <= n; ++i)
        {
            Dist[i] = -1;
            Cost[i] = -1;
            Mark[i] = false;
        }
        
        Dist[src] = 0;
        Mark[src] = true;
        Cost[src] = 0;
        
        int newNode = src;
        
        for(int i = 1; i <= n-1; ++i)
        {
            for(int j = 0; j < edge[newNode].size(); ++j)
            {
                int next = edge[newNode][j].next;
                int dist = edge[newNode][j].dist;
                int cost = edge[newNode][j].cost;
                if(Mark[next])
                    continue;
                if(Dist[next] == -1 || Dist[next] > Dist[newNode] + dist || (Dist[next] == Dist[newNode] + dist && Cost[next] > Cost[newNode] + cost))
                {
                    Dist[next] = Dist[newNode] + dist;
                    
                    Cost[next] = Cost[newNode] + cost;
                }
            }
            
            int min = 999999;
            for(int i = 1; i <= n; ++i)
            {
                if(Mark[i] == true)
                    continue;
                if(Dist[i] == -1)
                    continue;
                if(Dist[i] < min)
                {
                    min = Dist[i];
                    newNode = i;
                }
            }
            
            Mark[newNode] = true;
        }
        
        
        cout << Dist[n] << " " << Cost[n] << endl;
    }
    
    return 0;
}









































