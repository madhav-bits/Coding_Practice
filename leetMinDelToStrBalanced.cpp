/*
*
//******************************************1653. Minimum Deletions to Make String Balanced.*********************************************

https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aababbab"
"bbaaaaabbbbbaa"
"bbaaaaabb"
"bbb"
"aa"
"a"
"bbbbbbbaabbbbbaaabbbabbbbaabbbbbbaabbaaabaabbbaaaabaaababbbabbabbaaaabbbabbbbbaabbababbbaaaaaababaaababaabbabbbaaaabbbbbabbabaaaabbbaba"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration and observation based. Here, we store #a's in a var. At every point, we assume it as div point where
// indices to it's left(including itself) would be 'a' and to it's right as 'b'. While iterating, we track a's till now, with which
// we calc. #b's in the left half, #a's in right half and them to get #deletions if curr. index is split index. We extract the minm.
// deletions among all split points.








class Solution {
public:
    int minimumDeletions(string s) {
        // cout<<"len: "<<s.length()<<endl;
        int aCount=0;
        for(auto ch:s){
            if(ch=='a') aCount++;											// Count all a's in the string.
        }
        if(aCount%s.length()==0) return 0;									// Entire string is of same char.
        int currA=0, currB=0, res=aCount;									// Where we remove all a's in the string.
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') currA++;
            int del=i+1-currA;												// #b's in left substring.
			del+=aCount-currA;												// #a's in right subsring.
            res=min(res, del);												// Tracking minm. deletions.
        }
        return res;															// Returning minm. deletions needed.
    }
};
