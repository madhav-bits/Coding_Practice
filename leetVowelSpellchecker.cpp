/*
*
//************************************************************966. Vowel Spellchecker.*****************************************************

Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case 
in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the 
wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 

Note:

1 <= wordlist.length <= 5000
1 <= queries.length <= 5000
1 <= wordlist[i].length <= 7
1 <= queries[i].length <= 7
All strings in wordlist and queries consist only of english letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["ae", "ai"]
["OI"]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. Here, there are 4 cdns to lookout for with different proirities. Three of those properties require hashMaps to 
// be created, so, we build hashmaps acc. to requirement. One cdn is that, if the word from query is in wordlist, return that word exactly, so 
// we build a hashMap of words from wordlist. Second cdn is that, if we find case-insensitive word from query in wordlist, return first such word
// in wordlist, for that we create a map of lowercase strings where the value of that key would be first occurance of that lowercase string. Third
// cdn is that, if vowels in query can be replaced with any vowel and if the new modified matches case-insensitively with any word from wordlist,
// return first such instance. We build a hashmap of lowercase strings, where vowels are replaced by "#"(A diff. char representing presence of 
// vowels). We change the vowels in curr. lowercased string with "#", if we find the word in modified strings map, we return the value assigned to
// it. If we didn't find any of 3 maps, we return "".



class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>m;												// Stores words from wordlist.
        unordered_map<string,int>lower, modified;							// Stores lowercased strs, lowercased vowels modified strs.
        for(auto str: wordlist) m.insert(str);								// Inserting words into map.
        for(int i=0;i<wordlist.size();i++){									// Inserting lowercased strs into map.
            string t=wordlist[i];
            transform(t.begin(), t.end(), t.begin(), ::tolower);			// convert into lowercase.
            // cout<<"string : "<<wordlist[i]<<" and lower: "<<t<<endl;
            if(lower.count(t)==0) lower[t]=i;								// Assigning the lowercased str, it's first occurance.
        }
        for(int i=0;i<wordlist.size();i++){									// Inserting lowercased modified strs into map.
            string t=wordlist[i];
            transform(t.begin(), t.end(), t.begin(), ::tolower);			// Converting into lowercase.
            string temp="";
            for(int j=0;j<t.length();j++){									// Replacing vowels with "#" in the string.
                if(t[j]=='a' || t[j]=='e' || t[j]=='i' || t[j]=='o' || t[j]=='u') temp+="#";
                else temp+=t[j];
            }
            // cout<<"string: "<<wordlist[i]<<" and modified: "<<temp<<endl;
            if(modified.count(temp)==0) modified[temp]=i;					// Assigning the lowercased modified str, it's first occurance.
        }
        
        vector<string>res;													// Stores the final result.
        for(auto str:queries){												// Iter. over queries.
            if(m.count(str)==1){											// If word found in wordlist, push into final result.
                res.push_back(str);
                continue;
            }
            string t=str;
            transform(t.begin(), t.end(), t.begin(), ::tolower);			// Converting into lowercase.
            // cout<<"query. str: "<<str<<" and lower: "<<t<<endl;
            if(lower.count(t)==1){											// If lowercased str found, then push it's 1st orig. version into res.
                res.push_back(wordlist[lower[t]]);
                continue;
            }
            string temp="";
            for(int j=0;j<t.length();j++){
                if(t[j]=='a' || t[j]=='e' || t[j]=='i' || t[j]=='o' || t[j]=='u') temp+="#";// Modifying the lowercased str.
                else temp+=t[j];
            }
            if(modified.count(temp)==1){									// If modified str found, push it's 1st orig. version into res.
                res.push_back(wordlist[modified[temp]]);
                continue;
            }
            res.push_back("");												// If str not found, push "" into final res.
            
        }
        return res;															// Returning the vowel spellchecked queries.
    }
};

