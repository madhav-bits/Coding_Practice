/*

//************************************************ANARC05H - Chop Ahoy! Revisited!.**************************************************
https://www.spoj.com/problems/ANARC05H/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n*m).                                                    // m- sum of all elements.             

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n*m).                                                 // m- sum of all elements.                                                   
// This is Dynamic Programming based solution. Here, we iterate over given array and form subarrays[i,j] from various indices, calc. 
// their sum and adding the #combinations from next index(j+1) with sum>=subarray's sum which we store in dp array.Since it leads to 
// few overlapping subproblems, hashing/storing helps us optimize the solution. After setting dp values for an index, we iter. over
// DP array in that row in reverse drn and add dp[i][sum+1] to dp[i][sum], which is the main use of DP array. We travel from
// reverse drn as dp[i][sum] indicates #combi. starting index 'i', with first subarray's total>=sum, while init. dp array's values
// they represnt #subarrays only for that sum, we iter. in reverse drn and make it a cumulative one.



// dp[i][sum] indicates #combi. starting index 'i', with first subarray's total>=sum









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

    
    int test=0;
    string s="";
    cin>>s;
    while(s!="bye"){
        test++;
        int total=0;
        for(auto ch:s) total+=(ch-'0');
        vector<vector<int>>dp(s.length()+1, vector<int>(total+1,0));
        for(int j=0;j<=total;j++) dp[s.length()][j]=1;
        for(int i=s.length()-1;i>=0;i--){
            int sum=0;
            for(int j=i;j<s.length();j++){
                sum+=(s[j]-'0');
                dp[i][sum]+=dp[j+1][sum];
            }
            // int accum=0;
            for(int j=total-1;j>=0;j--) dp[i][j]+=dp[i][j+1];
        }
        cout<<test<<". "<<dp[0][0]<<endl;
        cin>>s;
    }
    

    return 0;
}