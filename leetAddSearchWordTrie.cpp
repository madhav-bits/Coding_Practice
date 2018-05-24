/*
*
//**************************************************211. Add and Search Word - Data structure design.*******************************************

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bads"],["dad"],["mad"],["pad"],["bad."],[".ad"],["..."]]



// Time Complexity: O(26^n).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(26^n).
// Space Complexity: O(n).	
// This algorithm is Trie based. First we construct a Trie using the given words. In the node containing the last word of str, we make it's
// endNode var to be true. While searching whenever we encounter '.', we iterate through all the ptrs in that node to it's children and iterate
// through each of them. The instant we get true as reply, we return true from that call. If we encounter char, which is in that node, we go to
// that child and traverse through it's children, if we encounter char, which is not in curr. node, then return false.





class WordDictionary {
public:
    /** Initialize your data structure here. */
	
    struct TrieNode{																// Declaring a Data Structure.
        vector<TrieNode*> m;
        bool endNode;
        
        
        TrieNode(){                                                 				// Constructor for the Data structure.
            m=vector<TrieNode*>(26,NULL);
            endNode=false;
        }
        
    };
    
    TrieNode* root;																	// Declaring a global variable.
    WordDictionary() {
        root= new TrieNode();														// Init. the global variable.
    }
    
    
    bool findWord(TrieNode* root, string &word, int index){							// We need exact word matching.
        if(index==word.length()){													// If entire length of str is traversed.
            if(root->endNode==true) return true;									// If that node has endNode=true indicating one of saved words.
            else return false;														// If there is no word ending at that node.
        }  
        
        if(word[index]=='.'){														// If we encounter '.', we iter. all child and traverse them.
            for(int i=0;i<26;i++)
                if(root->m[i]!=NULL){												// We iter. through all valid child.
                  if(findWord(root->m[i], word, index+1)) return true;  
                } 
        }
        else if(root->m[word[index]-'a']!=NULL) return findWord(root->m[word[index]-'a'], word, index+1); // If node has curr. index's char.
        return false;															// If node doesn't curr. index's char./ no word found in '.' iter
    }
    
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){											//Trav. entire length of word and creating nodes accor.
            if(temp->m[word[i]-'a']==NULL) temp->m[word[i]-'a']= new TrieNode();	// If child doesn't exist with that char. create child.
            temp=temp->m[word[i]-'a'];												// Travel to child.
        }
        temp->endNode=true;															// Marking last node with "True", indicating end of Word.
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word[0]=='.' || root->m[word[0]-'a']!=NULL)								// If root contains first char in word, then call fn.
            return findWord(root, word, 0);											// Calling the findWord. fn. to search for word in Trie.
        else return false;															// If first char is not present in root, return false.
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */