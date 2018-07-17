/*
*
//**********************************************************246. Strobogrammatic Number.***************************************************

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"669"


"619"


"1"


"121"


"691808169"


""


"65109"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Vector/HashMap based. As, there are 4 pairs of numbers, which are same when reversed. We form key/value pairs with them.
// We take ptrs, iterate from both sides, compare those chars check if first char's key's pair in map is equal to that of second char, then 
// we ahead in iteration, else return false.
// In case of odd length strings, we still need to check one more char(middle one), as this char stays in this psn upon rotation, it has to either
// 1/0/8, else return false. If no issue had arised till now, then return true.








class Solution {
public:
    bool isStrobogrammatic(string str) {
        unordered_map<char,char>m;											// Stores inverse pairs in map.
        m['1']='1';
        m['9']='6';
        m['6']='9';
        m['8']='8';
        int len=str.length();
        for(int i=0;i<str.length();i++){									// Iterating till mid of str.
            if(m[str[i]]!=str[len-1-i]) return false;						// Comparing inverse pair of first char with second char.
        }
        if(len%2!=0){														// In case of odd length str, check middle index.
            return (str[len/2]=='1' || str[len/2]=='8');	
        }
        return true;														// If no issues arises, return true.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Vector/HashMap based. As, there are 4 pairs of numbers, which are same when reversed. We form key/value pairs with them.
// We take ptrs, iterate from both sides, compare those chars check if first char's key's pair in map is equal to that of second char, then 
// we ahead in iteration, else return false.
// In case of odd length strings, we still need to check one more char(middle one), as this char stays in this psn upon rotation, it has to either
// 1/0/8, else return false. If no issue had arised till now, then return true.


// Same as the above one, here, I has used vectors instead of map.

class Solution {
public:
    bool isStrobogrammatic(string str) {
        vector<int>dup(10,-1);												// Set default inverse pairs as -1 to every num.
        dup[0]=0; dup[1]=1;dup[8]=8;dup[6]=9; dup[9]=6;						// Storing the inverse pairs in vector. 
        int len=str.length();
        for(int i=0;i<str.length();i++){
            if(dup[str[i]-'0']!=str[len-1-i]-'0') return false;				// Check inv. pair of first num equals second num.
        }
        if(len%2!=0){														// In case of odd length str, check middle index.
            return (str[len/2]=='1' || str[len/2]=='8'|| str[len/2]=='0');
        }
        return true;														// If no issue arises, return true.
    }
};