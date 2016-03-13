//
//  main.cpp
//  PAT-1009-ProductOfPolynomials
//
//  Created by 程锋 on 15/8/21.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  This time, you are supposed to find A*B where A and B are two polynomials.
 
     Input Specification:
     
     Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
     
     Output Specification:
     
     For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
     
     Sample Input
     2 1 2.4 0 3.2
     2 2 1.5 1 0.5
     Sample Output
     3 3 3.6 2 6.0 1 1.6
 
    map内部是红黑树结构，键值默认递增排序
 */

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

map<int, float> a;
map<int, float> b;
map<int, float> c;

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1009-ProductOfPolynomials/PAT-1009-ProductOfPolynomials/in", "r", stdin);
    
    int n1, n2;
    while(cin >> n1 && n1 != 0)
    {
        int key;
        float value;
        
        while (n1--)
        {
            cin >> key >> value;
            a.insert(make_pair(key, value));
        }
        
        cin >> n2;
        while (n2--)
        {
            cin >> key >> value;
            b.insert(make_pair(key, value));
        }
        
        map<int, float>::iterator ita;
        map<int, float>::iterator itb;
        map<int, float>::iterator itc;
        
        for(ita = a.begin(); ita != a.end(); ++ita)
            for(itb = b.begin(); itb != b.end(); ++itb)
            {
                int key;
                float value;
                
                key = ita -> first + itb -> first;
                itc = c.find(key);
                if(itc != c.end())
                    itc -> second += ita -> second * itb -> second;
                else
                {
                    value = ita -> second * itb -> second;
                    c.insert(make_pair(key, value));
                }
            }
        
        map<int, float>::reverse_iterator ritc;
        itc = c.begin();
        int cnt = (int)c.size();
//        if(itc -> first == 0)
//            cnt--;
        cout << cnt;
        for(ritc = c.rbegin(); ritc != c.rend(); ++ritc)
        {
            cout << fixed << setprecision(1);
//            if(ritc -> first != 0)
                cout << " " << ritc -> first << " " << ritc -> second;
        }

    }
    
    
    return 0;
}


























