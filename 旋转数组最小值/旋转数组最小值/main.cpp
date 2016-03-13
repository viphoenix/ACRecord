//
//  main.cpp
//  旋转数组最小值
//
//  Created by 程锋 on 15/7/28.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/旋转数组最小值/旋转数组最小值/in", "r", stdin);
    
    int n;
    int buf[100];
    
    while (scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &buf[i]);
        
        int low = 0;
        int high = n-1;
        int mid;
        
        while (low < high) {
            mid = (low + high) / 2;
            if(buf[mid] < buf[high])
                high = mid;
            else if(buf[mid] > buf[high])
                low = mid + 1;
                
        }
        
        printf("%d\n", buf[low]);
    }
    
    return 0;
}
