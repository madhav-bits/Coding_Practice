/*

//**************************************************ROCK - Sweet and Sour Rock.******************************************************
https://www.spoj.com/problems/ROCK/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, since we need optimal cuts to sell maxm. length of sweet. We use DP, one way
// is naive way where we get optimal cut for every substring by iter. over all cuts and chooseing that cut which leads to selling
// maxm. substring length. This is of O(n^3) complexity. 


// The optimized solution is, for adding every index into our string, since curr. index ill be part optimal cut, we iter. over all
// possible last cuts which includes curr. index and choose that cut that gives maxm. substring length sellable for curr. substring.
// In this way, we get maxm. possible sellable substring length by the time we reach end of string.






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



int getLength(int low, int high, vector<vector<int>>&dp, vector<int>&prefix){// Uses 2D dp array with O(n^3) solution.
    if(low>high) return 0;
    if(dp[low][high]!=-1) return dp[low][high];
    int candies=prefix[high+1]-prefix[low];
    int len=high-low+1;
    if(candies>len/2){
        dp[low][high]=len;
        // cout<<"Matching substring: low: "<<low<<" and high: "<<high<<" candies: "<<candies<<" and len: "<<len<<endl; 
        return len;
    }
    int res=0;
    for(int i=low;i<high;i++){
        res=max(res, getLength(low, i, dp, prefix)+getLength(i+1, high, dp, prefix));
    }
    dp[low][high]=res;
    return res;
}






int getMaxLength(vector<int>&prefix){

    int leng=prefix.size()-1;
    vector<int>dp(leng,0);

    for(int i=0;i<leng;i++){
        int candies=prefix[i+1];
        int len=i+1;
        if(candies>len/2){
            dp[i]=len;
        }
        int res=0;
        for(int j=0;j<i;j++){
            int cand=prefix[i+1]-prefix[j+1];
            len=i-j;
            res=max(res, dp[j]+((cand>len/2)?len:0));
        }
        // cout<<"i: "<<i<<" and res: "<<res<<endl;
        dp[i]=max(dp[i], res);
    }
    return dp.back();
}






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, len;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>len;
        string s="";
        cin>>s;
        vector<int>prefix(s.length()+1,0);
        for(int i=0;i<s.length();i++){                                      // Used to get #candies in each substring.
            if(s[i]=='1') prefix[i+1]=prefix[i]+1;
            else prefix[i+1]=prefix[i];
        }
        vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));
        // getLength(0,s.length()-1, dp, prefix);                           // Uses 2D dp array with O(n^3) solution.
        // cout<<dp[0][len-1]<<endl;


        int res=getMaxLength(prefix);                                       // Uses 1D dp array with O(n^2) solution.
        cout<<res<<endl;
    }

    return 0;
}
