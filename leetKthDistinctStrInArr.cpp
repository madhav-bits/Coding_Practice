/*
*
//*******************************************2053. Kth Distinct String in an Array.*******************************************

https://leetcode.com/problems/kth-distinct-string-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["d","b","c","b","c","a"]
2
["aaa","aa","a"]
1
["a","b","a"]
3



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. We first iter. over the array and store the strings and their #occur in the map. We iter. over array second time and each time
// we encounter a string which only occurred only once, we dec. the k value, the moment it becomes 0, that's the kth distinct string in the array and we return 
// the str.







class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>st;
        for(string&s:arr) st[s]++;											// Storing strings and their #occur in the map.
        for(string&s:arr) {
            if(st[s]==1 && --k==0) return s;								// If the curr. str is distinct and it is kth in seq., we return it.
        }
        return "";															// Return empty string if we don't have k distinct strings.
    }
};

