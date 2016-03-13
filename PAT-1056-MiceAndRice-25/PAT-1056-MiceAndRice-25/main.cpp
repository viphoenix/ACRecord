//
//  main.cpp
//  PAT-1056-MiceAndRice-25
//
//  Created by 程锋 on 15/9/7.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.
 
     First the playing order is randomly decided for NP programmers. Then every NG programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every NG winners are then grouped in the next match until a final winner is determined.
     
     For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 2 positive integers: NP and NG (<= 1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than NG mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) where each Wi is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1). All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.
     
     Sample Input:
     11 3
     25 18 0 46 37 3 19 22 57 56 10
     6 0 8 7 10 5 9 1 4 2 3
     Sample Output:
     5 5 5 2 5 5 5 3 1 3 5
 */
#include <cstdio>
#include <queue>
using namespace std;
#define MAX 1001
int w[MAX];
int ans[MAX];

int main(){
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1056-MiceAndRice-25/PAT-1056-MiceAndRice-25/in", "r", stdin);
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    
    queue<int> order;
    int x;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        order.push(x);
    }
    while (order.size() != 1)
    {
        queue<int> tmp;
        
        int groupNum = (int)order.size() / m + ((int)order.size()%m == 0 ? 0:1);
        
        for (int i = 0; i < groupNum; i++)
        {
            int max = -1, maxIndex = -1;
            
            for (int j = i*m; j < i*m + m && order.size() != 0; j++)
            {
                int t = order.front();
                
                ans[t] = groupNum + 1;
                order.pop();
                
                if (w[t] > max)
                {
                    max = w[t];
                    maxIndex = t;
                }
            }
            
            tmp.push(maxIndex);
        }
        
        order = tmp;
        
    }
    ans[order.front()] = 1;
    
    for (int i = 0; i < n; i++)
        printf("%d%c", ans[i], (i-n+1? ' ': '\n'));
    
    
    return 0;
}
























