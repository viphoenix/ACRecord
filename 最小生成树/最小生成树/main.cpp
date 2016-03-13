//
//  main.cpp
//  最小生成树
//
//  Created by 程锋 on 15/8/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
//  克鲁斯卡尔算法

#include <iostream>
#include <algorithm>

using namespace std;

int Tree[100];

bool mark[100]; //顶点标记法

struct Edge{
    int a;
    int b;
    int cost;
    
    bool operator < (const Edge & arg) const
    {
        return  cost < arg.cost;
    }
}edge[6000];

int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/最小生成树/最小生成树/in", "r", stdin);
    
    int n;
    
    while (cin >> n && n != 0) {
        for(int i = 1; i <= n; ++i)
        {
            Tree[i] = -1;
            mark[i] = false;
        }
        
        int a, b, cost;
        for(int i = 0; i < n*(n-1)/2; ++i)
        {
            cin >> a >> b >> cost;
            
            edge[i].a = a;
            edge[i].b = b;
            edge[i].cost = cost;
        }
        
        sort(edge, edge+n*(n-1)/2);
        
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n*(n-1)/2; ++i)
        {
            if(mark[edge[i].b] == false || mark[edge[i].b] == false)
                sum += edge[i].cost;

            if(mark[edge[i].a] == false)
            {
                mark[edge[i].a] = true;
                count++;
            }
            
            if(mark[edge[i].b] == false)
            {
                mark[edge[i].b] = true;
                count++;
            }
            
            if(count == n)
                break;
        }
        
        cout << sum << endl;
        
    }
    
    return 0;
}


int main1(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/最小生成树/最小生成树/in", "r", stdin);
    
    int n;
    
    while (cin >> n && n != 0) {
        for(int i = 1; i <= n; ++i)
            Tree[i] = -1;
        
        int a, b, cost;
        for(int i = 0; i < n*(n-1)/2; ++i)
        {
            cin >> a >> b >> cost;
            
            edge[i].a = a;
            edge[i].b = b;
            edge[i].cost = cost;
        }
        
        sort(edge, edge+n*(n-1)/2);
        
        int sum = 0;
        for(int i = 0; i < n*(n-1)/2; ++i)
        {
            a = findRoot(edge[i].a);
            b = findRoot(edge[i].b);
            
            if(a != b)
            {
                Tree[a] = b;
                sum += edge[i].cost;
            }
        }
        
        cout << sum << endl;
        
    }
    
    return 0;
}
