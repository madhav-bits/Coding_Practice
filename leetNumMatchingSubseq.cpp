/*
*
//******************************************************792. Number of Matching Subsequences.***********************************************

https://leetcode.com/problems/number-of-matching-subsequences/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"abcde"
["a","bb","acd","ace"]
"dsahjpjauf"
["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]



// Time Complexity: O(m+n*l).												// m- length of the string 's', n-#words, l-avg. length of the words.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n*l).												// m- length of the string 's', n-#words, l-avg. length of the words.
// Space Complexity: O(n).	
// This algorithm is Bucket/Dynamic Trie based. Here, to find the subsequences we iter. over 's' for each of the given words, which gives TLE error.
// We iter. over given words, store the words markers(word index, curr. looking for index). We iter. over 's' once, at every step we only work on words,
// whose curr. char is matching curr. char of 's', we look into next required char in all those words and all them to appropriate buckets for next. char
// in 's'. In this process, if we observe that curr. word's end is reached we inc. the res var by 1 and we return it at the end of iteration.









class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // int res=0;
        // for(string word:words){											// Brute force solution.
        //     int j=0,i=0;
        //     while(j<word.length() && i<s.length()){
        //         if(word[j]==s[i]) j++;
        //         i++;
        //     }
        //     if(j==word.length()) res++;
        // }
        // return res;
        
        vector<vector<pair<int,int>>>v(26);									// Buckets indicating next char requirement for the words.
        for(int i=0;i<words.size();i++){
            v[words[i][0]-'a'].push_back({i,0});							// Pushing word's markers into next. char related index in vector 'v'.
        }
        int res=0;
        for(int i=0;i<s.length();i++){
            vector<pair<int,int>>temp=v[s[i]-'a'];							// Copying bucket of curr. char of 's'.
            v[s[i]-'a'].clear();
            for(pair<int,int>&curr:temp){									// Iter. over curr. bucket's contents.
                curr.second++;
                if(curr.second==words[curr.first].size()){					// If curr. word has reached it's end, we inc. the res by 1.
                    // cout<<"curr. index: "<<i<<" and word: "<<words[curr.first]<<endl;
                    res++;
                }
                else v[words[curr.first][curr.second]-'a'].push_back(curr);	// We push curr. word's markers into bucket related to next char.
            }
        }
        return res;															// Returning the #matching subsequences.
    }
};
