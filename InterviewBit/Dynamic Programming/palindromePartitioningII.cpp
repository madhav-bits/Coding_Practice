/*
*
//**********************************************************Palindrome Partitioning II.***************************************************

https://www.interviewbit.com/problems/palindrome-partitioning-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



aaabbaaabbacccaccbba


aabbca



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, we first form a DP array to tracks the subarrays that are Palindromes. Later, we start 
// iterating form first index, till end of string, the instant we find a substring[i,j] to be palindrome, we give a recursive call to find min. 
// #palindromes starting that index[j+1]. While entering the recursive call, we check a dp array vals, where we check whether min. #palin.
// starting that index are already calculated are not, if calculated we return the value directly if not we calculate and update the DP array
// and return the value. At the end, we return min #palin starting index -'0'(vals[0]).











vector<int>vals;															// Stores min. #palindromes starting at index 'i'.

int findCombi(string&s, vector<vector<bool>>&dp, int index){				// Calc. min. #palindromes starting at index 'i'.
    if(index>=s.length()) return 0;											// If entire string is iterated.
    if(vals[index]!=-1) return vals[index];									// If min. #palin. already calculated, return value.
    int res=INT_MAX;														// #tracks Min. #palin.
    for(int i=index;i<s.length();i++){										// Iter. through all possible palindrome end indices.
        if(dp[index][i]==true) res=min(res, findCombi(s,dp, i+1));        	// If substr is palindrome, give recursive call.
    }
    vals[index]=res+1;														// Update DP array with min. #palin. starting curr. index.
    return res+1;															// Return the min. #palin.
}

int Solution::minCut(string s) {
    vals=vector<int>(s.length(), -1);										// Init. the DP array.
    vector<vector<bool>>palin(s.length(), vector<bool>(s.length(), false));	// Init. DP array to track palin. nature of diff. substrs.
    for(int i=0;i<s.length();i++){											// Marking substr of len=1, len=2(if any) as palindromes.
        palin[i][i]=1;
        if(i+1<s.length() && s[i]==s[i+1]) palin[i][i+1]=1;
    }
    for(int len=3;len<=s.length();len++){									// Marking various substr as palindromes.
        for(int i=0;i+len<=s.length();i++){
            if(s[i]==s[i+len-1] && palin[i+1][i+len-2]==true) palin[i][i+len-1]=true;
        }
    }
    

    // for(auto nums: palin){
    //     for(auto num:nums)
    //         cout<<num<<" ";
    //     cout<<endl;
    // }
    
    return findCombi(s,palin,0)-1;											// Giving call to find min. #palindromes starting at index '0'.
    
}