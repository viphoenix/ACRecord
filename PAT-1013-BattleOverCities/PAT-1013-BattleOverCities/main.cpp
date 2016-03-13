//
//  main.cpp
//  PAT-1013-BattleOverCities
//
//  Created by 程锋 on 15/8/22.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.
 
     For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.
     
     Input
     
     Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.
     
     Output
     
     For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
     
     Sample Input
     3 2 3
     1 2
     1 3
     2 1 3
     Sample Output
     1
     0
     0
 */

#include <iostream>

using namespace std;

int Tree[1001];
int vec[1001][1001];
bool mark[1001][1001];

int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;

    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1013-BattleOverCities/PAT-1013-BattleOverCities/in", "r", stdin);
    
    int n, m, k;
    
    while(cin >> n >> m >> k && n != 0)
    {
        //initialize
        for(int i = 1; i <= n; ++i)
        {
            
            for(int j = 1; j <= n; ++j)
                vec[i][j] = -1;
        }
        
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            vec[a][b] = vec[b][a] = 1;
        }
        
        while(k--)
        {
            for(int i = 1; i <= n; ++i)
            {
                Tree[i] = -1;
                for(int j = 1; j <= n; ++j)
                    mark[i][j] = false;
            }
            
            int p;
            cin >> p;
           /*  最主要的错误代码，循环输入时，注意上轮输入是否影响本轮
            for(int i = 1; i <= n; ++i)
                vec[i][p] = vec[p][i] = -1;
            */
            for(int i = 1; i <= n; ++i)
            {
                mark[i][p] = mark[p][i] = true;
            }
            
            //并查集找连通图
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                {
                    if(i == p || j == p || i == j)
                        continue;
                    if(mark[i][j])
                        continue;
                    if(vec[i][j] == -1)
                        continue;
                    int a = findRoot(i);
                    int b = findRoot(j);
                    if(a != b)
                        Tree[a] = b;
                    mark[i][j] = true;
                }
            
            int cnt = 0;
            for(int i = 1; i <= n; ++i)
            {
                //cout << Tree[i] << " ";
                if(i != p && Tree[i] == -1)
                    cnt++;
            }
            
            cout << (cnt - 1 > 0 ? cnt-1: 0);
            if(k != 0)
                cout << endl;
            
        }
    }
    
    
    return 0;
}



























