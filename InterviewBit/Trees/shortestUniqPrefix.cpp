/*
*
//**********************************************************Shortest Unique Prefix.***************************************************


https://www.interviewbit.com/problems/shortest-unique-prefix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



6 abc abcd bean zx zyx zxy



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is Trie based. Here, we construct a Trie based on the vector of strings provided, at each node in Trie we inc. the close var 
// in Trie node by one, that is #words having same prefix, once Trie is cretaed. We iterate over all words and iterate Trie in the process. We stop
// at node, where the close var is 1(The curr string has that Unique prefix). We store the substring till then for each string provided and 
// return them.








// struct Trie{																// This is Constructor I wrote.
//     char ch;																// Works fine for Custom Test Cases.
//     vector<Trie*>child;													// But, fails when submitted.
//     int close;
//     Trie(char c) : ch(c), close(0) {};
//     Trie(): ch('1') {};
// };


struct Trie{																// This constructor is suggested in the discussion forum.
    char ch;
    struct Trie* child[26];
    int close;
Trie(){
    char ch='1';
    for(int i=0;i<26;i++)
        child[i]=NULL;
    close=0;
}

};


void buildTrie(Trie*root, vector<string>&v){								// Builds Trie based on the words provided.
    Trie*temp=root;															// Temp. storing root of the Trie.
    for(int i=0;i<v.size();i++){											// Iter. over all words provided.
        temp=root;
        for(int j=0;j<v[i].length();j++){									// Iter. over Trie for each char of curr. string.
            char curr=v[i][j];
            if(temp->child[curr-'a']==NULL){								// If next Trie isn't defined, create one.
                temp->child[curr-'a']=new Trie();
                // temp->child[curr-'a']->child=vector<Trie*>(26,NULL);
            }
            temp=temp->child[curr-'a'];										// Moving  to next(child node) in Trie.
            temp->close++;													// Inc. the count(#words having this prefix).
        }
        
    }    
}

vector<string> Solution::prefix(vector<string> &v) {
    vector<string>res;														// Final result vector.
    Trie* root= new Trie();													// The root of the Trie.
    // root->child=vector<Trie*>(26,NULL);
    buildTrie(root,v);														// Builds Trie with strings provided.
    Trie* temp=root;
    for(int i=0;i<v.size();i++){											// ITer. over all words.
        temp=root;					
        int j=0;
        while(temp->close!=1){												// Iter. over curr. string/Trie until node with 1(Close count) is found.
            temp=temp->child[v[i][j]-'a'];									// Moving the temp's child.
            j++;
        }
        res.push_back(v[i].substr(0,j));									// Pushing Unique prefix to final result vector.
        
    }
    
    return res;																// Returning the final result vector with Shortest Uniq. Prefixes.
}
