//
//  main.cpp
//  PAT-1077-Kuchiguse-20
//
//  Created by 程锋 on 15/9/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
 
     Itai nyan~ (It hurts, nyan~)
     Ninjin wa iyada nyan~ (I hate carrots, nyan~)
     Now given a few lines spoken by the same character, can you find her Kuchiguse?
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.
     
     Output Specification:
     
     For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".
     
     Sample Input 1:
     3
     Itai nyan~
     Ninjin wa iyadanyan~
     uhhh nyan~
     Sample Output 1:
     nyan~
     Sample Input 2:
     3
     Itai!
     Ninjinnwaiyada T_T
     T_T
     Sample Output 2:
     nai
 
    注意空格：都是空格的情况，首字母是空格
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

void myreverse(string & s)
{
    int len = (int)s.size();
    
    for(int i = 0; i <= len/2 - 1; ++i)
    {
        char t = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = t;
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1077-Kuchiguse-20/PAT-1077-Kuchiguse-20/in", "r", stdin);
    
    string s[105];
    string res;
    
    int n;
    
    while(cin >> n)
    {
        getchar();
        
        int minLen = 0x7fffffff;
        for(int i = 0; i < n; ++i)
        {
            getline(cin, s[i]);
            
            if(s[i].size() < minLen)
                minLen = (int)s[i].size();

            reverse(s[i].begin(), s[i].end());
        }
        
        bool flag = true;
        
        for(int i = 0; i < minLen; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(s[j][i] != s[j-1][i])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag == true)
                res.push_back(s[0][i]);
        }
        
        
        reverse(res.begin(), res.end());
        

        bool blank = true;
        
        for (int i = 0; i < (int)res.size(); ++i) {
            if(res[i] != ' ')
                blank = false;
        }
        
        if(blank || res.size() == 0)
        {
            cout << "nai";
            return 0;
        }
        
        bool start = false;
        for(int i = 0; i < (int)res.size(); ++i)
        {
            if(res[i] != ' ' || start)
            {
                cout << res[i];
                start = true;
            }
            if(res[i] == ' ' && !start)
                continue;
        }
        //cout << res;
    }
    
    
    
    return 0;
}













