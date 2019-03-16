/*

//************************************************ADASEQEN - Ada and Subsequence.****************************************************
https://www.spoj.com/problems/ADASEQEN/



Time Complexity:O(n*m).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n*m).                                                  
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. This one is finding the Longest Common Subsequence of two strings, where each char
// have different weight. So, we have to find the common subseq. whose sum of weights would be maxm. So, we add the char value in dp 
// array when two chars match. So, dp[(s.length())%2][t.length()] would be having maxm. weight common subseq of two strings.







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

    int len1, len2;
    cin>>len1>>len2;
    vector<int>costs(26,0);
    for(int i=0;i<26;i++) cin>>costs[i];
    string s="", t="";
    cin>>s>>t;
    vector<vector<int>>dp(2,vector<int>(t.length()+1, 0));
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=t.length();j++){
            if(s[i-1]==t[j-1]){
                // cout<<"Matched at char: "<<s[i-1]<<" i: "<<i-1<<" and j: "<<j-1<<endl;
                dp[i%2][j]=dp[(i-1)%2][j-1]+costs[s[i-1]-'a'];    
            } 
            else{
                dp[i%2][j]=max(dp[(i-1)%2][j], dp[i%2][j-1]);
            }
        }
    }
    cout<<dp[(s.length())%2][t.length()]<<endl;

    return 0;
}
