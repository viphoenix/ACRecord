//
//  main.cpp
//  PAT-1028-ListSorting
//
//  Created by 程锋 on 15/8/25.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Excel can sort records according to any column. Now you are supposed to imitate this function.
 
     Input
     
     Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).
     
     Output
     
     For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.
     
     Sample Input 1
     3 1
     000007 James 85
     000010 Amy 90
     000001 Zoe 60
     Sample Output 1
     000001 Zoe 60
     000007 James 85
     000010 Amy 90
     Sample Input 2
     4 2
     000007 James 85
     000010 Amy 90
     000001 Zoe 60
     000002 James 98
     Sample Output 2
     000010 Amy 90
     000002 James 98
     000007 James 85
     000001 Zoe 60
     Sample Input 3
     4 3
     000007 James 85
     000010 Amy 90
     000001 Zoe 60
     000002 James 90
     Sample Output 3
     000001 Zoe 60
     000007 James 85
     000002 James 90
     000010 Amy 90
 
    陷阱：最后一个测试点，使用C++ sort算法超时，使用c qsort ok
    注意：qsort 比较函数形参类型一定是const void *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
    char id[10];
    char name[10];
    int grade;
}Data;

Data data[100001];

int cmp1(const void * at, const void * bt)
{
    Data * a = (Data *) at;
    Data * b = (Data *) bt;
    return strcmp(a->id, b->id);
}

int cmp2(const void * at, const void * bt)
{
    Data * a = (Data *) at;
    Data * b = (Data *) bt;
    if(strcmp(a->name, b->name) != 0)
        return strcmp(a->name, b->name);
    
    return strcmp(a->id, b->id);
}

int cmp3(const void * at, const void * bt)
{
    Data * a = (Data *) at;
    Data * b = (Data *) bt;
    if(a->grade != b->grade)
        return a->grade - b->grade;
    
    return strcmp(a->id, b->id);
}


int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1028-ListSorting/PAT-1028-ListSorting/in", "r", stdin);
    
    int n, c;
    
    while (scanf("%d%d", &n, &c) != EOF && n != 0) {
        
        for(int i = 0; i < n; ++i)
            scanf("%s%s%d", data[i].id, data[i].name, &data[i].grade);
        
        switch (c) {
            case 1:
                qsort(data, n, sizeof(Data), cmp1);
                for(int i = 0; i < n; ++i)
                    printf("%s %s %d\n", data[i].id, data[i].name, data[i].grade);
                break;
                
            case 2:
                qsort(data, n, sizeof(Data), cmp2);
                for(int i = 0; i < n; ++i)
                    printf("%s %s %d\n", data[i].id, data[i].name, data[i].grade);
                break;

            case 3:
                qsort(data, n, sizeof(Data), cmp3);
                for(int i = 0; i < n; ++i)
                    printf("%s %s %d\n", data[i].id, data[i].name, data[i].grade);
                break;

                
            default:
                break;
        }
        
    }
    
    
    return 0;
}



















