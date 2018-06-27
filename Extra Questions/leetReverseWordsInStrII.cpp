/*
*
//******************************************************186. Reverse Words in a String II.***********************************************

Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]


["t","h","e"," ","s","k","y"," ","i"," ","b","l","u","e"]


["t","h","e"," ","s","k","y"," ","b","l","u","e"]


["t","h","e"]


[]


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array, in the first iteration we reverse the entire string, in the second iteration, we reverse each word by 
// after finding it's first and last indices. Thus, we get the required answer.








class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());										// Reverse the entire string.
        for(int i=0;i<s.size();i++){										// Reverse the words in the string.
            int j=i;
            while(j<s.size() && s[j]!=' ') j++;								// Find the end index of curr. word.
            int k=j;
            j--;
            while(i<j){														// reverse the curr. word.
                swap(s[i], s[j]);
                i++;j--;
            }
            i=k;															// Setting indices to " " separating curr. and next word.
        }
        //for(auto ch:s)
        //    cout<<ch<<" ";
        //cout<<endl;
        return ;	
    }
};