/*
*
//***********************************************************87. Scramble String.***************************************************


Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"great"
"tgear"





// Time Complexity: O(n^4).  
// Space Complexity: O(n^3).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).													// Surprisingly, this works damn faster.
// Space Complexity: O(1).	
// This algorithm is recursion based. Here, we traverse through all possible combinations. For every substring of two strings considered to be
// scrambled, there might be a cut anywhere in the substr, where left, right parts of both substrs are equal. Or, left of first substr matches
// with right of second substr and right of first substr matches with left of second substr. If any of these cuts are matched, then curr.
// substr under consideration is scramble, this way we iterate till two complete strings, we can say whether they are scramble or not?









class Solution {
public:
    bool isScramble(string s1, string s2) {
        // cout<<"s1: "<<s1<<" and s2: "<<s2<<endl;
        if(s1.length()!=s2.length()) return false;
        if(s1==s2) return true;												// Base cases.
        if(s1.length()==0) return true;
        vector<int>count(26,0);
        for(int i=0;i<s1.length();i++){										// Comparing count of each chars in both strs.
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){												// If any char count mismatched, then return false.
            if(count[i]!=0) return false;
        }
        int total=s1.length();
        for(int len=1;len<s1.length();len++){								// Going through all possible cuts in curr. substrs.
            if(isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len))) return true;// Left, right of
																			// both substrs matches with counterpart form other string.
            
            if(isScramble(s1.substr(0,len), s2.substr(total-len)) && isScramble(s1.substr(len), s2.substr(0,total-len))) return true;
        }																	// Left of first matches right part of second substr and vicecersa.
        
        return false;														// If no match observed return false.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).
// Space Complexity: O(n^3).	
// This algorithm is DP/recursion based. Here, we traverse through all possible combinations. For every substring of two strings considered to be
// scrambled, there might be a cut anywhere in the substr, where left, right parts of both substrs are equal. Or, left of first substr matches
// with right of second substr and right of first substr matches with left of second substr. If any of these cuts are matched, then curr.
// substr under consideration is scramble, this way we iterate till two complete strings, we can say whether they are scramble or not?

// This is same as above algo. except that it prevents re-calculations using Hashing already calc. results.
// The DP array has three states: (-1) value not assigned, (1) scrambled substrs, (0) not scrambled substrs.
// This can also be considered Dynamic Programming Top-Down approach.






class Solution {
public:
    bool findStr(string s1, string s2, int start1, int start2, int len,vector<vector<vector<int>>>&dp){
        // cout<<"substr1: "<<s1.substr(start1,len)<<" and s2: "<<s2.substr(start2,len)<<" val: "<<dp[start1][start2][len]<<endl;
        if(dp[start1][start2][len]!=-1) return (dp[start1][start2][len]==1)?true:false;
        // cout<<"yo"<<endl;
        if(s1.substr(start1,len)==s2.substr(start2,len)){
            dp[start1][start2][len]=1;
            return true;
        }
        vector<int>count(26,0);
        for(int i=0;i<len;i++){
            count[s1[i+start1]-'a']++;
            count[s2[i+start2]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                dp[start1][start2][len]=0;
                return false;
            }    
        }
        for(int sep=1;sep<len;sep++){
            if(findStr(s1,s2,start1,start2,sep,dp) && findStr(s1,s2,start1+sep, start2+sep,len-sep,dp)){
                dp[start1][start2][len]=1;
                return true;
            }
            if(findStr(s1,s2,start1,start2+len-sep,sep,dp) && findStr(s1,s2,start1+sep, start2,len-sep,dp)){
                dp[start1][start2][len]=1;
                return true;
            }
        }
        dp[start1][start2][len]=0;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        // cout<<"s1: "<<s1<<" and s2: "<<s2<<endl;
        if(s1.length()!=s2.length()) return false;
        if(s1==s2) return true;
        if(s1.length()==0) return true;
        vector<int>count(26,0);
        for(int i=0;i<s1.length();i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0) return false;
        }
        int total=s1.length();
        vector<vector<vector<int>>>dp(total, vector<vector<int>>(total, vector<int>(total+1,-1)));// Init. DP array.
        // cout<<"Iint val: "<<dp[0][0][total]<<endl;
        return findStr(s1,s2, 0,0,total, dp);
    }
};












//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^4).
// Space Complexity: O(n^3).	
// This algorithm is Dynamic Programming based. We build the Hash from the bottom(Base cases, len of substrs startint from 1), and use those
// values to set higher values. We iter. from len=2 to len=total, iter. over all possible starts in both sentences, iter. over all possible
// cuts in curr. substrs from both strs. At the end, we get whether curr. strings are scrambled or not.


// dp[i][j][len], says s1's  substr starting at index 'i' and s2's  substr starting at index 'i2' with length=len, is scrambled or not.






class Solution {
public:
    
    
    bool isScramble(string s1, string s2) {
        // cout<<"s1: "<<s1<<" and s2: "<<s2<<endl;
        if(s1.length()!=s2.length()) return false;							// Base cases.
        if(s1==s2) return true;												
        if(s1.length()==0) return true;
        vector<int>count(26,0);
        for(int i=0;i<s1.length();i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0) return false;
        }
        int total=s1.length();
        vector<vector<vector<int>>>dp(total, vector<vector<int>>(total, vector<int>(total+1,false)));// Init. DP array.
        // cout<<"Iint val: "<<dp[0][0][total]<<endl;
        
        for(int i=0;i<total;i++){											// Base case of substrs of length=1.
            for(int j=0;j<total;j++){
                if(s1[i]==s2[j]) dp[i][j][1]=true;
            }
        }
        
        for(int len=2;len<=total;len++){									// Iter. over all possible length of substrs.
            for(int i=0;i<=total-len;i++){									// Iter. over all possible starts for this len of substr.
                for(int j=0;j<=total-len;j++){								// Iter. over starts in second string.
					if(s1.substr(i,len)==s2.substr(j,len)){					// If both substrs are equal, assign val. in DP array and return true.
                        dp[i][j][len]=true;									// Pruning Technique.
                        continue;
                    }
                    for(int sep=1;sep<len;sep++){							// Iter. over all possible cuts in both substrs.
                        if(dp[i][j][sep] && dp[i+sep][j+sep][len-sep]) dp[i][j][len]=true;// If substrs are scrambled, assign true.
                        if(dp[i][j+len-sep][sep] && dp[i+sep][j][len-sep]) dp[i][j][len]=true;
                    }
                }
            }
        }
        
        return dp[0][0][total];												// Returning whether given strs are scrambled or not.
        
        
    }
};