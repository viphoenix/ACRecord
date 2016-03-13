//
//  main.c
//  PAT-1099-BuildABinarySearchTree
//
//  Created by 程锋 on 15/8/28.
//  Copyright (c) 2015年 程锋. All rights reserved.
//


/**
 *  利用二叉搜索树中序遍历的特点
 */
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int value;
    int left;
    int right;
};

vector<Node> node(105);
vector<int> num(105);
queue<Node> q;

void inOrder(int root, int & index)
{
    if(root != -1)
    {
        inOrder(node[root].left, index);
        node[root].value = num[index++];
        inOrder(node[root].right, index);
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1099-BuildABinarySearchTree/PAT-1099-BuildABinarySearchTree/in", "r", stdin);
    
    int n;
    
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &node[i].left, &node[i].right);
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &num[i]);
        
        sort(num.begin(), num.begin() + n);

        int index = 0;
        inOrder(0, index);
        
        
        while(!q.empty())
            q.pop();
        
        q.push(node[0]);
        
        int cnt = 0;
        while(!q.empty())
        {
            Node front = q.front();
            if(cnt == 0)
                printf("%d", front.value);
            else
                printf(" %d", front.value);
            cnt++;
            
            q.pop();
            
            int left = front.left;
            int right = front.right;
            
            if(left != -1)
                q.push(node[left]);
            if(right != -1)
                q.push(node[right]);
        }
        
        
    }
    
    return 0;
}












