/*

//*******************************************************MCOINS - Coins Game.*********************************************************
https://www.spoj.com/problems/MCOINS/




Time Complexity:O(n).                                                       // n- maxm. coins among all the cases.                                                                                                                                                                      
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    // n- maxm. coins among all the cases. 
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, we are looking for a case, where the starter can win, so, we iter. over all 
// moves a person make, if in any move, then opponent looses, then we mark curr. person with those many coins at disposal can win.
// We marked maxm. coins needed to set the dp array. We iter. over queries, if for the curr. #coins, the result isn't calculated, 
// we call the fn. to calculate the result.







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




bool findWinner(vector<int>&dp, int coins, vector<int>&change){
    if(coins<0) return true;                                                // Insuff. coins for earlier person leads to win of curr. person.
    if(coins==0) return false;                                              // Suff. coins for earlier person leads to losing of curr. person.
    if(dp[coins]!=-1) return (dp[coins]==0)?false:true;                     // If alaready calc. return the value directly.
    // cout<<"inside fn. with coins: "<<coins<<endl;
    bool res=false;
    for(int i=0;i<3;i++){
        if(!findWinner(dp, coins-change[i], change)) res=true;              // If next person looses, we mark curr. person to win.
    }
    if(res) dp[coins]=1;
    else dp[coins]=0;
    return res;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    

    int tests, small, large;
    cin>>small>>large>>tests;
    vector<int>change(3);
    change[0]=1; change[1]=small; change[2]=large;
    vector<int>queries(tests);
    int maxm=-1;
    for(int a=0;a<tests;a++){
        cin>>queries[a];
        maxm=max(maxm, queries[a]);
    }

    vector<int>dp(maxm+1,-1);
    int coins;
    for(int i=0;i<tests;i++){
        coins=queries[i];
        if(dp[coins]==-1) findWinner(dp,coins, change);                     // If result not calc. call fn. to calc. result.
        if(dp[coins]==1) cout<<"A";
        else cout<<"B";
    }
    cout<<endl;
    // for(int i=0;i<=maxm;i++){
    //     cout<<"i: "<<i<<" and res: "<<dp[i]<<endl;
    // }
    return 0;
}