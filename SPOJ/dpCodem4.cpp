/*

//*******************************************************CODEM4 - Problem4.***********************************************************
https://www.spoj.com/problems/CODEM4/




Time Complexity:O((n^2)^2).                                                                                                                                                                                             
Space Complexity:O(n^2).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O((n^2)^2).                                                  
// Space Complexity:O(n^2).                                                   
// This is Dynamic Programming based solution. This is Top to Bottom based solution. Here, in case of smart opponent, everyone tries
// to minmize opponents score by opting an option that minmizes opponen't score in the long run. 
// In case of dumb opoonent, since he won't follow any logic, but since we are trying to get maxm. score for first player, we make
// the dumb opponent to follow a logic, where is trying to maximize opponent's score/(minimize his score).


// Since, in case of smarter opponent, as both the players try to maximize their score, dp[low][high] indicates maxm. score attainable
// by any player, if he has to chance to choose integer with [low, high] state of board.


// Since, in case of dumb opponent, opponent tries to get minimum score given any state, dpSecond[low][high] stores minm. opponent's
// score attainable. dpFirst[low][high] indicates maxm. score attainable by first player.







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





int smartVersion(vector<int>&v, int low, int high, vector<vector<int>>&dp, vector<int>&prefix){
    if(dp[low][high]!=-1) return dp[low][high];
    if(low>high) return 0;

    if(low==high){
        dp[low][high]=v[low];
        return v[low];
    }
    int res=smartVersion(v,low+1, high, dp, prefix);
    int res2=smartVersion(v,low, high-1, dp, prefix);
    int total=prefix[high+1]-prefix[low];
    // cout<<"low: "<<low<<" and high: "<<high<<" and total: "<<total<<endl;
    dp[low][high]=total-min(res,res2);                                      // Smart opponent tries to achieve maxm. score.
    return dp[low][high];
}





int dumbVersion(vector<int>&v, int low, int high, vector<vector<int>>&dpFirst, vector<vector<int>>&dpSecond, vector<int>&prefix, bool turn){
    if(turn && dpFirst[low][high]!=-1) return dpFirst[low][high];
    if(!turn && dpSecond[low][high]!=-1) return dpSecond[low][high];
    if(low>high) return 0;

    if(low==high){
        if(turn) dpFirst[low][high]=v[low];
        else dpSecond[low][high]=v[low];
        return v[low];
    }

    int res=dumbVersion(v,low+1, high, dpFirst, dpSecond, prefix, !turn);
    int res2=dumbVersion(v,low, high-1, dpFirst, dpSecond, prefix, !turn);
    int total=prefix[high+1]-prefix[low];
    // cout<<"low: "<<low<<" and high: "<<high<<" and total: "<<total<<endl;
    if(turn){                                                               
        dpFirst[low][high]=total-min(res,res2);
        return dpFirst[low][high];
    } 
    else{
        dpSecond[low][high]=total-max(res,res2);                            // Dumb opponent tries to achieve minm. score.
        return dpSecond[low][high];
    }
}






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nums;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>nums;
        vector<int>v(nums);
        for(int i=0;i<v.size();i++) cin>>v[i];
        vector<int>prefix(nums+1,0);
        for(int i=0;i<v.size();i++){
            prefix[i+1]=prefix[i]+v[i];
            // cout<<"new prefix i: "<<i<<" and val: "<<prefix[i+1]<<endl;
        }
        vector<vector<int>>dp(v.size(), vector<int>(v.size(),-1));
        int val1=smartVersion(v,0,v.size()-1, dp, prefix);
        // for(int i=0;i<v.size();i++){
        //     for(int j=0;j<v.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        dp=vector<vector<int>>(v.size(), vector<int>(v.size(),-1));
        vector<vector<int>>dpSecond(v.size(), vector<int>(v.size(),-1));
        int val2=dumbVersion(v,0,v.size()-1, dp, dpSecond ,prefix, true);
        cout<<val2<<" "<<val1<<endl; 
    }

    return 0;
}
