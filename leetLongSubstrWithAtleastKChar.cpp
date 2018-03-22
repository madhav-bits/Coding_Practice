/*
*
//************************************************395. Longest Substring with At Least K Repeating Characters.***************************************

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no 
less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"caaabb"
3



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n^2).	
// This algorithm iterates the array, calculates the count of all chars occurance. In the second pass, on reaching a char with no. of occurance<k,
// we split it into two substrings before and after that particular index. We search in the same way in the recursive call. The case we don't 
// find chars with #occurance<k is the end of recursion(which return length of string in that recursion call).


class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k==0) return s.length();									// If k==0, then the given string meets the requirement.
        if(s.length()<k) return 0;									// If s.length()<k, then we can't form the required substring.
        
        //map<char, int> m;
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++) v[s[i]-'a']++;//m[s[i]]++;	//Noting the counts of all chars in the string.
        int j;
        for(j=0;j<s.length();j++){									// Finding the index of first char with #occurance<k.
            if(v[s[j]-'a']<k) break;	
        }        
        if(j==s.length()) return s.length();						// If char with #occurance<k, then return the length of current string.
        
        int left=longestSubstring(s.substr(0,j),k);					// Calling the left part of string from current index. 
        int right=longestSubstring(s.substr(j+1, s.length()-j-1),k);// Calling the right part of string from current index.
        return (left>right?left:right);								// Returning the max. of them.
    }
};