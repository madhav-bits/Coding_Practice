/*

//***********************************************************AIBOHP - Aibohphobia.*********************************************************
https://www.spoj.com/problems/AIBOHP/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, we need to add min. chars to make string palindrome. So, we find the longest palin-
// -drome subseq. in the given string and add the rest chars symmetrically in the string to make it a total palindrome string. To find
// the longest palindrome subseq. we use the Longest Common Subsequene(LCS), by finding the LCS of given string and it's reversed string.
// Where it's the longest subseq., since we are working on reversed strings, it becomes Longest Palindromic Subsequence. At the end of 
// process, we return the (total string length-Longest Palin. Subseq.) length.












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
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(), t.end());
        vector<vector<int>>dp(2, vector<int>(s.length()+1, 0));

        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1]==t[j-1]) dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                else dp[i%2][j]=max(dp[(i-1)%2][j], dp[i%2][j-1]);
               // cout<<dp[i][j]<<" ";
            }
           // cout<<endl;
        }
        int len=dp[(s.length())%2][t.length()];
        cout<<(int)s.length()-len<<endl;
    }
    

    return 0;
}