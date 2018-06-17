/*
*
//****************************************************424. Longest Repeating Character Replacement.*********************************************

Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k 
times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"BBBBBBAAAABAA"
5

"ABBBCDBBEFACCCC"
5




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window based. We incrase the Sliding window, as long it follows the question's conditions, once it breached, we 
// remove the first char(start index) from the window, as it won't get involved any further windows, until the windows follows the rules.



// This algo. is sort of observation based, one can't directly come up with one certainly, we have to go through various scenarios, which would
// turn out to be successful, then we believe this algo.






class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==0) return 0;
        int start=0, res=0;												// Stores Start of window index, final maxLength window.
        vector<int>count(26,0);											// Tracks count of chars in window.
        int maxCount=0;													// Tracks count of maxRepeating char in window.
        for(int i=0;i<s.length();i++){									// Iterating through the array.
            maxCount=max(maxCount,++count[s[i]-'A']);					// Max repeating char.
            while(i-start+1-maxCount>k){								// Removing the char at start(inc. start value) till window follow rules
                count[s[start]-'A']--;									// Dec. the count of first char(At start index).
                start++;
            }
            res=max(res, i-start+1);									// Extracting max. window length.
        }
        // cout<<"The ans: "<<res<<endl;
        return res;														// Returning maxm. window length.
    }
};