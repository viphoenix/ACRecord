//
//  main.cpp
//  PAT-1017-QueueingAtBank-25
//
//  Created by 程锋 on 15/9/6.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.
 
     Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.
     
     Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.
     
     Output Specification:
     
     For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.
     
     Sample Input:
     7 3
     07:55:00 16
     17:00:01 2
     07:59:59 15
     08:01:00 60
     08:00:00 30
     08:00:02 2
     08:03:00 10
     Sample Output:
     8.2
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 10005
#define K 105
#define MAX 17*3600
#define INF 0x7fffffff

using namespace std;

struct Customer{
    int start;
    int wait;
    int interval;
    bool flag;
    
    bool operator < (const Customer & b) const
    {
        return start < b.start;
    }
};

vector<Customer> cust;

int serv[K];  //每个窗口下次提供服务的时间

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1017-QueueingAtBank-25/PAT-1017-QueueingAtBank-25/in", "r", stdin);
    
    int n, k;
    
    while(scanf("%d%d", &n, &k) != EOF)
    {
        for(int i = 0; i < k; ++i)
            serv[i] = 8*3600;
        
        for(int i = 0; i < n; ++i)
        {
            int start, hh, mm, ss, interval;
            Customer tmp;
            scanf("%d:%d:%d%d", &hh, &mm, &ss, &interval);
            
            start = hh*3600+mm*60+ss;
            if(start >= MAX)
                continue;
            
            tmp.start = hh*3600+mm*60+ss;
            tmp.interval = interval > 60 ? 60 : interval;
            cust.push_back(tmp);
            
        }
        
        sort(cust.begin(), cust.end());
        
        for(int i = 0; i < cust.size(); ++i)
        {
            if(k > 1)
                sort(serv, serv+k);  //优先选择最先提供服务的窗口
            
            
            if(serv[0] >= MAX)    //没有等到服务
            {
                if(cust[i].start < MAX)
                    cust[i].wait = MAX - cust[i].start;
            }
            
            if(cust[i].start >= serv[0])
            {
                cust[i].wait = 0;
                serv[0] = cust[i].start + cust[i].interval*60;      // bug，注意
            }
            else
            {
                cust[i].wait = serv[0] - cust[i].start;
                serv[0] += cust[i].interval*60;
            }
            
            
        }
        
        int sum = 0;
        for(int i = 0; i < cust.size(); ++i)
        {
            sum += cust[i].wait;
            //printf("%d %d %d\n", cust[i].start, cust[i].interval, cust[i].wait);
        }
        
        printf("%.1f", (float)sum/60.0/(float)cust.size());
    
    }
    
    
    
    return 0;
}



















