//
//  main.c
//  PAT-1097-DeduplicationOnALinkedList-25
//
//  Created by 程锋 on 15/8/27.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 10^5) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
     
     Then N lines follow, each describes a node in the format:
     
     Address Key Next
     
     where Address is the position of the node, Key is an integer of which absolute value is no more than 10^4, and Next is the position of the next node.
     
     Output Specification:
     
     For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.
     
     Sample Input:
     00100 5
     99999 -7 87654
     23854 -15 00000
     87654 15 -1
     00000 -15 99999
     00100 21 23854
     Sample Output:
     00100 21 23854
     23854 -15 99999
     99999 -7 -1
     00000 -15 87654
     87654 15 -1
 
    坑：可能会有多余的结点

 */


#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int address, key, next;
};

vector<Node> node(100005);
vector<int> cnt(10005, 0);
vector<Node> sourceList;
vector<Node> deleteList;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1097-DeduplicationOnALinkedList-25/PAT-1097-DeduplicationOnALinkedList-25/in", "r", stdin);
    
    int start, n;
    
    while(cin >> start >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            Node tmp;
            scanf("%d%d%d", &tmp.address, &tmp.key, &tmp.next);
            node[tmp.address] = tmp;
        }
        
        int pos = start;
        while(pos != -1)
        {
            if(cnt[abs(node[pos].key)] == 0)
                sourceList.push_back(node[pos]);
            else
                deleteList.push_back(node[pos]);
            
            cnt[abs(node[pos].key)] = 1;
            
            pos = node[pos].next;
        }

        for(int i = 0; i < sourceList.size(); ++i)
        {
            if(i != (int)sourceList.size()-1)
                printf("%05d %d %05d\n", sourceList[i].address, sourceList[i].key, sourceList[i+1].address);
            else
                printf("%05d %d %d\n", sourceList[i].address, sourceList[i].key, -1);
        }
        
        for(int i = 0; i < deleteList.size(); ++i)
        {
            if(i != (int)deleteList.size()-1)
                printf("%05d %d %05d\n", deleteList[i].address, deleteList[i].key, deleteList[i+1].address);
            else
                printf("%05d %d %d\n", deleteList[i].address, deleteList[i].key, -1);
        }
        
    }

    return 0;
}









