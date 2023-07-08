/*
*
//******************************************2131. Longest Palindrome by Concatenating Two Letter Words.********************************************

https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["lc","cl","gg"]
["ab","ty","yt","lc","cl","ab"]
["cc","ll","xx"]
["aa","aa","bb","bb","cc","cc","ab","ba","gh","eg","ge"]
["aa","aa","aa","bb","bb","bb","cc","cc","cc","ab","ba","gh","eg","ge"]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map based. Here, since we are dealing with strings of length 2, we convert their base 26 form to decimal and use to store the #occur. each 
// string in the given array. As we are trying to form palin. at every step we try to pairs which can be placed on either side of the center and can mirror 
// image each other and contribute to palindrome nature of the string, ex: when we check 'cd''s index, we calc.'dc''s index and use the min. of both as they 
// would reflect each other from the center of the string. For symmetric strings, the approach slightly varies, as we are looking at same string on both sides,
// we multiply their occur. with 2 and add to res, if we have odd #occur. we can use that symmetric string only once as using it more than once would affect
// the palindrome nature, so we place conditions and ensure that we add only once if odd. #occur exists for symmetric strings.





class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<int>occur(676,0);
        int res=0;
        bool odd=false;
        for(string&s:words) {
            int ind=(s[0]-'a')*26+(s[1]-'a');								// Calc. decimal rep. for the string.
            occur[ind]++;													// Inc. the occur. count for this string.
        }
        
        for(int i=0;i<26;i++) {
            for(int j=i;j<26;j++) {											// We only iterate in the upper half of the matrix as we use their symm indices in calc. here.
                int rep=min(occur[i*26+j], occur[j*26+i]);
                if(i==j) {													// For symmetric strings.
                    if(rep%2==1) odd=true, rep--;							// We mark if odd #occur. has occured and we make it even #occur to inc. res safely.
                    res+=2*rep;												// Inc. the res length corres. to the #occurances.
                }else res+=4*rep;											// Inc. the res length corres. to the #occur. of strings on both sides of center.
            }
        }
        if(odd) res+=2;														// If sym. strs occur. odd #times, we inc. res by 2 as it's placed right in middle.
        return res;															// Returning the max. length of the palindrome string.
    }
};







//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is same as the above except that it used 2D array instead of 1D array and the process slightly smoother/optimized here. When at a str, 
// we find the index of it's reflective string too and check if had occurred earlier, if yes we dec. it's count and add both curr. and prev. index's corres. 
// length(4) to res. If reflective haven't occurred in past, we simply the occur. count of curr. string by 1 in 2D array. Later, we iter over 2D array to check
// if symmetrical strings had occurred odd #times, if yes, as ONLY ONE can be used and can be placed right in the middle, we use ONLY ONE of them if present.







class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0;
        vector<vector<int>>occur(26, vector<int>(26,0));					// 2D array to store #occur. of each str.
        for(string&s:words) {
            int i=s[0]-'a', j=s[1]-'a';
            if(occur[j][i]) res+=4, occur[j][i]--;							// Use curr. and reflective str's prev. occur and inc. res length accordingly.
            else occur[i][j]++;												// If reflective str haven't occurred earlier, just inc. occur. count of curr. str
        }
        for(int i=0;i<26;i++) {
            if(occur[i][i]==0) continue;
            res+=2;															// If an odd #occur. symmetrical str found use it ONCE and break the loop.
            break;
        }	
        return res;															// Returning the max. length of the palindrome string.
    }
};

