//
//  main.cpp
//  PAT-1074-ReversingLinkedList-25
//
//  Created by 程锋 on 15/8/31.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 10^5) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
     
     Then N lines follow, each describes a node in the format:
     
     Address Data Next
     
     where Address is the position of the node, Data is an integer, and Next is the position of the next node.
     
     Output Specification:
     
     For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
     
     Sample Input:
     00100 6 4
     00000 4 99999
     00100 1 12309
     68237 6 -1
     33218 3 00000
     99999 5 68237
     12309 2 33218
     Sample Output:
     00000 4 33218
     33218 3 12309
     12309 2 00100
     00100 1 99999
     99999 5 68237
     68237 6 -1
 
    陷阱： 可能存在多个单链表
 */

#include <iostream>
#include <vector>
#include <fstream>
#define N 100005
#include <iomanip>

using namespace std;

struct Node{
    int address;
    int value;
    int next;
};

//vector<Node> source(N), output(N);
Node source[N], output[N];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1074-ReversingLinkedList-25/PAT-1074-ReversingLinkedList-25/in", "r", stdin);
    
    int start, n, k;
    
    while(scanf("%d%d%d", &start, &n, &k) != EOF)
    {
        
        for(int i = 0; i < n; ++i)
        {
            Node tmp;

            scanf("%d%d%d", &tmp.address, &tmp.value, &tmp.next);
            
            source[tmp.address] = tmp;
        }
        
        Node p = source[start];
        int size = k-1;
        int cnt = k;
        
        int i;
        for(i = 2; i <= n; ++i)
        {
            if(p.next == -1)
                break;
            p = source[p.next];
        }
        
        if(i < n+1)
        {
            n = i - 1;
        }
        
        //cout << n << endl;
        
        p = source[start];
        
        for(int i = 1; i <= n / k; ++i)
        {
            
            
            while(cnt--)
            {
                output[size--] = p;
                
                p = source[p.next];
            }
            
            cnt = k;
            size = (i+1)*k-1;
        }
        
        size = (n/k)*k;
        int nums = n % k;
        
        while (nums--)
        {
            output[size++] = p;
            p = source[p.next];
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(i != n - 1)
                printf("%05d %d %05d\n", output[i].address, output[i].value, output[i+1].address);
            else
                printf("%05d %d %d\n", output[i].address, output[i].value, -1);
        }
        
    }
    
    
    return 0;
}























