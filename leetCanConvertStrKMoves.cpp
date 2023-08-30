/*
*
//******************************************************1540. Can Convert String in K Moves.******************************************************

https://leetcode.com/problems/can-convert-string-in-k-moves/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"input"
"ouput"
9
"abc"
"bcd"
10
"aab"
"bbb"
27
"ljlrkljtnjsglnjstfjwoeipwoegmjgvd"
"joeirjgekjopeoijkmgknlqwedsbdgnok"
100



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, as the shifts cycle over from 'z' to 'a', we will have duplicate shifts for a k>26. ex: 1 shift=27 shifts as after
// every multiple 26 shifts, the char becomes it's orig. char once again. So, we track #occur of each of the shifts in range [0,25]. We can ignore 0 as it means 
// that chars match in both strings, we need not bother about #occur of these shifts being available, if unavailable we skip shifting that char and yet it
// matche target char. We first iter. over both strs parallelly and calc. #occur. of each shifts required. Later we iter over shifts [1,25] and check if we have
// enough #occur of shifts provided by k, if no we return false as we won't be able to shift some chars to match char in target str in that index. We also 
// carefully calculate #occur. of shifts available by k/26, and 1 more occur would be available for first k%26 shifts=> [1, k%26] shifts.







class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length()!=t.length()) return false;
        int change[26];
        memset(change, 0, sizeof(change));
        for(int i=0;i<s.length();i++) {
            change[(t[i]-s[i]+26)%26]++;									// Calc. #shifts required based on s and t.
        }
        int rem=k%26, shifts=k/26;											// Calc. #occur of each shifts provided by k.
        for(int i=1;i<=25;i++) {											// We ignore 0 shifts and process non-zero shifts.
            int oper=(rem>0)?shifts+1:shifts;								// We add 1 more occur for first k%26 shifts.
            if(change[i]>oper) return false; 								// If req. #occur>available #occur of this shift, we return false.
            if(rem>0) rem--;												// We dec. the rem value to limit extra 1 #occur for the shifts.
        }
        return true;														// Returning true if we can convert s to t using at max k moves.
    }
};

