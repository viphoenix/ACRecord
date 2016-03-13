//
//  main.cpp
//  PAT-1039-CourseListForStudent-25
//
//  Created by 程锋 on 15/9/5.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=40000), the number of students who look for their course lists, and K (<=2500), the total number of courses. Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students Ni (<= 200) are given in a line. Then in the next line, Ni student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, print your results in N lines. Each line corresponds to one student, in the following format: first print the student's name, then the total number of registered courses of that student, and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line must be separated by a space, with no extra space at the end of the line.
     
     Sample Input:
     11 5
     4 7
     BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
     1 4
     ANN0 BOB5 JAY9 LOR6
     2 7
     ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
     3 1
     BOB5
     5 9
     AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
     ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
     Sample Output:
     ZOE1 2 4 5
     ANN0 3 1 2 5
     BOB5 5 1 2 3 4 5
     JOE4 1 2
     JAY9 4 1 2 4 5
     FRA8 3 2 4 5
     DON2 2 4 5
     AMY7 1 5
     KAT3 3 2 4 5
     LOR6 4 1 2 4 5
     NON9 0
 
    hash 键尽量转换为整型，字符串处理耗时
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#define MAX 26 * 26 * 26 * 10 + 1

using namespace std;

vector<int> data[MAX];

//const int maxx = 26 * 26 * 26 * 10 + 1;

int hashName(char * name){
    return (name[0] - 'A') * 26 * 26 * 10\
    + (name[1] - 'A') * 26 * 10\
    + (name[2] - 'A') * 10\
    + (name[3] - '0');
}
int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1039-CourseListForStudent-25/PAT-1039-CourseListForStudent-25/in", "r", stdin);
    
   
    int n, k;
    
    while(cin >> n >>k)
    {
        for(int i = 0; i < k; ++i)
        {
            int no, cnt;
            cin >> no >> cnt;
            
            for(int j = 0; j < cnt; ++j)
            {
                char name[10];
                cin >> name;
                data[hashName(name)].push_back(no);
            }
        }
        
        for(int i = 0; i < n; ++i)
        {
            char str[10];
            scanf("%s", str);              //大量数据输入用scanf
            
            long int query = hashName(str);
            
            sort(data[query].begin(), data[query].end());
            printf("%s %d", str, (int)data[query].size());
            //cout << q << " " << m[query].size();
            for(int j = 0; j < data[query].size(); ++j)
                //cout << " " << m[query][j];
                printf(" %d", data[query][j]);
            
            printf("\n");
        }
    }
    
    
    
    return 0;
}





























