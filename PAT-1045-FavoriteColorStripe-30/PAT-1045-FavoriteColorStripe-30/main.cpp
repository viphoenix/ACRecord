//
//  main.cpp
//  PAT-1045-FavoriteColorStripe-30
//
//  Created by 程锋 on 15/9/10.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.
 
     It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.
     
     Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains a positive integer N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (<=200) followed by M Eva's favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (<=10000) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, simply print in a line the maximum length of Eva's favorite stripe.
     
     Sample Input:
     6
     5 2 3 1 5 6
     12 2 2 4 1 5 5 6 3 1 1 5 6
     Sample Output:
     7
 
    动态规划，
 */

#include <iostream>
#define MN 205
#define LN 10005
#define INF 0x7fffffff

using namespace std;

int dp[MN][LN];  //色带顺序前MN个，总体色带前LN个能够达到的最大值
int order[MN];
int stripe[LN];

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1045-FavoriteColorStripe-30/PAT-1045-FavoriteColorStripe-30/in", "r", stdin);
    
    int n, m, ln;
    
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i)
            scanf("%d", &order[i]);
        
        scanf("%d", &ln);
        for(int i = 1; i <= ln; ++i)
            scanf("%d", &stripe[i]);
        
        //initialize
        for(int i = 0; i <= m; ++i)
            for(int j = 0; j <= ln; ++j)
                dp[i][j] = 0;
        
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= ln; ++j)
            {
                int inc = 0;
                if(stripe[j] == order[i])
                    inc = 1;
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + inc;
                    
            }
        
        int maxV = -1;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= ln; ++j)
                if(dp[i][j] > maxV)
                    maxV = dp[i][j];
        }
        
        printf("%d", maxV);
            
    }
    
    
    
    return 0;
}

































