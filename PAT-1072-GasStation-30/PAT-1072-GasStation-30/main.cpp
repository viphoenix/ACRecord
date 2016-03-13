//
//  main.cpp
//  PAT-1072-GasStation-30
//
//  Created by 程锋 on 15/9/9.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.
 
     Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.
     
     Then K lines follow, each describes a road in the format
     P1 P2 Dist
     where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.
     
     Output Specification:
     
     For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.
     
     Sample Input 1:
     4 3 11 5
     1 2 2
     1 4 2
     1 G1 4
     1 G2 3
     2 3 2
     2 G2 1
     3 4 2
     3 G3 2
     4 G1 3
     G2 G1 1
     G3 G2 2
     Sample Output 1:
     G1
     2.0 3.3
     Sample Input 2:
     2 1 2 10
     1 G1 9
     2 G1 20
     Sample Output 2:
     No Solution
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 4020
#define INF 0x7fffffff
#define BASE 2001
#include <iomanip>

using namespace std;

int n, m, k, range;

int strToInt(char name[])
{
    int idx = 0;
    
    if(name[0] == 'G')
        idx = 1;
    
    int res = idx == 1 ? n : 0;
    
    res += atoi(name + idx);
    
    return res;
    
}

struct Result{
    int index;
    float minDis;
    float sum;
    
    Result(int _index, int _minDis, float _sum):index(_index), minDis(_minDis), sum(_sum){}
    
    bool operator < (const Result & b) const
    {
        if(minDis != b.minDis)
            return minDis > b.minDis;
        else if(sum != b.sum)
            return sum < b.sum;
        else
            return index < b.index;
    }
};

struct Node{
    int no, d;
    
    Node(int _no, int _d):no(_no), d(_d){}
};

vector<Result> res;
vector<Node> node[N];
bool mark[N];
int dist[N];
int newP;
int maxV;

void dij(int start)
{
    newP = start;
    mark[newP] = true;
    dist[newP] = 0;
    
    for(int i = 1; i < n+m; ++i)
    {
        for(int j = 0; j < node[newP].size(); ++j)
        {
            int no = node[newP][j].no;
            int d = node[newP][j].d;
            
            if(mark[no] == true)
                continue;
            
            if(dist[no] == -1 || dist[no] > dist[newP] + d)
                dist[no] = dist[newP] + d;
        }
        
        maxV = INF;
        for(int j = 1; j <= n+m; ++j)
        {
            if(dist[j] == -1)
                continue;
            if(mark[j] == true)
                continue;
            
            if(dist[j] < maxV)
            {
                maxV = dist[j];
                newP = j;
            }
            
        }

        mark[newP] = true;
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1072-GasStation-30/PAT-1072-GasStation-30/in", "r", stdin);
    
    while(scanf("%d%d%d%d", &n, &m, &k, &range) != EOF)
    {
        for(int i = 0; i < k; ++i)
        {
            char aname[10], bname[10];
            int d;
            scanf("%s%s%d", aname, bname, &d);
            
            int a = strToInt(aname);
            int b = strToInt(bname);
            
            node[a].push_back(Node(b, d));
            node[b].push_back(Node(a, d));
        }
        

        for(int i = n+1; i <= n+m; ++i)
        {
            for(int j = 0; j <= n+m; ++j)
            {
                mark[j] = false;
                dist[j] = -1;
            }

            dij(i);
            
            bool flag = true;
            float sumDis = 0.0;
            float minV = INF;
            for(int j = 1; j <= n; ++j)
            {
//                cout << dist[j] << " ";
                if(dist[j] == -1 || dist[j] > range)
                {
                    flag = false;
                    break;
                }
                sumDis += dist[j];
                if(dist[j] < minV)
                    minV = dist[j];
            }
            
            
            if(flag)
                res.push_back(Result(i, minV, sumDis));
        }
        
        if(res.size() == 0)
        {
            printf("No Solution\n");
            return 0;
        }
        
        sort(res.begin(), res.end());
        
        printf("G%d\n%.1f %.1f", res[0].index-n, res[0].minDis, res[0].sum/n);  //编译器的不同导致四舍五入的结果不同
        
    }
    
    return 0;
}



























