//
//  main.cpp
//  PAT-1010-Radix
//
//  Created by 程锋 on 15/8/21.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.
 
     Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.
     
     Input Specification:
     
     Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
     N1 N2 tag radix
     Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.
     
     Output Specification:
     
     For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.
     
     Sample Input 1:
     6 110 1 10
     Sample Output 1:
     2
     Sample Input 2:
     1 ab 1 2
     Sample Output 2:
     Impossible
 
        100 110 1 10
 
    剪枝：判断每一位与当前所求进制的大小关系，若大，则跳过
 */

#include <iostream>
#include <string.h>

using namespace std;

long long convert(char * str, int radix)
{
    long long res = 0;
    int len = (int)strlen(str);
    int weight = 1;
    
    for(int i = len-1; i >= 0; --i)
    {
        if(str[i] >= '0' && str[i] <= '9')
            res += (str[i] - '0') * weight;
        else if(str[i] >= 'a' && str[i] <= 'z')
            res += (str[i] - '0' - 39) * weight;
            
        weight *= radix;
    }
    
    return res;
}

int getRadix(long long na, char * nb, int low, int high)
{
    if(low > 36 || high < 2)
        return 0;
    while (low <= high)
    {
        int mid = (low+high)/2;
        long long res = convert(nb, mid);
        
        if(na > res)
            low = mid + 1;
        else if(na < res)
            high = mid - 1;
        else
            return mid;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1010-Radix/PAT-1010-Radix/in", "r", stdin);
    
    int tag, radix;
    char na[15];
    char nb[15];
    
    while (cin >> na >> nb >> tag >> radix)
    {
        //cout << na << " " << nb << endl;
        
        if(strcmp(na, nb) == 0)
        {
            cout << radix;
            return 0;
        }
        
        if(convert(na, radix) == 0 || convert(nb, radix) == 0)
            cout << "Impossible";
        if(convert(na, radix) == 0 && convert(nb, radix) == 0)
            cout << radix;
        
        
        //na 是否大于 nb
        bool flag;
        /*
        int len1 = (int)strlen(na);
        int len2 = (int)strlen(nb);
        
        if(len1 == len2)
            flag = strcmp(na, nb) > 0 ? true: false;
        else
            flag = len1 > len2 ? true : false;
        
        */
        
        if(tag == 1)
        {
            if(convert(na, radix) > convert(nb, radix))
                flag = true;
            else
                flag = false;
            //flag=true,则可能的结果一定大于radix
            if(flag)
            {
                int answer = getRadix(convert(na, radix), nb, radix+1, 36);
                if(answer)
                    cout << answer;
                else
                    cout << "Impossible";
            }
            else //flag=false,则可能的结果一定小于radix
            {
                int answer = getRadix(convert(na, radix), nb, 2, radix-1);
                if(answer)
                    cout << answer;
                else
                    cout << "Impossible";
            }
        }
        
        if(tag == 2)
        {
            if(convert(na, radix) > convert(nb, radix))
                flag = true;
            else
                flag = false;

            //flag=true,则可能的结果一定小于radix
            if(flag)
            {
                int answer = getRadix(convert(nb, radix), na, 2, radix-1);
                if(answer)
                    cout << answer;
                else
                    cout << "Impossible";
            }
            else //flag=false,则可能的结果一定大于radix
            {
                int answer = getRadix(convert(nb, radix), na, radix+1, 36);
                if(answer)
                    cout << answer;
                else
                    cout << "Impossible";
            }
        }
        

    }
    
    return 0;
}

















