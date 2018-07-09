/*
*
//******************************************************245. Shortest Word Distance III.***********************************************

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["practice", "makes", "perfect", "coding", "c","makes","a","b","makes"]
"makes"
"makes"



["a","c","d","b","e","a"]
"a"
"b"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is LInear search based. In the iteration, when words are encountered, we store the indices and calc. diff. to previous time 
// the other word had occured. If two words are same,we extract the last time, the same word had occured and calc. distance. We try to udpate 
// the min. distance whenever a word is encountered and the other word is encountered previously.








class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1=-1,index2=-1,res=words.size();
        for(int i=0;i<words.size();i++){
            if(words[i]==word1){											// IF word is encountered.
                if(word1==word2 && index1!=-1) res=min(res,i-index1);		// If both words are same and it's encountered in the past.
                if(index2!=-1) res=min(res,i-index2);						// If prev. word had been encountered in the past.
                index1=i;													// Updating the curr. encountered word's index.
            }
            else if(words[i]==word2){										// If other word is encountered.
                if(index1!=-1) res=min(res,i-index1);						// If prev. word had been encountered in the past.
                index2=i;													// Updating the curr. encountered word's index.
            }
        }
        return res;															// Returning the min. distance b/w the words given.
    }
};