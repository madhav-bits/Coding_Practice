/*
*
//*****************************************2273. Find Resultant Array After Removing Anagrams.******************************************

https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["abba","baba","bbaa","cd","cd"]
["a","b","c","d","e"]
["z","z","z","gsw","wsg","gsw","krptu"]



// Time Complexity: O(n*mlogm).												// n-length of the array, m-avg. length of the string.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*mlogm).												// n-length of the array, m-avg. length of the string.
// Space Complexity: O(m).	
// This algorithm is Sorting based. We observe that if we have a series of anagrams based on deletion strategy any string can be deleted by any of the prev. 
// anagrams in the series as these are anagrams, so any anagram with a anagram to it's left will be deleted from the series and only the first instance of 
// anagram will be left at the end. So, in the given array is composed of series of anagrams of length>=1, only the first of these series will be left, so 
// we add a string to res if it's sorted rep isn't equal to its prev. str sorted rep, if equal these two are anagrams and curr. have a anagram to it's left
// and it will be deleted in the process, if diff. curr. str is the first anagram of the next series and we add this to res, store the rep and continue the 
// process. We return res at the end of iter.







class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>res({words[0]});
        string prev=words[0];
        sort(prev.begin(), prev.end());										// Getting sorted rep of first word.
        for(int i=1;i<words.size();i++) {									// Iter. over array.
            string temp=words[i];
            sort(temp.begin(), temp.end());									// Get sorted rep of curr. word.
            if(temp!=prev) {												// If curr. rep isn't equal to prev. word's sorted rep.
                res.push_back(words[i]);									// We add curr. str to res as curr. str is first anagram of next series.
                prev=temp;													// We store sorted rep of curr. str.
            }
        }
        
        return res;															// Returning an array of final strs after all possible operations.
    }
};

