//
//  main.cpp
//  排序C++
//
//  Created by 程锋 on 15/7/28.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main(int argc, const char * argv[]) {
    
    int n;
    int buf[10000];
   
    freopen("/Users/chengfeng/Dev/Algorithm/排序C++/排序C++/in", "r", stdin);
    
    while ((scanf("%d", &n)) != EOF) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &buf[i]);
        
        sort(buf, buf+n, cmp);
        
        for(int i = 0; i < n; ++i)
            printf("%d ", buf[i]);
    }
    
    std::cout << endl << "Hello, World!";
    return 0;
}
