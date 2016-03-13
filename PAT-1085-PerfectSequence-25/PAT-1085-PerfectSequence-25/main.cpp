//
//  main.cpp
//  PAT-1085-PerfectSequence-25
//
//  Created by 程锋 on 15/9/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.
 
     Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 105) is the number of integers in the sequence, and p (<= 109) is the parameter. In the second line there are N positive integers, each is no greater than 109.
     
     Output Specification:
     
     For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.
     
     Sample Input:
     10 8
     2 3 20 4 5 1 6 7 8 9
     Sample Output:
     8
 */

#include <iostream>
#include <cstdlib>
#define N 100005

int cmp(const void * a, const void * b)
{
    long int * ta = (long int *)a;
    long int * tb = (long int *)b;
    
    return (int)((*ta) - (*tb));
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1085-PerfectSequence-25/PAT-1085-PerfectSequence-25/in", "r", stdin);
    
    int n, p;
    long int a[N];
    
    while(scanf("%d%d", &n, &p) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%ld", &a[i]);
        
        qsort(a, n, sizeof(long int), cmp);
        
        /*
        for(int i = 0; i < n; ++i)
            printf("%ld ", a[i]);
        printf("\n");
        */
        
        int max = 0;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + max; j < n; ++j)
            {
                long int tmp = a[i] * p;
                if(a[j] > tmp)
                    break;
                
                if(max < j - i + 1)
                    max = j - i + 1;
            }
        }
        
        printf("%d", max);
    }
    
    return 0;
}


























