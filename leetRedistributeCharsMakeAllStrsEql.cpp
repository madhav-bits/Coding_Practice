/*
*
//**********************************************1897. Redistribute Characters to Make All Strings Equal.******************************************

https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["abc","aabc","bc"]
["ab","a"]
["abcd","dbca","acbd"]



// Time Complexity: O(n*m).													// n-#strs, m-#avg length of the string.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n-#strs, m-#avg length of the string.
// Space Complexity: O(1).	
// This algorithm is observation based. Since, we can move chars b/w strings to any psns, we can eventually jumble the chars in the same string indirectly. So,
// the order of the chars(i.e words) doesn't matter, for ex: we can somehow transform all strs to a sorted chars string. So, we can make all strings equal as 
// long as #occur. of each char is in multiples of #strs in the array. We calc. #occur. of each char, then iter. over chars and return false if any of the
// occur. isn't multiple of #strs in the array. If we don't observe any such case, we return true after checking all chars.







class Solution {
public:
    bool makeEqual(vector<string>& v) {
        vector<int>occur(26,0);
        for(string&s:v) {
            for(char&ch:s) occur[ch-'a']++;									// We track #occur. of each char in all the strings.
        }
        for(int i=0;i<26;i++) {
            if(occur[i]%v.size()!=0) return false;							// If #occur. of a char isn't multiple of #strs, we can't redistribute equally.
        }
        return true;														// Returning true if all strings can be made equal.
    }
};

