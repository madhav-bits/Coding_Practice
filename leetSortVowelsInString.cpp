/*
*
//******************************************************2785. Sort Vowels in a String.******************************************************

https://leetcode.com/problems/sort-vowels-in-a-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"lEetcOde"
"lYmpH"
"ba"
"lkjhardMUDYMIASTHjHNGMAlkaj"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Map based. We store #occur. of all upper, lowercase vowels in the string. In the second iter. we replace the sorted alphabets based on the
// #occur. in map in the indices where vowels are present leaving consonants in their place.




 


class Solution {
public:
    
    bool isConsonant(char&ch) {
        if(isupper(ch) && 
          (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')) return false;
        if(islower(ch) && 
          (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')) return false;
        return true;
    }
    
    string sortVowels(string s) {
        
        vector<int>small(26, 0), large(26, 0);
        int smallCount=0, largeCount=0;
        for(char&ch:s) {
            if(isConsonant(ch)) continue;
            if(isupper(ch)) {												// Tracking #occur. of each of the uppercase vowels.
                large[ch-'A']++;
                largeCount++;
            }else {															// Tracking #occur. of each of the lowercase vowels.
                small[ch-'a']++;
                smallCount++;
            }
        }
        
        int i=0,j=0;
        for(char&ch:s) {
            if(isConsonant(ch)) continue;									// Leaving the consonants chars in their orig. psns.
            if(largeCount) {												// First filling out all the uppercase chars.
                while(j<26 && large[j]==0) j++;								// Skipping chars which occurred zero times/whose occur. are already used up.
                ch=('A'+j);
                large[j]--;													// Dec. the #occur. of curr. used char by 1.
                largeCount--;
            } else {														// Filling out lowercase chars once uppercase chars are done.
                while(i<26 && small[i]==0) i++;
                ch=('a'+i);
                small[i]--;
                smallCount--;
            } 
        }
        
        return s;															// Returning the string after sorting vowel chars.
    }	
};

