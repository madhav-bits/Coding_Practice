/*
*
//******************************************1061. Lexicographically Smallest Equivalent String.******************************************

https://leetcode.com/problems/lexicographically-smallest-equivalent-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"parker"
"morris"
"parser"
"leetcode"
"programs"
"sourcecode"





// Time Complexity: O((n+m)logk).											//n,m-lengths of the given strings, k-#unique chars, 26 in this case.
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((n+m)logk).											//n,m-lengths of the given strings, k-#unique chars, 26 in this case.
// Space Complexity: O(k).	
// This algorithm is Union-Find based. Here, we observe that all the connected equivalent chars can be interchanged based on the properties. Since we are
// trying to form lexically smallest equi str, we replace every char with it's lexically smallest connected char. We iter. over both strs and form 
// all connections while ensuring that lexically smallest char remains the root parent of each group of connections. We iter. over target str and replace 
// each char it's lexically smallest equi char and return the final str.







class Solution {
public:
    
    char getParent(vector<char>&parent, char ch) {							// Return root parent char of given char.
        if(parent[ch-'a']!=ch) 
            parent[ch-'a']=getParent(parent, parent[ch-'a']);
        return parent[ch-'a'];
    }
    
    string smallestEquivalentString(string s1, string s2, string res) {
        vector<char>parent(26,'a');
        for(int i=0;i<26;i++) parent[i]=(i+'a');
        for(int i=0;i<s1.length();i++) {									// Connect chars of same index in both strs.
            char parA=getParent(parent, s1[i]);								// Get root parent char of each char.
            char parB=getParent(parent, s2[i]);
            if(parA==parB) continue;										// If two chars are already connected.
            if(parA<parB) parent[parB-'a']=parA;							// If parA is lexically small, we make it the root parent.
            else parent[parA-'a']=parB;										// Else make parB as the root parent.
        }
        for(int i=0;i<res.length();i++) {									// Iter. over res string.
            res[i]=getParent(parent, res[i]);								// Replace each char with lexically smallest equi char.
        }
        return res;															// Returning the lexically smallest equi string.
    }
};

