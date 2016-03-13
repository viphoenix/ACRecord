//
//  main.c
//  查找学生信息
//
//  Created by 程锋 on 15/8/3.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Student{
    char id[20];
    char name[20];
    char sex[20];
    int age;
    
    bool operator < (const Student & b) const
    {
        int temp = strcmp(id, b.id);
        return temp < 0;
    }
}buf[1000];

int search(char * ss, int n);

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/查找学生信息/查找学生信息/in", "r", stdin);
    
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; ++i)
            scanf("%s%s%s%d", buf[i].id, buf[i].name, buf[i].sex, &buf[i].age);
        sort(buf, buf+n);
        /*
        for(int i = 0; i < n; ++i)
            printf("%s %s %s %d\n", buf[i].id, buf[i].name, buf[i].sex, buf[i].age);
        */
        
        scanf("%d", &m);
        
        char ss[20];
        for (int i = 0; i < m; ++i) {
            
            memset(ss, 0, 20);
            scanf("%s", ss);
            
            int res = search(ss, n);
            if(res != -1)
                printf("%s %s %s %d\n", buf[res].id, buf[res].name, buf[res].sex, buf[res].age);
            else
                printf("No Answer!");
             
        }
        
    }
    
    return 0;
}

int search(char * ss, int n)
{
    int left = 0;
    int right = n-1;
    
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int tmp = strcmp(ss, buf[mid].id);
        if(tmp < 0)
            right = mid-1;
        else if (tmp > 0)
            left = mid+1;
        else
            return mid;
        
    }
    
    return -1;
}
