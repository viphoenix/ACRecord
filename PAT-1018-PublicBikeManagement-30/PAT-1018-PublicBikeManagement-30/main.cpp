//
//  main.cpp
//  PAT-1018-PublicBikeManagement-30
//
//  Created by 程锋 on 15/9/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.
 
     The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.
     
     When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.
     
     
     Figure 1
     Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:
     
     1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.
     
     2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.
     
     Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.
     
     Sample Input:
     10 3 3 5
     6 7 0
     0 1 1
     0 2 1
     0 3 3
     1 3 1
     2 3 1
     Sample Output:
     3 0->2->3 0
 
    记录从起点到达每个终点，富余的自行车数量，如果不能达到perfect状态，选择富余最多的路径或路径上自行车数量最多的;如果能够达到perfect状态，选择富余最少的路径
 
    注意中间可能是0-10之间的值
 */



#include <iostream>
#include <vector>
#define N 505
#define INF 0x7fffffff

using namespace std;

int dist[N];
int remain[N]; //在保证路径上所有状态为perfect的情况下，富余的自行车数
bool mark[N];
int pre[N];

struct Node{
    int next;
    int time;
    int nums;
};

vector<Node> node[N];
int station[N] = {0};

void print(int dest)
{
    if(dest == 0)
    {
        printf("0");
        return;
    }
    
    print(pre[dest]);
    
    printf("->%d", dest);
    
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1018-PublicBikeManagement-30/PAT-1018-PublicBikeManagement-30/in", "r", stdin);
    
    int capacity, n, destination, roads;
    
    while(scanf("%d%d%d%d", &capacity, &n, &destination, &roads) != EOF)
    {
        
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &station[i]);
            
            mark[i] = false;
            remain[i] = -INF;
            dist[i] = -1;
            pre[i] = -1;
        }
        
        for(int i = 0; i < roads; ++i)
        {
            int a, b, t;
            scanf("%d%d%d", &a, &b, &t);
            
            Node tmp;
            tmp.next = b;
            tmp.time = t;
            tmp.nums = station[b];
            node[a].push_back(tmp);
            
            tmp.next = a;
            tmp.nums = station[a];
            node[b].push_back(tmp);
        }
        
        int start = 0;
        mark[start] = true;
        dist[start] = 0;
        remain[start] = 0;
        
        
        //int need = capacity/2 - station[destination];
        
        for(int i = 1; i <= n; ++i)  //注意次数不要漏
        {
            for(int j = 0; j < (int)node[start].size(); ++j)
            {
                int newNode = node[start][j].next;
                int time = node[start][j].time;
                int nums = node[start][j].nums;
                
                if(mark[newNode])
                    continue;
                
                if(dist[newNode] == -1 || dist[newNode] > dist[start] + time)
                {
                    dist[newNode] = dist[start] + time;
                    remain[newNode] = remain[start] + nums - capacity/2;
                    
                    pre[newNode] = start;
                }
                else if(dist[newNode] == dist[start] + time)
                {
                    if(remain[newNode] >= 0)   //是大于0，不是大于需要的数量，remain表示达到perfect状态后，剩余的数量
                    {
                        if(remain[newNode] > remain[start] + nums - capacity/2 && remain[start] + nums - capacity/2 >= 0)  //注意要大于0
                        {
                            remain[newNode] = remain[start] + nums - capacity/2;
                            pre[newNode] = start;
                        }
                    }
                    else
                    {
                        if(remain[newNode] < remain[start] + nums - capacity/2)
                        {
                            remain[newNode] = remain[start] + nums - capacity/2;
                            pre[newNode] = start;
                        }
                    }
                    
                }
            }
            
            int min = INF;
            for(int i = 0; i < n; ++i)
            {
                if(dist[i] == -1 || mark[i])
                    continue;
                
                if(dist[i] < min)
                {
                    min = dist[i];
                    start = i;
                }
            }
            
            mark[start] = true;
        }
        
        /*
         for(int i = 1; i <= n; ++i)
         printf("%d ", remain[i]);
         printf("\n");
         */
        
        if(remain[destination] < 0 && remain[destination] != -INF)
        {
            printf("%d ", remain[destination]*(-1));
            
            print(destination);
            
            printf(" 0");
        }
        else
        {
            printf("0 ");
            print(destination);
            printf(" %d", remain[destination]);
        }
        
    }
    
    
    
    return 0;
}





























