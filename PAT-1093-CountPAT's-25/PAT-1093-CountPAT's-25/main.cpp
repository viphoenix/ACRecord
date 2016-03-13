//
//  main.cpp
//  PAT-1093-CountPAT's-25
//
//  Created by 程锋 on 15/8/29.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.
 
     Now given any string, you are supposed to tell the number of PAT's contained in the string.
     
     Input Specification:
     
     Each input file contains one test case. For each case, there is only one line giving a string of no more than 10^5 characters containing only P, A, or T.
     
     Output Specification:
     
     For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.
     
     Sample Input:
     APPAPT
     Sample Output:
     2
 
    分别找出以A结束PA的个数和以T结束PAT的个数
 */

#include <iostream>
#include <cstring>
#define MAX 100005

using namespace std;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1093-CountPAT's-25/PAT-1093-CountPAT's-25/in", "r", stdin);
    
    char src[MAX];
    
    long int sumP[MAX];
    long int sumA[MAX];
    long int sumPA[MAX];
    long int sumT[MAX];
    long int sumPAT[MAX];

    while(cin >> src)
    {
        for(int i = 0; i < MAX; ++i)
        {
            sumP[i] = 0;
            sumA[i] = 0;
            sumPA[i] = 0;
            sumPAT[i] = 0;
            sumT[i] = 0;
        }
        
        int len = (int)strlen(src);
        
        for(int i = 0; i < len; ++i)
        {
            if(src[i] == 'P')
                sumP[i] = 1;
            
            if(src[i] == 'A')
                sumA[i] = 1;
            
            if(src[i] == 'T')
                sumT[i] = 1;
            
        }
        
        for(int i = 1; i < len; ++i)
        {
            sumP[i] += sumP[i-1];
            sumA[i] += sumA[i-1];
            sumT[i] += sumT[i-1];
        }
        
        
        
        //找出以i结尾的PA的个数
        for(int i = len-1; i >= 0; --i)
        {
            if(src[i] == 'A')
                sumPA[i] += sumP[i];
        }
        
        for(int i = 1; i < len; ++i)
            sumPA[i] += sumPA[i-1];
        
        
        //找出以i结尾的PAT的个数
        for(int i = len-1; i >= 0; --i)
        {
            if(src[i] == 'T')
                sumPAT[i] += sumPA[i];
        }
        
        for(int i = 1; i < len; ++i)
            sumPAT[i] += sumPAT[i-1];
        
        cout << sumPAT[len-1] % 1000000007;
        
    }
    
    return 0;
}



















