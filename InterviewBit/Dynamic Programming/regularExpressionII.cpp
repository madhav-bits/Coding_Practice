/*
*
//************************************************************Regular Expression II.*****************************************************

https://www.interviewbit.com/problems/regular-expression-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


s
**


s
s*



abcd
ab*d



abcccd
abc*d



abc
ab**c



ac
ab***c



caaba
ca*ba




// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, the important logic is of handling '*' char, it means considering zero/more times of prev. 
// char. In case of 'a*', if both chars are ignored then dp[i][j] = dp[i][j-2], if 'a*' matches multiple chars from s string, then it's that 
// those chars from s are ignored/matched, then dp[i][j] is true if dp[i-1][j] is true. We use these steps and fill up the whole DP table and
// return dp[s.length()][t.length()].








int Solution::isMatch(const string s, const string t) {
    vector<vector<bool>>dp(s.length()+1, vector<bool>(t.length()+1, false));
    dp[0][0]=true;
    for(int j=2;j<=t.length();j++){											// Filling first row of DP array. Init. base cases.
        if(dp[0][j-2]==true && t[j-1]=='*') dp[0][j]=true;
    }
    
    for(int i=1;i<=s.length();i++){											// ITer. over target string.
        for(int j=1;j<=t.length();j++){										// Iter. over given string.
            if(dp[i-1][j-1]==true && (s[i-1]==t[j-1]|| t[j-1]=='.')) dp[i][j]=true;// If curr. chars matched, t[j-1] is '.', then true.
            if(t[j-1]=='*' && j>1) dp[i][j]=dp[i][j-2];						// Ignores curr. and prev. char of t string.
            if(t[j-1]=='*' && (s[i-1]==t[j-2] || t[j-2]=='.')) dp[i][j]=(dp[i][j]||dp[i-1][j]);// Ignores/Matches curr. char from s.
        }
    }
    
    // for(auto nums: dp){
    //     for(auto num:nums)
    //         cout<<num<<" ";
    //     cout<<endl;
    // }
    
    return dp[s.length()][t.length()];										// Returning matching state of entire target string and given string.
}












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, the important logic is of handling '*' char, it means considering zero/more times of prev. 
// char. In case of 'a*', if both chars are ignored then dp[i][j] = dp[i][j-2], if 'a*' matches multiple chars from s string, then it's that 
// those chars from s are ignored/matched, then dp[i][j] is true if dp[i-1][j] is true. We use these steps and fill up the whole DP table and
// return dp[s.length()][t.length()].



// This algorithm is similar to above algorithm, except that, it is optimized space complexity wise.







int Solution::isMatch(const string s, const string t) {
    vector<vector<bool>>dp(2, vector<bool>(t.length()+1, false));
    dp[0][0]=true;
    for(int j=2;j<=t.length();j++){
        if(dp[0][j-2]==true && t[j-1]=='*') dp[0][j]=true;
    }
    
    for(int i=1;i<=s.length();i++){
        dp[i%2][0]=false;
        for(int j=1;j<=t.length();j++){
            dp[i%2][j]=false;
            if(dp[(i-1)%2][j-1]==true && (s[i-1]==t[j-1]|| t[j-1]=='.')) dp[i%2][j]=true;
            if(t[j-1]=='*' && j>1) dp[i%2][j]=dp[i%2][j-2];
            if(t[j-1]=='*' && (s[i-1]==t[j-2] || t[j-2]=='.')) dp[i%2][j]=(dp[i%2][j]||dp[(i-1)%2][j]);
        }
    }
    
    // for(auto nums: dp){
    //     for(auto num:nums)
    //         cout<<num<<" ";
    //     cout<<endl;
    // }
    
    return dp[s.length()%2][t.length()];
}
