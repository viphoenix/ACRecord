//
//  main.cpp
//  PAT-1033-ToFillOrNotToFill-25
//
//  Created by 程锋 on 15/8/31.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
     
     Sample Input 1:
     50 1300 12 8
     6.00 1250
     7.00 600
     7.00 150
     7.10 0
     7.20 200
     7.50 400
     7.30 1000
     6.85 300
     Sample Output 1:
     749.17
     Sample Input 2:
     50 1300 12 2
     7.10 0
     7.00 600
     Sample Output 2:
     The maximum travel distance = 1200.00
     
 */

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x7fffffff
#include <iomanip>

using namespace std;

struct Node{
    float distance;
    float price;
    
    bool operator < (const Node & b) const
    {
        return distance < b.distance;
    }
};

vector<Node> node;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1033-ToFillOrNotToFill-25/PAT-1033-ToFillOrNotToFill-25/in", "r", stdin);
    
    int cmax, d, davg, n;
    
    while(cin >> cmax >> d >> davg >> n)
    {
        Node tmp;
        for(int i = 0; i < n; ++i)
        {
            float price;
            float distance;
            
            cin >> price >> distance;
            
            tmp.distance = distance;
            tmp.price = price;
            
            node.push_back(tmp);
        }
        
        tmp.price = 0;
        tmp.distance = d;
        node.push_back(tmp);
        
        sort(node.begin(), node.end());
        
        if(n == 0 || node[0].distance != 0)
        {
            cout << "The maximum travel distance = 0.00" << endl;
            return 0;
        }
        
        int start = 0;
        float maxd = node[start].distance + cmax * davg;
        float minPrice;
        int destination = 0;
        float sum = 0;
        float left = 0;
        float need;
        
        while(1)
        {
            minPrice = node[start].price;
            
            minPrice = INF;
            
            for(int j = start+1; j < node.size(); ++j)
            {
                if(node[j].distance <= maxd && node[j].price <= minPrice)  //如果都比起点贵，则选择最便宜的加油站作为终点
                {
                    minPrice = node[j].price;
                    destination = j;
                    
                    if(minPrice < node[start].price)                     // 如果有更便宜的，则下一个加油站是离起点第一个最便宜的加油站
                        break;
                }
                else
                    break;
            }
            
            //cout << start << " " << destination << endl;
            if(minPrice == INF)  //能够到达的范围内没有加油站
            {
                if(maxd >= d)
                {
                    sum += ((d - node[start].distance)/davg - left) * node[start].price;
                    cout << fixed << setprecision(2) << sum;
                }
                else
                    cout << "The maximum travel distance = " << fixed << setprecision(2) << maxd << endl;
                
                break;
            }
            else if(minPrice <= node[start].price)
            {
                need = (node[destination].distance - node[start].distance) / davg;
                
                if(left >= need)
                {
                    left -= need;
                }
                else
                {
                    sum += (need - left) * node[start].price;
                    left = 0;
                }
                
                start = destination;
            }
            else if(minPrice > node[start].price) //加满
            {
                sum += (cmax - left) * node[start].price;
                
                left = cmax - (node[destination].distance - node[start].distance) / davg;
                
                start = destination;
            }
            
            
            
            maxd = node[start].distance + cmax * davg;
            
            
        }
    }
    
    
    return 0;
}













