//
//  main.c
//  LCS-最长公共字串
//
//  Created by 程锋 on 15/8/17.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int dp[101][101];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/LCS-最长公共字串/LCS-最长公共字串/in", "r", stdin);
    
    char str1[101], str2[101];
    
    while (scanf("%s%s", str1, str2) != EOF) {
        
        int len1 = (int)strlen(str1);
        int len2 = (int)strlen(str2);
        
        
//        printf("%d %d\n", len1, len2);
        
        for(int i = 0; i < len1; ++i)
        {
            for(int j = 0; j < len2; ++j)
            {
                int ni = i - 1;
                int nj = j - 1;
                int dpi = 0;
                int dpj = 0;
                if(ni >= 0)
                    dpi = dp[i-1][j];
                if(nj >= 0)
                    dpj = dp[i][j-1];
                
                if(str1[i] == str2[j])
                    dp[i][j] = max(dpi, dpj) + 1;
                else
                    dp[i][j] = max(dpi, dpj);
            }
        }
        
        printf("%d\n", dp[len1-1][len2-1]);
        
    }
    
    
    return 0;
}
