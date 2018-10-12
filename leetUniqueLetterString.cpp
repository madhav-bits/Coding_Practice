/*
*
//**********************************************************828. Unique Letter String.***************************************************

A character is unique in string S if it occurs exactly once in it.

For example, in string S = "LETTER", the only unique characters are "L" and "R".

Let's define UNIQ(S) as the number of unique characters in string S.

For example, UNIQ("LETTER") =  2.

Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.

If there are two or more equal substrings at different positions in S, we consider them different.

Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.

 

Example 1:

Input: "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: "ABA"
Output: 8
Explanation: The same as example 1, except uni("ABA") = 1.
 

Note: 0 <= S.length <= 10000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"CCAABBACAD"

"AACC"

""



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we extract the substrings where a char is Unique. This can be achieved by Tracking occur.
// of all chars, if a char has occured at index 'i', then the substrings in which prev. occurance of curr. char depends on it's prev. 
// and curr. index 'i'. So, we use both those indices to get total #combination of substrs involving prev. occurance of curr. char.
// (occur[s[i]-'A']-prev[s[i]-'A']) indicates all chars b/w prev. and it's prev. occurance, (i-occur[s[i]-'A']) chars b/w curr. and prev. occur.
// We multiply these two values to get all combinations involving prev. occurance of char. At the end of iter. we have to get all combi. of 
// substrs where last occur. of each char had occured with s.length() as curr. occurance point.








class Solution {
public:    
    int uniqueLetterString(string s) {
        vector<int>occur(26,-1), prev(26,-1);								// Tracks prev. and it's prev. occurance indices of chars.
        int modu=1000000007;												// Mod value.
        int res=0;															// Final result value.
        for(int i=0;i<s.length();i++){										// Iter. through all indices.
                int len=occur[s[i]-'A']-prev[s[i]-'A'];						// #chars b/w prev. and it's prev. occur. of curr. char.
                int curr=i-occur[s[i]-'A'];									// #chars b/w curr. index/char and it's prev. occurance.
                res=(res+(len*curr)%modu)%modu;								// Adding #combi. to total combinations.
                prev[s[i]-'A']=occur[s[i]-'A'];								// Updating the prev. to prev. to prev. index.
                occur[s[i]-'A']=i;											// Updating prev. index to curr. index.
            // cout<<"res: "<<res<<endl;
        }
        for(int i=0;i<26;i++){												// All combinations with last occur. of all chars.
            int len=occur[i]-prev[i];
            int curr=s.length()-occur[i];
            // cout<<"len: "<<len<<" and curr: "<<curr<<endl;
            res=(res+(len*curr)%modu)%modu;
        }
        return res;															// Reutrning the final result combinations.
    }
};