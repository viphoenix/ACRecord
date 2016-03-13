//
//  main.cpp
//  PAT-1067-SortWithSwap(0,*)-25
//
//  Created by 程锋 on 15/9/2.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:
 
     Swap(0, 1) => {4, 1, 2, 0, 3}
     Swap(0, 3) => {4, 1, 2, 3, 0}
     Swap(0, 4) => {0, 1, 2, 3, 4}
     
     Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.
     
     Input Specification:
     
     Each input file contains one test case, which gives a positive N (<=10^5) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each case, simply print in a line the minimum number of swaps need to sort the given permutation.
     
     Sample Input:
     10 3 5 7 2 6 4 9 0 8 1
     Sample Output:
     9
 */

#include <iostream>
#define N 100005

using namespace std;

int a[N];

int findPos(int a[], int start, int end)
{
    for(int i = start; i < end; ++i)
        if(a[i] != i)
            return i;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1067-SortWithSwap(0,*)-25/PAT-1067-SortWithSwap(0,*)-25/in", "r", stdin);
    
    int n;
    
    while(scanf("%d", &n) != EOF)
    {
        if(n == 1)
            printf("0");
        for(int i = 0; i < n; ++i)
        {
            int t;
            scanf("%d", &t);
            a[t] = i;
        }
        
        int cnt = 0;
        int first = findPos(a, 1, n);
        
        while (first)
        {
            if(a[0] == 0)
            {
                a[0] = a[first];
                a[first] = 0;
                cnt++;
            }
            
            while(a[0] != 0)
            {
                int tmp = a[0];
                a[0] = a[tmp];
                a[tmp] = tmp;
                cnt++;
            }
            
            first = findPos(a, first, n);
        }
        
        
        printf("%d", cnt);
    }
    
    return 0;
}


































