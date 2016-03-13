//
//  main.c
//  PAT-1005-SpellItRight
//
//  Created by 程锋 on 15/8/20.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  1005. Spell It Right (20)
 
     Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
     
     Input Specification:
     
     Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100).
     
     Output Specification:
     
     For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.
     
     Sample Input:
     12345
     Sample Output:
     one five
    
    注意和为0的情况
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1005-SpellItRight/PAT-1005-SpellItRight/in", "r", stdin);
    
    char str[102];
    char map[11][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    
    memset(str, 0, 102);
    while(scanf("%s", str) != EOF)
    {
        int sum = 0;
        int len = (int)strlen(str);
        
        
        for(int i = 0; i < len; ++i)
            sum += (str[i] - '0');
        
        if(sum == 0)
        {
            printf("zero");
            return 0;
        }
        
        int size = 0;
        while(sum)
        {
            str[size] = sum % 10 + '0';
            sum /= 10;
            size++;
        }
        
        for(int i = size-1; i >= 0; --i)
        {
            if(i != size-1)
                printf(" ");
                
            printf("%s", map[str[i]-'0']);
        }
        
    }
    
    
    
    return 0;
}
