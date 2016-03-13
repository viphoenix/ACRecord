//
//  main.cpp
//  并查集-找朋友
//
//  Created by 程锋 on 15/8/5.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <map>

#define N 10000001

using namespace std;

int Tree[N];
int sum[N];
map<int, int> m;

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

int main1(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/并查集-找朋友/并查集-找朋友/in", "r", stdin);
    
    int n;
    while(cin >> n && n != 0)
    {
        for(int i = 0; i < N; ++i)
        {
            Tree[i] = -1;
            sum[i] = 1;
        }
        
        m.erase(m.begin(), m.end());
        
        for(int i = 0; i < n; ++i)
        {
            int a, b;
            
            cin >> a >> b;
            m.insert(pair<int, int>(a, 1));
            m.insert(pair<int, int>(b, 1));
            
            a = findRoot(a);
            b = findRoot(b);
            
            if(a != b)
            {
                Tree[a] = b;
                map<int, int>::iterator ita = m.find(a);
                map<int, int>::iterator itb = m.find(b);
                
                itb->second += ita->second;
            }
        }
        
        int max = 1;
        
        map<int, int>::iterator it;
        for(it = m.begin(); it != m.end(); ++it)
            if(it->second > max)
                max = it->second;
        
        cout << max << endl;
    }
    
    return 0;
}



int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/并查集-找朋友/并查集-找朋友/in", "r", stdin);
    
    int n;
    while(cin >> n && n != 0)
    {
        for(int i = 0; i < N; ++i)
        {
            Tree[i] = -1;
            sum[i] = 1;
        }
        for(int i = 0; i < n; ++i)
        {
            int a, b;
            
            cin >> a >> b;
            a = findRoot(a);
            b = findRoot(b);
            if(a != b)
            {
                Tree[a] = b;
                sum[b] += sum[a];
            }
        }
        
        int max = 1;
        for(int i = 0; i <= N; ++i)
            if(sum[i] > max)
                max = sum[i];
        cout << max << endl;
    }
    
    return 0;
}
