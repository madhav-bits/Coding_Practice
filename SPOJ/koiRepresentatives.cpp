/*

//***************************************************KOIREP - Representatives.********************************************************
https://www.spoj.com/problems/KOIREP/




Time Complexity:O((n*m)logn).                                                                                                                                                                                             
Space Complexity:O(n*m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O((n*m)logn).                                                  
// Space Complexity:O(n*m).                                                   
// This is Sliding Window & Priority Queue based solution.  Here, since we need minm. diff b/w rep from each class, we sort the given 
// classes, we take least values from all of them. Subtract the maxm. and minm. of those and udpdate the result. We move ahead the ptr
// of least value in hope with the points width b/w maxm. and minm. dec. So, to get minm value, we use priority queue. remove least val
// and push it's following element into PQ, and try to update the maxm. var. Same process goes again, we do this until we reach end of 
// any class's reps.







#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;




struct comp{                                                                // Returns the pair with minm. first value.
    bool operator()(pair<int,int>&lt, pair<int,int>&rt){
        return lt.first>rt.first;
    }
};



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int rows, cols;
    cin>>rows>>cols;
    // cout<<"rows: "<<rows<<" and cols: "<<cols<<endl;
    vector<vector<int>>v(rows, vector<int>(cols,0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++) cin>>v[i][j];
        sort(v[i].begin(), v[i].end());
    }
    // cout<<"yo"<<endl;
    vector<int>indices(rows,0);
    int res=INT_MAX, maxm=INT_MIN, minm=INT_MAX;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp>pq;
    for(int i=0;i<rows;i++){
        maxm=max(maxm, v[i][0]);
        // int ind=(i)*cols;
        pq.push({v[i][0],i*cols});
    }
    while(true){
        res=min(res, maxm-pq.top().first);
        // cout<<"maxm: "<<maxm<<" and minm: "<<pq.top().first;
        int row=pq.top().second/cols, col=pq.top().second%cols;
        // cout<<"row: "<<row<<" and col: "<<col<<endl;
        pq.pop();
        col++;
        if(col==cols) break;
        int ind=(row)*cols+(col);
        pq.push({v[row][col],ind});
        maxm=max(maxm, v[row][col]);
    }  
    cout<<res<<endl;


    return 0;
}
