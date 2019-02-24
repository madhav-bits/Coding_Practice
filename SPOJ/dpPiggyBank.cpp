/*

//*******************************************************PIGBANK - Piggy-Bank.*******************************************************
https://www.spoj.com/problems/PIGBANK/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m).                                                   
// This is Dynamic Programming based solution. Here, we iterate over given weights, if the curr. weight is possible to obtain using
// given coins, we iter. over coins and update the curr. weight +curr.coin's weight with min. value possible. At the end of iter, 
// if the total weight is possible with given coins, we return the min. val else we print "Impossible".











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



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;
    for(int a=0;a<tests;a++){
        int base, total, target;
        cin>>base>>total;
        target=total-base;
        int types;
        cin>>types;
        vector<pair<int,int>>coins(types);
        for(int i=0;i<types;i++){
            int val, wei;
            cin>>val>>wei;
            // cout<<"wei: "<<wei<<" and val: "<<val<<endl;
            coins[i]={wei, val};
        }
        sort(coins.begin(), coins.end());
        // cout<<"first; "<<coins[0].first<<" and val: "<<coins[0].second<<endl;
        vector<int>dp(target+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<target;i++){
            if(dp[i]==INT_MAX) continue;
            for(int j=0;j<coins.size();j++){
                int val=coins[j].second, weight=coins[j].first;
                if(i+weight>target) break;
                dp[i+weight]=min(dp[i+weight], dp[i]+val);
            }
        }
        // for(int i=0;i<=target;i++){
        //     cout<<"i: "<<i<<" and dp: "<<dp[i]<<endl;
        // }
        if(dp[target]==INT_MAX) cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[target]<<"."<<endl;
    }
    


    return 0;
}