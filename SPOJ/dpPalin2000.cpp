/*

//***************************************************IOIPALIN - Palindrome 2000.******************************************************
https://www.spoj.com/problems/IOIPALIN/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n^2).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n^2).                                                   
// This is Longest Common Subsequence based problem. Here, we find the longest palindrome by calculating the longest common
// subsequence in given and it's reversed string. We add the remaining characters to the given string symmetrically to make it 
// the entire string palindromic.







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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int len;
    cin>>len;
    string s="";
    cin>>s;
    string t=s;
    reverse(t.begin(), t.end());
    vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, 0));
    int palin=1;
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=s.length();j++){
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
            palin=max(palin, dp[i][j]);
        }
    }
    // cout<<"palin: "<<palin<<endl;
    cout<<s.length()-palin<<endl;
    
    return 0;
}