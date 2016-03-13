//
//  main.cpp
//  PAT-1025-PATRanking
//
//  Created by 程锋 on 15/8/25.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.
     
     Output Specification:
     
     For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
     
     registration_number final_rank location_number local_rank
     
     The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
     
     Sample Input:
     2
     5
     1234567890001 95
     1234567890005 100
     1234567890003 95
     1234567890002 77
     1234567890004 85
     4
     1234567890013 65
     1234567890011 25
     1234567890014 100
     1234567890012 85
     Sample Output:
     9
     1234567890005 1 1 1
     1234567890014 1 2 1
     1234567890001 3 1 2
     1234567890003 3 1 2
     1234567890004 5 1 4
     1234567890012 5 2 2
     1234567890002 7 1 5
     1234567890013 8 2 3
     1234567890011 9 2 4
 
    注意：成绩排序分两种情况：本题属于第二种
            1. 名次连续，求最优排名
            2. 名次不连续，有序序列中某一元素的排名名次大于或等于下标
 
    陷阱：考虑连续多个人成绩相同的情况（大于2）
 */

#include <iostream>
#include <string.h>
#include <algorithm>

struct Score{
    char id[15];
    int grade;
    int loc;
    int final_rank;
    int local_rank;
    
    bool operator < (const Score & b) const
    {
        if(grade != b.grade)
            return grade > b.grade;
        
        return strcmp(id, b.id) < 0;
    }
}list[30005];

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1025-PATRanking/PAT-1025-PATRanking/in", "r", stdin);
    
    int n;
    
    while(cin >> n)
    {
        int pos = 1;
        for(int i = 1; i <= n; ++i)
        {
            int k;
            cin >> k;
            
            int start = pos;
            for(int j = 1; j <= k; ++j, pos++)
            {
                char id[15];
                int grade;
                
                cin >> id >> grade;
                
                strcpy(list[pos].id, id);
                list[pos].grade = grade;
                list[pos].loc = i;
            }
            
            sort(list+start, list+pos);
            
            int r = 1;
            
            for(int j = start; j < pos; ++j)
            {
                if(list[j].grade != list[j-1].grade)
                {
                    r = j - start + 1;
                    list[j].local_rank = r;
                }
                else
                    list[j].local_rank = r;
                
            }
        }
        
        sort(list+1, list+pos);
        
        int r = 1;
        
        for(int i = 1; i < pos; ++i)
        {
            if(list[i].grade != list[i-1].grade)
            {
                r = i;
                list[i].final_rank = r;
            }
            else
                list[i].final_rank = r;
            
            
        }
        
        cout << pos - 1 << endl;
        
        for(int i = 1; i < pos; ++i)
            cout << list[i].id << " " << list[i].final_rank << " " << list[i].loc << " " << list[i].local_rank << endl;
        
    }
    
    
    return 0;
}




































