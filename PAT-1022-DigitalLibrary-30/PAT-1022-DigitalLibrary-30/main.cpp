//
//  main.cpp
//  PAT-1022-DigitalLibrary
//
//  Created by 程锋 on 15/8/31.
//  Copyright (c) 2015年 程锋. All rights reserved.
/**
 *  A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.
 
     Input Specification:
     
     Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:
     
     Line #1: the 7-digit ID number;
     Line #2: the book title -- a string of no more than 80 characters;
     Line #3: the author -- a string of no more than 80 characters;
     Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
     Line #5: the publisher -- a string of no more than 80 characters;
     Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
     It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.
     
     After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:
     
     1: a book title
     2: name of an author
     3: a key word
     4: name of a publisher
     5: a 4-digit number representing the year
     Output Specification:
     
     For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.
     
     Sample Input:
     3
     1111111
     The Testing Book
     Yue Chen
     test code debug sort keywords
     ZUCS Print
     2011
     3333333
     Another Testing Book
     Yue Chen
     test code sort keywords
     ZUCS Print2
     2012
     2222222
     The Testing Book
     CYLL
     keywords debug book
     ZUCS Print2
     2011
     6
     1: The Testing Book
     2: Yue Chen
     3: keywords
     4: ZUCS Print
     5: 2011
     3: blablabla
     Sample Output:
     1: The Testing Book
     1111111
     2222222
     2: Yue Chen
     1111111
     3333333
     3: keywords
     1111111
     2222222
     3333333
     4: ZUCS Print
     1111111
     5: 2011
     1111111
     2222222
     3: blablabla
     Not Found
 
    //bug: 查找不成功，直接return了
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>


using namespace std;

//5个可以替换为一个map数组，就不必使用switch ... case 了
map<string, vector<string>> mtitle;
map<string, vector<string>> mauthor;
map<string, vector<string>> mkeyword;
map<string, vector<string>> mpublisher;
map<string, vector<string>> myear;

int main(int argc, const char * argv[]) {
    
    freopen("/Users/chengfeng/Dev/Algorithm/PAT甲级/PAT-1022-DigitalLibrary-30/PAT-1022-DigitalLibrary-30/in", "r", stdin);
    
    int n, m;

    while(cin >> n)
    {
        
        //intitialize
        
        mtitle.erase(mtitle.begin(), mtitle.end());
        mauthor.erase(mauthor.begin(), mauthor.end());
        mkeyword.erase(mkeyword.begin(), mkeyword.end());
        mpublisher.erase(mpublisher.begin(), mpublisher.end());
        myear.erase(myear.begin(), myear.end());
        
        /**
         *  注意 getchar(),否则不会换行，读入一行空格
         */
        getchar();
        
        while(n--)
        {
            string id, title, author, keywords, publisher, year;
            
            getline(cin, id);
            
            getline(cin, title);
            mtitle[title].push_back(id);
            
            getline(cin, author);
            mauthor[author].push_back(id);
            
            getline(cin, keywords);
            
            int start = 0;
            for(int i = 0; i < keywords.size(); ++i)
            {
                if(keywords[i] == ' ')
                {
                    string s = keywords.substr(start, i-start);
                    mkeyword[s].push_back(id);
                    start = i + 1;
                }
            }
            
            string s = keywords.substr(start);
            mkeyword[s].push_back(id);
            
            getline(cin, publisher);
            mpublisher[publisher].push_back(id);
            
            getline(cin, year);
            myear[year].push_back(id);
            
        }
        
        cin >> m;
        
        getchar();  //注意
        
        string queryStr;
        while(m--)
        {
            getline(cin, queryStr);
            
            string query = queryStr.substr(queryStr.find_first_of(' ') + 1);
            
            //cout << query << endl;
            
            switch (queryStr[0])
            {
                case '1':
                    cout << queryStr << endl;
                    if(mtitle[query].size() == 0)
                         cout << "Not Found" << endl;
                    
                    sort(mtitle[query].begin(), mtitle[query].end());
                    
                    for(int i = 0; i < mtitle[query].size(); ++i)
                        cout <<  mtitle[query][i] << endl;
                    
                    break;
                    
                case '2':
                    
                    cout << queryStr << endl;
                    if(mauthor[query].size() == 0)
                        cout << "Not Found" << endl;
                    
                    sort(mauthor[query].begin(), mauthor[query].end());
                    
                    for(int i = 0; i < mauthor[query].size(); ++i)
                        cout << mauthor[query][i] << endl;
                    
                    break;
                    
                case '3':
                    
                    cout << queryStr << endl;
                    if(mkeyword[query].size() == 0)
                        cout << "Not Found" << endl;
                    
                    sort(mkeyword[query].begin(), mkeyword[query].end());
                    
                    for(int i = 0; i < mkeyword[query].size(); ++i)
                        cout << mkeyword[query][i] << endl;
                    
                    break;
                    
                case '4':
                    
                    cout << queryStr << endl;
                    if(mpublisher[query].size() == 0)
                        cout << "Not Found" << endl;
                    
                    sort(mpublisher[query].begin(), mpublisher[query].end());
                    
                    for(int i = 0; i < mpublisher[query].size(); ++i)
                        cout << mpublisher[query][i] << endl;
                    
                    break;
                    
                case '5':
                    
                    cout << queryStr << endl;
                    if(myear[query].size() == 0)
                        cout << "Not Found" << endl;
                    
                    sort(myear[query].begin(), myear[query].end());
                    
                    for(int i = 0; i < myear[query].size(); ++i)
                        cout << myear[query][i] << endl;
                    
                    break;
                    
                default:
                    break;
            }
        }
    }
    
    return 0;
}











































