//
//  main.cpp
//  二叉排序树
//
//  Created by 程锋 on 15/8/3.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    Node * lchild;
    Node * rchild;
    int value;
}Tree[101];

void preOrder(Node * root);
void inOrder(Node * root);
void postOrder(Node * root);

int loc = 0;

Node * create()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

Node * buildTree(Node * root, int x)
{
    if(root == NULL)
    {
        root = create();
        root->value = x;
    }
    else
    {
        if(x > root->value)
            root->rchild = buildTree(root->rchild, x);
        else if(x < root->value)
            root->lchild = buildTree(root->lchild, x);
    }
    
    return root;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/二叉排序树/二叉排序树/in", "r", stdin);
    
    int n;
    
    while(cin >> n)
    {
        int tmp;
        Node * root = NULL;
        for(int i = 0; i < n; ++i)
        {
            cin >> tmp;
            root = buildTree(root, tmp);
        }
        
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
    }
    
    return 0;
}

void preOrder(Node * root)
{
    if(root != NULL)
    {
        cout << root->value << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
    
}

void inOrder(Node * root)
{
    if(root != NULL)
    {
        inOrder(root->lchild);
        cout << root->value << " ";
        inOrder(root->rchild);
    }
    
}

void postOrder(Node * root)
{
    if(root != NULL)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        cout << root->value << " ";
    }
    
}







