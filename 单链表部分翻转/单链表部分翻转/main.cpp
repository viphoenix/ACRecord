//
//  main.cpp
//  单链表部分翻转
//
//  Created by 程锋 on 15/7/29.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;


struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

/*

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        while(head == NULL || head->next == NULL || m == n)
            return head;
        
        int num = n - m + 1;
        int pos = 0;
        ListNode * result = 0, * curNode = head, *preNode, *tailNode, *tmpNode;
        while(curNode)
        {
            pos++;
            if(pos == m)
            {
                preNode = curNode;
                tailNode = curNode;
                for(int i = 0; i < num; ++i)
                {
                    tmpNode = curNode->next;
                    curNode->next = result;
                    result = curNode;
                    curNode = tmpNode;
                }
                preNode = result;
                tailNode->next = curNode;
                break;
            }
            curNode = curNode->next;
        }
        return head;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/单链表部分翻转/单链表部分翻转/in", "r", stdin);
    
    int len, start, end;
    int tmp;
    
    while (cin >> len) {
        ListNode * head = (ListNode *)malloc(sizeof(ListNode));
        ListNode * p = head;
        for(int i = 0; i < len; ++i)
        {
            cin >> tmp;
            cout << tmp << endl;
            ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
            newNode->val = tmp;
            newNode->next = NULL;
            p = newNode;
            p = newNode->next;
        }
        
        while(p)
        {
            cout << p->val;
            p = p->next;
        }
        cin >> start >> end;
        
        
    }
    
    
    return 0;
}
