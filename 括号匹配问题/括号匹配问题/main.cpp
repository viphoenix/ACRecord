//
//  main.cpp
//  括号匹配问题
//
//  Created by 程锋 on 15/8/3.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/括号匹配问题/括号匹配问题/in", "r", stdin);
    
    stack<int> s;
    char str[100];
    char res[100];
    
    while (scanf("%s", str) != EOF) {
        int len = (int)strlen(str);
        strcpy(res, str);
        
        while (!s.empty()) {
            s.pop();
        }
        
        for(int i = 0; i < len; ++i)
        {
            if(str[i] != '(' && str[i] != ')')
            {
                res[i] = ' ';
                continue;
            }
            if(str[i] == '(')
                s.push(i);
            else if(str[i] == ')')
            {
                if(!s.empty())
                {
                    res[i] = ' ';
                    res[s.top()] = ' ';
                    s.pop();
                }
                else
                    res[i] = '?';
                    
            }
        }
        
        if(!s.empty())
        {
            int tmp = s.top();
            res[tmp] = '$';
            s.pop();
        }
        
        puts(str);
        puts(res);
    }
    
    
    return 0;
}
