/*
*
//******************************************************************Word Break.***********************************************************

https://www.interviewbit.com/problems/word-break/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


myinterviewtrainer
7 myinter  my intervie inter  erview w trainer

""
7 myinter  my intervie inter  erview w trainer


b
1 bbbb



// Time Complexity: O(n^2).  
// Space Complexity: O(n*l).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n*^2).
// Space Complexity: O(n*l).	
// This algorithm is BFS/Dynamic Programming/Trie based. Here, we first form a Trie of all the nums from the dictionary. Next, we iterate over the 
// given target string, parallely iterater over Trie, as long as we find char in the Trie, target string is not over. During iteration, if 
// we find end of word mark in Trie, we push those indices into Queue(Starting from there we start iteration once again in search of other words
// to fill up the remaining chars from target string). We do process until we reach end of target string and end of word at the same time/Queue is 
// empty, if we find end of target string and end of word at the same time, then we return true else return false.







struct Trie{																// Data Type to form Trie.
    char ch;
    unordered_map<char, Trie*>children;										// Map to store pointers to child Trie.
    bool finish;
    Trie(char c){
        ch=c;
        finish=false;
    }
};


void insertTrie(string s, Trie* root){										// Inserting words into Trie.
    for(int i=0;i<s.length();i++){											// Iterating over curr. string.
        if(root->children.count(s[i])==0){									// If pointer for curr. char not found in child map, create one.
            root->children[s[i]]=new Trie(s[i]);
        }
        root=root->children[s[i]];											// Move the pointer to child Trie.
    }
    root->finish=true;														// Mark the last Trie with end of word indication.
}

int Solution::wordBreak(string s, vector<string> &v) {
    Trie* root= new Trie('s');												// Form a Root ptr to the Trie.
    for(auto str: v) insertTrie(str, root);									// Insert all given words into the Trie.
    queue<int>q;															// Stores indices from where, we should start our iter. for new words.
    q.push(0);																// Starting iter. from 0.
    Trie* node=root;														// Temp. storing ptr to Trie.
    unordered_set<int>st;													// Tracks, so that duplicate indices aren't placed.
    st.insert(0);
    while(!q.empty()){														// Until all indices are searched for.
        int curr=q.front();													
        q.pop();																
        node=root;															// Start iteration from root of Trie.
        for(int i=curr;i<s.length();i++){									// Start matching chars till end of target string.
            if(node->children.count(s[i])==0) break;						// If curr. char is not found in Trie, break.
            else{
                if( node->children[s[i]]->finish==true && i==s.length()-1) return true;// If entire string is matched with words from dict. 
                if(node->children[s[i]]->finish==true && st.count(i+1)==0){	// If entire word is matched in dict. insert next index into Queue.
                    q.push(i+1);											// Push next index to Queue.
                    st.insert(i+1);											// Mark next index as already pushed into Queue.
                } 
                node=node->children[s[i]];									// Move to child Trie.
            }
        }
    }
    return false;															// If end of target string isn't reached, return false.
}
