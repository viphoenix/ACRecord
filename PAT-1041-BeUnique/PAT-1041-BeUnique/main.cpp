//
//  main.cpp
//  PAT-1041-BeUnique
//
//  Created by 程锋 on 15/8/25.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 10^4]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.
 
     Input Specification:
     
     Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=10^5) and then followed by N bets. The numbers are separated by a space.
     
     Output Specification:
     
     For each test case, print the winning number in a line. If there is no winner, print "None" instead.
     
     Sample Input 1:
     7 5 31 5 88 67 88 17
     Sample Output 1:
     31
     Sample Input 2:
     5 888 666 666 888 888
     Sample Output 2:
     None
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1041-BeUnique/PAT-1041-BeUnique/in", "r", stdin);
    
    
    int n;
    int num[10001];
    int buf[100001];
    
    while (cin >> n && n != 0)
    {
        for(int i = 1; i < 10001; ++i)
            num[i] = 0;
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
            
            num[buf[i]]++;
        }
        
        int i;
        for(i = 0; i < n; ++i)
            if(num[buf[i]] == 1)
            {
                cout << buf[i];
                break;
            }
        
        if(i == n)
            cout << "None";
    }
    
    return 0;
}
