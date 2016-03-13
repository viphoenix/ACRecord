//
//  main.cpp
//  PAT-1094-TheLargestGeneration-25
//
//  Created by 程锋 on 15/8/29.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.
 
     Input Specification:
     
     Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:
     
     ID K ID[1] ID[2] ... ID[K]
     
     where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.
     
     Sample Input:
     23 13
     21 1 23
     01 4 03 02 04 05
     03 3 06 07 08
     06 2 12 13
     13 1 21
     08 2 15 16
     02 2 09 10
     11 2 19 20
     17 1 22
     05 1 11
     07 1 14
     09 1 17
     10 1 18
     Sample Output:
     9 4
 
    简单层次遍历，注意1个结点的情况
     
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> node[105];
queue<int> q;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1094-TheLargestGeneration-25/PAT-1094-TheLargestGeneration-25/in", "r", stdin);
    
    int n, m;
    
    while(cin >> n >> m)
    {
        for(int i = 0; i < 105; ++i)
             if(!node[i].empty())
                node[i].clear();
        while(!q.empty())
            q.pop();
        
        while(m--)
        {
            int no, size;
            cin >> no >> size;
            
            while(size--)
            {
                int tmp;
                cin >> tmp;
                node[no].push_back(tmp);
            }
        }
        
        q.push(1);
        
        int cnt = 1;
        int level = 1;
        int max = 1;        //一个结点输出1
        int maxLevel = 1;  //一个结点输出1
        
        while(!q.empty())
        {
            int sum = 0;
            while(cnt--)
            {
                int front = q.front();
                q.pop();
                for(int i = 0; i < node[front].size(); ++i)
                    q.push(node[front][i]);
                
                sum += node[front].size();
            }
            
            level++;
            
            if(sum > max)
            {
                max = sum;
                maxLevel = level;
            }
            
            cnt = sum;
            
        }
        
        cout << max << " " << maxLevel;
        
    }
    
    return 0;
}




















