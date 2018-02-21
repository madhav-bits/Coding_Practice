/*
*
//******************************************************151. Reverse Words in a String.***********************************************

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"         the         sky is blue  "
"the sky is blue"
" a"
"a "
"     "



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm iterates the array, keeps appending the words to the end of the curr. string. While avoids the continuous white spaces in between.
// This can also be done by reversing chars of a word. and reverse the whole string at the end(elim. continuous white spaces).


class Solution {
public:
    void reverseWords(string &s) {
      string t="";
      int len=s.length();
      for(int i=len-1;i>=0;i--){									// Iterating the curr. array.
          if(s[i]!=' ')												// Save a word in temp. varible.
              t=s[i]+t;
          else if(i<len-1 && s[i]==' ' &&s[i+1]!= ' '){				// Append the string at the end of the current string..
              s+=t+" ";
              t="";
          }
      }
      if(t.length()>0)												// Appending the last encountered word.
        s+=t+" ";
      //cout<<"The new string is: "<<s<<endl;
      s=s.substr(len,s.length()-len-1);								// Retrieving only newly appended reversed string.
      //cout<<"The new string is: "<<s<<endl;
    }
};