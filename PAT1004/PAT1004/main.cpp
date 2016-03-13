//
//  main.c
//  PAT1004
//
//  Created by 程锋 on 15/8/20.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
     Input
     
     Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
     
     ID K ID[1] ID[2] ... ID[K]
     where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
     Output
     
     For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
     
     The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
     
     Sample Input
     2 1
     01 1 02
     Sample Output
     0 1
 
    算法思想：使用邻接表保存数结构，根据每个结点的孩子数，得到每层的结点总数，每层遍历完成，层数加1，同时，可以记录本层所有的孩子结点
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int no;
};

vector<Node> node[100];
queue<Node> qu;

//每层的叶节点数
int depth[100];
int level = 0;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT1004/PAT1004/in", "r", stdin);
    
    int n, m;
    
    while(cin >> n >> m && n != 0)
    {
        //initialize
        
        for(int i = 0; i < 100; ++i)
        {
            if(!node[i].empty())
                node[i].clear();
            depth[i] = 0;
        }
        while (!qu.empty())
            qu.pop();
            
        
        for(int i = 0; i < m; ++i)
        {
            int parent, k;
            cin >> parent >> k;
            for(int i = 0; i < k; ++i)
            {
                Node tmp;
                cin >> tmp.no;
                node[parent].push_back(tmp);
                
            }
         }
        Node root;
        root.no = 1;
        qu.push(root);
        
        //队列每层弹出的结点数
        int nums = 1;
        while (!qu.empty())
        {
            int sum = 0;
            for(int i = 0; i < nums; ++i)
            {
                Node newNode = qu.front();
                qu.pop();
                int no = newNode.no;
                
                //把所有子节点添加到队列中
                if(node[no].size() > 0)
                {
                    sum += node[no].size();
                    
                    for(int i = 0; i < node[no].size(); ++i)
                    {
                        int tmpNo = node[no][i].no;
                        Node tmpNode;
                        tmpNode.no = tmpNo;
                        qu.push(tmpNode);
                        
                    }
                }
                else
                    depth[level]++; //如果一个结点的孩子数为0，则该层的叶节点数+1
            }
            
            nums = sum;
            
            level++; //每层遍历完level增加1
            
        }
        
        for(int i = 0; i < level; ++i)
        {
            if(i == 0)
                printf("%d", depth[i]);
            else
                printf(" %d", depth[i]);
        }
     }
    
    return 0;
}














