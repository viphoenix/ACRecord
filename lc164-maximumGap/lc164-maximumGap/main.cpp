//
//  main.cpp
//  lc164-maximumGap
//
//  Created by 程锋 on 15/8/9.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 
 *   Try to solve it in linear time/space.
 
 *   Return 0 if the array contains less than 2 elements.
 
 *   You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 *
 *   桶排序思想：
 */

#include <iostream>
#include <vector>

using namespace std;

long int max(long int a, long int b)
{
    return a > b ? a : b;
}

long int min(long int a, long int b)
{
    return a < b ? a : b;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/lc164-maximumGap/lc164-maximumGap/in", "r", stdin);
    
    long int n;
    while (cin >> n && n != 0) {
        
        if(n < 2)
            return 0;
        
        long int * buf = (long int *) malloc(sizeof(long int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
        }
        
        long int maxNum = buf[0], minNum = buf[0];
        for(int i = 0; i < n; ++i)
        {
            if(buf[i] > maxNum)
                maxNum = buf[i];
            if(buf[i] < minNum)
                minNum = buf[i];
        }
        
        //设置n+1个桶
        vector<bool> empty(n+1, true);
        //记录每个桶的最大值和最小值
        vector<long int> pmax(n+1);
        vector<long int> pmin(n+1);
        
        for(int i = 0; i < n; ++i)
        {
            long int no = (buf[i] - minNum) * (n+1) / (maxNum - minNum);
            //cout << buf[i] << " " << no << endl;
            if(no > n)
                no = n;
            if(empty[no])
            {
                empty[no] = false;
                pmax[no] = pmin[no] = buf[i];
            }
            else
            {
                pmax[no] = max(pmax[no], buf[i]);
                pmin[no] = min(pmin[no], buf[i]);
            }
                
        }
        /*
        for(int i = 0; i <= n; ++i)
            cout << pmax[i] << " " << pmin[i] << endl;
        */
        long int last = -1, res = 0;
        for(int i = 0; i <= n; ++i)
        {
            if(!empty[i])
            {
                if(last < 0)
                    last = pmax[i];
                else
                {
                    res = max(res, pmin[i] - last);
                    last = pmax[i];
                }
            }
        }
        
        cout << res << endl;
            
    }
    
    
    return 0;
}




























