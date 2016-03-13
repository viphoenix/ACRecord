//
//  main.cpp
//  PAT-1082-ReadNumberInChinese-25
//
//  Created by 程锋 on 15/9/11.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".
 
     Input Specification:
     
     Each input file contains one test case, which gives an integer with no more than 9 digits.
     
     Output Specification:
     
     For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.
     
     Sample Input 1:
     -123456789
     Sample Output 1:
     Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
     Sample Input 2:
     100800
     Sample Output 2:
     yi Shi Wan ling ba Bai
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1082-ReadNumberInChinese-25/PAT-1082-ReadNumberInChinese-25/in", "r", stdin);
    
    char num[15];
    char hash_num[20][20] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char hash_step[20][20] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
    char result[25][20];
    
    
    while(scanf("%s", num) != EOF)
    {
        if(strcmp(num, "0") == 0)
        {
            printf("ling");
            return 0;
        }
        int len = (int)strlen(num);
        int size = 0;
        bool flag = false;
        int j = 0;
        for(int i = len-1; i >= 0; --i, ++j)
        {
            if(num[i] == '-')
            {
                strcpy(result[size++], "Fu");
                break;
            }
            
            if(j % 4 == 0 && flag == true)
            {
                strcpy(result[size++], hash_step[j]);
                flag = false;
            }
            
            if(flag == true && num[i] == '0')
            {
                strcpy(result[size++], hash_num[num[i]-'0']);
                continue;
            }
            
            if(num[i] == '0' && flag == false)
                continue;
            else
            {
                flag = true;
                if(j % 4 != 0)
                    strcpy(result[size++], hash_step[j]);
                strcpy(result[size++], hash_num[num[i]-'0']);
            }
            
            
            
        }
        
        for(int i = size-1; i >= 0; --i)
        {
            if(i == 0)
                printf("%s", result[i]);
            else
                printf("%s ", result[i]);
        }
    }
    
    
    return 0;
}















