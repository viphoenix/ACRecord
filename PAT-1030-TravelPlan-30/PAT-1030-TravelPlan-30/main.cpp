//
//  main.cpp
//  PAT-1030-TravelPlan-30
//
//  Created by 程锋 on 15/8/30.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
 
     Input Specification:
     
     Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
     
     City1 City2 Distance Cost
     
     where the numbers are all integers no more than 500, and are separated by a space.
     
     Output Specification:
     
     For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.
     
     Sample Input
     4 5 0 3
     0 1 1 20
     1 3 2 30
     0 3 4 10
     0 2 2 20
     2 3 1 20
     Sample Output
     0 2 3 3 40
 */

#include <iostream>
#define N 5005
#define INF 0x7fffffff
#include <vector>
#include <cstring>

using namespace std;

struct Node{
    int no;
    int distance;
    int cost;
};

vector<Node> node[N];

int dist[N];
int cost[N];
bool mark[N];
int pre[N];

void init()
{
    memset(dist, -1, N);
    memset(cost, 0, N);
    memset(mark, false, N);
    memset(pre, -1, N);
    
    for(int i = 0;i < N; ++i)
        if(!node[i].empty())
            node[i].clear();
}

int n, m, s, d;

void print(int root)
{
    if(root == s)
    {
        cout << root;
        return;
    }
    
    print(pre[root]);
    
    cout << " " << root;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1030-TravelPlan-30/PAT-1030-TravelPlan-30/in", "r", stdin);
    
    
    
    while(cin >> n >> m >> s >> d)
    {
        init();
        
        while(m--)
        {
            int a, b, dis, cos;
            cin >> a >> b >> dis >> cos;
            
            Node tmp;
            tmp.no = b;
            tmp.distance = dis;
            tmp.cost = cos;
            
            node[a].push_back(tmp);
            tmp.no = a;
            node[b].push_back(tmp);
        }
        
        int newNode = s;
        dist[newNode] = 0;
        cost[newNode] = 0;
        mark[newNode] = true;
        
        for(int i = 1; i < n; ++i)
        {
        
            for(int j = 0; j < node[newNode].size(); ++j)
            {
                int no = node[newNode][j].no;
                int dis = node[newNode][j].distance;
                int cos = node[newNode][j].cost;
                
                if(mark[no])
                    continue;
                
                if(dist[no] == -1 || dist[no] > dist[newNode] + dis)
                {
                    dist[no] = dist[newNode] + dis;
                    cost[no] = cost[newNode] + cos;
                    
                    pre[no] = newNode;
                }
                else if(dist[no] == dist[newNode] + dis && cost[no] > cost[newNode] + cos)
                {
                    cost[no] = cost[newNode] + cos;
                    
                    pre[no] = newNode;
                }
            }
            
            int min = INF;
            
            for(int i = 0; i < n; ++i)
            {
                if(dist[i] == -1)
                    continue;
                
                if(mark[i])
                    continue;
                
                if(dist[i] < min)
                {
                    min = dist[i];
                    newNode = i;
                }
            }
            
            mark[newNode] = true;
        }
        
        print(d);
        
        cout << " " << dist[d] << " " << cost[d];
    }
    
    return 0;
}














