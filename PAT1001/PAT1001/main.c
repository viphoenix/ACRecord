//
//  main.c
//  PAT1001
//
//  Created by 程锋 on 15/8/20.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
 
     Input
     
     Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.
     
     Output
     
     For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
     
     Sample Input
     -1000000 9
     Sample Output
     -999,991
 *
 *
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT1001/PAT1001/in", "r", stdin);
    
    int a, b;
    
    while(scanf("%d%d", &a, &b) != EOF)
    {
        int sum;
        char str[20];
        int flag = 0;
        
        memset(str, 0, 20);
        
        sum = a + b;
        
        //当sum等于0时，字符串输出为空
        if(sum == 0)
        {
            printf("%d",0);
            return 0;
        }
        
        if(sum < 0)
        {
            flag = 1;
            sum = -sum;
        }
        
        int i = 0;
        while(sum)
        {
            str[i] = sum % 10 + '0';
            sum /= 10;
            ++i;
        }
        
        if(flag)
            printf("%c", '-');
        
        int len = (int)strlen(str);
        
        int start = len % 3 - 1;
        
        if(start < 0)
            start += 3;
        
        for(int i = len-1; i >= 0; --i)
        {
            printf("%c", str[i]);
            if(len -i - 1 == start && i != 0)
            {
                printf("%c", ',');
                start += 3;
            }
            
        }
        
        printf("\n");
      
    }
    
    return 0;
}
