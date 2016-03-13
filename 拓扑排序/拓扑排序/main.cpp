//
//  main.cpp
//  拓扑排序
//
//  Created by 程锋 on 15/8/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int next;
};

vector<int> edge[101];
int inDegree[101];
queue<int> qu;


int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/拓扑排序/拓扑排序/in", "r", stdin);
    
    int n, m;
    
    while(cin >> n >> m && n != 0)
    {
        for(int i = 0; i < n; ++i)
        {
            edge[i].clear();
            inDegree[i] = 0;
        }
        while(!qu.empty())
            qu.pop();
        
        for(int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
        
            edge[b].push_back(a);
            
            inDegree[a]++;
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(inDegree[i] == 0)
                qu.push(i);
        }
        
        int count = 0;
        while(!qu.empty())
        {
            count++;
            int node = qu.front();
            qu.pop();
            for(int i = 0; i < edge[node].size(); ++i)
            {
                inDegree[edge[node][i]]--;
                if(inDegree[edge[node][i]] == 0)
                    qu.push(edge[node][i]);
            }
        }
        
        if(count == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        
    }
    
    
    return 0;
}











