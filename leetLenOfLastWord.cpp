/*
*
//**********************************************************58. Length of Last Word.***************************************************

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"Hello World     bg"

"Hello World    "


""

"   "


" aa  "


"       aa a   "




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array. In the first algo. when a space char following a word is encountered, we store the len of that word in other
// var. Thus, if after the entire iteration, we have len=0(because of multiple space bars at the end of string), we return prev. len value.






class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0, prev=0;
        for(int i=0;i<s.length();i++){								// Iterating through the array.
            if(s[i]!=' ') len++;									// If empty char encountered, inc. count.
            else if(s[i]==' ' && s[i-1]!=' '){						// First char after a word, store the prev. word's length.
                prev=len;											// This counters continuous space bars in the string..
                len=0;    
            } 
        }
        if(len==0) len=prev;										// If we have continuous space bars at end, we get len=0, then ret. prev len.
        //cout<<"The res. is: "<<len<<endl;
        return len;													// Returning the last word's len.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algo. is that we start iterating from the end, we neglect all the space bars at the end of the string. We count the length of last word
//(First word encountered from the last) and return it.






class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0, ind=s.length()-1;								// We iterate from the back till end of first word.
        while(ind>=0 && s[ind]==' ') ind--;							// Neglecting space chars at the end.
        while(ind>=0 && s[ind]!=' '){								// Counting the length of the last word(First encoun. word form last).
            len++; ind--;
        }
        // cout<<"The res. is: "<<len<<endl;
        return len;													// Returning length of last word.
    }
};