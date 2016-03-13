//
//  main.cpp
//  数组-众数
//
//  Created by 程锋 on 15/8/11.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/数组-众数/数组-众数/in", "r", stdin);
    
    int n;
    while (cin >> n && n != 0) {
        
        int * nums = (int *) malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            nums[i] = tmp;
        }
        
        int count = 1, num = nums[0];
        
        for(int i = 1; i < n; ++i)
        {
            if(count == 0)
            {
                num = nums[i];
                count = 1;
            }
            else if(nums[i] == num)
                count++;
            else
            {
                count--;
            }
        }
        
        cout << num << endl;
    }
    
    
    return 0;
}
