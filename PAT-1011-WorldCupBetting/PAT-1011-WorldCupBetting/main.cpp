//
//  main.cpp
//  PAT-1011-WorldCupBetting
//
//  Created by 程锋 on 15/8/21.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.
 
     Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.
     
     For example, 3 games' odds are given as the following:
     
     W    T    L
     1.1  2.5  1.7
     1.2  3.0  1.6
     4.1  1.2  1.1
     To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).
     
     Input
     
     Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.
     
     Output
     
     For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.
     
     Sample Input
     1.1 2.5 1.7
     1.2 3.0 1.6
     4.1 1.2 1.1
     Sample Output
     T T W 37.98
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1011-WorldCupBetting/PAT-1011-WorldCupBetting/in", "r", stdin);
    
    float buf[9];
    char hash[3] = {'W', 'T', 'L'};;
    
    for(int i = 0; i < 9; ++i)
    {
        float tmp;
        cin >> tmp;
        buf[i] = tmp;
    }
    
    int times;
    float max = buf[0];
    float product = 1.0;
    int pos = 0;
    for(int i = 0, times = 0; i < 9; ++i, ++times)
    {
        if(buf[i] > max)
        {
            max = buf[i];
            pos = i;
        }
    
        if((times+1) % 3 == 0)
        {
            product *= max;
            cout << hash[pos%3] << " ";
        }
        
        //开始新一轮比赛
        if(times % 3 == 0)
        {
            max = buf[i];
            pos = i;
        }
        
    }
    
    cout << fixed << setprecision(2);
    cout << (product*0.65-1)*2;
    
    return 0;
}

















