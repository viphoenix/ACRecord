//
//  main.cpp
//  PAT-1087-AllRoadsLeadToRome-30
//
//  Created by 程锋 on 15/8/30.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format "City1 City2 Cost". Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.
     
     Output Specification:
     
     For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommended. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.
     
     Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route. Then in the next line, you are supposed to print the route in the format "City1->City2->...->ROM".
     
     Sample Input:
     6 7 HZH
     ROM 100
     PKN 40
     GDN 55
     PRS 95
     BLN 80
     ROM GDN 1
     BLN ROM 1
     HZH PKN 1
     PRS ROM 2
     BLN HZH 2
     PKN GDN 1
     HZH PRS 1
     Sample Output:
     3 3 195 97
     HZH->PRS->ROM
 
    部分正确，一个测试点答案错误，得分25分，迪杰斯特拉过程状态保存不熟练
    把每个结点前面的结点数记录下来，作为权重判断
 
 */

#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#define MAX 215
#define INF 0x7fffffff

using namespace std;

struct PathInfo{
    int sumCost;
    int sumHappy;
    vector<int> p;
    
    bool operator < (const PathInfo & b) const
    {
        if(sumCost != b.sumCost)
            return sumCost < b.sumCost;
        else if(sumHappy != b.sumHappy)
            return sumHappy > b.sumHappy;
        else
            return sumHappy/p.size() > b.sumHappy/b.p.size();
            
    }
}curPath;

map<int, vector<int>> graph;
map<int, int> happiness;
map<string, int> strToInt;
map<int, string> intToStr;
bool mark[MAX];
vector<PathInfo> path;
int weight[MAX][MAX];

int n, k;
string s;
int start = 0, dest;
int sumCost = 0, sumHappy = 0;


void dfs(int root, int _sumCost, int _sumHappy)
{
//    cout << root << " " << _sumCost << " " << _sumHappy << endl;
    for(int i = 0; i < graph[root].size(); ++i)
    {
        int no = graph[root][i];
        int cost = weight[root][no];
        
        if(mark[no] == false)
        {
            mark[no] = true;
            _sumCost += cost;
            _sumHappy += happiness[no];
            
            curPath.sumCost = _sumCost;
            curPath.sumHappy = _sumHappy;
            curPath.p.push_back(no);
            
            if(no == dest)
            {
                path.push_back(curPath);
                
            }
            
            dfs(no, _sumCost, _sumHappy);
            mark[no] = false;
            _sumCost -= weight[root][no];
            _sumHappy -= happiness[no];
            curPath.p.pop_back();
        }
    }
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1087-AllRoadsLeadToRome-30/PAT-1087-AllRoadsLeadToRome-30/in", "r", stdin);
    
    
    while(cin >> n >> k >> s)
    {
        strToInt[s] = 0;
        intToStr[0] = s;
        
        for(int i = 1; i < n; ++i)
        {
            string name;
            int value;
            cin >> name >> value;
            if(name == "ROM")
                dest = i;
            strToInt[name] = i;
            intToStr[i] = name;
            
            happiness[i] = value;
        }
        
        for(int i = 0; i < k; ++i)
        {
            string na, nb;
            int cost;
            cin >> na >> nb >> cost;
            
            int noa = strToInt[na];
            int nob = strToInt[nb];
            
            graph[noa].push_back(nob);
            graph[nob].push_back(noa);
            
            weight[noa][nob] = cost;
            weight[nob][noa] = cost;
        }
        
        for(int i = 0; i < n; ++i)
            mark[i] = false;
        
        mark[start] = true;
        curPath.p.push_back(start);
        dfs(start, 0, 0);
        
        sort(path.begin(), path.end());
        
        int cnt = 1;
        for(int i = 1; i < path.size(); ++i)
            if(path[i].sumCost == path[0].sumCost)
                cnt++;
        printf("%d ", cnt);

        printf("%d %d %d\n", path[0].sumCost, path[0].sumHappy, path[0].sumHappy/(int)(path[0].p.size()-1));
        printf("%s", intToStr[path[0].p[0]].c_str());
            for(int j = 1; j < path[0].p.size(); ++j)
                printf("->%s", intToStr[path[0].p[j]].c_str());
            printf("\n");
        
    }
    
    return 0;
}

















