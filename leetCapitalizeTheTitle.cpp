/*
*
//******************************************************2129. Capitalize the Title.******************************************************

https://leetcode.com/problems/capitalize-the-title/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"capiTalIze tHe titLe"
"First leTTeR of EACH Word"
"i lOve leetcode"
"A ab aBcD ABc cddfG A"
"a Ab adsfas badbAGS aB"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. In the iteration we convert all chars to lower case chars. We keep track of first indices of each word and upon reaching space char, we calc. the length of the
// word using first char index and convert the first char to upper case if the length of the word>=3 and reset the tracking var=-1, which would reset upon moving to next index(first char of word).






class Solution {
public:
    string capitalizeTitle(string s) {
        int index=-1;																					// Tracks starting index of each word.
        for(int i=0;i<s.length();i++) {
            if(index==-1) index=i;																		// Stores index of first char of each word while iterating.
            if(isalpha(s[i])) s[i]=tolower(s[i]);														// Converting every char to lower case.
            else {
                // cout<<"i: "<<i<<" and index: "<<index<<endl;
                if(index!=-1 && (i-index)>=3) s[index]=toupper(s[index]);								// If length of the word>=3, we convert first char to upper case.
                index=-1;																				// Reset the word's starting index tracker to -1.
            }
        }
        if(s.length()-index>=3) s[index]=toupper(s[index]);												// Checking condition for the last word.
        return s;																						// Returning the transformed string.
    }
};

