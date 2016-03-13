//
//  main.cpp
//  PAT-1079-TotalSalesOfSupplyChain-25
//
//  Created by 程锋 on 15/9/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
 
     Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
     
     Now given a supply chain, you are supposed to tell the total sales from all the retailers.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:
     
     Ki ID[1] ID[2] ... ID[Ki]
     
     where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after Kj. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 1010.
     
     Sample Input:
     10 1.80 1.00
     3 2 3 5
     1 9
     1 4
     1 7
     0 7
     2 6 1
     1 8
     0 9
     0 4
     0 3
     Sample Output:
     42.4
 */

#include <iostream>
#define N 100005
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;


vector<int> node[N];
int cap[N];
queue<int> q;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1079-TotalSalesOfSupplyChain-25/PAT-1079-TotalSalesOfSupplyChain-25/in", "r", stdin);
    
  
    int n;
    double p, r;
    
    while(cin >> n >> p >> r)
    {
        for(int i = 0; i < N; ++i)
        {
            node[i].clear();
            cap[i] = 0;
        }
        
        while(!q.empty())
            q.pop();
        
        for(int i = 0; i < n; ++i)
        {
            int k;
            cin >> k;
            if(k > 0)
            {
                while(k--)
                {
                    int t;
                    cin >> t;
                    node[i].push_back(t);
                }
            }
            else if(k == 0)
            {
                int t;
                cin >> t;
                cap[i] = t;
            }
        }
        
        q.push(0);
        int level = 0;
        int levelNum = 1;
        int cnt;
        double sumCapicity;
        double sumPrice = 0;
        
        while(!q.empty())
        {
            cnt = 0;
            sumCapicity = 0;
            
            for(int i = 0; i < levelNum; ++i)
            {
                int front = q.front();
                q.pop();
                
                if(cap[front] > 0)
                    sumCapicity += cap[front];
                
                for(int j = 0; j < node[front].size(); ++j)
                {
                    int no = node[front][j];
                    q.push(no);

                    cnt++;
                }
            }
            
            levelNum = cnt;
            //cout << sumCapicity << " " << level << endl;
            
            sumPrice += sumCapicity * (p * pow((1.0+r/100),level));
            
            level++;
            
        }
        
        cout << fixed << setprecision(1) << sumPrice;
        
        
    }
    
    
    
    return 0;
}

































