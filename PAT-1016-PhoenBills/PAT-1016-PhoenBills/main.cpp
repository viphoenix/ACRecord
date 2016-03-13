//
//  main.cpp
//  PAT-1016-PhoenBills
//
//  Created by 程锋 on 15/8/24.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A long-distance telephone company charges its customers by the following rules:
 
     Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.
     
     Input Specification:
     
     Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
     
     The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.
     
     The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
     
     For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.
     
     Output Specification:
     
     For each test case, you must print a phone bill for each customer.
     
     Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.
     
     Sample Input:
     10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
     10
     CYLL 01:01:06:01 on-line
     CYLL 01:28:16:05 off-line
     CYJJ 01:01:07:00 off-line
     CYLL 01:01:08:03 off-line
     CYJJ 01:01:05:59 on-line
     aaa 01:01:01:03 on-line
     aaa 01:02:00:01 on-line
     CYLL 01:28:15:41 on-line
     aaa 01:05:02:24 on-line
     aaa 01:04:23:59 off-line
     Sample Output:
     CYJJ 01
     01:05:59 01:07:00 61 $12.10
     Total amount: $12.10
     CYLL 01
     01:06:01 01:08:03 122 $24.40
     28:15:41 28:16:05 24 $3.85
     Total amount: $28.25
     aaa 01
     02:00:01 04:23:59 4318 $638.80
     Total amount: $638.80
    
    陷阱：至少有一个配对成功的，但并不是说没有配对失败的消费者，需要输出所有消费者的账单，Total amount: $0.00
        配对算法有误，状态是on-line时，不应该修改起始节点，应该对每一个online结点，排序规则，先按名字排序，再按on-line off-line排序
 
    一个人配对多次
 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <iomanip>
#include <map>

using namespace std;

struct Bill{
    char name[30];
    char time[20];
    int flag;
    
    bool operator < (const Bill & b) const
    {
        if(strcmp(name, b.name) != 0)
            return strcmp(name, b.name) < 0;
        else
            return strcmp(time, b.time) < 0;
    }
}bill[1001], paired[1001];

int toll[25];
char month[3];

struct Node{
    char start[20];
    char end[20];
};
map<string, vector<Node>> m;

void getResult(char start[], char end[], int & interval, float & sum)
{
    int dd1 = (start[3]-'0')*10+start[4]-'0';
    int hh1 = (start[6]-'0')*10+start[7]-'0';
    int mm1 = (start[9]-'0')*10+start[10]-'0';
    
    int dd2 = (end[3]-'0')*10+end[4]-'0';
    int hh2 = (end[6]-'0')*10+end[7]-'0';
    int mm2 = (end[9]-'0')*10+end[10]-'0';
    
    while(dd1 != dd2 || hh1 != hh2 || mm1 != mm2)
    {
        mm1++;
        sum += toll[hh1];
        interval++;
        if(mm1 >= 60)
        {
            hh1 += mm1/60;
            mm1 %= 60;
            if(hh1 >= 24)
            {
                dd1 += hh1/24;
                hh1 %= 24;
            }
            
        }
    }
    
    sum /= 100.0;
}



int main(int argc, const char * argv[]) {

    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1016-PhoenBills/PAT-1016-PhoenBills/in", "r", stdin);
    
    int n;
    
    for(int i = 0; i < 24; ++i)
    {
        int tmp;
        cin >> tmp;
        toll[i] = tmp;
    }
    
    cin >> n;
    
    for(int i = 1; i <= n; ++i)
    {
        char name[30];
        char time[20];
        char isLine[20];
        
        cin >> name >> time >> isLine;
        strncpy(month, time, 2);
        
        strcpy(bill[i].name, name);
        strcpy(bill[i].time, time);
        if(strcmp(isLine, "on-line") == 0)
            bill[i].flag = 1;
        else if(strcmp(isLine, "off-line") == 0)
            bill[i].flag = 0;
    }
    
    sort(bill + 1, bill + n + 1);

    int size = 1;
    for(int i = 1; i <= n-1;)
    {
        if(strcmp(bill[i].name, bill[i+1].name) == 0)
        {
            if(bill[i].flag == 1 && bill[i+1].flag == 0)
            {
                paired[size++] = bill[i];
                paired[size++] = bill[i+1];
                
                i += 2;
            }
            else
                ++i;
        }
        else
            ++i;
    }
    
    for(int i = 1; i < size;)
    {
        string key(paired[i].name);
        Node tmp;
        strcpy(tmp.start, paired[i].time);
        strcpy(tmp.end, paired[i+1].time);
        m[key].push_back(tmp);
        
        i += 2;
    }
     int interval = 0;
    float sum = 0.0, total = 0.0;
    
    map<string, vector<Node>>::iterator mit;
    for(mit = m.begin(); mit != m.end(); ++mit)
    {
        printf("%s %s\n", mit->first.c_str(), month);
        
        char start[20], end[20];
        for(int i = 0; i < mit->second.size(); ++i)
        {
            strcpy(start, mit->second[i].start);
            strcpy(end, mit->second[i].end);
            
            getResult(start, end, interval, sum);
            printf("%s %s %d $%.2f\n", start+3, end+3, interval, sum);
            total += sum;
            interval = 0;
            sum = 0.0;
        }
        
        printf("Total amount: $%.2f\n", total);
        total = 0.0;
    }
    
    return 0;
}












































