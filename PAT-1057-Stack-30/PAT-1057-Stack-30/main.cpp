//
//  main.cpp
//  PAT-1057-Stack-30
//
//  Created by 程锋 on 15/8/25.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains a positive integer N (<= 10^5). Then N lines follow, each contains a command in one of the following 3 formats:
     
     Push key
     Pop
     PeekMedian
     where key is a 「positive」 integer no more than 10^5.
     
     Output Specification:
     
     For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.
     
     Sample Input:
     17
     Pop
     PeekMedian
     Push 3
     PeekMedian
     Push 2
     PeekMedian
     Push 1
     PeekMedian
     Pop
     Pop
     Push 5
     Push 4
     PeekMedian
     Pop
     Pop
     Pop
     Pop
     Sample Output:
     Invalid
     Invalid
     3
     2
     2
     1
     2
     4
     4
     5
     3
     Invalid
 
    获取中位数算法思想：对每个添加的元素进行计数，中位数即数组前i项和等于（s.size()+1）/ 2的下标，因此，需要频繁的求数组区间和，这里是前i项和，使用树状数组可以在O(lgn)的复杂度内完成求前i项和，否则求前i项和的时间复杂度为O(n) 
    树状数组应用场景：频繁查询数组以及频繁求数组区间和和情况
    tip: 获取中位数对时间要求高，使用树状数组，并且，输入，输出一定要用scanf 和 printf
 */

#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string.h>

#define N 100005

using namespace std;

stack<int> s;
int n;

struct TreeArray{
    vector<int> a;
    TreeArray()
    {
        a = vector<int>(N, 0);
    }
    
    void print()
    {
        for(int i = 0; i < 20; ++i)
        {
            cout << a[i] << " ";
        }
    }
    
    int lowbit(int i)
    {
        return i & (-i);
    }
    
    
    void update(int i, int x)
    {
        while(i <= N)
        {
            a[i] += x;
            i = i + lowbit(i);
        }
    }
    
    //前i项和
    int getSum(int i)
    {
        int sum = 0;
        while(i > 0)
        {
            sum += a[i];
            i -= lowbit(i);
        }
        
        return sum;
    }
    
    //查找第i个元素
    int findMedian(int i, int low, int high)
    {
        /*
        if(low == high)
            return low;
        
        int mid = (low + high) / 2;
        
        if(getSum(mid) < i)
            return findMedian(i, mid + 1, high);
        else
            return findMedian(i, low, mid);
         */
        
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            if(getSum(mid) < i)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }

}tree;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1057-Stack-30/PAT-1057-Stack-30/in", "r", stdin);

    while(cin >> n)
    {
        while(!s.empty())
            s.pop();
        
        while(n--)
        {
            char command[20];
            
            scanf("%s", command);
            
            if(command[1] == 'o')
            {
                if(!s.empty())
                {
                    int tmp = s.top();
                    
                    tree.update(tmp, -1);
                    
                    cout << tmp << endl;
                    s.pop();
                }
                else
                {
                    cout << "Invalid" << endl;
                    continue;
                }
            }
            else if (command[1] == 'e')
            {
                if(s.empty())
                {
                    cout << "Invalid" << endl;
                    continue;
                }
                
                //tree.print();
//                cout << endl;
                printf("%d\n", tree.findMedian((int)(s.size()+1)/2, 1, N));  //使用cout 超时，使用prinf
                
            }
            else if(command[1] == 'u')
            {
                int key ;
                
                scanf("%d", &key);  //使用cin超时，使用scanf
                
                tree.update(key, 1);
                
                s.push(key);
            }
            else
            {
                cout << "Invalid";
                continue;
            }
        }
        
    }
    
    return 0;
}
























