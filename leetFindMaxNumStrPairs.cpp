/*
*
//******************************************************2744. Find Maximum Number of String Pairs.******************************************************

https://leetcode.com/problems/find-maximum-number-of-string-pairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["cd","ac","dc","ca","zz"]
["ab","ba","cc"]
["aa","ab"]



// Time Complexity: O(n*l).													// n-#strings, l-avg. length of the string.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*l).													// n-#strings, l-avg. length of the string.
// Space Complexity: O(n).	
// This algorithm is Hash Map/Set based. Here, we use set to store the prev. occur of the strings, while iterating at every step we check if the reverse of the curr. string
// has occured in the past, if true we inc. res by 1, in this case since we observed reverse version of str in the past, we dont have to store curr. str as each word is 
// part of only one pair, in the other case we store the curr. str in the set.


// Other way is two for loops with Time Complexity of O(n^2) where we just compare the alternate indices of the inner and outer string.

// Other way is to encode the given string into it's integer rep: s[0]*26+s[1] in an boolean array of size 676, we check for prev. occur. of reversed version of curr. str.







class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int res=0;
        unordered_set<string>st;											// Stores the prev. version of the strings while iterating.
        for(string&s:words) {
            if(st.count(s)==1) res++;										// If curr. str is already observed, we inc. res.
            else {
                reverse(s.begin(), s.end());								// We reverse curr. string.
                st.insert(s);												// And insert it into set.
            }
        }
        return res;															// Returning the total #pairs.
    }
};

