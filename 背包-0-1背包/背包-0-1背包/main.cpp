//
//  main.cpp
//  背包-0-1背包
//
//  Created by 程锋 on 15/8/18.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <iostream>

using namespace std;

#define INF 0x7fffffff

struct Node{
    int cost;
    int value;
}list[101];

//前i件物品体积不超过j的最大价值
int dp[101][1001];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/背包-0-1背包/背包-0-1背包/in", "r", stdin);
    
    int T, n;
    
    while (cin >> T >> n && T != 0)
    {
        int nc, nv;
        for(int i = 1; i <= n; ++i)
        {
            cin >> nc >> nv;
            list[i].cost = nc;
            list[i].value = nv;
        }
        
        for(int i = 0; i <= T; ++i)
            dp[0][i] = 0;
        
        //依次遍历每个对象，根据是否能够放在背包内，分两种情况
        for(int i = 1; i <= n; ++i)
        {
            //对于剩余时间j，前i个对象，所能达到的最大价值
            //1⃣️能够放在背包内，可以不放入
            for(int j = T; j >= list[i].cost; --j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[i].cost]+list[i].value);
            }
            
            //2⃣️不能放在背包内
            for(int j = list[i].cost-1; j >= 0; --j)
            {
                dp[i][j] = dp[i-1][j];
            }
        }
        
        cout << dp[n][T] << endl;
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= T; ++j)
                if(dp[i][j])
                    cout << i << ":"<< j << " "<< dp[i][j] << endl;;
//            cout << endl;
        }
    }
    
    
    return 0;
}
