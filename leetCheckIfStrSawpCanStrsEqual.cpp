/*
*
//******************************************************1790. Check if One String Swap Can Make Strings Equal.******************************************************

https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"bank"
"kanb"
"abcd"
"dcbd"
"abcd"
"cbad"
"abcd"
"cbed"
"abcd"
"defd"
"attack"
"defend"
"kelb"
"kelb"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation+iteration based. Here, we count #mismatches b/w both strings, if it is>2, we return false. When first mismatch is encountered, we store the index, upon encountering 
// second mismatch we check if swapping worked b/w curr. and first mistmach index, if swap doesn't work, we return false. At end of iter. if we see only 1 mismatch index, that means swapping can't 
// be possible and strings wont be equal(we return false), if #mismatches is 2, then swapping works, so we return true.








class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
		if(s1==s2) return true;
        int diff=0, firstIndex=-1;																		// Stores #mismatches, index of first mismatch.
        for(int i=0;i<s1.length();i++) {
            if(s1[i]==s2[i]) continue;
            if(++diff>2) return false;																	// If #mismatches>2, we return false.
            if(firstIndex==-1) firstIndex=i;															// Storing first mismatch index.
            else {
                if(s1[firstIndex]!=s2[i] || s2[firstIndex]!=s1[i]) return false;						// Checking if swapping makes both strings equal.
            }
        }
        return (diff!=1);																				// If #mismatch is 1, then we can't make strings equal.
    }
};

