//
//  main.cpp
//  RootOfAVLTree
//
//  Created by 程锋 on 15/9/12.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

struct Node{
    Node * left;
    Node * right;
    int value;
    int height; //左右高度最大值
    
    Node(int _value):left(NULL), right(NULL), value(_value){}
};

int getHeight(Node * root)
{
    if(root == NULL)
        return 0;
    else
        return root->height;
}

bool isBalanced(Node * root)
{
    return abs(getHeight(root->left) - getHeight(root->right)) < 2;
}

Node * rotateLL(Node * parent)
{
    Node * left = parent->left;
    parent->left = left->right;
    left->right = parent;
    
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;  //先更新这个节点的高度
    left->height = max(getHeight(left->left), getHeight(left->right)) + 1;
    
    return left;
}

Node * rotateRR(Node * parent)
{
    Node * right = parent->right;
    parent->right = right->left;
    right->left = parent;
    
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;  //先更新这个节点的高度
    right->height = max(getHeight(right->left), getHeight(right->right)) + 1;
    
    return right;
}

Node * rotateLR(Node * parent)
{
    Node * left = parent->left;
    parent->left = rotateRR(left);
    
    return rotateLL(parent);
}

Node * rotateRL(Node * parent)
{
    Node * right = parent->right;
    parent->right = rotateLL(right);
    
    return rotateRR(parent);
}

Node * build(Node * parent, int value)
{
    if(parent == NULL)
        parent = new Node(value);
    else
    {
        if(value < parent->value)
        {
            parent->left = build(parent->left, value);
            
            if(!isBalanced(parent))
            {
                if(value < parent->left->value)
                    parent = rotateLL(parent);
                else
                    parent = rotateLR(parent);
            }
        }
        else
        {
            parent->right = build(parent->right, value);
            
            if(!isBalanced(parent))
            {
                if(value >= parent->right->value)
                    parent = rotateRR(parent);
                else
                    parent = rotateRL(parent);
            }
        }
    }
    
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    
    return parent;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/Review/RootOfAVLTree/RootOfAVLTree/in", "r", stdin);
    
    int n;
    while(cin >> n)
    {
        Node * root = NULL;
        
        while(n--)
        {
            int v;
            cin >> v;
            
            root = build(root, v);
        }
        
        
        cout << root->value;

    }
    
    return 0;
}

























