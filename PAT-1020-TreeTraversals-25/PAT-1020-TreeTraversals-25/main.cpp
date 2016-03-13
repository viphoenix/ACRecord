//
//  main.cpp
//  PAT-1020-TreeTraversals-25
//
//  Created by 程锋 on 15/8/30.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
     
     Sample Input:
     7
     2 3 1 5 7 6 4
     1 2 3 4 5 6 7
     Sample Output:
     4 1 6 3 5 7 2
 */

#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
}tree[32];

int postorder[32];
int inorder[32];

int size = 0;

queue<Node *> q;

Node * create()
{
    //tree[size].left = tree[size].right = NULL;
    Node * node = new Node();
    node->left = node->right = NULL;
    
    return node;
}

Node * buildTree(int * a, int s1, int e1, int * b, int s2, int e2)
{
    Node * root = create();
    
    root->value = a[e1];
    
    int rootIndex;
    for(int i = s2; i <= e2; ++i)
        if(b[i] == a[e1])
        {
            rootIndex = i;
            break;
        }
    
    if(rootIndex != s2)      //重点
        root->left = buildTree(a, s1, s1 + (rootIndex-s2) -1, b, s2, rootIndex-1);
    if(rootIndex != e2)
        root->right = buildTree(a, e1 - (e2-rootIndex), e1-1, b, rootIndex+1, e2);

    return root;
}

void levelTraversal(Node * root)
{
    while(!q.empty())
        q.pop();
    
    q.push(root);
    cout << root->value;
    while(!q.empty())
    {
        Node * fr = q.front();
        q.pop();
        
        if(fr->left != NULL)
        {
            q.push(fr->left);
            cout << " " << fr->left->value;
        }
        
        if(fr->right != NULL)
        {
            q.push(fr->right);
            cout << " " << fr->right->value;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1020-TreeTraversals-25/PAT-1020-TreeTraversals-25/in", "r", stdin);
    
    int n;
    
    while(cin >> n)
    {
        int tmp;
        for(int i = 1; i <= n; ++i)
        {
            cin >> tmp;
            postorder[i] = tmp;
        }
        
        
        for(int i = 1; i <= n; ++i)
        {
            cin >> tmp;
            inorder[i] = tmp;
        }
    }
    
    Node * root = buildTree(postorder, 1, n, inorder, 1, n);
    
    levelTraversal(root);
    
    
    
    return 0;
}



























