/*
*
//***************************************************************Word Break II.********************************************************

https://www.interviewbit.com/problems/word-break-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


catsanddog
3 cat cats and dog


catsanddog
5 cat cats and sand dog



aabbbabaaabbbabaabaab
9 bababbbb bbbabaa abbb a aabbaab b babaabbbb aa bb



// Time Complexity: O(n!).  												// Not sure about Time Complexity.
// Space Complexity: O(n*n!).												// Not sure about Space Complexity.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).													// Not sure about Time Complexity.
// Space Complexity: O(n*n!).												// Not sure about Space Complexity.
// This algorithm is Backtracking/ Trie/ Dynamic Programming based. Here, we first we build Trie based on words in dictionary. Next, we iterate
// over give string and Trie parallely and form the word until end of word or  no such word exists in dictionary. Once, a word is found, append
// " " to the temp. string and forward it to recursive call in search of other words following curr. word. Once, we are back from the recursive 
// call, we continue forming bigger words in curr. recursive call and give recursive calls accordingly. In the recursive calls, if we reach 
// end of given string, we push the seq. of words we formed till now to result vector. After, entire iteration, we return the result vector.







struct Trie{                                                                // Data Type to form Trie.
    char ch;
    unordered_map<char, Trie*>children;                                     // Map to store pointers to child Trie.
    bool finish;
    Trie(char c){
        ch=c;
        finish=false;
    }
};
 
 
void insertTrie(string s, Trie* root){                                        // Inserting words into Trie.
    for(int i=0;i<s.length();i++){                                            // Iterating over curr. string.
        if(root->children.count(s[i])==0){                                    // If pointer for curr. char not found in child map, create one.
            root->children[s[i]]=new Trie(s[i]);
        }
        root=root->children[s[i]];                                            // Move the pointer to child Trie.
    }
    root->finish=true;                                                        // Mark the last Trie with end of word indication.
}
 
void formStrings(int index, string&s, string&temp, Trie*root,vector<string>&res){// Call to form curr. word in sequence.
    // cout<<"index: "<<index<<" and temp: "<<temp<<endl;
    if(index>s.length()) return ;
    Trie*node=root;															// Temp. storing root of Trie.
    string init=temp;														// Temp. storing sequence of words formed till now.
    for(int i=index;i<s.length();i++){										// Iter. over remaining string.
        if(node->children.count(s[i])==0) break;							// If no such word found, break from loop.
        temp+=s[i];															// Cont. forming curr. word and add it to seq. of words formed till now.
        node=node->children[s[i]];											// Moving to Child Trie.
        if(node->finish==true && i==s.length()-1) res.push_back(temp);		// If we reached end of given str. and end of word then push into res.
        if(node->finish==true){												// If end of word is reached, give recursive call to find next words.
            temp+=" ";														// Add space after. curr. formed word before appending next word.
            formStrings(i+1, s, temp, root, res);							// Call. to find next words.
            temp.pop_back();												// Remove space bar from seq. of words string to accom. bigger curr. word.
        } 
    }
    temp=init;																// Reverting to seq. of words at the beginning of this call.
}
 
vector<string> Solution::wordBreak(string s, vector<string> &v) {
    Trie* root= new Trie('s');
    for(auto str: v) insertTrie(str, root);									// Build Trie from words in dictionary.
    vector<string>res;														// Final result vector.
    string temp="";															// Keeps track of words accumulated in every instant.
    formStrings(0, s, temp, root, res);										// Call fn. to accumulate words.
    return res;																// Returning the final result vector.
}

