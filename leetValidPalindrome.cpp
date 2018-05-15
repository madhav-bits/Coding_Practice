/*
*
//**********************************************************125. Valid Palindrome.***************************************************

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



""
"a"
"a1 1a"
"a1: 1a"
"abcba"
"abba"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the string and preprocesses it by removing all other chars other than alphanumeric ones. We check for palindrome in the 
// transformed string by taking two ptrs one from the start and one from the end and checking whether same or not until half of th length of new
// string.



class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0 || s.length()==1) return true;										// If string is null/ length=1, return true.
        int i=0, j;
        string temp="";																		// Stores new transformed string.
        for(int i=0;i<s.length();i++){														// Accepts only alphanumeric chars into new string.
            if(s[i]>=65 & s[i]<=90)
                temp+=s[i]+32;
            else if(s[i]>=97 & s[i]<=122)
                temp+=s[i];
            else if(s[i]>=48 && s[i]<=57)
                temp+=s[i];
        }
        //cout<<"Trnasformed string is: "<<temp<<endl;
        j=temp.length()-1;
        while(i<j){																			// Checks whether new string is palindrome or not?
            
            if(temp[i]!=temp[j]) return false;												// If chars are not equal, return false.
            i++;
            j--;
        }
        return true;																		// No chars found to be not equal.
    }
};