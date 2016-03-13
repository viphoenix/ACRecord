//
//  main.cpp
//  0子数组问题
//
//  Created by 程锋 on 15/7/28.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?(-(a)):(a))

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/0子数组问题/0子数组问题/in", "r", stdin);
    
    int n;
    
    
    while (cin >> n) {
        int start, end;
        vector<int> buf(n,0);
        vector<int> sum(n+1,0);
        map<int, int> resMap;
        resMap.insert(pair<int, int>(0,0));
        
        for(int i = 0; i < n; ++i)
            cin >> buf[i];
        
        map<int, int>::iterator mit;
        for(int i = 1; i < n+1; ++i)
        {
            sum[i] = sum[i-1] + buf[i-1];
            
            mit = resMap.find(sum[i]);
            cout << sum[i] << " " << i << endl;
            if(mit != resMap.end())
            {
                cout << "fklds" << "--" << mit->second << endl;
                start = mit -> second;
                end = i - 1;
                cout << "数组区间：" << start << "--" << end << endl;
                break;
            }
             
            
            resMap.insert(pair<int, int>(sum[i],i));
        }

        sort(sum.begin(),sum.end());
        for(int i = 0; i < n+1; ++i)
            cout << sum[i] << " ";
        
        int min = abs(sum[1]-sum[0]);
        int left = sum[0];
        int right = sum[1];
        
        for(int i = 2; i < n+1; ++i)
        {
            int diff = abs(sum[i]-sum[i-1]);
            if(diff < min)
            {
                min = diff;
                left = sum[i-1];
                right = sum[i];
            }
        }
        
        int l = resMap.find(left)->second;
        int r = resMap.find(right)->second;
        
        if(l > r)
            swap(l,r);
        start = l;
        end = r - 1;
        cout << "数组区间：" << start << "--" << end << endl;
    }
    
    return 0;
}


int testc(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/0子数组问题/0子数组问题/in", "r", stdin);
    
    int n;
    int buf[100];
    
    while (scanf("%d", &n) != EOF) {
     
        for(int i = 0; i < n; ++i)
            scanf("%d", &buf[i]);
        
        int * sum = new int[n+1];
        sum[0] = 0;
        
        for(int i = 1; i < n+1; ++i)
            sum[i] = sum[i-1] + buf[i];
        
        sort(sum, sum+n+1);
       
        int res = sum[1] - sum[0];
        
        for(int i = 2; i < n+1; ++i)
        {
            int diff = sum[i] - sum[i-1];
            if(ABS(diff) < ABS(res))
            {
                res = ABS(diff);
            }
            
        }
        delete[] sum;
        
        printf("%d\n", res);
        
    }
    
    return 0;
}
