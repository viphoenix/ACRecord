//
//  main.cpp
//  数组-环形数组最大子数组和
//
//  Created by 程锋 on 15/8/11.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  分两种情况：
 *      一、最大连续子数组在数组中：退化为求普通最大子数组和问题
 *      二、最大连续子数组跨过数组首尾，可以求出普通最小子数组和，然后，数组和减去这个值
 */

#include <iostream>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/数组-环形数组最大子数组和/数组-环形数组最大子数组和/in", "r", stdin);
    
    int n;
    
    while(cin >> n && n != 0)
    {
        int * nums = (int *) malloc(sizeof(int) * n);
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            nums[i] = tmp;
        }
        
        int sum = nums[0], maxAnswer = nums[0], minAnswer = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        
        for(int i = 1; i < n; ++i)
        {
            maxSum = MAX(nums[i], maxSum+nums[i]);
            minSum = MIN(nums[i], minSum+nums[i]);
            maxAnswer = MAX(maxAnswer, maxSum);
            minAnswer = MIN(minAnswer, minSum);
            
            sum += nums[i];
        }
        
        cout << MAX(maxAnswer, sum - minAnswer) << endl;
    }

    
    return 0;
}
