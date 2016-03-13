//
//  main.cpp
//  排序-桶排序
//
//  Created by 程锋 on 15/8/9.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

/**
 *  桶排序
 *  算法思想：将待排数据尽量均匀分布在一定数量的桶中，依次对每个桶中的元素排序，桶内排序可以使用任何排序算法，最后按顺序输出桶内的元素
 *  适用场景：元素的集合范围不应该过大；元素尽可能均匀分布在各个桶内，极端的情况是，每个桶一个元素
 *  时间复杂度：O(n+m*n/mlogn/m) O(n+ nlogn - nlogm) 当n=m时，时间复杂度为O(n)
 *  空间复杂度：O(n+m)
 *
 *  难点：确定元素所在桶编号
 *  桶的大小为d, 桶的个数k, 序列最大值max,最小值min
 *  根据桶的大小d,确定桶的个数k k = (max-min+1)/d + 1;
 *  根据桶的个数k,确定桶的大小d d = (max-min)/k;
 *  对于元素 num, 桶的编号为：(num-min+1)/d，其中 d = (max-min)/k
 *  综上，桶的编号可记作：(num-min+1)*k/(max-min)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buf[100];

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/排序-桶排序/排序-桶排序/in", "r", stdin);
    
    int n;
    while(cin >> n && n != 0)
    {
        
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            buf[i] = tmp;
        }
        int max = buf[0], min = buf[0];
        for(int i = 1; i < n; ++i)
        {
            if(buf[i] > max)
                max = buf[i];
            if(buf[i] < min)
                min = buf[i];
        }
        
//        cout << max << " " << min << endl;
        
        //每个桶的大小为10
        //桶的数量num, max-min+1 取决于最后一个区间是右开还是右闭
        int num = (max-min+1)/10+1;
        
        vector<vector<int> > bucket(num);
        
        for(int i = 0; i < n; ++i)
        {
            int no = (buf[i]-min)/10;
//            cout << buf[i] << " " << no << endl;
            bucket[no].push_back(buf[i]);
        }
        
//        cout << bucket.size() << endl;

        vector<vector<int> >::iterator bit;
        vector<int>::iterator vit;
        for(bit = bucket.begin(); bit != bucket.end(); ++bit)
        {
            if(!(*bit).empty())
                sort((*bit).begin(),(*bit).end());
        }
        
        for(bit = bucket.begin(); bit != bucket.end(); ++bit)
        {
            if(!(*bit).empty())
                for(vit = (*bit).begin(); vit != (*bit).end(); ++vit)
                    cout << * vit << " ";
        }

        
        
        
      
        
    }
    
    return 0;
}























