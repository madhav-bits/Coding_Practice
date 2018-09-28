/*
*
//********************************************************115. Distinct Subsequences.*************************************************


Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without 
disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac"
"ceadbaa"



"rabbbit"
"rabbit"





// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm BackTracking and Hashing based. Here, we go through all probable matching chars, if two chars from two strings are matched,
// we move to next chars in both strings to find all combinations of target string. We decide target string is obtained, once we reach end of 
// target string. As, we might be calculating same set of states in BackTracking, we hash the states which we had already calculated. If we 
// go to that state at some later point of time, we return the value directly.

// m[index1,index2] is #combinations to get substring(index1,s.length()-1) from given substring(index2,t.length()-1).

// dp[i][j] is #combinations to get substring[j, t.length()-1] from given substring[i,s.length()-1].




class Solution {
public:
    int findCount(string s, string t, int index1, int index2, unordered_map<string,int>&m){
        if(index2==t.length()) return 1;									// If end of target string is reached, return 1.
        string temp=to_string(index1)+to_string(index2);					// Creating a hash key for this state.
        if(m.count(temp)==1) return m[temp];								// If this state is already visited, return count.
        int count=0;														// No. of possible combinations to get rem. target string.
        for(int i=index1;i<s.length();i++){									// Iter. over all possible start indices.
            if(s[i]==t[index2]){											// If curr. chars match.
                count+=findCount(s,t,i+1,index2+1,m);						// Get #combinations to get rem. target string from rem. given str.
            }
        }
        m[temp]=count;														// #combinations to get rem. target string from rem. given string.
        return count;														// Returning the combinations.
    }
    
    int numDistinct(string s, string t) {
        unordered_map<string,int>m;											// Used to hash the states which had already been visited.
        if(s.length()<t.length()) return 0;									// If given string is shorter than target string, return 0.
        return findCount(s,t,0,0,m);										// Call fn. to get all possible combinations.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This is Dynamic Programming based. The recurrent relation is based on the recursive relations defined above. We first build the values in the
// values in the last column(#combinations to get last char in target str from various rem. start indices in given str). We iter. from last
// to first. If we are at index[i,j], then #combinations to get rem. target string from rem. given string depends on matching chars
// after that pai[i,j], we sum up #combinations from all those pairs and assign it to curr. pair. At the end, we get the result in [0,0].


// Way easier DP recurrent relation is given in the Discussion section.







class Solution {
public:
    
    int numDistinct(string s, string t) {
        if(s.length()<t.length()) return 0;									// Base case.
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),0));		// DP to store combinations to get target str.
        int count=0;
        for(int i=s.length()-1;i>=0;i--){									// Setting up base cases.
            if(s[i]==t.back()) count++;										// Counting the maching chars with last char of target str.
            dp[i][t.length()-1]=count;										// Assigning the count to curr. index.
        }
        
        for(int j=t.length()-2;j>=0;j--){									// Iter. over indices in target str.
            int count=0;
            for(int i=s.length()-1;i>=0;i--){								// Iter. over start indices from the back.
                if(s[i]==t[j] && i+1<s.length() && j+1<t.length())			// If curr. chars get count of next pair of indices.
                    count+=dp[i+1][j+1];
                dp[i][j]=count;												// Assign the count to curr. index.
                
            }
        }
        
        // for(auto nums:dp){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        
        
        return dp[0][0];													// Return the total #combinations to get target string.
    }
};