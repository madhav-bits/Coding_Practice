/*
*
//******************************************************2325. Decode the Message.******************************************************

https://leetcode.com/problems/decode-the-message/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"the quick brown fox jumps over the lazy dog"
"vkbs bs t suepuv"
"eljuxhpwnyrdgtqkviszcfmabo"
"zwx hnfx lqantp mnoeius ycgk vcnjrdb"



// Time Complexity: O(n+m).													//n-length of key, m-length of the message.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													//n-length of key, m-length of the message.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we are mapping first occur of chars to lowercase alphabets sequentially, we use an array, a var to map them.
// The var shows the least char which is still yet to mapped, array shows the mapping b/w chars. We iter. over message, we replace the chars with mapped chars
// and return the encrypted message at the end of iter.







class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char>v(26,'*');												// Array to store mapping b/w the chars.
        char ch='a';
        for(int i=0;i<key.length() && ch<='z';i++) {
            if(key[i]==' ') continue;
            if(v[key[i]-'a']=='*') v[key[i]-'a']=ch++;						// Mapping the first occur of char with seq. lowercase chars.
        }
        for(char&ch:message) {
            if(ch==' ') continue;
            ch=v[ch-'a'];													// Replacing the chars with mapped chars.
        }
        return message;														// Returning the encrypted string.
    }
};

