/*
*
//******************************************************676. Implement Magic Dictionary.***********************************************

Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the 
modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test 
cases. Please see here for more details.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

- No Test cases, I had created and worked on.



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm build Maigc Dictionary using a Dictionary in the background. This is straight forward implementation of Map. While pushing new 
// elements into map, just pushing it into map as it as. While searching, we search through out the map with all keys and check for those keys with 
// length same as the given target word and mismatches the target word by only single char.





class MagicDictionary {
public:
    /** Initialize your data structure here. */
     map<string, int> m;											// The Map which we work on, in the solution.
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> v) {
        for(int i=0;i<v.size();i++){								//Pushing the given vector of words into Map.
            m[v[i]]=1;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto it=m.begin();it!=m.end();it++){					//Iterating through all the keys in the map.
            //cout<<"Inside the for with words: "<<it->first<<" and the word is: "<<word<<endl;
            if(it->first.length()!= word.length()) continue;		// If a key's length != target word's length then continue.
            int count=0;
            for(int i=0;i<word.length();i++){
                if(it->first[i]!=word[i]){							// If a key's char mismatches with target word.
                    //cout<<"The unequal words with index: "<<i<<" are: "<<it->first[i]<<" and: "<<word[i]<<endl;
                    count++;
                }
            }
            if(count==1) return true;								// If #mismatches =1, then this is the required modified string.
        }
        return false;												// If we can't find any required modified string(Differ by only sing char).
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */