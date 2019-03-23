/*

//********************************************************BAT2 - BATMAN2.************************************************************
https://www.spoj.com/problems/BAT2/




Time Complexity:O(n^3).                                                                                                                                                                                             
Space Complexity:O(n^3).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^3).                                                  
// Space Complexity:O(n^3).                                                   
// This is Dynamic Programming based solution. This is of the same logic as dpBlackOWhite. Here, since we need to find the longest 
// visited indices, we find the minm. skipped indices and substract that from the total length to get longest painted indices.





// This video has explanation of this Top Down Approach:
// https://www.facebook.com/programmingcompetitive/videos/1851244488535869/?type=2&theater









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
#include<cstring>



using namespace std;




int findMinIndices(vector<int>&v, int index, int lastInc, int lastDec, vector<vector<vector<int> > >&dp){// vector<vector<vector<int> > >&dp
    if(index==v.size()) return 0;
    if(dp[index][lastInc][lastDec]!=-1) return dp[index][lastInc][lastDec];

    int res1=1+findMinIndices(v,index+1, lastInc, lastDec, dp);
    int res2=INT_MAX;
    if(lastInc<v[index]) res2=findMinIndices(v,index+1, v[index], lastDec, dp);
    int res3=INT_MAX;
    if(lastDec==0 || lastDec>v[index]) res3=findMinIndices(v, index+1, lastInc, v[index], dp);

    return dp[index][lastInc][lastDec]=min(res1, min(res2,res3));

}



void compress(vector<int>&v){
    vector<pair<int,int>>compr;
    for(int i=0;i<v.size();i++) compr.push_back({v[i], i});
    sort(compr.begin(), compr.end());
    int rank=1;
    for(int i=0;i<compr.size();i++){
        if(i>0 && compr[i].first!=compr[i-1].first) rank++;
        v[compr[i].second]=rank;
    }
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");


    int tests, rooms;
    cin>>tests;

    for(int a=0;a<tests;a++){
        cin>>rooms;
        vector<int>v(rooms);
        for(int i=0;i<rooms;i++) cin>>v[i];
        compress(v);
        vector<vector<vector<int> > >dp(101, vector<vector<int>>(101, vector<int>(101,-1)));
        // int dp[201][201][201];
        // memset(dp, -1, sizeof dp);
        int res=findMinIndices(v,0,0,0, dp);
        cout<<v.size()-res<<endl;
    }
    
    return 0;
}
