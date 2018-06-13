/*
*
//******************************************************434. Number of Segments in a String.***********************************************

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"Hello , \t \n my name is John"


"Hello , \t \n my name is "

" "

"a"

"a "





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based At each step, we check whether curr. index is space following a word or not? If it is, we inc. the count, this
// way we account for all words in the str, but the last word finishing with end of string isn't accounted for, for that we check just whether
// at last index we have char or not?, if it is, we inc. the count, then we return the count.







class Solution {
public:
    int countSegments(string s) {
        if(s.length()==0) return 0;
        int count=0;															// Tracks #words in string.
        for(int i=1;i<s.length();i++){
            if(s[i]==' ' && s[i-1]!=' ') count++;								// If the curr. index is space following a word.
        }
        if(s[s.length()-1]!=' ') count++;										// This acconts for word ending with last index of string.
        // cout<<"The count is: "<<count<<endl;
        return count;															// Returning the #words in the string.
    }
};