//
//  main.cpp
//  数制转换
//
//  Created by 程锋 on 15/8/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

void convert(int sum, int m)
{
    int size = 0;
    char res[100];
    memset(res, 0, 100);
    
    
    do{
        res[size++] = sum % m + '0';
        sum /= m;
    }while(sum != 0);
    
    for(int i = size-1; i >= 0; --i)
        cout << res[i];
    cout << endl;
        
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/数制转换/数制转换/in", "r", stdin);
    
    int m, a, b;
    
    while(cin >> m && m != 0)
    {
        cin >> a >> b;
        
//        cout << a << b;
        
        convert(a+b, m);
    }
    
    return 0;
}
