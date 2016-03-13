//
//  main.cpp
//  PAT-1066-RootOfAVLTree-25
//
//  Created by 程锋 on 15/8/31.
//  Copyright (c) 2015年 程锋. All rights reserved.
//  修改的是距离插入结点最近的不平衡结点为根的子树，利用递归回溯得到这个根节点

#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    int height;   //左子树和右子树高度最大值
    
    Node(int v):value(v),left(NULL),right(NULL),height(0){}
};

int getNodeHeight(Node * root)
{
    if(root == NULL)
        return 0;
    else
        return root->height;
}

Node * rotate_LL(Node * parent)
{
    Node * leftChild = parent->left;
    parent->left = leftChild->right;
    leftChild->right = parent;
    
    parent->height = max(getNodeHeight(parent->left), getNodeHeight(parent->right)) + 1;
    leftChild->height = max(getNodeHeight(leftChild->left), getNodeHeight(leftChild->right)) + 1;
    
    return leftChild;
}

Node * rotate_RR(Node * parent)
{
    Node * rightChild = parent->right;
    parent->right = rightChild->left;
    rightChild->left = parent;
    
    parent->height = max(getNodeHeight(parent->left), getNodeHeight(parent->right)) + 1;
    rightChild->height = max(getNodeHeight(rightChild->left), getNodeHeight(rightChild->right)) + 1;
    
    return rightChild;
}

Node * rotate_LR(Node * parent)
{
    Node * leftChild = parent->left;
    parent->left = rotate_RR(leftChild);
    
    return rotate_LL(parent);
}

Node * rotate_RL(Node * parent)
{
    Node * rightChild = parent->right;
    parent->right = rotate_LL(rightChild);
    
    return rotate_RR(parent);
}


bool isBalanced(Node * root)
{
    return abs(getNodeHeight(root->left) - getNodeHeight(root->right)) < 2;
}

Node * insertNode(Node * parent, int v)
{
    if(parent != NULL)
    {
        if(v < parent->value)
        {
            parent->left = insertNode(parent->left, v);
            if(!isBalanced(parent))
            {
                if(v < parent->left->value)
                    parent = rotate_LL(parent);
                else if(v > parent->left->value)
                    parent = rotate_LR(parent);
                    
            }
        }
        else if(v > parent->value)
        {
            parent->right = insertNode(parent->right, v);
            if(!isBalanced(parent))
            {
                if(v < parent->right->value)
                    parent = rotate_RL(parent);
                else if(v > parent->right->value)
                    parent = rotate_RR(parent);
                
            }
        }
            
    }
    else
        parent = new Node(v);
    
    parent->height = max(getNodeHeight(parent->left), getNodeHeight(parent->right)) + 1;   //注意
    
    return parent;
}

int main(int argc, const char * argv[]) {
    
    ifstream cin("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1066-RootOfAVLTree-25/PAT-1066-RootOfAVLTree-25/in");
    
    int n;
    
    while(cin >> n)
    {
        Node * root = NULL;
        
        while(n--)
        {
            int v;
            cin >> v;
            root = insertNode(root, v);
        }
        
        cout << root->value;
        
    }
    
    
    return 0;
}
