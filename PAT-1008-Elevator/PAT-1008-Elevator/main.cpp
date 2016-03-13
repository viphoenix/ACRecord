//
//  main.cpp
//  PAT-1008-Elevator
//
//  Created by 程锋 on 15/8/21.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
 
     For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
     
     Input Specification:
     
     Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.
     
     Output Specification:
     
     For each test case, print the total time on a single line.
     
     Sample Input:
     3 2 3 1
     Sample Output:
     41
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1008-Elevator/PAT-1008-Elevator/in", "r", stdin);
    
    int n;
    
    while (cin >> n && n != 0)
    {
        int * buf = (int *) malloc(sizeof(int) * (n+1));
        
        for(int i = 1; i <= n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
        }
        
        buf[0] = 0;
        int sumTime = 0, len = n;
        for(int i = 1; i <= len; ++i)
        {
            int sub = buf[i] - buf[i-1];
            if(sub > 0)
                sumTime += 6*sub;
            else if(sub < 0)
                sumTime += 4*(-sub);
           // else  //不必考虑两个连续相等的层
             //   n--;
        }
        
        cout << sumTime+n*5 << endl;
        free(buf);
    }
    
    return 0;
}
