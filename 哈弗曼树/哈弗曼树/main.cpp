//
//  main.cpp
//  哈弗曼树
//
//  Created by 程锋 on 15/8/3.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/哈弗曼树/哈弗曼树/in", "r", stdin);
    
    int n;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    while (cin >> n) {
        while(!pq.empty())
            pq.pop();
        int tmp;
        for(int i = 0; i < n; ++i)
        {
            cin >> tmp;
            pq.push(tmp);
        }
        
        int sum = 0;
        
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum += a+b;
            pq.push(a+b);
        }
        
        cout << sum << endl;
    }
    
    
    return 0;
}
