//
//  main.cpp
//  PAT-1101-QuickSort-25
//
//  Created by 程锋 on 15/9/14.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?
 
     For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:
     
     1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
     3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
     2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
     and for the similar reason, 4 and 5 could also be the pivot.
     Hence in total there are 3 pivot candidates.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line gives a positive integer N (<= 105). Then the next line contains N distinct positive integers no larger than 109. The numbers in a line are separated by spaces.
     
     Output Specification:
     
     For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.
     
     Sample Input:
     5
     1 3 2 4 5
     Sample Output:
     3
     1 4 5
 */

#include <iostream>
#include <algorithm>
#define N 100005
#define INF 0x7fffffff
#include <vector>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1101-QuickSort-25/PAT-1101-QuickSort-25/in", "r", stdin);
    
    int buf[N];
    int dp1[N], dp2[N];
    bool mark[N];
    
    int n;
    
    vector<int> res;
    
    while(cin >> n)
    {
        for(int i = 1; i <= n; ++i)
        {
            int t;
            cin >> t;
            buf[i] = t;
            
            dp1[i] = dp2[i] = t;
            mark[i] = false;
        }
        
        dp1[0] = 0;
        dp2[n+1] = INF;
        
        for(int i = 1; i <= n; ++i)
            dp1[i] = max(dp1[i], dp1[i-1]);
        
        for(int i = n; i >= 1; --i)
            dp2[i] = min(dp2[i], dp2[i+1]);
        
        int cnt = 0;
        res.clear();
        for(int i = 1; i <= n; ++i)
            if(buf[i] > dp1[i-1] && buf[i] < dp2[i+1])
            {
                cnt++;
                mark[i] = true;
                res.push_back(buf[i]);
            }
        
        if(res.size() == 0)
        {
            cout << "0";
            return 0;
        }
        
        sort(res.begin(), res.end());
        
        
        cout << res.size() << endl;
        
        for(int i = 0; i < (int)res.size(); ++i)
        {
            if(i == 0)
                cout << res[i];
            else
                cout << " " << res[i];
        }
        
                
    }
    
    return 0;
}




















