//
//  main.cpp
//  PAT-1015-ReversiblePrimes
//
//  Created by 程锋 on 15/8/23.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
 
     Now given any two positive integers N (< 10^5) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.
     
     Input Specification:
     
     The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.
     
     Output Specification:
     
     For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.
     
     Sample Input:
     73 10
     23 2
     23 10
     -2
 
        注意：1不是素数，转换前后的数据都需要判断
 */

#include <iostream>
#include <string.h>

using namespace std;

int prime[100000];
bool mark[100000];

void init(int * prime)
{
    for(int i = 1; i < 100000; ++i)
    {
        prime[i] = 0;
        mark[i] = false;
    }
    //1不是素数
    mark[1] = true;
    
    int size = 0;
    
    for(int i = 2; i < 100000; ++i)
    {
        if(mark[i])
            continue;
        
        prime[size++] = i;

        for(unsigned long j = i*i; j < 100000; j+=i)
            mark[j] = true;
    }
}

int convert(int n, int radix)
{
    int size = 0;
    int res = 0;
    int weight = 1;
    char ans[100];
    
    while(n)
    {
        ans[size++] = n % radix + '0';
        n /= radix;
    }
    
    int s;
    for(int i = 0; i < size; ++i)
        if(ans[i] != '0')
        {
            s = i;
            break;
        }
    for(int i = size - 1; i >= s; --i)
    {
        res += (ans[i] - '0') * weight;
        weight *= radix;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1015-ReversiblePrimes/PAT-1015-ReversiblePrimes/in", "r", stdin);
    
    init(prime);
    
    int n, radix;
    
    while(cin >> n >> radix && n > 0)
    {
        
        if(mark[n])
        {
            cout << "No" << endl;
            continue;
        }
        
        n = convert(n, radix);
        
        if(!mark[n])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
    }
    
    return 0;
}



















