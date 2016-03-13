//
//  main.c
//  time
//
//  Created by 程锋 on 15/8/27.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int NUM = 1000000;

//生成1000000个数
void generate()
{
    ofstream file("/Users/chengfeng/Dev/Algorithm/TEST/time/time/data");
    for(int i = 0 ; i < NUM ; i++)
    {
        file<<rand()<<' ';
        if((i+1)%20 == 0)
            file<<endl;
    }
}

void cinTime()
{
    freopen("data","r",stdin);
    int n,start,end;
    start = clock();
    for(int i = 0 ; i < NUM ; i++)
        cin>>n;
    end = clock();
    cout<<double(end-start)/CLOCKS_PER_SEC<<endl;     // 0.009242

}

void scanfTime()
{
    freopen("data","r",stdin);
    int n,start,end;
    start = clock();
    for(int i = 0 ; i < NUM ; i++)
        scanf("%d",&n);
    end = clock();
    printf("%lf\n",double(end-start)/CLOCKS_PER_SEC);  // 0.042325

}

//理论上cin 在编译期决定需要输入的变量类型，而scanf在运行期间才决定，所以理论上cin cout 比 scanf printf 快，
//但是由于编译器处理方式导致比scanf printf 慢, 一般是在g++编译器上
//
int main()
{
    generate();
    
    cinTime();
    
    scanfTime();
    
    return 0;
}