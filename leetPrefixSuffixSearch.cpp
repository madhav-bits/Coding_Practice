/*
*
//********************************************************745. Prefix and Suffix Search.*************************************************

Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). It will return the word with given prefix 
and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1
Note:
words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["WordFilter","f"]
[[["yo", "apple"]], ["a","e"]]


["WordFilter","f","f"]
[[["yo", "abcd","aef","abced","apple"]], ["a","e"], ["a","d"]]



["WordFilter","f","f"]
[[["yo", "abcd", "aef", "abced","apple"]], ["abc",""], ["a","d"]]


["WordFilter","f","f","f","f","f"]
[[["yo", "abcd", "aef", "abced","apple","stop"]], ["abc",""], ["a","d"], ["","top"], ["s",""], ["",""]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we create prefix and suffix search trees. Next we take prefixes and suffixes and extract strs
// ending with those suffix and prefixes from the Trie. Of the available, we are returning the longest str.
 
 
//***********************************************************************************************************************************
// MY ALGO. IS ALMOST SAME AS THE ALGORITHM 2, WHICH IS ACCPETED BY LEETCODE. WORKED ON THIS FOR 2 HOURS, MAKING MANY DATA STRUCTRE CHANGES, BUT
// ANYTHING DOESN'T WORK OUT. BUT THE LOGIC IS SAME IN BOTH ALGOS.
 
 
class WordFilter {
public:
    struct Trie{
        // bool end;
        vector<Trie*>w;
        vector<int>u;
        Trie(): u(0,""),w(26,NULL){}
    };
    
    
    Trie* pre= new Trie(), *suff= new Trie();								// Init. Prefix, Suffix Tries.
    WordFilter(vector<string> v) {
        Trie* curr1, *curr2;
        for(int i=0;i<v.size();i++){										// We iterate through the str, and push them ito tries.
            string str=v[i];
            curr1=pre; curr2=suff;
            // cout<<"Start of string: "<<str<<endl;
            for(int j=0,k=str.length()-1;j<str.length()&& k>=0;j++,k--){	// Iterating through word/trie, at each step,we push the curr. str's
                // cout<<"Curr. char: "<<curr1->ch<<endl;					// index(representing the str).
                if(curr1->w[str[j]-'a']==NULL){								// If child Trie doesn't exist, create one.
                    // cout<<"Creating trie node for char: "<<str[j]<<endl;
                    curr1->w[str[j]-'a']= new Trie();  
                } 
                
                if(curr2->w[str[k]-'a']==NULL) curr2->w[str[k]-'a']= new Trie();
                
                // cout<<"Pushing str at char: "<<str[j]<<endl;
                curr1->u.push_back(i);										// Pushing index representing curr. str
                curr2->u.push_back(i);
                curr1=curr1->w[str[j]-'a'];									// Iterating to child Trie.
                curr2=curr2->w[str[k]-'a'];
                
            }
            curr1->u.push_back(i);											// At the end, we push the curr. str's representative index value.
            curr2->u.push_back(i);
            
        }
        
        
    }
    
    int f(string prefix, string suffix) {
        int res=-1;
        reverse(suffix.begin(), suffix.end());
        unordered_set<int>s;											// Tracks indexes of strs with given prefix, suffix.
        Trie*curr1=pre, *curr2=suff;
        // cout<<"prefix first node size: "<<pre->w[prefix[0]-'a']->ch<<endl;
        int i=0,j=0;
        for(;i<prefix.length();i++){									// Iterating through the prefix, get all strs with this prefix.
            // cout<<"Curr. char of prefix: "<<prefix[i]<<endl;
            if(curr1->w[prefix[i]-'a']==NULL) break;					// If no str exist with this prefix, then break.
            curr1=curr1->w[prefix[i]-'a'];
        }
        if(i==prefix.length()){											// If strs exist.
            // cout<<"Extracted str1 count: "<<curr1->u.size()<<endl;
            for( auto str: curr1->u) s.insert(str);
        }
        
        for(;j<suffix.length();j++){									// Iterating through suffix str.
            // cout<<"Curr. char of suffix: "<<suffix[j]<<endl;
            if(curr2->w[suffix[j]-'a']==NULL) break;
            curr2=curr2->w[suffix[j]-'a'];
        }
        
        if(j==suffix.length()){											//Iterating through strs with given suffix.
            // cout<<"Extracted str2 count: "<<curr2->u.size()<<endl;
            for( auto str: curr2->u){
                if(s.count(str)==1) res=max(res,str);					// Extracting max. index of strs with both given prefix and suffix.
            }
        }
        
        return res;														// Return the str with largest index value with given prefix, suffix.
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we create prefix and suffix search trees. Next we take prefixes and suffixes and extract strs
// ending with those suffix and prefixes from the Trie. Of the available, we are returning the longest str.








#define MAX_NODE_SZ 26
class TrieNode {
    bool existed;
    struct TrieNode* next[MAX_NODE_SZ];
    set<int> weights;
public:
    TrieNode():existed(false) {
        memset(next, 0, sizeof(next));
    }
    ~TrieNode() {
        for (int i=0;i<MAX_NODE_SZ;++i) {
            if (next[i]) {
                delete next[i];
                next[i] = NULL;
            }
        }
    }
    void insert(const char* s, int beg, int end, int step, int weight) {
        if (s == NULL || *s == '\0') return;
        int i;
        TrieNode* p = this;
        for (int i=beg; i!=end; i+=step) {
            int idx = s[i] - 'a';
            if (p->next[idx] == NULL) {
                TrieNode* n = new TrieNode();
                p->next[idx] = n;
            }
            p = p->next[idx];
            p->weights.insert(weight);
        }
        p->existed = true;
    }
    bool find(const char* s, int beg, int end, int step, bool* prefix = NULL) {
        TrieNode* p = this;
        for (int i=beg; i!=end && p!=NULL; i+=step) {
            int idx = s[i] - 'a';
            p = p->next[idx];
        }
        if (prefix) *prefix = p;
        return p && p->existed;
    }
    set<int>* findWeight(const char* s, int beg, int end, int step) {
        TrieNode* p = this;
        for (int i=beg; i!=end && p!=NULL; i+=step) {
            int idx = s[i] - 'a';
            p = p->next[idx];
        }
        if (p) return &(p->weights);
        return NULL;
    }
};

class WordFilter {
    TrieNode prefixTrie;
    TrieNode suffixTrie;
    int len;
public:
    WordFilter(vector<string> words) {
        len=words.size();
        for (int i=0; i<words.size(); ++i) {
            prefixTrie.insert(words[i].c_str(), 0, words[i].size(), 1, i);
            suffixTrie.insert(words[i].c_str(), words[i].size()-1, -1, -1, i);
        }  
    }
    
    int f(string prefix, string suffix) {
        if (prefix == "") {
            if (suffix == "") return len-1;
            set<int>* s2 = suffixTrie.findWeight(suffix.c_str(), suffix.size()-1, -1, -1);
            if (s2) return *(s2->rbegin());
        }
        set<int>* s1 = prefixTrie.findWeight(prefix.c_str(), 0, prefix.size(), 1);
        if (s1) {
            if (suffix == "") return *(s1->rbegin());
            set<int>* s2 = suffixTrie.findWeight(suffix.c_str(), suffix.size()-1, -1, -1);
            if (s2) {
                for (set<int>::reverse_iterator it=s1->rbegin(); it!=s1->rend(); ++it) {
                    if (s2->find(*it) != s2->end()) return *it;
                }
            }
        }
        return -1;
    }
};