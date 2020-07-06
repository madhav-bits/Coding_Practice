/*
*
//*************************************************1370. Increasing Decreasing String.*************************************************

https://leetcode.com/problems/increasing-decreasing-string/description/


Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

 

Example 1:

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
Example 3:

Input: s = "leetcode"
Output: "cdelotee"
Example 4:

Input: s = "ggggggg"
Output: "ggggggg"
Example 5:

Input: s = "spo"
Output: "ops"
 

Constraints:

1 <= s.length <= 500
s contains only lower-case English letters.


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with the examples provided with the question.



// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(k).													// k- constant value.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(k).													// k- constant value.
// This algorithm is occurrences based. Here, we cnt the #occurrences of each char. We follow the given rules by iter. over the occur array,
// if the chars are remaining, we add that char to the final result. We do this in a loop, until all chars are filled.








class Solution {
public:
    string sortString(string s) {
        vector<int>occur(26,0);												// Stores the #occur. of each char.
        int used=0;
        for(auto ch: s) occur[ch-'a']++;									// Storing #occurrences of each char.
        string res="";
        while(used!=s.length()){											// Until all chars are used.
            for(int i=0;i<26;i++){											// Gathering the inc. order sequence.
                if(occur[i]==0) continue;
                occur[i]--;
                used++;
                res+=char(i+97);
            }
            
            for(int i=25;i>=0;i--){											// Gathering the dec. order sequence.
                if(occur[i]==0) continue;
                occur[i]--;
                used++;
                res+=char(i+97);
            }
        }
        return res;															// Returning the finally formed string.
    }
};

