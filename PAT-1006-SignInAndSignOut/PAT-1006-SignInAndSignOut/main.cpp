//
//  main.cpp
//  PAT-1006-SignInAndSignOut
//
//  Created by 程锋 on 15/8/21.
//  Copyright (c) 2015年 程锋. All rights reserved.
//
/**
 *  At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.
 
     Input Specification:
     
     Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
     
     ID_number Sign_in_time Sign_out_time
     where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.
     
     Output Specification:
     
     For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.
     
     Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.
     
     Sample Input:
     3
     CS301111 15:30:28 17:00:10
     SC3021234 08:00:00 11:25:25
     CS301133 21:45:00 21:58:40
     Sample Output:
     SC3021234 CS301133
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node{
    char no[20];
    char inTime[20];
    char outTime[20];
    int inHH;
    int inMM;
    int inSS;
    
    int outHH;
    int outMM;
    int outSS;
    
    void init()
    {
        inHH = (inTime[0]-'0')*10+(inTime[1]-'0');
        inMM = (inTime[3]-'0')*10+(inTime[4]-'0');
        inSS = (inTime[6]-'0')*10+(inTime[7]-'0');
        outHH = (outTime[0]-'0')*10+(outTime[1]-'0');
        outMM = (outTime[3]-'0')*10+(outTime[4]-'0');
        outSS = (outTime[6]-'0')*10+(outTime[7]-'0');
    }
};

bool compareIn(const Node & a, const Node & b)
{
    if(a.inHH != b.inHH)
        return a.inHH < b.inHH;
    else if(a.inMM != b.inMM)
        return a.inMM < b.inMM;
    else
        return a.inSS < b.inSS;
        
}

bool compareOut(const Node & a, const Node & b)
{
    if(a.outHH != b.outHH)
        return a.outHH > b.outHH;
    else if(a.outMM != b.outMM)
        return a.outMM > b.outMM;
    else
        return a.outSS > b.outSS;
    
}


int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1006-SignInAndSignOut/PAT-1006-SignInAndSignOut/in", "r", stdin);
    
    int n;
    while(cin >> n && n != 0)
    {
        Node * node = (Node *) malloc(sizeof(Node) * n);
        
        for(int i = 0; i < n; ++i)
        {
            char no[20], inTime[20], outTime[20];
            cin >> no >> inTime >> outTime;
            strcpy(node[i].no, no);
            strcpy(node[i].inTime, inTime);
            strcpy(node[i].outTime, outTime);
            
            node[i].init();
        }
        
        sort(node, node+n, compareIn);
        printf("%s ", node[0].no);
        
        sort(node, node+n, compareOut);
        printf("%s", node[0].no);
    }
    
    return 0;
}
















