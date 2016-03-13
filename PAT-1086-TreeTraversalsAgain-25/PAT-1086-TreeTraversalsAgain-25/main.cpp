//
//  main.cpp
//  PAT-1086-TreeTraversalsAgain-25
//
//  Created by 程锋 on 15/9/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    Node * left;
    Node * right;
    int value;
    
    Node(int v):value(v),left(NULL),right(NULL){}
};

int n;
int cnt = 0;
int size = 0;

Node * build()
{
    Node * root = NULL;
    
    
    string input;
    int v;
    
    if(cnt < 2*n)
    {
        cin >> input;
        if(input[1] == 'u')
        {
            cin >> v;
            root = new Node(v);
            cnt ++;
        }
        else if(input[1] == 'o')
        {
            cnt++;
            return NULL;
        }
        
        root->left = build();
        root->right = build();
    }
    
    return root;
}

void postOrder(Node * root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        if(size == 0)
            cout << root->value;
        else
            cout << " " << root->value;
        
        size++;
       
    }
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1086-TreeTraversalsAgain-25/PAT-1086-TreeTraversalsAgain-25/in", "r", stdin);
    
   // while(cin >> n)
//    {
        cin >> n;
        
        Node * root = build();
        
        postOrder(root);
//    }
    
    
    return 0;
}





















