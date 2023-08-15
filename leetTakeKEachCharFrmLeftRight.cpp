/*
*
//********************************************2516. Take K of Each Character From Left and Right.********************************************

https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aabaaaacaabc"
2
"a"
1
"bacbbaacbbbccaacbbcacbbacbabcba"
3
"cabbcbacbaaabcbbabcbacbababcbbacababcbacbabc"
6



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, we try to find min indices to use on both sides to get 'k' a/b/cs. So, we calc. total a/b/cs, we substract k
// from them to get rem chars count. Now, we use sliding window to enclose as many indices as possible while remChars count for all 3 chars remain>=0, if it 
// gets<0, that means we don't have >=k of any of a/b/cs, which doesn't meet your condition, so in case of this issue, we shrink window to ensure remChars
// count>=0, thus ensuring out of window/border a/b/cs count>=k. We try to minimize the border indices count and return it.







class Solution {
public:
    int takeCharacters(string s, int k) {
        int occurA=0, occurB=0, occurC=0;
        for(char&ch:s) {
            if(ch=='a') occurA++;
            else if(ch=='b') occurB++;
            else if(ch=='c') occurC++;
        }
        if(occurA<k || occurB<k || occurC<k) return -1;						// If we don't have enough a/b/cs, we return -1.
        int target[3];														// Tracks remChars count after using k on borders.
        target[0]=occurA-k;
        target[1]=occurB-k;
        target[2]=occurC-k;
        
        int start=0, res=s.length()+1;
        for(int i=0;i<s.length();i++) {
            if(--target[s[i]-'a']<0) {										// If any of remChars count<0.
                while(target[s[i]-'a']<0) target[s[start++]-'a']++;			// We shrink window and ensure remChars>=0, thus ensuring borderChars count>=k.
            }
            if(s.length()-(i-start+1)<res) res=s.length()-(i-start+1);		// Tracking the minm border indices count.
        }
        return res;															// Returning min. oper needed to get k of each char.
    }
};

