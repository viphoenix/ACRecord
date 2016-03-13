//
//  main.cpp
//  PAT-1095-CarsOnCampus-30
//
//  Created by 程锋 on 15/9/8.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>

#define MAXN 10005
#define MAXK 80005

using namespace std;

struct Car{
    char name[10];
    int hh, mm, ss;
    int seconds;
    
    char st[5];
};

map<string, int> m;

bool cmp1(const Car a, const Car b)
{
    if(strcmp(a.name, b.name) != 0)
        return strcmp(a.name, b.name) < 0;
    else if(a.hh != b.hh)
        return a.hh < b.hh;
    else if(a.mm != b.mm)
        return a.mm < b.mm;
    else
        return a.ss < b.ss;
}

bool cmp2(const Car a, const Car b)
{
    return a.seconds < b.seconds;
}

Car src[MAXN];
Car paired[MAXN];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1095-CarsOnCampus-30/PAT-1095-CarsOnCampus-30/in", "r", stdin);
    
    int n, k;
    
    while(scanf("%d%d", &n, &k) != EOF)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%s%d:%d:%d%s", src[i].name, &src[i].hh, &src[i].mm, &src[i].ss, src[i].st);
            src[i].seconds = src[i].hh*3600 + src[i].mm*60 + src[i].ss;
        }
        
        sort(src, src+n, cmp1);
        
        
        //配对算法, 过滤掉非法数据
        int size = 0;
        for(int i = 0; i < n-1;)
        {
            if(strcmp(src[i].name, src[i+1].name) == 0)
            {
                if(strcmp(src[i].st, "in") == 0 && strcmp(src[i+1].st, "out") == 0)
                {
                    paired[size++] = src[i];
                    paired[size++] = src[i+1];
                    string key = string(src[i].name);
                    m[key] += src[i+1].seconds - src[i].seconds; //停留时间
                    
                    i += 2;
                }
                else
                    i++;
            }
            else
                i++;
                
        }
        
        sort(paired, paired+size, cmp2);
        
        int hh, mm, ss, sec, ans = 0, start = 0;
        
        while (k--)
        {
            scanf("%d:%d:%d", &hh, &mm, &ss);
            sec = hh * 3600 + mm * 60 + ss;
            
            for(int i = start; i < size; ++i)
            {
                if(paired[i].seconds <= sec)
                {
                    if(strcmp(paired[i].st, "in") == 0)
                        ans++;
                    else
                        ans--;
                }
                
                if(paired[i].seconds > sec)  //如果sec是一天中最后一秒，则这一步可能不执行，所以printf不能放在这里面
                {
                    start = i;
                    break;
                }
                
            }
            
            
            printf("%d\n", ans);
        }
        
        map<string, int>::iterator it;
        int max = -1;
        for(it = m.begin(); it != m.end(); it++)
        {
            if(it->second > max)
                max = it->second;
        }
        
        for(it = m.begin(); it != m.end(); it++)
        {
            if(it->second == max)
                printf("%s ", it->first.c_str());
        }

        hh = max / 3600;
        mm = (max - hh*3600) / 60;
        ss = max - hh*3600 - mm*60;
        
        printf("%02d:%02d:%02d", hh, mm, ss);
        
        
    }
    
    return 0;
}


















