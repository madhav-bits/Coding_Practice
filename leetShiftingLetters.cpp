/*
*
//******************************************************848. Shifting Letters.******************************************************

https://leetcode.com/problems/shifting-letters/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abc"
[3,5,9]
"aaa"
[1,2,3]
"poqjiodjiodbzmzxnvknsfo"
[1,2,4,5,3,6,67,4,5,18,76,3,3,5,28,8,76,43,3,6,7,6,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Mod Arithmatic based. As shifts'[i] affects first 'i' indices and all the indices to it's right will also affect first 'i' indices 
// atleast, we do a suffixSum of shifts to get total #shifts each index have to make. We later iter. over array and make shifts as per calc. and update 
// the given string and return it after iter.







class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        shifts.back()%=26;
        for(int i=shifts.size()-2;i>=0;i--) {
            shifts[i]=(shifts[i]+shifts[i+1])%26;							// Calc. suffixSum from 'i' to back.
        }
        
        for(int i=0;i<s.length();i++) {
            int moves=(s[i]-'a'+shifts[i])%26;								// Calc. final char after the shifts.
            s[i]=('a'+moves);												// Updatin curr. index with the final char.
        }
        return s;															// Returning the final str after the shifts.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Mod Arithmatic based. This is same as the above algo, except that it's a slightly simplified version.





class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int total=0;
        for(int i=s.length()-1;i>=0;i--) {
            total=(total+shifts[i])%26;										// Tracking suffixSum of shifts until 'i' from the back.
            int moves=(s[i]-'a'+total)%26;
            s[i]=('a'+moves);
        }
        return s;															// Returning the final str after the shifts.
    }
};


