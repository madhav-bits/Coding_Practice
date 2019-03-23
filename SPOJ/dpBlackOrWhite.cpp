/*

//*****************************************************BORW - Black or White.*********************************************************
https://www.spoj.com/problems/BORW/




Time Complexity:O(n^3).                                                                                                                                                                                             
Space Complexity:O(n^3).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^3).                                                  
// Space Complexity:O(n^3).                                                   
// This is Dynamic Programming based solution. This is Top To Down approach. Here, we start from first index, since an index can be
// taken into black or white or not taken, we consider three possibilities and accept the best result. We take 
// dp[index][lastBlack][lastWhite] as variants as even if we take paint curr. index as white, the black index would be prev. painted
// index, so we have to maintain prev. painted indices as variants. If we skip an index, we inc. the count, and if we paint the index,
// we get the count from next recursive call. Since, we are counting skipped indices, we return the minm. count of all three possib.



// dp[index][lastBlack][lastWhite] indicates minm. #skipped indices if we are at index, where the last painted index with black color 
// is 'lastBlack' and last painted white index is 'lastWhite'.






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




int findMinIndices(vector<int>&v, int index, int lastBlack, int lastWhite, vector<vector<vector<int> > >&dp){// vector<vector<vector<int> > >&dp
    if(index==v.size()) return 0;
    if(dp[index][lastBlack][lastWhite]!=-1) return dp[index][lastBlack][lastWhite];

    int res1=1+findMinIndices(v,index+1, lastBlack, lastWhite, dp);
    int res2=INT_MAX;
    if(lastBlack<v[index]) res2=findMinIndices(v,index+1, v[index], lastWhite, dp);
    int res3=INT_MAX;
    if(lastWhite==0 || lastWhite>v[index]) res3=findMinIndices(v, index+1, lastBlack, v[index], dp);

    return dp[index][lastBlack][lastWhite]=min(res1, min(res2,res3));

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

    int nums;
    cin>>nums;
    while(nums!=-1){
        vector<int>v(nums);
        for(int i=0;i<nums;i++) cin>>v[i];
        compress(v);
        vector<vector<vector<int> > >dp(201, vector<vector<int>>(201, vector<int>(201,-1)));
        // int dp[201][201][201];
        // memset(dp, -1, sizeof dp);
        int res=findMinIndices(v,0,0,0, dp);
        cout<<res<<endl;
        cin>>nums;
    }
    return 0;
}
