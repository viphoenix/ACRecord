//
//  main.cpp
//  PAT-1078-Hashing-25
//
//  Created by 程锋 on 15/9/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.
 
     Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.
     
     Sample Input:
     4 4
     10 6 4 15
     Sample Output:
     0 1 4 -
 */

#include <iostream>
#include <cstring>
#define N 10015

using namespace std;

bool mark[N];

void initPrime()
{
    memset(mark, true, N);
    
    /**
     *  注意
     */
    mark[1] = false;
    
    for(int i = 2; i < N; ++i)
    {
        if(mark[i] == false)
            continue;
        
        for(int j = i*i; j < N; j+=i)
            mark[j] = false;
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1078-Hashing-25/PAT-1078-Hashing-25/in", "r", stdin);
    
    int size, n;
    
    bool isFull[N];
    
    while(cin >> size >> n)
    {
        initPrime();
        memset(isFull, false, N);
        
        if(mark[size] == false)
        {
            for(int i = size; i < N; ++i)
                if(mark[i])
                {
                    size = i;
                    break;
                }
        }
        
        for(int i = 0; i < n; ++i)
        {
            int t, pos;
            cin >> t;
            
            int j;
            for(j = 0; j < size; ++j)
            {
                pos = (t + j * j) % size;
                
                if(isFull[pos] == false)
                {
                    isFull[pos] = true;
                    cout << (i == 0 ? "" : " ") << pos;
                    break;
                }
            }
            
            if(j == size)
                cout << (i == 0 ? "" : " ") << "-";
        
        }
    }
    
    
    return 0;
}















