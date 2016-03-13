//
//  main.c
//  PAT-1070-MoonCake-25
//
//  Created by 程锋 on 15/8/27.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.
 
     Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 2 positive integers N (<=1000), the number of different kinds of mooncakes, and D (<=500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.
     
     Sample Input:
     3 200
     180 150 100
     7.5 7.2 4.5
     Sample Output:
     9.45
 
    注意：最好不要使用强制转换
    坑：数量也用double类型
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct Cake{
    double amounts;  // 必须是double类型，否则第三个测试点过不去
    double price;
    
    double w;
    
    bool operator < (const Cake & b) const
    {
        return w > b.w;
    }
}cake[1005];

int main(int argc, const char * argv[]) {
    
    //freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1070-MoonCake-25/PAT-1070-MoonCake-25/in", "r", stdin);
    
    int n, d;
    
    while(scanf("%d%d", &n, &d) != EOF)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%lf", &cake[i].amounts);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lf", &cake[i].price);
            cake[i].w = cake[i].price / cake[i].amounts;
        }
        
        sort(cake+1, cake+n+1);
        
        /*
         for(int i = 1; i <= n; ++i)
         printf("%d %f %lf\n", cake[i].amounts, cake[i].price, cake[i].w);
         */
        double ans = 0.0;
        for(int i = 1; i <= n; ++i)
        {
            
            if(cake[i].amounts <= d)
            {
                ans += cake[i].price;
                d -= cake[i].amounts;
            }
            else
            {
                ans += ((double)d/cake[i].amounts)*cake[i].price;
                break;
            }
        }
        
        printf("%.2f", ans);
    }
    
    return 0;
}
















