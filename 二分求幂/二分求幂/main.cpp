//
//  main.cpp
//  二分求幂
//
//  Created by 程锋 on 15/8/5.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/二分求幂/二分求幂/in", "r", stdin);
    
    int a, n;
    while(cin >> a >> n && a != 0 && n != 0)
    {
        int res = 1;
        while (n != 0)
        {
            if(n % 2 == 1)
            {
                res *= a;
                res %= 1000;
            }
            
            n /= 2;
            a *= a;
            a %= 1000;
        }
        
        cout << res << endl;
        
    }
    
    
    return 0;
}
