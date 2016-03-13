//
//  main.cpp
//  PAT-1098-InsertionOrHeapSort
//
//  Created by 程锋 on 15/8/28.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  According to Wikipedia:
 
     Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
     
     Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.
     
     Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
     
     Sample Input 1:
     10
     3 1 2 8 7 5 9 4 6 0
     1 2 3 7 8 5 9 4 6 0
     Sample Output 1:
     Insertion Sort
     1 2 3 5 7 8 9 4 6 0
     Sample Input 2:
     10
     3 1 2 8 7 5 9 4 6 0
     6 4 5 1 0 3 2 7 8 9
     Sample Output 2:
     Heap Sort
     5 4 3 1 0 2 6 7 8 9
     
 */

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int src[105];
int ans[105];
int temp[100];

int n;
int flag;

bool isEqual(int a[], int b[])
{
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] != b[i])
            return false;
    }
    
    return true;
}

void print(int a[])
{
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1)
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}

bool isInsertion()
{
    flag = 0;
    for(int i = 2; i <= n; ++i)
    {
        if(flag && !isEqual(temp, ans))
        {
            printf("Insertion Sort\n");
            print(temp);
            return true;
        }
            
        sort(temp+1, temp+i+1);
        if(isEqual(temp, ans))
            flag = 1;
    }
    
    return false;
}

bool isHeap()
{
    flag = 0;
    for(int i = n; i >= 2; --i)
    {
        if(flag && !isEqual(src, ans))
        {
            printf("Heap Sort\n");
            print(src);
            return true;
        }
        
        //生成大顶堆  生成小顶堆make_heap(src+1, src+i+1, greater<int>());
        make_heap(src+1, src+i+1);
        
        //最大值和最后一个数对调
        pop_heap(src+1, src+i+1);
        
        if(isEqual(src, ans))
            flag = 1;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1098-InsertionOrHeapSort/PAT-1098-InsertionOrHeapSort/in", "r", stdin);
    
    
    while (scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &src[i]);
            temp[i] = src[i];
        }
        
        for(int i = 1; i <= n; ++i)
            scanf("%d", &ans[i]);
        
        if(!isInsertion())
            isHeap();
        
        
    }
    
    
    return 0;
}

























