//
//  main.cpp
//  PAT-1026-TableTennis-30
//
//  Created by 程锋 on 15/9/2.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.
 
     Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.
     
     One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.
     
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains an integer N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.
     
     Output Specification:
     
     For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.
     
     Sample Input:
     9
     20:52:00 10 0
     08:00:00 20 0
     08:02:00 30 0
     20:51:00 10 0
     08:10:00 5 0
     08:12:00 10 1
     20:50:00 10 0
     08:01:30 15 1
     20:53:00 10 1
     3 1
     2
     Sample Output:
     08:00:00 08:00:00 0
     08:01:30 08:01:30 0
     08:02:00 08:02:00 0
     08:12:00 08:16:30 5
     08:10:00 08:20:00 10
     20:50:00 20:50:00 0
     20:51:00 20:51:00 0
     20:52:00 20:52:00 0
     3 3 2
 */

#include<stdio.h>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

struct VIPdata{//vip队列
    int starts;
    int startget;
    int lasts;
    int VIP;
    int id;
    
    friend bool operator <(VIPdata x,VIPdata y){
        if(x.VIP==y.VIP)
            return x.starts>y.starts;
        else
            return x.VIP<y.VIP;
    }
}s[10099];

struct Ordata{//普通队列
    int starts;
    int startget;
    int lasts;
    int VIP;
    int id;
    Ordata(int a,int b,int c,int d,int e){
        starts=a;startget=b;lasts=c;VIP=d;id=e;
    }
    friend bool operator <(Ordata x,Ordata y){
        return x.starts>y.starts;
    }
};

int ifplay[10999];//某人是否已经玩过

int cmp(VIPdata x,VIPdata y){
    return x.starts<y.starts;
}

struct Table{
    int ifuse;
    int end;
    int vip;
    int useNum;
}table[109];

int main(){
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1026-TableTennis-30/PAT-1026-TableTennis-30/in", "r", stdin);
    int n,tableNum,VipNum,PuNum;
    while(scanf("%d",&n)!=EOF){
        int i,hh,mm,ss,j;
        for(i=1;i<=n;i++){
            ifplay[i]=0;
            scanf("%d:%d:%d",&hh,&mm,&ss);
            s[i].starts=hh*3600+mm*60+ss;
            scanf("%d",&mm);
            if(mm>120)mm=120;//不要超过2个小时
            s[i].lasts=mm*60;
            scanf("%d",&s[i].VIP);
            s[i].id=i;
        }
        scanf("%d",&tableNum);
        scanf("%d",&VipNum);
        PuNum=tableNum-VipNum;
        
        for(i=1;i<=tableNum;i++){
            table[i].ifuse=0;
            table[i].end=0;
            table[i].vip=0;
            table[i].useNum=0;
        }
        int temp;
        for(i=1;i<=VipNum;i++){
            scanf("%d",&temp);
            table[temp].vip=1;
        }
        
        sort(&s[1],&s[1+n],cmp);
        //for(i=1;i<=n;i++){
        //    printf("%02d:%02d:%02d %d\n",s[i].starts/3600,(s[i].starts%3600)/60,s[i].starts%60,s[i].VIP);
        //}
        int first=8*3600,end=21*3600;
        int Vipnow=0,Punow=0;
        priority_queue<Ordata>Orqq;
        priority_queue<VIPdata>VIPqq;
        
        j=1;
        int k,x;
        for(i=first;i<end;i++){
            for(k=1;k<=tableNum;k++){//退台球桌
                if(table[k].ifuse==0)continue;
                if(table[k].end==i){
                    table[k].ifuse=0;
                    if(table[k].vip==1)Vipnow--;
                    else Punow--;
                    table[k].ifuse=0;
                }
            }
            
            //到点的人排队
            while(s[j].starts==i&&j<=n){
                Orqq.push(Ordata(s[j].starts,s[j].startget,s[j].lasts,s[j].VIP,s[j].id));
                VIPqq.push(s[j]);j++;
            }
            
            if((Vipnow+Punow)==tableNum)continue;
            for(k=Vipnow+1;k<=VipNum;k++){//排队中的人进台球桌 有VIP桌先满足VIP
                if(VIPqq.empty())break;
                if(VIPqq.top().VIP==0)break;
                
                while(!VIPqq.empty()&&ifplay[VIPqq.top().id]==1/*||(VIPqq.top().lasts+i)>end)*/){
                    VIPqq.pop();
                }if(VIPqq.empty())break;
                
                int rx=-1;
                for(x=1;x<=tableNum;x++){
                    if(table[x].ifuse==1)continue;
                    if(table[x].vip==0)continue;
                    rx=x;break;
                }if(rx==-1)break;
                
                printf("%02d:%02d:%02d",(VIPqq.top().starts/3600),(VIPqq.top().starts%3600)/60,VIPqq.top().starts%60);
                printf(" %02d:%02d:%02d",(i/3600),(i%3600)/60,i%60);
                printf(" %d\n",(i-VIPqq.top().starts+30)/60);//这里注意+30
                
                table[rx].end=VIPqq.top().lasts+i;
                table[rx].ifuse=1;
                table[rx].useNum++;
                Vipnow++;
                ifplay[VIPqq.top().id]=1;
                VIPqq.pop();
                
            }
            
            //排队中的人进台球桌 现在按普通队列排
            if((Vipnow+Punow)==tableNum)continue;
            for(k=1;k<=tableNum;k++){//普通人也可以玩VIP桌子
                if(Orqq.empty())break;
                
                while(!Orqq.empty()&&ifplay[Orqq.top().id]==1){
                    Orqq.pop();
                }if(Orqq.empty())break;
                
                int rx=-1;
                for(x=1;x<=tableNum;x++){
                    if(table[x].ifuse==1)continue;
                    rx=x;break;
                }if(rx==-1)break;
                
                printf("%02d:%02d:%02d",(Orqq.top().starts/3600),(Orqq.top().starts%3600)/60,Orqq.top().starts%60);
                printf(" %02d:%02d:%02d",(i/3600),(i%3600)/60,i%60);
                printf(" %d\n",(i-Orqq.top().starts+30)/60);//这里注意+30
                
                table[rx].end=Orqq.top().lasts+i;
                table[rx].ifuse=1;
                table[rx].useNum++;
                if(table[rx].vip==1)Vipnow++;
                else
                    Punow++;
                ifplay[Orqq.top().id]=1;
                Orqq.pop();
            }
        }
        int ok=0;
        for(i=1;i<=tableNum;i++){
            if(ok==0)ok=1;
            else printf(" ");
            printf("%d",table[i].useNum);
        }printf("\n");
    }
    return 0;
}





















































