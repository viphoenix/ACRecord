//
//  main.cpp
//  PAT-1096-ConsecutiveFactors-20
//
//  Created by 程锋 on 15/8/29.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.
 
     Input Specification:
     
     Each input file contains one test case, which gives the integer N (1<N<2^31).
     
     Output Specification:
     
     For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.
     
     Sample Input:
     630
     Sample Output:
     3
     5*6*7
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1096-ConsecutiveFactors-20/PAT-1096-ConsecutiveFactors-20/in", "r", stdin);
    
    int n;
    
    while(cin >> n)
    {
        int max = 0;
        int pos;
        int cnt = 0;
        
        for(int i = 2; i <= sqrt(n); ++i)
        {
            int j = i;
            int arg = n;
            while(!(arg % j))
            {
                cnt++;
                arg /= j;
                j++;
            }
            
            if(cnt > max)
            {
                pos = i;
                max = cnt;
            }
            
            cnt = 0;
        }
        if(max == 0)
        {
            cout << "1" << endl << n;
            return 0;
        }
        cout << max << endl << pos;
        for(int i = 1; i < max; ++i)
            cout << "*" << pos+i;
    }
    
    
    return 0;
}
