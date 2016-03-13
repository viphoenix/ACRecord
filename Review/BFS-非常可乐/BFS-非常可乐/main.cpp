//
//  main.cpp
//  BFS-非常可乐
//
//  Created by 程锋 on 15/9/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int s, n, m;

struct State{
    int sv, nv, mv;
    
    int nums;
    
    State(int _sv, int _nv, int _mv, int _nums):sv(_sv), nv(_nv), mv(_mv), nums(_nums){}
};

queue<State> qu;

bool mark[105][105][105];

void AToB(int &a, int sa, int & b, int sb)
{
    if(a > sb - b)
    {
        a -= sb - b;
        b = sb;
    }
    else
    {
        b += a;
        a = 0;
    }
}

bool check(int a, int b, int c)
{
    
    if(a == s/2 && b == s/2)
        return true;
    
    if(a == s/2 && c == s/2)
        return true;
    
    if(c == s/2 && b == s/2)
        return true;
    
    return false;
}

int bfs(int s, int n, int m)
{
    while(!qu.empty())
    {
        State st = qu.front();
        qu.pop();
        
        int av, bv, cv, nums;
        
        av = st.sv;
        bv = st.nv;
        cv = st.mv;
        
        AToB(av, s, bv, n);
        
        nums = st.nums + 1;
        
        if(mark[av][bv][cv] == false)
        {
            mark[av][bv][cv] = true;
            
            if(check(av, bv, cv))
                return nums;
            
            qu.push(State(av, bv, cv, nums));
        }
        
        
        av = st.sv;
        bv = st.nv;
        cv = st.mv;
        
        AToB(bv, n, av, s);
        
        nums = st.nums + 1;
        
        if(mark[av][bv][cv] == false)
        {
            mark[av][bv][cv] = true;
            
            if(check(av, bv, cv))
                return nums;
            
            qu.push(State(av, bv, cv, nums));
        }
        
        av = st.sv;
        bv = st.nv;
        cv = st.mv;
        
        AToB(av, s, cv, m);
        
        nums = st.nums + 1;
        
        if(mark[av][bv][cv] == false)
        {
            mark[av][bv][cv] = true;
            
            if(check(av, bv, cv))
                return nums;
            
            qu.push(State(av, bv, cv, nums));
        }
        
        av = st.sv;
        bv = st.nv;
        cv = st.mv;
        
        AToB(cv, m, av, s);
        
        nums = st.nums + 1;
        
        if(mark[av][bv][cv] == false)
        {
            mark[av][bv][cv] = true;
            
            if(check(av, bv, cv))
                return nums;
            
            qu.push(State(av, bv, cv, nums));
        }
        
        av = st.sv;
        bv = st.nv;
        cv = st.mv;
        
        AToB(bv, n, cv, m);
        
        nums = st.nums + 1;
        
        if(mark[av][bv][cv] == false)
        {
            mark[av][bv][cv] = true;
            
            if(check(av, bv, cv))
                return nums;
            
            qu.push(State(av, bv, cv, nums));
        }
        
        av = st.sv;
        bv = st.nv;
        cv = st.mv;
        
        AToB(cv, m, bv, n);
        
        nums = st.nums + 1;
        
        if(mark[av][bv][cv] == false)
        {
            mark[av][bv][cv] = true;
            
            if(check(av, bv, cv))
                return nums;
            
            qu.push(State(av, bv, cv, nums));
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Review/BFS-非常可乐/BFS-非常可乐/in", "r", stdin);
    
    while(cin >> s >> n >> m && s != 0)
    {
        if(s % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        
        for(int i = 0; i < 105; ++i)
            for(int j = 0; j < 105; ++j)
                for(int k = 0; k < 105; ++k)
                    mark[i][j][k] = false;
        
        
        mark[s][0][0] = true;
        qu.push(State(s, 0, 0, 0));
        
        int res = bfs(s, n, m);
        
        if(res != -1)
            cout << res << endl;
        else
            cout << "NO" << endl;
    }
    
    
    
    return 0;
}
































