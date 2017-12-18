/*

//***************************************************318. Maximum Product of Word Lengths.***********************************************

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.


//Time Complexity: O(n^2)
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 
// Here the signatures are not exactly unique, i.e., "aaaaa" and "aaa" would give same sign "1", so in order to reduce redundancy, the-
//- repeating strings max. len is stored, thus reducing no. of calculations to get answer, as comparing all other elem. with "aaaaa" is -
//- same as comparing with "aaa" as both have same sign.
// The Solution can be optimized by considering using unoredered_map with char signature as keys and max. len of repeated strings(if any) 
//- as values.



class Solution {
public:
    int maxProduct(vector<string>& v) {
        int result=0;
        vector<int>ind_array(v.size());						//Creating the char signatures of all words in this array.
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].length();j++)
                ind_array[i]=ind_array[i]|1<<(v[i][j]-'a');	//Creating signature. "ac" is modified to "101". "c" pushes 1 2 steps to left-
            for(int k=0;k<i;k++){							//- and get appended to ind_array.
                if(!(ind_array[k] & ind_array[i]))			// When there is no, common elem. b/w two strings, then result is zero.
                    result=max(result, int(v[k].length()*v[i].length()));// When no match, length is multiplied and max is stored every time.
            }
        }
        return result;										//Returning the maximum product of string lengths.
    }
};