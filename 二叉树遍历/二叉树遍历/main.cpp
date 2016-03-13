//
//  main.cpp
//  二叉树遍历
//
//  Created by 程锋 on 15/8/3.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct Node{
    Node * lchild;
    Node * rchild;
    char value;
}Tree[50];

int loc;
Node * create()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

Node * buildTree(string preStr, string inStr, int preStart, int preEnd, int inStart, int inEnd)
{
    Node * ret = create();
    ret->value = preStr[preStart];
    
    int rootIndex;
    
    for(int i = inStart; i <= inEnd; ++i)
    {
        if(inStr[i] == preStr[preStart])
        {
            rootIndex = i;

            break;
        }
    }
    
    if(rootIndex != inStart)
        ret->lchild = buildTree(preStr, inStr, preStart+1, preStart+(rootIndex-inStart), inStart, rootIndex-1);
    if(rootIndex != inEnd)
        ret->rchild = buildTree(preStr, inStr, preStart+(rootIndex-inStart)+1, preEnd, rootIndex+1, inEnd);

    
    return ret;
    
}

void postOrder(Node * root)
{
    if(root->lchild != NULL)
        postOrder(root->lchild);
    if(root->rchild != NULL)
        postOrder(root->rchild);
    cout << root->value;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/二叉树遍历/二叉树遍历/in", "r", stdin);
    
    string preStr, inStr;
    while(cin >> preStr)
    {
        cin >> inStr;
        
        loc = 0;
    
        Node * root = buildTree(preStr, inStr, 0, preStr.size()-1, 0, inStr.size()-1);
        postOrder(root);
        cout << endl;
    }
    
    return 0;
}
