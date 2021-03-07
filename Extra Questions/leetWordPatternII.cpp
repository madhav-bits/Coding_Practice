/*
*
//************************************************************291. Word Pattern II.*****************************************************

https://leetcode.com/problems/word-pattern-ii/



Given two strings, we have to check whether bijectively mapping char from pattern and substrings in s would make them to have similar pattern or not?



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"abab"
"redblueredblue"
"aabb"
"asdasdasdasd"
"aabb"
"xyzabcxzyabc"
"aaaa"
"asdasdasdasd"
"abab"
"asdasdasdasd"
"aabb"
"xyzabcxzyabc"
"abba"
"dogcatcatdog"



// Time Complexity: O(n^m).													// n- length of string, m-length of the pattern.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^m).													// n- length of string, m-length of the pattern.
// Space Complexity: O(n).	
// This algorithm is DFS+Backtracking based. Here, at every step we check curr. char in pattern is already used, if used we check whether attached substr
// starting curr. index in string matches the linked string, if not we return false. If they match we move to i+1 in pattern j+linked str length() in 
// given string. If curr. char in pattern is not linked, we assign substrings starting from curr. index and look for substrings for following chars in
// pattern and return true if we reach end of indices in both strings at same time(indicating all chars are mapped perfectly).










class Solution {
public:
    
    bool findPattern(string &pattern, int i, string &s, int j, vector<string>&v, unordered_set<string>&st){
        if(i==pattern.length() || j==s.length()){							// Checking whether we reached end of string at same time.
            // if((i==pattern.length() && j==s.length())) 
                // cout<<"matching a: "<<v[0]<<" matching b: "<<v[1]<<endl;
            return (i==pattern.length() && j==s.length());
        } 
        if(v[pattern[i]-'a']!=""){											// If curr. char in pattern is already mapped.
            if(v[pattern[i]-'a']!=s.substr(j,v[pattern[i]-'a'].length())) return false;	// If mapped string!=curr. substring in s, return false.
            return findPattern(pattern, i+1, s, j+v[pattern[i]-'a'].length(), v, st);	// Checking indices after curr. substr in s.
        }
        
        for(int k=j;k<s.length();k++){										// If char isn't mapped, we assign substr to it in backtracking way.
            string temp=s.substr(j,k-j+1);
            // cout<<"i: "<<i<<" and substr trying: "<<temp<<endl;
            if(st.count(temp)==1) continue;									// If this substr is already used, we can't assign this substr to curr. char.
            v[pattern[i]-'a']=temp;											// Assigning curr. substr to curr. char in pattern.
            st.insert(temp);
            if(findPattern(pattern, i+1, s, k+1, v, st)) return true;		// If we can reach end of strs at same time, we return true.
            st.erase(temp);													// If we can't reach end of pattern, remove curr. substr and try another one.
        }
        v[pattern[i]-'a']="";												// Remove assigned substr to curr. char in pattern.
        return false;														// Return false if we can't reach end of both strs at same time.
    }
    
    bool wordPatternMatch(string pattern, string s) {
        vector<string>v(26,"");												// Stores substr attached to each char in pattern.
        unordered_set<string>st;
        return findPattern(pattern, 0, s, 0, v, st);						// Checks for all combinations in backtracking way.
    }
};
