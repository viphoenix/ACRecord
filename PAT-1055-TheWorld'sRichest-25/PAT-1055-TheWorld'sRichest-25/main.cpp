//
//  main.cpp
//  PAT-1055-TheWorld'sRichest-25
//
//  Created by 程锋 on 15/9/7.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.
 
 Input Specification:
 
 Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=105) - the total number of people, and K (<=103) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [-106, 106]) of a person. Finally there are K lines of queries, each contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.
 
     Output Specification:
     
     For each query, first print in a line "Case #X:" where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format
     
     Name Age Net_Worth
     The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output "None".
     Sample Input:
     12 4
     Zoe_Bill 35 2333
     Bob_Volk 24 5888
     Anny_Cin 95 999999
     Williams 30 -22
     Cindy 76 76000
     Alice 18 88888
     Joe_Mike 32 3222
     Michael 5 300000
     Rosemary 40 5888
     Dobby 24 5888
     Billy 24 5888
     Nobody 5 0
     4 15 45
     4 30 35
     4 5 95
     1 45 50
     Sample Output:
     Case #1:
     Alice 18 88888
     Billy 24 5888
     Bob_Volk 24 5888
     Dobby 24 5888
     Case #2:
     Joe_Mike 32 3222
     Zoe_Bill 35 2333
     Williams 30 -22
     Case #3:
     Anny_Cin 95 999999
     Michael 5 300000
     Alice 18 88888
     Cindy 76 76000
     Case #4:
     None
 
    因为m的值小于100， 所以当一个年龄出现超过100次后，不再计数,否则第二个测试点超时
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Person{
    char name[10];
    int age;
    int worth;
    
    bool operator < (const Person & b) const
    {
        if(worth != b.worth)
            return worth > b.worth;
        else if(age != b.age)
            return age < b.age;
        else
            return strcmp(name, b.name) < 0;
    }
};

vector<Person> richer;
int ageNum[205] = {0};
int p[100005];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1055-TheWorld'sRichest-25/PAT-1055-TheWorld'sRichest-25/in", "r", stdin);
    
    int n, k;
    
    while(scanf("%d%d", &n, &k) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            char name[10];
            int age, worth;
            Person p;
            
            scanf("%s%d%d", name, &age, &worth);
            strcpy(p.name, name);
            p.age = age;
            p.worth = worth;
            
            richer.push_back(p);
        }
        
        sort(richer.begin(), richer.end());
        
        int m, start, end, size = 0;
        
        for(int i = 0; i < (int)richer.size(); ++i)
        {
            int age = richer[i].age;
            
            ageNum[age]++;
            
            if(ageNum[age] < 101)
                p[size++] = i;
        }
        
        for(int j = 1; j <= k; ++j)
        {
            scanf("%d%d%d", &m, &start, &end);
            
            printf("Case #%d:\n", j);
            
            bool flag = false;
            for(int i = 0; i < size && m>0; ++i)
            {
                int age = richer[p[i]].age;
                
                if(age >= start && age <= end)
                {
                    printf("%s %d %d\n", richer[p[i]].name, richer[p[i]].age, richer[p[i]].worth);
                    flag = true;
                    m--;
                }
            }
            
            if(!flag)
                printf("None\n");
        }

    }

    return 0;
}


















