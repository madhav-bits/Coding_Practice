/*
*
//******************************************************2109. Adding Spaces to a String.******************************************************

https://leetcode.com/problems/adding-spaces-to-a-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"LeetcodeHelpsMeLearn"
[8,13,15]
"icodeinpython"
[1,5,7,9]
"spacing"
[0,1,2,3,4,5,6]
"jlkajeraobnjotjaddl"
[0,3,4,5,6,8,9,10,17,18]



// Time Complexity: O(n+m).													//n-length of the string, m-size of spaces array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													//n-length of the string, m-size of spaces array.
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over orig. string and add empty spaces in the res in the indices mentioned in the array and we keep adding chars
// from orig. string, in this way we add empty spaces in the requested positions. we return res str at the end of iter.

// The commented part is also an accepted solution. Here, we fill res str from the back, this approach would be extremely effective when we are add empty
// spaces to the same str provided, as in this case we can use another str for res, we used another str else commented part would be effective.







class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
		
		// This is also accepted solution, this fills res str from the back.
        // string t=string(s.length()+spaces.size(),' ');					// We fill the res str from the back in this process.
        // int i=s.length()-1, j=t.length()-1, k=spaces.size()-1;
        // while(i>=0) {
        //     if(k>=0 && k+spaces[k]==j) j--, k--;							// We pre calc. the index of spaces in res str and add them accordingly.
        //     else t[j--]=s[i--];											// We add chars from orig. str from the back in non-space indices.
        // }
        // return t;
        
        string res="";
        int i=0,j=0;
        while(i<s.length()) {
            if(j<spaces.size() && spaces[j]==i) res+=' ', j++;				// If curr. index needs empty space, we add space.
            res+=s[i++];													// We add chars from orig. str. to res str.
        }
        return res;															// Returning final str with empty spaces.
    }
};

