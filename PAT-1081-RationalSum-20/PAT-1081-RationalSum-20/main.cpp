//
//  main.cpp
//  PAT-1081-RationalSum-20
//
//  Created by 程锋 on 15/9/11.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.
 
     Input Specification:
     
     Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long long". If there is a negative number, then the sign must appear in front of the numerator.
     
     Output Specification:
     
     For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.
     
     Sample Input 1:
     5
     2/5 4/15 1/30 -2/60 8/3
     Sample Output 1:
     3 1/3
     Sample Input 2:
     2
     4/3 2/3
     Sample Output 2:
     2
     Sample Input 3:
     3
     1/3 -1/6 1/8
     Sample Output 3:
     7/24
 */

#include <iostream>

using namespace std;

long long up[105], down[105];
int n;

long long getGCD(long long a, long long b)
{
    if(a < b)
    {
        long long t = a;
        a = b;
        b = t;
    }
    
    if(b == 0)
        return a;
    else
        return getGCD(b, a%b);
}

long long getLCM(long long a, long long b)
{
    return a * b / getGCD(a, b);
}

long long getArrayLCM(long long a[])
{
    long long res = getLCM(a[1], a[2]);
    
    for(int i = 3; i <= n; ++i)
    {
        res = getLCM(res, a[i]);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1081-RationalSum-20/PAT-1081-RationalSum-20/in", "r", stdin);
    
    
    
    while (scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lld/%lld", &up[i], &down[i]);
        }
        
        long long lcm = getArrayLCM(down);
        
        long long sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            up[i] *= lcm/down[i];
            sum += up[i];
        }
        
        long long itg = sum / lcm;
        long long numerator = sum % lcm;
        long long gcd = getGCD(numerator, lcm);
        numerator /= gcd;
        lcm /= gcd;
        
        if(itg)
            printf("%lld", itg);
        else if(numerator == 0)
            printf("0");
        
        if(numerator != 0)
        {
            if(itg)
                printf(" %lld/%lld", numerator, lcm);
            else
                printf("%lld/%lld", numerator, lcm);
        }
    }
    
    
    
    
    return 0;
}

























