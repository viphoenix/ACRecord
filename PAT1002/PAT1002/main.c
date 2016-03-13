//
//  main.c
//  PAT1002
//
//  Created by 程锋 on 15/8/20.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  This time, you are supposed to find A+B where A and B are two polynomials.
 
     Input
     
     Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.
     
     Output
     
     For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
     
     Sample Input
     2 1 2.4 0 3.2
     2 2 1.5 1 0.5
     Sample Output
     3 2 1.5 1 2.9 0 3.2
 
    注意点：和为0时，不计数，也不输出

 *
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT1002/PAT1002/in", "r", stdin);
    
    float ans[1001];
    int flag[1001];
    
    for(int i = 0; i < 1001; ++i)
    {
        ans[i] = 0;
        flag[i] = 0;
    }
    
    int k;
    int nk;
    float ak;
    int cnt = 0;
    
    while(scanf("%d", &k) != EOF)
    {
        for(int i = 0; i < k; ++i)
        {
            scanf("%d%f", &nk, &ak);
            ans[nk] += ak;
            
            if(flag[nk] == 0 && ans[nk] != 0)
            {
                cnt++;
                flag[nk] = 1;
            }
            
            if(flag[nk] == 1 && ans[nk] == 0)
                cnt--;
        }
        
        scanf("%d", &k);
        for(int i = 0; i < k; ++i)
        {
            scanf("%d%f", &nk, &ak);
            ans[nk] += ak;
            
            if(flag[nk] == 0 && ans[nk] != 0)
            {
                cnt++;
                flag[nk] = 1;
            }
            if(flag[nk] == 1 && ans[nk] == 0)
            cnt--;
        }
        
        printf("%d", cnt);
        for(int i = 1000; i >= 0; --i)
            if(ans[i] != 0)
                printf(" %d %.1f", i, ans[i]);
    }
    
    
    
    return 0;
}
