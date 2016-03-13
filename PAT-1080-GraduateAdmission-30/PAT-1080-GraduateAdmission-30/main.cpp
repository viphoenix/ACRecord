//
//  main.cpp
//  PAT-1080-GraduateAdmission-30
//
//  Created by 程锋 on 15/9/4.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  It is said that in 2013, there were about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.
 
     Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview grade GI. The final grade of an applicant is (GE + GI) / 2. The admission rules are:
     
     The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
     If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade GE. If still tied, their ranks must be the same.
     Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
     If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.
     Input Specification:
     
     Each input file contains one test case. Each case starts with a line containing three positive integers: N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; and K (<=5), the number of choices an applicant may have.
     
     In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.
     
     Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's GE and GI, respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.
     
     Output Specification:
     
     For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.
     
     Sample Input:
     11 6 3
     2 1 2 2 2 3
     100 100 0 1 2
     60 60 2 3 5
     100 90 0 3 4
     90 100 1 2 0
     90 90 5 1 3
     80 90 1 0 2
     80 80 0 1 2
     80 80 0 1 2
     80 70 1 3 2
     70 80 1 2 3
     100 100 0 2 4
     Sample Output:
     0 10
     3
     5 6 7
     2 8
     
     1 4
 
     记录每个学校上一个录取的学生名次
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    int ge, gi, no;
    float final;
    vector<int> choice;
    int rank;
    
    bool operator < (const Student & b) const
    {
        if(final != b.final)
            return final > b.final;
        else
            return ge > b.ge;
    }
}stu[40005];

int n, m, k;
int quota[105]; // 每个学校的名额
int lastRank[105];  //每个学校上一个录取学生的名次，默认为0
vector<int> result[105];

void put()
{
    for(int i = 0; i < m; ++i)
        cout << quota[i] << " ";
    
    cout << endl;
    
    for(int i = 0; i < n; ++i)
    {
        cout << stu[i].ge << " " << stu[i].gi << " " << stu[i].final << " " << stu[i].rank << " ----";
        
        for(int j = 0; j < k; ++j)
            cout  << " " << stu[i].choice[j];
        
        cout << endl;
    }
}


int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1080-GraduateAdmission-30/PAT-1080-GraduateAdmission-30/in", "r", stdin);
    
    while(cin >> n >> m >> k)
    {
        for(int i = 0; i < m; ++i)
        {
            int c;
            cin >> c;
            quota[i] = c;
            
            lastRank[i] = 0;
            result[i].clear();
        }
        
        for(int i = 0; i < n; ++i)
        {
            int a, b, c;
            cin >> a >> b;
            stu[i].no = i;
            stu[i].ge = a;
            stu[i].gi = b;
            stu[i].final = (a+b)/2;
            
            for(int j = 0; j < k; ++j)
            {
                cin >> c;
                stu[i].choice.push_back(c);
            }
        }
        
        sort(stu, stu+n);
        
        int r = 1;
        stu[0].rank = r;
        
        for(int i = 1; i < n; ++i)
        {
            if(stu[i].final == stu[i-1].final && stu[i].ge == stu[i-1].ge)
                stu[i].rank = r;
            else
            {
                r++;
                stu[i].rank = r;
            }
        }
        
        //put();
        
        //开始录取
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < k; ++j)
            {
                int c = stu[i].choice[j];
                int r = stu[i].rank;
                int no = stu[i].no;
                
                if(quota[c] > 0)
                {
                    quota[c]--;  //学校名额减1
                    lastRank[c] = r;  //更新学校录取的排名
                    result[c].push_back(no); //已录取
                    
                    break;
                }
                else if(quota[c] == 0 && r == lastRank[c])
                {
                    result[c].push_back(no);
                
                    break;
                }
                
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            sort(result[i].begin(), result[i].end());
            
            for(int j = 0; j < result[i].size(); ++j)
                cout << (j == 0 ? "" : " ") << result[i][j];
            
            cout << endl;
        }
    }
    
    
    return 0;
}























