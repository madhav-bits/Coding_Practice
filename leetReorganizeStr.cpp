/*
*
//**********************************************************767. Reorganize String.***************************************************

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aaadfefdsfadhthtngndjfhgdioab"
"aaba"
"aba"
"aaabbab"
"a"



// Time Complexity: O(nlogk).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk).			// n- length of string.
// Space Complexity: O(n).	
// This algorithm is GREEDY ALGORITHM. We iterate and store #occurances of chars in string. We greedily push the char with max #occurances
// into final result, we dec. it's #occurances and push back into PQ,if#occurances>0 for that char. If at the end, if we have a char with #occur-
// -ances >0, then it's not possible to get a desired string, so return "", else return the final result str.






class Solution {
public:
    
    string reorganizeString(string s) {
        vector<int>v(26,0);													// Stores #ocurances of all chars in string.
        for(auto ch:s) v[ch-'a']++;											// Counting chars in array.
        
        auto cmp=[&v]( int a, int b){                       				// Implements Max Heap.
            return v[a]<v[b];
        };
        
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);            
        for(int i=0;i<26;i++)												// Push all indices into PQ.
            if(v[i]>0) pq.push(i);
        
        for(int i=0, prev=-1;i<s.length();i++){								// Iterates through the length of the string.
            // cout<<"index i: "<<i<<endl;
            if(pq.empty() && prev>=0) return "";							// If pq. is size and a char is yet present, then return "".
            int curr=pq.top();
            pq.pop();
            s[i]=curr+'a';
            if(prev>=0) pq.push(prev);										// Pushing the prev. char into PQ, if count>0.
            prev=(--v[curr]==0)?-1:curr;									// Setting the index<0, if #occur. of that char is<=0. 
            
        }
        return s;															// Returning the final resultant str.
    }
};

