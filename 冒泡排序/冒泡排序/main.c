//
//  main.c
//  冒泡排序
//
//  Created by 程锋 on 15/7/28.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n;
    int buf[100];
    
    freopen("/Users/chengfeng/Dev/Algorithm/冒泡排序/冒泡排序/in", "r", stdin);
    
    while ((scanf("%d", &n)) != EOF) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &buf[i]);
        
        for(int i = 0; i < n; ++i)
            printf("%d ", buf[i]);
        
        for(int i = 0; i < n-1; ++i)
            for(int j = 0; j < n-1-i; ++j)
            {
                int tmp;
                if(buf[j] > buf[j+1])
                {
                    tmp = buf[j+1];
                    buf[j+1] = buf[j];
                    buf[j] = tmp;
                }
            }
        
        printf("\n");
        for(int i = 0; i < n; ++i)
            printf("%d ", buf[i]);
        
    }
    
    return 0;
}
