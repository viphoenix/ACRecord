//
//  main.cpp
//  PAT-1092-ToBuyOrNotToBuy-20
//
//  Created by 程锋 on 15/8/29.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1092-ToBuyOrNotToBuy-20/PAT-1092-ToBuyOrNotToBuy-20/in", "r", stdin);
    
    char shop[1005];
    char need[1005];
    
    
    int a[100];
    
    while(cin >> shop >> need)
    {
        for(int i = 0; i < 100; ++i)
            a[i] = 0;
        
        int k;
        for(int i = 0; i < (int)strlen(shop); ++i)
        {
            if(shop[i] >= '0' && shop[i] <= '9')
                k = shop[i] - '0';
            else if(shop[i] >= 'a' && shop[i] <= 'z')
                k = shop[i] - 'a' + 10;
            else if(shop[i] >= 'A' && shop[i] <= 'Z')
                k = shop[i] - 'A' + 36;
            
            a[k]++;
        }
        
        int miss = 0;
        
        for(int i = 0; i < (int)strlen(need); ++i)
        {
            if(need[i] >= '0' && need[i] <= '9')
                k = need[i] - '0';
            else if(need[i] >= 'a' && need[i] <= 'z')
                k = need[i] - 'a' + 10;
            else if(need[i] >= 'A' && need[i] <= 'Z')
                k = need[i] - 'A' + 36;
            
            if(a[k] > 0)
                a[k]--;
            else
                miss++;
        }
        
        if(miss > 0)
            cout << "No " << miss;
        else
        {
            int sum = 0;
            for(int i = 0; i < 62; ++i)
                sum += a[i];
            
            cout << "Yes " << sum;
            
        }

    }
        
    
    return 0;
}
