/*
*
//************************************************1408. String Matching in an Array.************************************************

https://leetcode.com/problems/string-matching-in-an-array/description/


Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


["mass","as","hero","superhero"]
["leetcode","et","code"]
["blue","green","bu"]



// Time Complexity: O(m^2*n^2).												// m- Avg. length of the string, n-length of the array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m^2*n^2).												// m- Avg. length of the string, n-length of the array.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we pick a string, then iter. over the entire array to find a str, which contains the curr. 
// str. If we find it, we push curr. str into final list of str. We use find func. of str, which gives the index of first occurance of
// given substr. in the given str.








class Solution {
public:
    vector<string> stringMatching(vector<string>& v) {
        vector<string>res;													// Stores the final list of strings found to be substrings.
        for(int i=0;i<v.size();i++){										// Iter. over array.
            for(int j=0;j<v.size();j++){									// Iter. over array.
                if(i==j) continue;
                if(v[j].find(v[i])!=string::npos){							// Checking if v[i] is substr of v[j], returns the index.
                    res.push_back(v[i]);									// If it is substr, we push v[i] into final list.
                    break;
                }
            }
        }
        return res;															// Returning the final list of strings which are substrings.
    }
};