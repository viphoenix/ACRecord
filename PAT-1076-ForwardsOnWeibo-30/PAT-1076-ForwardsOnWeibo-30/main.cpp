//
//  main.cpp
//  PAT-1076-ForwardsOnWeibo-30
//
//  Created by 程锋 on 15/9/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:
     
     M[i] user_list[i]
     
     where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.
     
     Then finally a positive K is given, followed by K UserID's for query.
     
     Output Specification:
     
     For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.
     
     Sample Input:
     7 3
     3 2 3 4
     0
     2 5 6
     2 3 1
     2 3 4
     1 4
     1 5
     2 2 6
     Sample Output:
     4
     5
 
    注意回路，标记访问过的结点
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define N 1005

using namespace std;

vector<int> user[N];
queue<int> q;
bool mark[N];

int n, l, k;

int level = 0;
int levelNum = 1;
int sum = 0;

void getForwards(int root)
{
    q.push(root);
    mark[root] = true;
    
    while(!q.empty())
    {
        int cnt = 0;
        
        for(int i = 0; i < levelNum; ++i)
        {
            int node = q.front();
            
            q.pop();
            
            for(int j = 0; j < (int)user[node].size(); ++j)
            {
                if(!mark[user[node][j]])
                {
                    q.push(user[node][j]);
                    
                    mark[user[node][j]] = true;
                    cnt++;
                }
            }
            
            //cnt += user[node].size();
        }
        
        levelNum = cnt; // 下一层的节点数
        
        sum += levelNum;
        
        level++; // 下一层所在的level
        
        if(level == l)
            break;
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1076-ForwardsOnWeibo-30/PAT-1076-ForwardsOnWeibo-30/in", "r", stdin);
    
    while(cin >> n >> l)
    {
        while(!q.empty())
            q.pop();
        
        for(int i = 0; i < N; ++i)
        {
            user[i].clear();
        }
        
        for(int i = 1; i <= n; ++i)
        {
            int k, t;
            cin >> k;
            while(k--)
            {
                cin >> t;
                user[t].push_back(i);
            }
        }
        
        cin >> k;
        while(k--)
        {
            int query;
            cin >> query;
            
            /**
             *  注意初始化
             */
            
            memset(mark, false, N);
            while(!q.empty())
                q.pop();
            
            level = 0;
            levelNum = 1;
            sum = 0;
            
            getForwards(query);
            
            cout << sum << endl;
        }
    }
    
    
    
    
    return 0;
}






















