/*
*
//*************************************************************131. Palindrome Partitioning.****************************************************

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

""
"aa"
"abcba"



// Time Complexity: O(n^2).
// Space Complexity: O(n^3).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^3).			
// This algorithm is dfs, 
// We do a dfs, at each step using isPalindrome function we know whether the substring is palin.. Once we reach the end of string,
// forming palindromes till then. Then we push all this palindromic substr accumulated in the vector stirng into the final result vector 2D array.

class Solution {
public:
    
    vector<vector<string>>v;
    
    void findSubStr(vector<string>u, int start, string s){
        int i=start;
            for(int j=start;j<s.length();j++){
                if(isPalindrome(s,i,j)){//dp[i][j]==1
                    u.push_back(s.substr(i,j-i+1));
                    if(j==s.length()-1) v.push_back(u);
                    findSubStr(u,j+1,s);
                    u.pop_back();
                }
                
            }
        
    }
    
    bool isPalindrome(string s, int begin, int end){
        while(begin<end){
            if(s[begin]!=s[end])
                return false;
            begin++; end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        if(s.length()==0) return v;
        vector<string> u;
        
        findSubStr(u,0,s);
        
        return v;
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).		
// Space Complexity: O(n^3).	//Not exactly n^3 complexity.		
// This algorithm is dfs, fisrt created dp array, whose rows and clmn indicate the start and end of substring, and say whether they are palin.
// are not. We do a dfs, at each step using dp array we know whether the substring is palin. from dp array. Once we reach the end of string,
// forming palindromes till then. Then we push all this palindromic substr accumulated in the vector stirng into the final result vector 2D
// array.







class Solution {
public:
    
    vector<vector<string>>v;
    
    void findSubStr(vector<vector<int>> dp, vector<string>u, int start, string s){
        int i=start;
            for(int j=start;j<dp.size();j++){				// The checking substr has to begin from the "start" index.
                if(dp[i][j]==1){							// Says substr start at "i" and end at "j" is palindrome.
                    u.push_back(s.substr(i,j-i+1));			// Temp. storing the pain. substr in the temp vector, in search of following palin.
                    if(j==dp.size()-1) v.push_back(u);		//If we reach end of string making all palindromes till then,then push into final array.
                    findSubStr(dp,u,j+1,s);					// Looking for following palin.
                    u.pop_back();							// To accomodate other palin. combi. starting from index "start".
                }
                
            }
        
    }
    
    vector<vector<string>> partition(string s) {
        if(s.length()==0) return v;							//If length=0, then we won't get palin. strings, so, return NULL.
        vector<string> u;
        int len=s.length();
        vector<vector<int>>dp(len,vector<int>(len,0));		// DP array to store palin. substirng- true or not.
        for(int i=0;i<len;i++) dp[i][i]=1;
        
        for(int k=2;k<=len;k++){							// Dynamic Programming, array to store whether the substr is palin. or not.
            for(int i=0;i+k-1<len;i++){
                int j=i+k-1;
                //cout<<" i is: "<<i<<" and j: "<<j<<" values are: "<< s[i]<<" and "<<s[j]<<" and dp value: "<<dp[i+1][j-1]<<endl;
                if(j==i+1 && s[i]==s[j])
                    dp[i][j]=1;
                else if(s[i] ==s[j] && dp[i+1][j-1]==1)
                    dp[i][j]=1;
                
            }
        }
        findSubStr(dp,u,0,s);
        /*
        for(auto nums:dp){
            for(auto  num:nums)
                cout<<num<<" ";
            cout<<endl;
        }
        */
        return v;
    }
};