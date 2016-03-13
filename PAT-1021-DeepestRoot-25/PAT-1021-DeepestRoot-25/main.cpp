//
//  main.cpp
//  PAT-1021-DeepestRoot-25
//
//  Created by 程锋 on 15/8/30.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
     
     Output Specification:
     
     For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.
     
     Sample Input 1:
     5
     1 2
     1 3
     1 4
     2 5
     Sample Output 1:
     3
     4
     5
     Sample Input 2:
     5
     1 3
     1 4
     2 5
     3 4
     Sample Output 2:
     Error: 2 components
 */

#include <iostream>
#include <vector>
#define MAX 10005

using namespace std;

int Tree[MAX];
int dp[MAX];
vector<int> node[MAX];
bool mark[MAX];

int maxDep = 1;
int depth = 1;


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

void DFS(int root, int & depth)
{
    if(depth >= maxDep)
        maxDep = depth;
    
    for(int i = 0; i < node[root].size(); ++i)
    {
        int newNode = node[root][i];
        
        if(mark[newNode] == false)
        {
            mark[newNode] = true;
            depth += 1;
            DFS(newNode, depth);
            depth -= 1;      //注意
            mark[newNode] = false;
        }
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1021-DeepestRoot-25/PAT-1021-DeepestRoot-25/in", "r", stdin);
    
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < MAX; ++i)
        {
            Tree[i] = -1;
            mark[i] = false;
            node[i].clear();
        }
        
        for(int i = 1;i < n; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            
            node[a].push_back(b);
            node[b].push_back(a);
            
            a = findRoot(a);
            b = findRoot(b);
            if(a != b)        //注意不要漏掉
                Tree[a] = b;
        }
        
        int cnt = 0;
        for(int i = 1;i <= n; ++i)
            if(Tree[i] == -1)
                cnt++;
        
        //判断是否存在连通分量
        if(cnt-1 > 0)
        {
            printf("Error: %d components", cnt);
            return 0;
        }
        
        for(int i = 1; i <= n; ++i)
        {
            mark[i] = true;       //注意
            DFS(i, depth);
            //cout << maxDep << endl;
            dp[i] = maxDep;
            maxDep = 1;
//            depth = 1;         针对每一个结点的所有DFS后，depth回溯为1，所以不必要     DFS最后一定会回溯到起点
            mark[i] = false;   //注意
        }
        
        int max = 0;
        for(int i = 1; i <= n; ++i)
            if(dp[i] > max)
                max = dp[i];
        
        for(int i = 1; i <= n; ++i)
            if(dp[i] == max)
                printf("%d\n", i);
        
    }
    
    return 0;
}




















