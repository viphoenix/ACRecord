//
//  main.c
//  PAT1003
//
//  Created by 程锋 on 15/8/20.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
 
     Input
     
     Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The no line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.
     
     Output
     
     For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
     All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
     
     Sample Input
     5 6 0 2
     1 2 1 5 3
     0 1 1
     0 2 2
     0 3 1
     1 2 1
     2 4 1
     3 4 1
     Sample Output
     2 4
 
    算法思想：深度优先搜索，获得所有从起点到终点的路径，在搜索过程中可以得到每条路径的距离和以及人数和
            根据已获得的距离和最小值，剪枝
 */

#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int no;
    int distance;
    int num;
};
int n, m, c1, c2;

vector<Edge> edge[501];

bool mark[501];

//分别保存起点到每个结点的距离和人数
int dist[501], peo[501];
int size = 0;
int tmax = 0x7fffffff;

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void DFS(int start, int d, int n)
{
    //剪枝，如果当前结点的距离已经大于已获得路径的最小值，并且start!=c2,则终止
    if(d > tmax)
        return;
    if(start == c2)
    {
        dist[size] = d;
        peo[size] = n;
        size++;
        tmax = min(tmax, d);
        return;
    }
    
    for(int i = 0; i < edge[start].size(); ++i)
    {
        if(mark[edge[start][i].no])
            continue;
        int dis = d + edge[start][i].distance;
        int nums = n + edge[start][i].num;
        
        mark[edge[start][i].no] = true;
        DFS(edge[start][i].no, dis, nums);
        
        mark[edge[start][i].no] = false;
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT1003/PAT1003/in", "r", stdin);
    
    while(scanf("%d%d%d%d", &n, &m, &c1, &c2) != EOF)
    {
        for(int i = 0; i < 501; ++i)
        {
            mark[i] = false;
            if(!edge[i].empty())
                edge[i].clear();
        }
        
        Edge tmp;
        int p[501];
        for(int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        for(int i = 0; i < m; ++i)
        {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            tmp.no = b;
            tmp.distance = d;
            tmp.num = p[b];
            edge[a].push_back(tmp);
            tmp.no = a;
            tmp.num = p[a];
            edge[b].push_back(tmp);
        }
        
        mark[c1] = true;
        DFS(c1, 0, p[c1]);
        
        int paths = 0x7fffffff, cnt = 0;
        int persons = 0;
        for(int i = 0; i < size; ++i)
        {
            paths = min(paths, dist[i]);
        }
        for(int i = 0; i < size; ++i)
        {
            if(dist[i] == paths)
            {
                cnt++;
                persons = max(persons, peo[i]);
            }
        }
        printf("%d %d", cnt, persons);
        
    }
    
    return 0;
}


































