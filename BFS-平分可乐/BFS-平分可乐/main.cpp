//
//  main.cpp
//  BFS-平分可乐
//
//  Created by 程锋 on 15/8/7.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <queue>
#define NUM 101

using namespace std;

//状态数据结构
struct Node{
    int s, n, m;
    int times;
};

bool mark[NUM][NUM][NUM];
queue<Node> qu;

//状态变更函数

void AToB(int &a, int sa, int &b, int sb)
{
    if(sb - b >= a)
    {
        b += a;
        a = 0;
    }
    else
    {
        a -= sb-b;
        b = sb;
        
    }
}

void init()
{
    for(int i = 0; i < NUM; ++i)
        for(int j = 0; j < NUM; ++j)
            for(int k = 0; k < NUM; ++k)
            {
                mark[i][j][k] = false;
            }
    while (!qu.empty()) {
        qu.pop();
    }
}

bool judge(int S, int a, int b, int c)
{
    if(a == S/2 && b == S/2)
        return true;
    if(a == S/2 && c == S/2)
        return true;
    if(c == S/2 && b == S/2)
        return true;
    return false;
}

int BFS(int S, int N, int M)
{
    while (!qu.empty()) {
        Node newNode = qu.front();
        qu.pop();
        
        int ns = newNode.s;
        int nn = newNode.n;
        int nm = newNode.m;
        int nt = newNode.times;
        
        AToB(ns, S, nn, N);
        if(mark[ns][nn][nm] == false)
        {
            mark[ns][nn][nm] = true;
            
            if(judge(S, ns, nn, nm))
                return nt + 1;
                
            Node tmp;
            tmp.s = ns;
            tmp.n = nn;
            tmp.m = nm;
            tmp.times = nt + 1;
            
            qu.push(tmp);
        }
        
        ns = newNode.s;
        nn = newNode.n;
        nm = newNode.m;
        nt = newNode.times;
        AToB(ns, S, nm, M);
        if(mark[ns][nn][nm] == false)
        {
            mark[ns][nn][nm] = true;
            
            if(judge(S, ns, nn, nm))
                return nt + 1;
            
            Node tmp;
            tmp.s = ns;
            tmp.n = nn;
            tmp.m = nm;
            tmp.times = nt + 1;
            
            qu.push(tmp);
        }

        ns = newNode.s;
        nn = newNode.n;
        nm = newNode.m;
        nt = newNode.times;
        AToB(nn, N, nm, M);
        if(mark[ns][nn][nm] == false)
        {
            mark[ns][nn][nm] = true;
            
            if(judge(S, ns, nn, nm))
                return nt + 1;
            
            Node tmp;
            tmp.s = ns;
            tmp.n = nn;
            tmp.m = nm;
            tmp.times = nt + 1;
            
            qu.push(tmp);
        }

        ns = newNode.s;
        nn = newNode.n;
        nm = newNode.m;
        nt = newNode.times;
        AToB(nm, M, nn, N);
        if(mark[ns][nn][nm] == false)
        {
            mark[ns][nn][nm] = true;
            
            if(judge(S, ns, nn, nm))
                return nt + 1;
            
            Node tmp;
            tmp.s = ns;
            tmp.n = nn;
            tmp.m = nm;
            tmp.times = nt + 1;
            
            qu.push(tmp);
        }

        ns = newNode.s;
        nn = newNode.n;
        nm = newNode.m;
        nt = newNode.times;
        AToB(nm, M, ns, S);
        if(mark[ns][nn][nm] == false)
        {
            mark[ns][nn][nm] = true;
            
            if(judge(S, ns, nn, nm))
                return nt + 1;
            
            Node tmp;
            tmp.s = ns;
            tmp.n = nn;
            tmp.m = nm;
            tmp.times = nt + 1;
            
            qu.push(tmp);
        }

        ns = newNode.s;
        nn = newNode.n;
        nm = newNode.m;
        nt = newNode.times;
        AToB(nn, N, ns, S);
        if(mark[ns][nn][nm] == false)
        {
            mark[ns][nn][nm] = true;
            
            if(judge(S, ns, nn, nm))
                return nt + 1;
            
            Node tmp;
            tmp.s = ns;
            tmp.n = nn;
            tmp.m = nm;
            tmp.times = nt + 1;
            
            qu.push(tmp);
        }
    
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/BFS-平分可乐/BFS-平分可乐/in", "r", stdin);
    
    int S, N, M;
    while (cin >> S >> N >> M && S != 0) {
        
        if(S % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        
        init();
        
        Node tmp;
        tmp.s = S;
        tmp.n = 0;
        tmp.m = 0;
        tmp.times = 0;
        qu.push(tmp);
        
        mark[S][0][0] = true;
        int rt = BFS(S, N, M);
        
        if(rt != -1)
            cout << rt << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}














































