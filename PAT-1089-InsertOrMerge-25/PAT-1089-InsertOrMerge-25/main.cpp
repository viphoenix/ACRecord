//
//  main.cpp
//  PAT-1089-InsertOrMerge-25
//
//  Created by 程锋 on 15/9/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  According to Wikipedia:
 
     Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
     
     Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.
     
     Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
     
     Sample Input 1:
     10
     3 1 2 8 7 5 9 4 6 0
     1 2 3 7 8 5 9 4 6 0
     Sample Output 1:
     Insertion Sort
     1 2 3 5 7 8 9 4 6 0
     Sample Input 2:
     10
     3 1 2 8 7 5 9 4 0 6
     1 3 2 8 5 7 4 9 0 6
     Sample Output 2:
     Merge Sort
     1 2 3 8 4 5 7 9 0 6
 */

#include <iostream>
#include <algorithm>
#define N 105

using namespace std;

int n;

void output(int a[])
{
    cout << a[0];
    for(int i = 1; i < n; ++i)
        cout << " " << a[i];
    cout << endl;
}

bool isEqual(int a[], int b[])
{
    
    for(int i = 0; i < n; ++i)
        if(a[i] != b[i])
            return false;
    
    return true;
}

bool isInsert(int * src, int * ans)
{
    bool flag = false;
    
    for(int i = 2; i < n; ++i)
    {
        if(flag && !isEqual(src, ans))
        {
            cout << "Insertion Sort" << endl;
            output(src);
            return true;
        }
        
        sort(src, src+i);
        
        if(isEqual(src, ans))
            flag = true;
        
    }
    
    return false;
}

void merge(int * src, int step)
{
    int i = 0;
    
    while(i < n)
    {
        int start = i;
        int mid = i + step;
        int end = mid + step;
        
        mid = mid > n ? n : mid;
        end = end > n ? n : end;
        
        inplace_merge(src+start, src+mid, src+end);
        //output(src);
        i = end;
    }
}

bool isMerge(int * src, int * ans)
{
    bool flag = false;
    int step = 1;
    
    while(step < n)
    {
        
        
        merge(src, step);
        
        step *= 2;
        
        if(isEqual(src, ans))
            flag = true;
        
        if(flag && !isEqual(src, ans))
        {
            cout << "Merge Sort" << endl;
            output(src);
            return true;
        }
    }
    
    return false;
}


int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1089-InsertOrMerge-25/PAT-1089-InsertOrMerge-25/in", "r", stdin);
    
    int src[N], tmp[N], ans[N];
    
    while(cin >> n)
    {
        int t;
        
        for(int i = 0; i < n; ++i)
        {
            cin >> t;
            src[i] = t;
            tmp[i] = t;
        }
        
        for(int i = 0; i < n; ++i)
        {
            cin >> t;
            ans[i] = t;
        }
        
        if(!isInsert(tmp, ans))
            isMerge(src, ans);
        
    }
    
    
    return 0;
}




































