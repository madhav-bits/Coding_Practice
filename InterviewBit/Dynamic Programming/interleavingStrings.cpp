/*
*
//************************************************************Interleaving Strings.*****************************************************

https://www.interviewbit.com/problems/interleaving-strings/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


aabcc
dbbca
aadbbcbcac



aabcc
dbbca
aadbbbaccc



aabcxabc
dbbcxde
abcde




// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we are using of interleavig of strings, we fill dp[i][j] based indices stores in dp[i-1][j] 
// and dp[i][j-1] that is, filling curr. index(index stored in those two dp indices+1 OR Curr. Row+Clmn in dp array) of target string by s[i] and 
// t[j] respectively. If in the last index, we have target.length()-1 indicating that we have obtained target string by interleaving given 
// strings, then return true else return false.

// If an index is not taking/satisfying target string values based on indice in prev. row, prev. clmn's indices, then it remains -1, as a result
// it's following/depending indices would have to start matching target string starting from index-0.



// dp[i][j] indicates max. length of substring starting from index '0' that can be achieved in target string by interleaving s, t substrings upto
// indices i,j respectively.


int Solution::isInterleave(string s, string t, string target) {
    if(target.length()!=(s.length()+t.length())) return 0;					// As, we are interleaving lengths of both strs have to match target str.
    vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, -1));		// Init. 2D DP array.
    for(int i=1;i<=s.length();i++){											// If empty second string is given.
        if(s[i-1]==target[dp[i-1][0]+1]) dp[i][0]= dp[i-1][0]+1;   
    }
    for(int j=1;j<=t.length();j++){											// If empty first string is given.
        if(t[j-1]==target[dp[0][j-1]+1]) dp[0][j]=dp[0][j-1]+1;
    }
    for(int i=1;i<=s.length();i++){											// Iter. through both strings.
        for(int j=1;j<=t.length();j++){
            // dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1]==target[dp[i-1][j]+1]) dp[i][j]=max(dp[i][j], dp[i-1][j]+1);// If first string satisfy curr. index of target string.
            if(t[j-1]==target[dp[i][j-1]+1]) dp[i][j]=max(dp[i][j], dp[i][j-1]+1);// If second string satisfy curr. index of target string.
        }
    }
    
    // for(auto nums: dp){
    //     for(auto num: nums)
    //         cout<<num<<"    ";
    //     cout<<endl;
    // }
    
    return (dp[s.length()][t.length()]==target.length()-1);					// Checking whether last index has tagret string len-1 or not?
}











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. This is optimized version of above solution Space Complexity wise.






int Solution::isInterleave(string s, string t, string target) {
    if(target.length()!=(s.length()+t.length())) return 0;
    vector<vector<int>>dp(2, vector<int>(t.length()+1, -1));
    // for(int i=1;i<=s.length();i++){
    //     if(s[i-1]==target[dp[i-1][0]+1]) dp[i][0]= dp[i-1][0]+1;   
    // }
    for(int j=1;j<=t.length();j++){
        if(t[j-1]==target[dp[0][j-1]+1]) dp[0][j]=dp[0][j-1]+1;
    }
    for(int i=1;i<=s.length();i++){
        if(s[i-1]==target[dp[(i-1)%2][0]+1]) dp[i%2][0]=dp[(i-1)%2][0]+1;
        for(int j=1;j<=t.length();j++){
            dp[i%2][j]=-1;
            // dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1]==target[dp[(i-1)%2][j]+1]) dp[i%2][j]=max(dp[i%2][j], dp[(i-1)%2][j]+1);
            if(t[j-1]==target[dp[i%2][j-1]+1]) dp[i%2][j]=max(dp[i%2][j], dp[i%2][j-1]+1);
        }
    }
    
    // for(auto nums: dp){
    //     for(auto num: nums)
    //         cout<<num<<"    ";
    //     cout<<endl;
    // }
    
    return (dp[s.length()%2][t.length()]==target.length()-1);
}
