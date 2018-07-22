/*
*
//**************************************************************541. Reverse String II.*******************************************************

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If 
there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse 
the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcdefghijklm"
4


"abcdefghijk"
4


"abcdefghijklmno"
4


"abcdefghijklmnopq"
2





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We first calc. the index till where complete iterations of length "k" occurs. Later, we calc. we remainig
// substr's length is >"k" or not? If it is length <"k", then we reverse entire remaining substr, else, we reverse next "k" chars.








class Solution {
public:
    void reverse(string &s, int start, int end){
        while(start<end)													// Reversing the given str. b/w two indices.
            swap(s[start++],s[end--]);
            
    }
    
    string reverseStr(string s, int k) {
        int limit=2*k*(s.length()/(2*k));									// Upper index, till where we can reverse substr of length "k".
        for(int i=0;i<limit;i+=2*k){										// Iteraing the array.
            // cout<<"Reverse's start: "<<i<<" and end: "<<i+k-1<<endl;
            reverse(s,i,i+k-1);												// Reversing the substr of length "k".
        }
        // int index=2*k*(s.length()/(2*k));
        if(limit==s.length()) return s;										// Get start index after reversing is done.
        int end=min((int)s.length()-1,limit+k-1);							// Calc. end index to reverse now.
        reverse(s,limit,end);												// Call. fn. to reverse chars in b/w these indices.
        return s;															// Return the reversed/result string.
    }
};