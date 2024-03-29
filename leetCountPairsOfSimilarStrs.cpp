/*
*
//******************************************************2506. Count Pairs Of Similar Strings.******************************************************

https://leetcode.com/problems/count-pairs-of-similar-strings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["aba","aabb","abcd","bac","aabc"]
["aabb","ab","ba"]
["nba","cba","dba"]



// Time Complexity: O(m*n).																				// m-#words, n-#avg. length of the words.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).																				// m-#words, n-#avg. length of the words.
// Space Complexity: O(m).	
// This algorithm is binary representation based. Here, we have to form pairs of strings which have same set of chars. As, we are only dealing with lower case alphabets, we use ints to store the
// chars present in the words, we update the cnt of each set of chars represented by num rep in map by 1 after iter. Thus, at the end of iter, we have the freq. of all set of chars in the
// words in the array, we calc. number of pairs possible for each set of chars and add it to res and return it.







class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res=0;
        unordered_map<int,int>m;																		// Stores the freq. of occur. of each set of chars in words.
        for(string&s:words) {
            int rep=0;
            for(char&ch:s) {																			// Iter. over curr. string.
                rep|=(1<<(ch-'a'));																		// Marking that curr. char had occured in the rep. number.
            }
            m[rep]++;																					// Inc. the count of rep. number in the map.
        }
        for(auto it=m.begin();it!=m.end();it++) {
            if(it->second>1) res+=(it->second*(it->second-1))/2;										// Calc. number of pairs for each set of chars.
        }
        return res;																						// Returing the cnt of total number of pairs of similar words.
    }
};

