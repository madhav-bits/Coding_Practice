/*
*
//**********************************************************243. Shortest Word Distance.***************************************************

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["practice", "makes", "perfect", "coding"]
"coding"
"practice"


["a", "b", "c","e","f", "d","a","b","a"]
"a"
"d"


["a", "b", "c","e","f", "d","b","b","a"]
"a"
"d"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We first iterate and store the indices of occurances of two words in string. Then extract two adjacent 
// indices belonging to two words, then calculate the min. dist of all those combinations. I don't want to use abs fn., that's why I had done
// it this way.








class Solution {
public:
    int shortestDistance(vector<string>& v, string word1, string word2) {
        int res=INT_MAX;													// Final result.
        vector<int>str1, str2;												// Stores occuring indices of two words.
        for(int i=0;i<v.size();i++){
            if(v[i]==word1) str1.push_back(i);								// Storing index of word1.
            else if(v[i]==word2) str2.push_back(i);							// Storing index of word2.
        }
        int i=0,j=0;
        while(i<str1.size() && j<str2.size()){								// Iterating through stored indices.
            if(str1[i]>=str2[j]){											// If index of word1>latest index of word2.
                res=min(res,str1[i]-str2[j]);
                j++;
            }
            else{
                res=min(res,str2[j]-str1[i]);								// If latest index of word2>latest index of word1.
                i++;
            }
        }
        return res;															// Returning the min. diff. dist.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate and store the latest indices of occurances of two words in string. Then calculate the dist 
//  b/w curr. latest indices and track the min. dist. of all those combinations. I don't want to use abs fn., that's why I had done it this way.



class Solution {
public:
    int shortestDistance(vector<string>& v, string word1, string word2) {
        int res=INT_MAX;
        int index1=-1, index2=-1;											// Default index values.
        for(int i=0;i<v.size();i++){
            if(v[i]== word1){												// If word1 had occured.
                if(index2!=-1) res=min(res,abs(i-index2));					// If word2 had prev. occured, calc. min. dist to it.
                index1=i;													// Update the latest occurance of word1.
            }
            else if(v[i]==word2){											// If word2 had occured.
                if(index1!=-1) res=min(res,abs(i-index1));					// If word1 had prev. occured, calc. dist to it.
                index2=i;													// Update the latest occurance of word2.
            }
        }
        return res;															// Returning the min. dist.
    }
};