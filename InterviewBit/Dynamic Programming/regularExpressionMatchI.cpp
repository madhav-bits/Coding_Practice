/*
*
//**************************************************************Regular Expression Match.*********************************************************

https://www.interviewbit.com/problems/regular-expression-match/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



aab
*?*b


aaaab
*?*b



aaaab
aaa*?*b


aaaab
aaa*?*




aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*


""
"*"


"a"
""



caabccca
c*


a
?

// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, two chars to focus on are '?' and '*', '?' takes in any char, so we have make sure that 
// dp[i-1][j-1] is true, s[i] would be matched by '?' char. We have '*', this char matches any sequence of chars including empty chars(removing
// curr. index in t), in this case if dp[i][j-1] is true, we set dp[i][j] to true.
// , or any char in s, means ignoring that char in s, in this case if dp[i-1][j] is true, we set dp[i][j] to true. If s[i] and t[j] match and 
// dp[i-1][j-1] is true, we set dp[i][j] to true. Finally we return dp[s.length()][t.length()] indicating whether s is completely matched by t.


// dp[i][j] indicates whether s substring until index 'i-1' is matched by t substring until index 'j-1'.








int Solution::isMatch(const string s, const string t) {
    vector<vector<bool>>dp(s.length()+1, vector<bool>(t.length()+1, false));
    dp[0][0]=true;
    for(int j=1;j<=t.length();j++){											// Setting values for empty target string is given.
        if(t[j-1]=='*' && dp[0][j-1]==true) dp[0][j]=true;    
    }
    
    for(int i=1;i<=s.length();i++){											// Iter. over both strings.
        for(int j=1;j<=t.length();j++){
            // if(i==2 && j==1) cout<<"dp: "<<dp[i-1][j]<<"s: "<<s[i-2]<<endl;
            if((s[i-1]==t[j-1] || t[j-1]=='?') && dp[i-1][j-1]==true) dp[i][j]=true;// If dp[i-1][j-1]=true, curr. chars match  or '?'. 
            if(t[j-1]=='*' && (dp[i][j-1]==true)) dp[i][j]=true;			// Ignoring char from t, when '*' encountered.
            if(t[j-1]=='*' && dp[i-1][j]==true) dp[i][j]=true;				// Ignoring char from s(* from t matching chars from s).
        }
    }
    // for(auto nums: dp){
    //     for(auto num: nums)
    //         cout<<num<<" ";
    //     cout<<endl;
    // }
    return dp[s.length()][t.length()];										// Returing whether strings matching or not. 
}









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, two chars to focus on are '?' and '*', '?' takes in any char, so we have make sure that 
// dp[i-1][j-1] is true, s[i] would be matched by '?' char. We have '*', this char matches any sequence of chars including empty chars(removing
// curr. index in t), in this case if dp[i][j-1] is true, we set dp[i][j] to true.
// , or any char in s, means ignoring that char in s, in this case if dp[i-1][j] is true, we set dp[i][j] to true. If s[i] and t[j] match and 
// dp[i-1][j-1] is true, we set dp[i][j] to true. Finally we return dp[s.length()][t.length()] indicating whether s is completely matched by t.


// dp[i][j] indicates whether s substring until index 'i-1' is matched by t substring until index 'j-1'.


// This is optimized version of above solution, Space Complexity wise.








int Solution::isMatch(const string s, const string t) {
    vector<vector<bool>>dp(2, vector<bool>(t.length()+1, false));
    dp[0][0]=true;
    for(int j=1;j<=t.length();j++){
        if(t[j-1]=='*' && dp[0][j-1]==true) dp[0][j]=true; 
    }
    
    for(int i=1;i<=s.length();i++){
        dp[i%2][0]=false;
        for(int j=1;j<=t.length();j++){
            dp[i%2][j]=false;
            // if(i==2 && j==1) cout<<"dp: "<<dp[i-1][j]<<"s: "<<s[i-2]<<endl;
            if((s[i-1]==t[j-1] || t[j-1]=='?') && dp[(i-1)%2][j-1]==true) dp[i%2][j]=true;
            if(t[j-1]=='*' && dp[i%2][j-1]==true) dp[i%2][j]=true;
            if(t[j-1]=='*' && dp[(i-1)%2][j]==true) dp[i%2][j]=true;
        }
    }
    // for(auto nums: dp){
    //     for(auto num: nums)
    //         cout<<num<<" ";
    //     cout<<endl;
    // }
    return dp[s.length()%2][t.length()];
}
