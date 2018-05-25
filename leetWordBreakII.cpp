/*
*
//**********************************************************140. Word Break II.***************************************************

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where 
each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"catsanddog"
["cat","cats","and","sand","dog"]



"pineapplepenapple"
["apple", "pen", "applepen", "pine", "pineapple"]




"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
// This algorithm is Trie based solution. We form a Trie using the words in the dictionary. Now, we iterate over the given string, once we 
// encounter a end of word in dict, we start from the root of the Trie in search of next word. We also MEMOIZATION here, to aovid repetitive calls
// as we need to extract all possible combinations of words, the given word can be split into. 







class Solution {
public:
    
    struct TrieNode{																	// Declaring the Trie Structure.
        string str;
        vector<TrieNode*> m;
        //TrieNode* m[26];
        bool endNode;
        
        TrieNode(){                                     								// Constructor.
            str="";
            m=vector<TrieNode*>(26,NULL);
            endNode=false;
        }
        
    };
    
    
    vector<string> extractStr(string s, TrieNode* node, unordered_map<string, vector<string>> & n){
        //cout<<"INside the fn. with string: "<<s<<" with length: "<<s.length()<<" node val: "<<node->str<<endl;
        if(n.count(s)==1) return n[s];											// If curr. substr is already encountered and extr. return them.
        
        if(s.length()==0){														// If end of str.is reached, return empty string.
            vector<string> a(1,"");
            n[s]=a;																// Update the map.
            return a;															// Return the empty string.
        }
        
        
        TrieNode* tempNode=node;
        
        for(int i=0;i<=s.length();i++){											// Iterating the curr. string.	
            //cout<<"curr. index is: "<<i<<" with char: "<<s[i]<<" and tempNode val is: "<<tempNode->endNode<<"val: "<<tempNode->str<<endl;
            if(tempNode->endNode==true){										// When one compl. word is found, we start from root.
                //cout<<"Calling the next fn. at index: "<<i<<" with string: "<<s<<endl;
                vector<string> ans=extractStr(s.substr(i),node, n);				// Pass only substring to extract words out of it.
                for(auto stri:ans){
                    if(stri=="") n[s].push_back(s.substr(0,i));					// If we get empty list of str(Occurs at end of iter. of entire. str)
                    else    n[s].push_back(s.substr(0,i)+" "+stri);         	// We append the curr. str's substr till now to the list of str. obt
                }
            }
            if(tempNode->m[s[i]-'a']==NULL) break;						// If curr. char not found in Trie, then return list of str. extr. till now.
            tempNode=tempNode->m[s[i]-'a'];										// Moving to child node for next iter.
        }
        return n[s];															// Returning all possible. combi. of words extracted.
    }
    
    
    TrieNode* root= new TrieNode();
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> res;
        if(s.length()==0 || dict.size() ==0) return res;
        for(int i=0;i<dict.size();i++){                                         //Creating a Trie using words from the dict.
            TrieNode* temp=root;
            for(int j=0;j<dict[i].size();j++){
                if(temp->m[dict[i][j]-'a']==NULL) temp->m[dict[i][j]-'a']= new TrieNode();
                temp=temp->m[dict[i][j]-'a'];
            }
            temp->endNode=true;													// Indicates end of word in dict.
            temp->str=dict[i];													// Storing the word from dict. in that node.
        }
        
        unordered_map<string, vector<string>> n;								// Map to store all possible combi. of words extracted from a str
        return extractStr(s,root, n);											// Calling the fn. to extract all words.
        return res;																// Returning all combi. of words making given string.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Trie based solution. We form a Trie using the words in the dictionary. Now, we iterate over the given string, once we 
// encounter a end of word in dict, we start from the root of the Trie in search of next word. This algo. doesn't use Memoization, so it gives TLE
// excpetion for few cases.

// This algo. is almsot same as above algo.





class Solution {
public:
    
    struct TrieNode{																// Trie Structure.
        string str;
        vector<TrieNode*> m;
        //TrieNode* m[26];
        bool endNode;
        
        
        TrieNode(){                                     							// Constructor.
            str="";
            m=vector<TrieNode*>(26,NULL);
            endNode=false;
        }
        
    };
    
    
    void extractStr(string s, TrieNode* node, vector<string>&res, string &temp, int index){
        //cout<<"INside the fn. with index: "<<index<<endl;
        if(index==s.length()){
            if(node->endNode==true){
                res.push_back(temp+node->str);
                //cout<<"Pushing temp into final res: "<<temp+node->str<<endl;
            } 
            return ;
        }
        
        string temp2=temp;
        if(node->endNode==true){
            temp+=node->str+" ";
            //node->endNode=false;
            //cout<<"Adding str to temp: "<<node->str<<endl;
            if(root->m[s[index]-'a']!=NULL){
                //cout<<"Fresh traversal with char: "<<s[index]<<endl;
                extractStr(s,root, res, temp, index);    
            }     
        } 
        temp=temp2;
        if(node->m[s[index]-'a']!=NULL) extractStr(s,node->m[s[index]-'a'], res, temp, index+1);
        
        
    }
    
    TrieNode* root= new TrieNode();
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> res;
        if(s.length()==0 || dict.size() ==0) return res;
        for(int i=0;i<dict.size();i++){                                         //Creating a Trie using words from the dict.
            TrieNode* temp=root;
            for(int j=0;j<dict[i].size();j++){
                if(temp->m[dict[i][j]-'a']==NULL) temp->m[dict[i][j]-'a']= new TrieNode();
                temp=temp->m[dict[i][j]-'a'];
            }
            temp->endNode=true;													// Indicates end of word in dict.
            temp->str=dict[i];													// Storing the word from dict. in that node.
        }
        
        string temp="";
        extractStr(s,root, res, temp, 0);
        return res;
    }
};





//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Map based solution. We form a Map/Dict using the words in the dictionary. Now, we iterate over the given string, once we 
// encounter a end of word in dict, we start searching for next word in the next fn. call. We also MEMOIZATION here, to aovid repetitive calls
// as we need to extract all possible combinations of words, the given word can be split into. 




class Solution {
public:
    
    vector<string> extractStr(string s, unordered_map<string, int> &dict, unordered_map<string, vector<string>> &visited){
        if(visited.count(s)==1) return visited[s];
        if(s.length()==0){														// When end of string is reach, return empty string.
            visited[s].push_back("");											// Store empty string in map.
            return visited[s];
        }
        //vector<string>res;
        for(int len=1;len<=s.length();len++){
            string temp=s.substr(0,len);
            if(dict.count(temp)==1){											// If the substr. is found in dict. start looking for other word.
                vector<string> ans;
                ans=extractStr(s.substr(len),dict, visited);					// Extract all possible. combi. of words next substr. split into.
                for(auto str: ans){												// Forming a split sente. using combi. of words from next substr
                    if(str=="") visited[s].push_back(temp);						// Handling to avoid " " in case of last empty substr/spilt word.
                    else visited[s].push_back(temp+" "+str);
                }
            }
        }
        
        return visited[s];												// Return all possible combi. of words can be this substr. can be split into.
    }
    
    vector<string> wordBreak(string s, vector<string>& e) {
        vector<string> res;
        unordered_map<string, int>dict;
        for(auto str:e) dict[str]=1;                                        	// Storing the dict words in a dictionary.
        unordered_map<string, vector<string>> visited;							// Stores already extracted list of words for a substring.
        return extractStr(s,dict,visited);										// Returning all possible combi. of words making the given word.
    }
};






