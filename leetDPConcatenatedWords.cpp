/*
*
//******************************************************472. Concatenated Words.***********************************************

Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["cat","cats","catsdogcats","dog","dogdog","dogcatsdog","hippopotamuses","rat","ratcatdogcat",""]

["a", "aa","aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaa", "aaaaaaaaaaaa", "aaaaaaaaaaaaa", "aaaaaaaaaaaaaa", "aaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaa","b", "bc"]

["b","c","d"]

["", "b","c","d"]



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is DP/Memoization based. We store all words in the Map. We start iterating each word, when we encounter a substr from dict.
// we call fn. to extract words from rem. substr, in the process we store no. of words extracted from particular substr in the visited map.
// The instant we have >=2 words extracted from a substr,we return true to the caller. If true is returned to the main fn., we append that str.
// to the result vector of strings.

// This is DP from top to bottom, bottom to top DP would be much more appealing/simple.




class Solution {
public:
    int extractStr(string s, int comb,  unordered_map<string, int> &visited, unordered_map<string, int> &dict){
        //cout<<"Beginning of Function call with string s: "<<s<<endl;
        int maxm=INT_MIN;
        if(visited.count(s)==1) return visited[s];								// If a substr is already visited, return the val. in visited map.
        
        
        if(s.length()==0){														// If empty string encountered, return 0.
            //cout<<"Returning zero for empty string."<<endl;
            visited[s]=0;
            return 0;
        }
        
        for(int len=1;len<=s.length();len++){
            string temp=s.substr(0,len);
            if(dict.count(temp)==1){											// If substr. is in dict., call fn. to extr. words from rem. substr
                //cout<<"calling the next fn. with str: "<<s.substr(len)<<endl;
                int ans=extractStr(s.substr(len), comb+1,  visited, dict);		// Extract no. of words from rem. substr.
                //cout<<"value extracted from fm.call with string: "<<s.substr(len)<<" is: "<<ans<<endl;
                maxm=max(maxm, 1+ans);											// Max. no. of words from curr. string.
                if(1+ans>=2) return 1+ans;										// The instant #words>=2, return 2.
            }
            
        }
        visited[s]=maxm;														// Updating the visited map.
        return maxm;															// Returning max #words extracted from curr. string.
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_map<string, int> dict;										// Stores words in the map.
        unordered_map<string, int> visited;										// Stores #words extracted from the visited substr.
        for(auto str:words) dict[str]=1;										// Storing words into dict.
        for(int i=0;i<words.size();i++){
            if(extractStr(words[i],0, visited, dict)>=2) res.push_back(words[i]);	// Calling fn. to extract words from curr. string.
        }
        return res;																// Returning result vector of strings which have >=2 extr. words.
    }
};