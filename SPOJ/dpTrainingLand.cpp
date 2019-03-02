/*

//**************************************************NFURY - Training Land of Fury.****************************************************
NFURY - Training Land of Fury




Time Complexity:O(n*m).                                                     //m=# perfect squares less than largest input given.                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n*m).                                            //m=# perfect squares less than largest input given.                 
// Space Complexity:O(1).                                                   
// This is Dynamic Programming based solution. This is precomputation based. Here, we computer cost for a area based on costs
// computed applied for smaller areas, so we iter. over perfect. squares less than curr. number and try to update curr. cost with
// (costs from curr. num-perf. square)+1. After init. all values, we iter. over queries, return the costs directly from the DP 
// array.





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










void findCost(vector<int>&dp){
    // unordered_set<int>st;
    vector<int>sq;
    int k=1;
    while(k*k<=1000){
        sq.push_back(k*k);
        k++;
    }
    dp[0]=0;
    for(int i=1;i<=1000;i++){
        int j=0;
        while(i-sq[j]>=0){
            // cout<<"i: "<<i<<" and sq; "<<sq[j]<<endl;
            dp[i]=min(dp[i], dp[i-sq[j]]+1);
            j++;
        } 
    }
    return ;
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;

    vector<int>dp(1001,INT_MAX);
    findCost(dp);
    int target;
    for(int a=0;a<tests;a++){
        cin>>target;
        cout<<dp[target]<<endl;
    }


        
    

    return 0;
}

