//
//  main.c
//  前m大的数
//
//  Created by 程锋 on 15/8/3.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <stdio.h>
#define LEN 1000001
#define VEC 500000

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/前m大的数/前m大的数/in", "r", stdin);
    
    int n, m;
    int hash[LEN] = {0};
    
    
    while(scanf("%d", &n) != EOF && n != 0)
    {
        scanf("%d", &m);
        int temp;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &temp);
            
            hash[temp+VEC] = 1;
        }
        
       
        for(int i = LEN-1; i >= 0; --i)
        {
            if(hash[i] == 1 && m > 0)
            {
                --m;
                printf("%d%s", i-VEC, m>0?" ":"");
                
            }
        }
        
    }
    
    return 0;
}
