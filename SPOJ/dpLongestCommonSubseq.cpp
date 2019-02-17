/*

//****************************************************LCS0 - Longest Common Subsequence.**************************************************
https://www.spoj.com/problems/LCS0/




Time Complexity:O(m*n).                                                                                                                                                                                             
Space Complexity:O(m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
//******************************************************THIS IS SPOJ ACCEPTED CODE.**************************************************
// Time Complexity:O(m*n).                                                  
// Space Complexity:O(m).                                                   
// This is Dynamic Programming based solution. Here, we form a DP array, where each inde's value depend on prev. row's and prev. clmn's 
// values. That's why we use only two rows. At an index, if chars from both strings match, then we assign dp[i-1][j-1]+1 to curr. index,
// if chars doesn't match then we assign max(dp[i-1][j], dp[i][j-1]) to curr. index. Thus, at the end of iter. the longest subseq.
// length is stored in bottom right index.


// dp[i][j] indicates longest subsequence in string s upto 'i-1' index and 'j-1' index in string t.

// An advanced algorithm is detailed in this link, will need to work on this later:
// http://users.monash.edu/~lloyd/tildeStrings/Alignment/86.IPL.html 




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

    string s,t;
    cin>>s>>t;
    
    vector<vector<int>>dp(2,vector<int>(t.length()+1, 0));
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1]==t[j-1]) dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                else dp[i%2][j]=max(dp[(i-1)%2][j], dp[i%2][j-1]);
               // cout<<dp[i][j]<<" ";
            }
           // cout<<endl;
        }
        printf("%d \n", dp[(s.length())%2][t.length()]);
        // cout<<dp[(s.length())%2][t.length()]<<endl;

    return 0;
}