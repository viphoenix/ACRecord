//
//  main.cpp
//  PAT-1053-PathOfEqualWeight-30
//
//  Created by 程锋 on 15/9/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[105];
int weight[105] = {0};
bool mark[105];
//long long totalWeight = 0;

vector<int> curPath;
vector<vector<int>> paths;

bool cmp(vector<int> a, vector<int> b)
{
    int minLen = a.size() > b.size() ? b.size() : a.size();
    
    for(int i = 0; i < minLen; ++i)
    {
        if(a[i] != b[i])
            return a[i] > b[i];
        else
            continue;
    }
    
    return false;
}

int n, m, s;

void dfs(int root, int totalWeight)
{
    if(mark[root] == false)
    {
        totalWeight += weight[root];
        
        curPath.push_back(weight[root]);
        
        if(tree[root].size() == 0)
        {
            if(totalWeight == s)
                paths.push_back(curPath);
        }
        
        mark[root] = true;
        
        
        for(int i = 0; i < tree[root].size(); ++i)
        {
            int nowP = tree[root][i];
            
            dfs(nowP, totalWeight);
//            totalWeight -= weight[nowP];
            curPath.pop_back();  //删除最后一个元素
        }
    }
}

/*
void dfs(int root)
{
    if(mark[root] == false)
    {
        totalWeight += weight[root];
        
        curPath.push_back(weight[root]);
        
        if(tree[root].size() == 0)
        {
            if(totalWeight == s)
                paths.push_back(curPath);
        }
        
        mark[root] = true;
        
        
        for(int i = 0; i < tree[root].size(); ++i)
        {
            int nowP = tree[root][i];
            
            dfs(nowP);
            totalWeight -= weight[nowP];
            curPath.pop_back();  //删除最后一个元素
        }
    }
}
*/

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1053-PathOfEqualWeight-30/PAT-1053-PathOfEqualWeight-30/in", "r", stdin);
    
    while (scanf("%d%d%d", &n, &m, &s) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &weight[i]);
            
            tree[i].clear();
            mark[i] = false;
        }
        
        for(int i = 0; i < m; ++i)
        {
            int root, nums, child;
            scanf("%d%d", &root, &nums);
            
            while (nums--)
            {
                scanf("%d", &child);
                tree[root].push_back(child);
            }
        }
        
//        totalWeight = 0;
        dfs(0, 0);
        
        sort(paths.begin(), paths.end(), cmp);
        for(int i = 0; i < paths.size(); ++i)
        {
            cout << paths[i][0];
            for(int j = 1; j < paths[i].size(); ++j)
            {
                cout << " " << paths[i][j];
            }
            cout << endl;
        }
        
    }
    
    
    
    return 0;
}
