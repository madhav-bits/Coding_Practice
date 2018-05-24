/*
*
//**********************************************************212. Word Search II.***************************************************

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically 
neighboring. The same letter cell may not be used more than once in a word.

Example:

Input: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.

Hint:

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could 
answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a 
basic trie, please work on this problem: Implement Trie (Prefix Tree) first.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
["oath","pea","eat","rain","oat"]


[["a","a"]]
["a"]

[["a","t","b"]]
["ata"]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Trie based. We first create a Trie using the words in the dictionary. In the last node of the Trie containing a word's char
// we store the entire string in var. str, we also make the endNode var for the last node to be True. We start iterating from all indices of 
// array. We move to next index iff there is a node (with adj. index's char)connected to the node representing  curr. index's char. In the iteration
// at any instant if we encounter endNode=True, push the str in that node into final string result vector.

// In this implementation I had used map to store the ptrs to child nodes.






class Solution {
public:
    
    struct TrieNode{
        string str;																// Stores the string from the dict in it's last node in Trie.
        map<char,TrieNode*> m;													// Links parent and child nodes.
        bool endNode;															// Indicates that a word had ended in this node.
        //TreeNode(): m
    };
    
    
    void findStr(TrieNode* root, vector<vector<char>> &v, set<string> &res, vector<vector<int>>&mark, int row, int clmn){
        //cout<<"Inside the fn. with row: "<<row<<" and clmn: "<<clmn<<endl;
        mark[row][clmn]=1;                                                      // Marking as visited.
        if(root->endNode==true){												// If end of word is reached, push it into final result str vector.
            //cout<<"Pushing str into final res: "<<root->str<<endl;
            res.insert(root->str);
        } 
        
        if(row-1>=0 && mark[row-1][clmn]==0 && root->m.count(v[row-1][clmn])==1) findStr(root->m[v[row-1][clmn]], v,res,mark, row-1, clmn);
        
        if(clmn-1>=0 && mark[row][clmn-1]==0 && root->m.count(v[row][clmn-1])==1) findStr(root->m[v[row][clmn-1]], v,res, mark, row, clmn-1);
        
        if(row+1<v.size() && mark[row+1][clmn]==0 && root->m.count(v[row+1][clmn])==1) findStr(root->m[v[row+1][clmn]], v,res, mark, row+1, clmn);
        
        if(clmn+1<v[0].size() && mark[row][clmn+1]==0 && root->m.count(v[row][clmn+1])==1) findStr(root->m[v[row][clmn+1]], v,res, mark, row, clmn+1);
        
        mark[row][clmn]=0;														// Removing the visited mark, making it free for other traversals.
        
    }
    
    vector<string> findWords(vector<vector<char>>& v, vector<string>& words) {
        vector<string> re;
        set<string> res;																// As in output Unique strings are required.
        if(words.size()==0) return re;													// If empty board is given return empty vector.
        TrieNode* root =new TrieNode();													// Creating a root node.
        //cout<<"bool: "<<root->str.length()<<endl;
        vector<vector<int>>mark(v.size(),vector<int>(v[0].size(),0));					// To mark the already visited indices in board.
        for(int i=0;i<words.size();i++){                                                // Building the Trie.
            TrieNode* temp=root;
            for(int j=0;j<words[i].size();j++){
                if(temp->m.count(words[i][j])==0) temp->m[words[i][j]]=new TrieNode();
                temp=temp->m[words[i][j]];
                
                //temp->m[words[i][j]]=new TrieNode();
            }
            temp->str=words[i];                                                          // Storing the word in the last node.
            temp->endNode=true;                                                          // Setting the last node's endNode value to True.

        }
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(root->m.count(v[i][j])==1){											// If the root node contains this char start iteration.
                    //cout<<"Starting loop at row: "<<i<<" and clmn: "<<j<<endl;
                    findStr(root->m[v[i][j]], v, res, mark, i, j);						
                } 
            }
        }
        return vector<string>(res.begin(), res.end());									// Return the unique occurances of words in board.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Trie based. We first create a Trie using the words in the dictionary. In the last node of the Trie containing a word's char
// we store the entire string in var. str, we also make the endNode var for the last node to be True. We start iterating from all indices of 
// array. We move to next index iff there is a node (with adj. index's char)connected to the node representing  curr. index's char. In the iteration
// at any instant if we encounter endNode=True, push the str in that node into final string result vector.

// In this implementation I had used Array to store the ptrs to child nodes, as Sequential chars are used to link Parent and Child Nodes. Moreover
// vector is a simpler data structure, leading to quicker execution of operations.






class Solution {
public:
    
    struct TrieNode{
        string str;
        //map<char,TrieNode*> m;
        vector<TrieNode*> m;
        bool endNode;
        //TreeNode(): m
        TrieNode(){                                                 // Constructor.
            str="";
            m=vector<TrieNode*>(26,NULL);							// As chars are used to link parent and child nodes.
            endNode=false;											// Default value is false.
        }
        
    };
    
    
    void findStr(TrieNode* root, vector<vector<char>> &v, set<string> &res, vector<vector<int>>&mark, int row, int clmn){
        //cout<<"Inside the fn. with row: "<<row<<" and clmn: "<<clmn<<endl;
        mark[row][clmn]=1;                                                      // Marking as visited.
        if(root->endNode==true){
            //cout<<"Pushing str into final res: "<<root->str<<endl;
            res.insert(root->str);
        } 
        
        if(row-1>=0 && mark[row-1][clmn]==0 && root->m[v[row-1][clmn]-'a']!=NULL) findStr(root->m[v[row-1][clmn]-'a'], v,res,mark, row-1, clmn);
        
        if(clmn-1>=0 && mark[row][clmn-1]==0 && root->m[v[row][clmn-1]-'a']!=NULL) findStr(root->m[v[row][clmn-1]-'a'], v,res, mark, row, clmn-1);
        
        if(row+1<v.size() && mark[row+1][clmn]==0 && root->m[v[row+1][clmn]-'a']!=NULL) findStr(root->m[v[row+1][clmn]-'a'], v,res, mark, row+1, clmn);
        
        if(clmn+1<v[0].size() && mark[row][clmn+1]==0 && root->m[v[row][clmn+1]-'a']!=NULL) findStr(root->m[v[row][clmn+1]-'a'], v,res, mark, row, clmn+1);
        
        mark[row][clmn]=0;
        
    }
    
    vector<string> findWords(vector<vector<char>>& v, vector<string>& words) {
        vector<string> re;
        set<string> res;
        if(words.size()==0) return re;
        TrieNode* root =new TrieNode();
        //cout<<"bool: "<<root->str.length()<<endl;
        vector<vector<int>>mark(v.size(),vector<int>(v[0].size(),0));
        for(int i=0;i<words.size();i++){                                                // Building the Trie.
            TrieNode* temp=root;
            for(int j=0;j<words[i].size();j++){
                if(temp->m[words[i][j]-'a']==NULL) temp->m[words[i][j]-'a']=new TrieNode();
                temp=temp->m[words[i][j]-'a'];
                
                //temp->m[words[i][j]]=new TrieNode();
            }
            temp->str=words[i];                                                          // Storing the word in the last node.
            temp->endNode=true;                                                          // Setting the last node's endNode value to True.

        }
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(root->m[v[i][j]-'a']!=NULL){
                    //cout<<"Starting loop at row: "<<i<<" and clmn: "<<j<<endl;
                    findStr(root->m[v[i][j]-'a'], v, res, mark, i, j);
                } 
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};