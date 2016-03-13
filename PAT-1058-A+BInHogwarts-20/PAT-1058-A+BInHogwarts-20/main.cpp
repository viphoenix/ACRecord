//
//  main.c
//  PAT-1058-A+BInHogwarts-20
//
//  Created by 程锋 on 15/8/27.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 10^7], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).
 
     Input Specification:
     
     Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.
     
     Output Specification:
     
     For each test case you should output the sum of A and B in one line, with the same format as the input.
     
     Sample Input:
     3.2.1 10.16.27
     Sample Output:
     14.1.28
 
    坑：最高位不用考虑进位， 简单方法，输入时，直接处理：scanf("%d%c%d%c%d");

 */

#include <iostream>
#include <cstring>

using namespace std;

struct Number{
    int a;
    int b;
    int c;
};

Number  operator + (const Number left, const Number & right)
{
    Number res;
    res.a = res.b = res.c = 0;
    
    res.c = left.c + right.c;
    
    if(res.c >= 29)
    {
        res.b += res.c / 29;
        res.c %= 29;
    }
    
    res.b += left.b + right.b;
    if(res.b >= 17)
    {
        res.a += res.b / 17;
        res.b %= 17;
    }
    
    res.a += left.a + right.a;
    
        
        return res;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1058-A+BInHogwarts-20/PAT-1058-A+BInHogwarts-20/in", "r", stdin);
    
    
    char a[20];
    char b[20];
    
    while(scanf("%s%s", a, b) != EOF)
    {
        Number A, B, C;
        
        int ans = 0;
        int weight = 1;
        int cnt = 0;
        for(int i = (int)strlen(a)-1; i >= 0; --i)
        {
            if(a[i] == '.')
            {
                if(cnt == 0)
                    A.c = ans;
                else if(cnt == 1)
                    A.b = ans;
                
                cnt ++;
                
                ans = 0;
                weight = 1;
            }
            else
            {
                ans += (a[i]-'0') * weight;
                weight *= 10;
            }
            
            if(cnt == 2)
                A.a = ans;
        }
        
        cnt = 0;
        ans = 0;
        weight = 1;
        for(int i = (int)strlen(b)-1; i >= 0; --i)
        {
            if(b[i] == '.')
            {
                if(cnt == 0)
                    B.c = ans;
                else if(cnt == 1)
                    B.b = ans;

                cnt ++;
                
                ans = 0;
                weight = 1;
            }
            else
            {
                ans += (b[i]-'0') * weight;
                weight *= 10;
            }
            
            if(cnt == 2)
                B.a = ans;

        }
        
        C = A + B;
        
        printf("%d.%d.%d", C.a, C.b, C.c);
    }
    
    return 0;
}








