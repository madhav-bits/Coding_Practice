/*
*
//******************************************************288. Unique Word Abbreviation.***********************************************

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓    
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if 
no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique","isUnique","isUnique","isUnique","isUnique"]
[[["deer","door","cake","card","ab","c",""]],["dear"],["cart"],["cane"],["make"],["a"],[""],["ab"],["c"]]



["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique","isUnique","isUnique","isUnique","isUnique"]
[[["deer","door","cake","card","cord","ab","ef","c",""]],["dear"],["cart"],["cane"],["make"],["a"],[""],["ab"],["card"]]



["ValidWordAbbr","isUnique"]
[[["hello"]],["hello"]]







// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We scan through the entire vector, to store each word and it's abbreviation, if their length>=3, as length<=2
// strings are considered unique, and they would be unique anyway. If a word is given, if the length<3, they are unique, if not we extract the
// abbre. and compare it's count with whether curr. word has occured. If the word haven't occured/ occured but only once and the abbre. had also
// occured only once, then return true else return false.









class ValidWordAbbr {
public:
    unordered_map<string,int> m;											// Stores the abbre. count.
    unordered_map<string,int>count;											// Stores occurance of a str.
    ValidWordAbbr(vector<string> dict) {
        for(int i=0;i<dict.size();i++){
            // cout<<"The curr. string: "<<dict[i]<<endl;
            string str="";
            if(dict[i].length()>=3){										// Extract abbre. and inc. it's count 
                str=dict[i][0]+to_string(dict[i].length()-2)+dict[i].back();
                m[str]++;
                count[dict[i]]++;											// Store occurance of curr. word.
                // cout<<"Non-Empty abbre: "<<str<<" and count: "<<m[str]<<endl;
            } 
        }
    }
    
    bool isUnique(string word) {
        string str="";
        // cout<<"Curr. word: "<<word<<endl;
        if(word.length()>=3) str=word[0]+to_string(word.length()-2)+word.back();// Extract abbre.
        else return true;													// If length<3, then return true.
        // cout<<"Calc. abbre: "<<str<<endl;
        return (count[word]==m[str])?true:false;							// Word haven't occured/word occured and count of abbre.is same as word.
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */