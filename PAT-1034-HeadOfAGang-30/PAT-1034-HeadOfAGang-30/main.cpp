//
//  main.cpp
//  PAT-1034-HeadOfAGang
//
//  Created by 程锋 on 15/9/1.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:
     
     Name1 Name2 Time
     
     where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
     
     Output Specification:
     
     For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.
     
     Sample Input 1:
     8 59
     AAA BBB 10
     BBB AAA 20
     AAA CCC 40
     DDD EEE 5
     EEE DDD 70
     FFF GGG 30
     GGG HHH 20
     HHH FFF 10
     Sample Output 1:
     2
     AAA 3
     GGG 3
     Sample Input 2:
     8 70
     AAA BBB 10
     BBB AAA 20
     AAA CCC 40
     DDD EEE 5
     EEE DDD 70
     FFF GGG 30
     GGG HHH 20
     HHH FFF 10
     Sample Output 2:
     0
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Node{
    string start;
    string end;
    int w;
};

vector<Node> node;

map<string, vector<string>> tree;
map<string, int> weight;   //每个成员的权重
map<string, int> result;
map<string, bool> mark;

int cnt;
string head;
int totalWeight;

void dfs(string root)
{
    for(int i = 0; i < tree[root].size(); ++i)
    {
        string ns = tree[root][i];
        if(mark[ns] == false)
        {
            mark[ns] = true;
            totalWeight += weight[ns];
            cnt++;
            if(weight[ns] > weight[head])
                head = ns;
            
            dfs(ns);
        }
    }
}

int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1034-HeadOfAGang-30/PAT-1034-HeadOfAGang-30/in", "r", stdin);
    
    int n, k;
    
    while(cin >> n >> k)
    {
        for(int i = 0; i < n; ++i)
        {
            string sa, sb;
            int w;
            
            cin >> sa >> sb >> w;
            
            tree[sa].push_back(sb);
            tree[sb].push_back(sa);
            
            weight[sa] += w;
            weight[sb] += w;
        }
        
        map<string, int>::iterator mit;
        int size = 0;
        
        for(mit = weight.begin(); mit != weight.end(); ++mit)
        {
            head = mit->first;
            cnt = 1;
            totalWeight = weight[head];
            
            if(mark[head] == false)
            {
                mark[head] = true;
                dfs(head);
            }
            //cout << cnt << endl;;
            if(cnt > 2 && totalWeight/2 > k)
            {
                size++;
                result[head] = cnt;
            }
            
        }
        
        cout << size << endl;
        
        for(mit = result.begin(); mit != result.end(); ++mit)
            cout << mit->first << " " << mit->second << endl;
        
    }
    
    
    return 0;
}

























