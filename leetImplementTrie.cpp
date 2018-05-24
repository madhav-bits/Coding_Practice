/*
*
//******************************************************208. Implement Trie (Prefix Tree).***********************************************

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Trie","insert","startsWith"]
[[],["abc"],["a"]]


["Trie","insert","startsWith","search"]
[[],["abcd"],["b"],["abcd"]]


["Trie","insert","insert","startsWith","search","search"]
[[],["abcd"],["abcdef"],["abc"],["abcd"],["abcdef"]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Trie Based. We create a new Data Structure named Trie with vector with 26 size and bool indicating whether the curr. node is 
// end of any of the inserted words or not. While inserting we start from the root node, if the char we are looking for is not present in the
// curr. node we initialize a TrieNode and store it's ptr in the curr. node, this way we iterate the entire inserting string.

// While searching for entire word, we start travelling from the root to the child, if that char is present in the curr. node. If we iterated
// the entire string completely without any issues and the last TrieNode we are in is the end of a inserted word(endNode==true), we return true
// else return false.  While searching for prefix, if we the length of the string without any issues, we return true.







class TrieNode{																		// Creating a New Trie Data Structure.
    
public:
    
    vector<TrieNode*> v;
    bool endNode;
    
    TrieNode(){																		// Var Init. with size using () can't be done outside fn.
        v=vector<TrieNode*>(26,NULL);												// Initializing vector of size 26, here in constructor.
																					// Array can be initialized at same time outside fn.
        endNode=false;																// Initializing var. to false.
    }
};



class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;																	// Declaring a global Trie root node.
    Trie() {
        root=new TrieNode();														// Initializing root node.
    }
    
    /** Inserts a word into the trie. */
    void insert(string words) {
        TrieNode* temp=root;
        for(int i=0;i<words.length();i++){											// Iterating the length of the string.
            if(temp->v[words[i]-'a']==NULL){										// If char not present in curr. node, create a Node and store
                temp->v[words[i]-'a']=new TrieNode();								// ptr in curr. node.
            } 
            temp=temp->v[words[i]-'a'];												// Travel to the child node.
        }
        temp->endNode=true;															// Mark the last node as True, indicating end of string.
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode*temp=root;
        for(int i=0;i<word.size();i++){												// Iterating the length of the string.
            if(temp->v[word[i]-'a']==NULL) return false;							// If char not present in curr. node, return false.
            temp=temp->v[word[i]-'a'];												// Travelling to child node.
        }
        return temp->endNode;														// If the last node has endNode=true, ret true else ret false.
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode*temp=root;
        for(int i=0;i<prefix.length();i++){											// Iterating the length of the string.
            //cout<<"Curr. char is: "<<prefix[i]<<endl;
            if(temp->v[prefix[i]-'a']==NULL) return false;							// If char not present in curr. node, return false.
                temp=temp->v[prefix[i]-'a'];										// Travelling to chlid node.
        }
        return true;																// If total length of prefix travelled return true.
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */