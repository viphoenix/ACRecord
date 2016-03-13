//
//  main.cpp
//  PAT-1012-TheBestRank
//
//  Created by 程锋 on 15/8/21.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.
 
     For example, The grades of C, M, E and A - Average of 4 students are given as the following:
     
     StudentID  C  M  E  A
     310101     98 85 88 90
     310102     70 95 88 84
     310103     82 87 94 88
     310104     91 91 91 91
     Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.
     
     Input
     
     Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.
     
     Output
     
     For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.
     
     The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.
     
     If a student is not on the grading list, simply output "N/A".
     
     Sample Input
     5 6
     310101 98 85 88
     310102 70 95 88
     310103 82 87 94
     310104 91 91 91
     310105 85 90 90
     310101
     310102
     310103
     310104
     310105
     999999
     Sample Output
     1 C
     1 M
     1 E
     1 A
     3 A
     N/A
 */

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct Grade{
    int no;
    char id[10];
    int c;
    int m;
    int e;
    int a;
};

bool cmpA(const Grade & a, const Grade & b)
{
    return a.a > b.a;
}

bool cmpC(const Grade & a, const Grade & b)
{
    return a.c > b.c;
}

bool cmpM(const Grade & a, const Grade & b)
{
    return a.m > b.m;
}

bool cmpE(const Grade & a, const Grade & b)
{
    return a.e > b.e;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1012-TheBestRank/PAT-1012-TheBestRank/in", "r", stdin);
    
    int N, M;
    
    while(cin >> N >> M)
    {
        Grade * grade = (Grade *) malloc(sizeof(Grade) * N);
        
        int rank[2001][4];  //记录一个同学四项排序结果
        
        for(int i = 0; i < 2001; ++i)
            for(int j = 0; j < 4; ++j)
                rank[i][j] = 0;
        
        char id[10];
        int c;
        int m;
        int e;
        
        for(int i = 0; i < N; ++i)
        {
            cin >> id >> c >> m >> e;
            grade[i].no = i;
            strcpy(grade[i].id, id);
            grade[i].c = c;
            grade[i].m = m;
            grade[i].e = e;
            grade[i].a = (c+m+e)/3;
        }
        
        
        //注意成绩相同并列的情况
        sort(grade, grade+N, cmpA);
        int pos = 0;
        for(int i = 0; i < N; ++i)
        {
            if(i > 0)
            {
                if(grade[i].a != grade[i-1].a)
                    pos++;
            }
            rank[grade[i].no][0] = pos;
        }
        
        sort(grade, grade+N, cmpC);
        pos = 0;
        for(int i = 0; i < N; ++i)
        {
            if(i > 0)
            {
                if(grade[i].c != grade[i-1].c)
                    pos++;
            }

            rank[grade[i].no][1] = pos;
        }

        sort(grade, grade+N, cmpM);
        pos = 0;
        for(int i = 0; i < N; ++i)
        {
            if(i > 0)
            {
                if(grade[i].m != grade[i-1].m)
                    pos++;
            }

            rank[grade[i].no][2] = pos;
        }

        sort(grade, grade+N, cmpE);
        pos = 0;
        for(int i = 0; i < N; ++i)
        {
            if(i > 0)
            {
                if(grade[i].e != grade[i-1].e)
                    pos++;
            }

            rank[grade[i].no][3] = pos;
        }
/*
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < 4; ++j)
                cout << rank[i][j] << " ";
            cout << endl;
        }
        
*/
        char courseName[4] = {'A', 'C', 'M', 'E'};
        for(int i = 0; i < M; ++i)
        {
            char in[10];
            cin >> in;
            
            int j;
            for(j = 0; j < N; ++j)
            {
                if(strcmp(grade[j].id, in) == 0)
                {
                    int pos = grade[j].no;
                    int maxRank = 0x7fffffff;
                    int course = 0;
                    for(int k = 0; k < 4; ++k)
                        if(rank[pos][k] < maxRank)
                        {
                            maxRank = rank[pos][k];
                            course = k;
                        }
                    
                    cout << maxRank + 1 << " " << courseName[course];
                    if(i != M-1)
                        cout << endl;
                    
                    break;
                    
                }
            }
            
            if(j >= N)
            {
                cout << "N/A";
                if(i != M-1)
                    cout << endl;
            }
            
        }
        
        free(grade);
    }
    
    return 0;
}
























