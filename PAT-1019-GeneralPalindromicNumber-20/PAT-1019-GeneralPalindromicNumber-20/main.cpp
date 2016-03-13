//
//  main.cpp
//  PAT-1019-GeneralPalindromicNumber-20
//
//  Created by 程锋 on 15/8/31.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
 
     Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N > 0 in base b >= 2, where it is written in standard notation with k+1 digits ai as the sum of (aibi) for i from 0 to k. Here, as usual, 0 <= ai < b for all i and ak is non-zero. Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 in any base and is also palindromic by definition.
     
     Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.
     
     Input Specification:
     
     Each input file contains one test case. Each case consists of two non-negative numbers N and b, where 0 <= N <= 10^9 is the decimal number and 2 <= b <= 10^9 is the base. The numbers are separated by a space.
     
     Output Specification:
     
     For each test case, first print in one line "Yes" if N is a palindromic number in base b, or "No" if not. Then in the next line, print N as the number in base b in the form "ak ak-1 ... a0". Notice that there must be no extra space at the end of output.
     
     Sample Input 1:
     27 2
     Sample Output 1:
     Yes
     1 1 0 1 1
     Sample Input 2:
     121 5
     Sample Output 2:
     No
     4 4 1
 
    //注意进制比较大的情况，不能使用字符数组保存结果
 */

#include <iostream>
#include <cstring>

using namespace std;

int size = 0;

void convert(int * ans, int n, int b)
{
    while(n)
    {
        ans[size++] = n % b;
        n /= b;
    }
}

bool check(int * ans)
{
    for(int i = 0; i <= size/2-1; ++i)
        if(ans[i] != ans[size-i-1])
            return false;
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1019-GeneralPalindromicNumber-20/PAT-1019-GeneralPalindromicNumber-20/in", "r", stdin);
    
    int n, b;
    
    while(cin >> n >> b)
    {
        if(n == 0 || n == 1)
        {
            cout << "Yes" << endl << n;
            return 0;
        }
        
        int ans[1000];
        
        convert(ans, n, b);
        
        if(check(ans))
        {
            cout << "Yes" << endl;
            
            for(int i = size-1; i >= 0; --i)
            {
                if(i == size-1)
                    cout << ans[i];
                else
                    cout << " " << ans[i];
            }
        }
        else
        {
            cout << "No" << endl;
            for(int i = size-1; i >= 0; --i)
            {
                if(i == size-1)
                    cout << ans[i];
                else
                    cout << " " << ans[i];
            }
        }
        
    }
    
    
    
    return 0;
}
