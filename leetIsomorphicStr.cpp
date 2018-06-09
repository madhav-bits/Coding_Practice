/*
*
//**********************************************************205. Isomorphic Strings.***************************************************

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map 
to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"EggE"
"Adcb"


"ab"
"aa"




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We save the corresponding char in other string to the curr. string's char, we do this both ways. If there
// is no mapping b/w both string curr. chars, we assign them. If only one of them doesn't have any char. assigned to it, return false or if
// the assigned chars doesn't match the other char. return false. If no issue arises until the end of the iteration, then return true.








class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;									// If lengths are not equal, return false.
        map<char,char>m,n;															// Stores relation b/w chars.
        for(int i=0;i<s.length();i++){
            // cout<<"Beginnig of loop: index: "<<i<<" s[i]: "<<s[i]<<" and "<<t[i]<<endl;
            if(m.count(s[i])==0 && n.count(t[i])==0){								// If both curr. chars are not assigned any chars, assign them.
                m[s[i]]=t[i];
                n[t[i]]=s[i];
            }
            else if(m.count(s[i])==0 || n.count(t[i])==0) return false;				// If only one of them not assigned any char, return false.
            else if(m[s[i]]!=t[i] || n[t[i]]!=s[i]) return false;					// If assigned chars doesn't match, return false.
        }
        return true;																// If no issue arises, return true.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We save last time curr. char has occured. If index matches to that of other char's index then that's fine, 
// if not return false. Matching index number indicates same set of chars had occured once again/ Or the pair of are occuring for the first time.


// If I use HashMap execution speed decreased drastically.So, I switched to vector of size(256).





class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;									// If lengths are not equal, return false.
        // map<char,int>m,n;														// Stores rel. b/w chars(It uses indices to match chars).
        vector<int>m(256,0), n(256,0);												// Stores rel. b/w chars.
        for(int i=0;i<s.length();i++){
            // cout<<"Beginnig of loop: index: "<<i<<" s[i]: "<<s[i]<<" and "<<t[i]<<endl;
            if(m[s[i]]!=n[t[i]]) return false;										// If checks prev. occured index of these chars are same.
            m[s[i]]=i+1;															// Update to curr. index.
            n[t[i]]=i+1;														// Update to curr. index(this covers first occur. of both chars)
        }
        return true;																// If no issue arises, return true.
    }
};