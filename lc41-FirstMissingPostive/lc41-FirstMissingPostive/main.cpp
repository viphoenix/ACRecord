//
//  main.cpp
//  lc41-FirstMissingPostive
//
//  Created by 程锋 on 15/8/2.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/lc41-FirstMissingPostive/lc41-FirstMissingPostive/in", "r", stdin);
    
    int n;
    ;
    
    while (cin >> n) {
        vector<int> buf(0);
        int temp;
        
        for(int i = 0; i < n; ++i)
        {
            cin >> temp;
            buf.push_back(temp);
        }
        
        for(int i = 0; i < n; ++i)
        {
            while (buf[i] != i+1) {
                
                if(buf[i] <= 0 || buf[i] > n)
                    break;
                
                swap(buf[i], buf[buf[i]-1]);
            }
        }
        
        for(int i = 0; i < n; ++i)
            if(buf[i] != i+1)
                cout << i+1 << endl;
    }
    
    return 0;
}
