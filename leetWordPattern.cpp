/*
*
//**********************************************************290. Word Pattern.***************************************************

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abbc"
"dog cat cat"


"ab"
"dog dog"


"abcdd"
"dog cat pig horse"

"abcd"
"dog cat pig"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We maintain two ptrs, first ptr makrs the curr. char to be compared, second char marks next words to be extrac.
// If the char in old & word is new/ char is new & word is old, then return false. If one of strings had completed iteration earlier->return false.
// If compl. iteration occured without any issues, then return true.





class Solution {
public:
    bool wordPattern(string pat, string str) {
        bool res;
        map<char,int> m1;																// Stores the chars in pattern.
        map<string, int> m2;															// Stores the words in string.
        string temp="";
        int i=0, ind=0;																	// Iterators for str and path.
        while(ind<pat.length() && i<str.length()){										// Iterates until any one of two str and comp. iterated.
            while(i<str.length() && str[i]!=' '  ){										// Extracting the word from string.
                temp+=str[i];
                i++;
            }
            //cout<<"Curr. extracted string is: "<<temp<<" and char is: "<<pat[ind]<<endl;
            if(m1.count(pat[ind])==0){													// If the char is new to pattern map, add it.
                if(m2.count(temp)==1) return false;										// If this word is pres. in patt. map, return false.
                m1[pat[ind]]=ind;														// Adding new char/word to both maps.
                m2[temp]=ind;
            }
            else{
                //cout<<"Inside the else"<<endl;
                if(m2.count(temp)==0) return false;										// If the char old and word is new, return false.
                if(m1[pat[ind]]!=m2[temp]) return false;								// If the first occur. of char/word doesn't match,ret false.
            }
            temp="";																	// Initiazling for next word.
            ind++;																		// Inc. both the iterators.
            i++;
        }
        //cout<<"Ouside the while"<<endl;
        if(ind<pat.length() || i<str.length()) return false;							// If one of strs had reached end, then ret. false.
        return true;																	// If properly iterated compl., then return true.
    }
};