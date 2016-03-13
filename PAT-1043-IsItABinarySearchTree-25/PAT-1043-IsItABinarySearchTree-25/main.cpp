//
//  main.cpp
//  PAT-1043-IsItABinarySearchTree-25
//
//  Created by 程锋 on 15/9/10.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
 
     The left subtree of a node contains only nodes with keys less than the node's key.
     The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
     Both the left and right subtrees must also be binary search trees.
     If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.
     
     Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
     
     Sample Input 1:
     7
     8 6 5 7 10 8 11
     Sample Output 1:
     YES
     5 7 6 8 11 10 8
     Sample Input 2:
     7
     8 10 11 8 6 7 5
     Sample Output 2:
     YES
     11 8 10 7 5 6 8
     Sample Input 3:
     7
     8 6 8 5 10 9 11
     Sample Output 3:
     NO
 */

#include <iostream>
#define N 1005

using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    
    Node(int _v):value(_v), left(NULL), right(NULL){}
};

int n, a[N];

Node * build(Node * root, int value)
{
    if(root == NULL)
    {
        root = new Node(value);
        return root;
    }
    
    else
    {
        if(value < root->value)
            root->left = build(root->left, value);
        else
            root->right = build(root->right, value);
    }
    
    return root;
}
bool flag1 = true;
bool flag2 = true;
int idx1 = 0;
int idx2 = 0;

void preorder(Node * root)
{
    if(root != NULL)
    {
        if(a[idx1] != root->value)
            flag1 = false;
        
        idx1++;
//        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }

}

void mirror_preorder(Node * root)
{
    if(root != NULL)
    {
        if(a[idx2] != root->value)
            flag2 = false;
        
        idx2++;
//        cout << root->value << " ";
        mirror_preorder(root->right);
        mirror_preorder(root->left);

    }
    
}

void postorder(Node * root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        
        if(idx1 == 0)
            printf("%d", root->value);
        else
            printf(" %d", root->value);
        idx1++;
    }
}

void mirror_postorder(Node * root)
{
    if(root != NULL)
    {
        mirror_postorder(root->right);
        mirror_postorder(root->left);
    
        if(idx2 == 0)
            printf("%d", root->value);
        else
            printf(" %d", root->value);
        idx2++;}
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1043-IsItABinarySearchTree-25/PAT-1043-IsItABinarySearchTree-25/in", "r", stdin);
    
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        
        Node * root = NULL;
        
        for(int i = 0; i < n; ++i)
            root = build(root, a[i]);
        
        preorder(root);
        mirror_preorder(root);
        
        if(flag1)
        {
            idx1 = 0;
            printf("YES\n");
            postorder(root);
        }
        else if(flag2)
        {
            idx2 = 0;
            printf("YES\n");
            mirror_postorder(root);
        }
        else
            printf("NO\n");
        
        
    }
    
    
    return 0;
}


































