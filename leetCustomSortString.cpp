/*
*
//**********************************************************791. Custom Sort String.***************************************************

S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More 
specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
 

Note:

S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"abcd"
"abcbadefged"


"kqeps"
"pekeasdasfasdq"


""
"asfsfasdq"

// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm iterates the target array and counts the occurance of all characters in it. Later, it iterates the sorted string, also extracts
// same chars from the second string, and places them in same order. After that we, iterate over the map once again and extract those chars,
// which are not present in the sorted string, and appends them to final result string.



class Solution {
public:
    string customSortString(string s1, string s2) {
        string t="";
        map<char, int> m;												// Stores the # occurances of the chars in string 2.
        for( auto ch:s2)
            m[ch]+=1;
        for(int i=0;i<s1.length();i++){
            while(m[s1[i]]>0){											// Appends, chars from s2 in the same order as s1 to the final string.
                //cout<<"Adding char is: "<<s2[i]<<"with new count: "<<m[s2[i]]<<endl;
                t+=s1[i];
                m[s1[i]]--;
            }
        }
        for(auto it=m.begin();it!=m.end();it++){						// Appends, remaining chars from s2 to the final result.
            while(it->second>0){
                t+=it->first;
                it->second--;
            }
        }
        return t;														// Returning the final result string.
    }
};