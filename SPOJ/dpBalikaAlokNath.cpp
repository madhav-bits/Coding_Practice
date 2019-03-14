/*

//***********************************************BVAAN - Balika Vadhu and Alok Nath.***************************************************
https://www.spoj.com/problems/BVAAN/




Time Complexity:O(n*m*p).                                                                                                                                                                                             
Space Complexity:O(n*m*p).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n*m*p).                                                  
// Space Complexity:O(n*m*p).                                                   
// This is Dynamic Programming based solution. Here, since we need a subsequence of length 'k' with maxm. sum, we maintain a array
// of length 'k' for each index. If curr. chars of two strings match, we update the array with 'k' elems. based on values from 
// dp[i-1][j-1] and on curr. char.We also try to update it with prev. val directly. If chars doesn't match, we take max. of two values
// from dp[i-1][j] and dp[i][j-1]. At every index, we update the final result with value in kth index of array.










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
    string s="", t="";
    int targetLen=0;
    for(int a=0;a<tests;a++){
        cin>>s>>t>>targetLen;
        // cout<<"targetLen: "<<targetLen<<endl;
        vector<vector<vector<int>>>dp(s.length()+1, vector<vector<int>>(t.length()+1, vector<int>(targetLen+1,-1)));
        int res=0;
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=t.length();j++){
                dp[i][j][0]=0;
            }
        }

        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                for(int k=targetLen;k>0;k--){
                    if(s[i-1]==t[j-1] && dp[i-1][j-1][k-1]>-1) dp[i][j][k]=max(dp[i-1][j-1][k], dp[i-1][j-1][k-1]+s[i-1]);
                    else if(s[i-1]!=t[j-1]) dp[i][j][k]=max(dp[i][j-1][k], dp[i-1][j][k]);
                }
                res=max(res, dp[i][j][targetLen]);
                // cout<<dp[i][j][targetLen]<<" ";
            }
            // cout<<endl;
        }
        cout<<res<<endl;
    }

    return 0;
}
