//
//  main.cpp
//  PAT-1040-LongestSymmetricString-25
//
//  Created by 程锋 on 15/9/5.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.
 
     Input Specification:
     
     Each input file contains one test case which gives a non-empty string of length no more than 1000.
     
     Output Specification:
     
     For each test case, simply print the maximum length in a line.
     
     Sample Input:
     Is PAT&TAP symmetric?
     Sample Output:
     11
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string sa;

bool check(int start, int end, int & cnt)
{
    cnt = 0;
    
    while (start < end)
    {
        if(sa[start] != sa[end])
            return false;
        
        if(sa[start] == sa[end])
        {
            start++;
            end--;
            
            cnt++;
        }
    }
    
    return true;
    
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1040-LongestSymmetricString-25/PAT-1040-LongestSymmetricString-25/in", "r", stdin);
    
    while(getline(cin, sa))
    {
        int start = 0, end = 0, cnt = 0;
        int max = -1;
        
        int len = (int)sa.size();
        
        for(int i = 0; i < len-1; ++i)
        {
            for(int j = i+1; j < len; ++j)
            {
                if(sa[j] == sa[i] && check(i, j, cnt) && cnt > max)
                {
                    start = i;
                    end = j;
                    max = cnt;
                }
                
            }
        }
        
        max = ((end - start) % 2) ? max*2 : max*2+1;
        bool flag = false;
        int size = 0;
        for(int i = start; i <= end; ++i)
        {
            if(sa[i] == '\0')
                break;
            
            if(!flag && sa[i] == ' ')
            {
                sa[start+end-i] = '\0';
                continue;
            }
            if(!flag && sa[i] != ' ')
                flag = true;
            
            if(flag)
                size++;
        }
        cout << size;
        //cout << start << " " << end << " " << max << endl;
        
    }
    
    
    return 0;
}














