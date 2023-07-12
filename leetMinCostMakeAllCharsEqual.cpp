/*
*
//*************************************2712. Minimum Cost to Make All Characters Equal.*****************************************

https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"0011"
"010101"
"0001100011100"
"00011100"
"001111"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Greedy Approach based. Here, whenever we encounter two diff. chars, we try to make them same by flipping either the left char or right char
// flipping left chars takes 'i' cose, right chars take 'n-i' cost, we use the minm. of them., if we flipped the right chars, the reverse nature of the chars
// remain the same even if they are flipped, so we can still calc. the #flips needed originally to make those chars equal.

// When we assign the min. flips of the prefix, suffix flips, we make the curr. char as part of the final string, because it would be extra cost to flip it 
// from it's given state and work on the left indices as their flipped state would still have same nature of opposite values. Thus, at every step we greedily 
// pick min. #fips and ensure the total #flips is minimum.



// This discussion forum link has better explanation for this approach:
// https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/discuss/3574435/one-pass-dp-intuition-for-check-s-i-s-i-1/



class Solution {
public:
    long long minimumCost(string s) {
        long long int res=0;
        for(int i=1;i<s.length();i++) {
            if(s[i]!=s[i-1]) res+=min(i, (int)s.length()-i);				// Adding min. of flips to make these chars equal, to res.
        }
        return res;															// Returning the minm. #flips required to make all chars equal.
    }
};

