//
//  main.cpp
//  有多少个正方形
//
//  Created by 程锋 on 15/7/25.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#define NUM 19
#define MIN(a,b) ((a)<(b)?(a):(b))


int main(int argc, const char * argv[]) {
    
    /**
     *  18行18列，共有多少个正方形
     *  以某个点为右下角的正方形有多少个
     */
    
    int sum = 0;
    for(int i = 0; i < NUM; ++i)
        for(int j = 0; j < NUM; ++j)
            sum += MIN(i, j);
    
    printf("%d\n", sum);
    
    return 0;
}
