/*

//*******************************************************ADFRUITS - Advanced Fruits.**************************************************
https://www.spoj.com/problems/ADFRUITS/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n^2).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n^2).             
//******************************************THIS IS SIMILAR TO LONGEST COMMON SUBSEQUENCE PROBLEM.************************************                                      
// This is Dynamic Programming based Solution. Here, the concept is to get a smallest supersequence which includes gien two strings as 
// a sequence in it. Here at every index, we check for two cdns, if chars from both strs are equal, we add len. of supersesquence to 
// include two strings till [i-1], [j-1] index resp. and add 1 to it and assign to current index. If they doesn't match, we make min. 
// steps from two possibilities dp[i-1][j], dp[i][j-1] which tries to match one of unmatched from earlier char from other string and
// so on. At the end of iteration, we get least supersequence to get given two strs as subseq.
// In the second step, we backtrack the DP array from last index to starting index through the way in which min. moves are taken
// at each step, thus giving min. length reverse supersequence at the end of backtracking. We reverse this string and return it.






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

    
    string s="", t="";
    cin>>s;
    while(!cin.eof()){
        cin>>t;
        // cout<<"s: "<<s<<" and t: "<<t<<endl;
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, 0));    
        for(int j=1;j<=t.length();j++) dp[0][j]=j;
        for(int i=1;i<=s.length();i++) dp[i][0]=i;
        
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;    
                else{
                    dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

        string res="";
        int i=s.length(), j=t.length();
        while(i!=0 || j!=0){
            // cout<<"i: "<<i<<" and j: "<<j<<endl;
            if(s[i-1]==t[j-1]){
                res+=s[i-1];
                i--;j--;
            }else if(j>0 && dp[i][j]==1+dp[i][j-1]){
                res+=t[j-1];
                j--;
            }else if(i>0 && dp[i][j]==1+dp[i-1][j]){
                res+=s[i-1];
                i--;
            }
            // cout<<"res: "<<res<<endl;
        }
        // res.pop_back();
        reverse(res.begin(), res.end());
        cout<<res<<endl;
        cin>>s;

    }

    return 0;
}