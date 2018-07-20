/*
*
//******************************************************642. Design Search Autocomplete System.***********************************************

Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For 
each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence 
already typed. Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of 
hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:

The constructor function:

AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists 
of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next character the user types:

List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), 
blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the 
top 3 historical hot sentences that have prefix the same as the part of sentence already typed.


Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2]) 
The system have already tracked down the following sentences and their corresponding times: 
"i love you" : 5 times 
"island" : 3 times 
"ironman" : 2 times 
"i love leetcode" : 2 times 
Now, the user begins another search: 

Operation: input('i') 
Output: ["i love you", "island","i love leetcode"] 
Explanation: 
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 
and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" 
will be ignored. 

Operation: input(' ') 
Output: ["i love you","i love leetcode"] 
Explanation: 
There are only two sentences that have prefix "i ". 

Operation: input('a') 
Output: [] 
Explanation: 
There are no sentences that have prefix "i a". 

Operation: input('#') 
Output: [] 
Explanation: 
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as 
a new search. 

Note:
The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't 
exceed 100.
Please use double-quote instead of single-quote when you write test cases even for a character input.
Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test 
cases. Please see here for more details.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["AutocompleteSystem","input","input","input","input"]
[[["i love you","island","ironman","i love leetcode"],[5,3,2,2]],["i"],[" "],["a"],["#"]]



["AutocompleteSystem","input","input","input","input","input"]
[[["abc","ade","bcd","bcf"],[5,5,4,3]],["a"],["d"],["e"],["#"],["a"]]



["AutocompleteSystem","input","input","input","input","input","input"]
[[["a b c","a d e","bc d","a b f","bc e"],[5,4,4,4,3]],["a"],[" "],["d"],[" "],["#"],["a"]]



["AutocompleteSystem","input","input","input","input","input","input"]
[[["bniyggdcloefwy","ouedhtkpkg","otjvvkegwleyyxtghwgfmlsqlhrlibdvqfinyyebotjpwoaejhtornfgikmifdmwswbqgwhcbzuhrpajxuqicegcptszct","a b f","bc e"],[15,24,40,4,3]],["w"],[" "],["d"],[" "],["#"],["a"]]








// Time Complexity: O(n).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n^2).	
// This algorithm is Binary Trie based. Here, we at each step, check for next node avaialble for curr. char or not. If not, we create a new node
// in it, we store the string that this char belongs to. Also, the #times that str had occured till now. We write a custom sort based on string
// length,if lengths are equal, we sort strings based on ASCII chars values to extract top 3 hottest strings. At the end, of iteration, we 
// reinsert the string into the map and inc. the count of str, if it has already occured in the past.








class AutocompleteSystem {
public:
    
    
    struct compare{															// Custom sort, useful in extracting hot strings.
      bool operator()(const pair<string,int>&lt, const pair<string,int>&rt){
        return (lt.second<rt.second)||((lt.second==rt.second)&& (lt.first>rt.first));
      }
    };
    
    struct Trie{
        unordered_map<char,Trie*> m;										// LInks to child tries.
        unordered_map<string,int>strs;										// Stores strs with curr. substr and the string's count.
        Trie(): m(), strs() {}
    };
    

    void extractStrs(Trie* node,vector<string>&res){
        // cout<<"Inside the extractStr "<<endl;
        if(node==NULL) return ;												// If the root is NULL, return empty vector.
        
        priority_queue<pair<string,int>, vector<pair<string,int>>,compare> pq;// Push elem. into Priority queue.
        for(auto it=node->strs.begin();it!=node->strs.end();it++){			// We push str, #occurances of the string.
            // cout<<"Pushing str: "<<it->first<<endl;
            pq.push({it->first,it->second});
            // pq.push(make_pair(it->first,it->second));
        }
        int count=0;
        while(!pq.empty() && count<3){										// Extract top 3 hottest strings.
            res.push_back(pq.top().first);
            pq.pop();
            count++;
        }
        
    }
    
    void insertWord(string &s,int count, Trie* node){
        for(int i=0;i<s.length();i++){
            // cout<<"Curr. char: "<<s[i]<<endl;
            if(node->m[s[i]]==NULL){										// If child doesn't exist for this char, create one.
                // cout<<"Created node."<<endl;
                node->m[s[i]]=new Trie();
            }
            // insert(node,s, node->strs[s]);
            node=node->m[s[i]];												// Move to child node.
            node->strs[s]+=count;											// Store string, #occurances in child node.
        }    
    }
    
    Trie* root= new Trie();													// Our base Trie.
    Trie* currNode=root;
    string curr="";															// Tracks str/perfix obtained till now.
    AutocompleteSystem(vector<string> v, vector<int> times) {
        for(int i=0;i<v.size();i++){
            // cout<<"Inserting word: "<<v[i]<<endl;
            insertWord(v[i],times[i],root);									// insert all given words into Trie.
            // cout<<"Done Inserting word: "<<v[i]<<endl;
        }
    }
    
    vector<string> input(char c) {
        vector<string>res;
        // cout<<"Curr. char: "<<c<<endl;
        
        if(c=='#'){															// If end of string is reached.
            if(curr.length()!=0)											// If the string has some length.
                insertWord(curr,1,root);									// Insert it into Trie.
            curr="";														// Set to base values.
            currNode=root;
            return res;
        }
        curr+=c;
        if(currNode==NULL) return res;								// If currNode=NULL, return empty vector.(If we search word with all new chars).
        // cout<<"Calling. extractStr fn."<<endl;
        currNode=currNode->m[c];											// Go to child Trie.
        // cout<<"The num. of node: "<<currNode->num<<endl;
        extractStrs(currNode,res);											// Extract top 3 hottest strings.
        // for(auto str: res)
        //     cout<<"Str: "<<str<<endl;
        return res;															// Return the hottest strings.
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
 
 
 
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n^2).	
// This algorithm is Binary Trie based. Here, we at each step, check for next node avaialble for curr. char or not. If not, we create a new node
// in it, we store the string that this char belongs to. Also, the #times that str had occured till now. We write a custom sort based on string
// length,if lengths are equal, we sort strings based on ASCII chars values to extract top 3 hottest strings. At the end, of iteration, we 
// reinsert the string into the map and inc. the count of str, if it has already occured in the past.
 
 
 
// This algo. is same as above one. Except that I had optimized it space comp. wise. Instead of storing a strings in all possible prefixes of it.
// I had stored and referring num. in all prefix's nodes pointing to the string in other vector.As, it doesn't deal with too much of memory, it 
// has improved the speed significantly.
 
 
 
 
 
 
 
class AutocompleteSystem {
public:
    
    
    struct Trie{															// Trie with link to Child Tries, rep nums to trace back to str,#occur.
        unordered_map<char,Trie*> m;
        vector<int>rep;
        Trie(): m(),rep() {}
    };
    

    void extractStrs(Trie* node,vector<string>&res){						// Extract the hottest strings.
        // cout<<"Inside the extractStr "<<endl;
        if(node==NULL) return ;
        
        auto cmp=[=](int a,int b){											// Custom comparator fn.
            return (lengths[a]<lengths[b])||((lengths[a]==lengths[b]) && (words[a]>words[b]));
        };
        
        priority_queue<int, vector<int>,decltype(cmp)> pq(cmp);				// Decl. Priority Queue.
        for(auto it=node->rep.begin();it!=node->rep.end();it++){			// Push all referring indices into PQ.
            // cout<<"Pushing str: "<<it->first<<endl;
            pq.push(*it);
            // pq.push(make_pair(it->first,it->second));
        }
        int count=0;
        while(!pq.empty() && count<3){										// Extract top 3 hottest strings.
            res.push_back(words[pq.top()]);
            pq.pop();
            count++;
        }
        
    }
    
    void insertWord(string &s,int ids, Trie* node){
        for(int i=0;i<s.length();i++){										// Iterarting through all words given.
            // cout<<"Curr. char: "<<s[i]<<endl;
            if(node->m[s[i]]==NULL){
                // cout<<"Created node."<<endl;
                node->m[s[i]]=new Trie();
            }
            node=node->m[s[i]];												// Move to child Trie.
            node->rep.push_back(ids);										// Storing rep. num in Trie.
        }    
    }
    
    Trie* root= new Trie();
    Trie* currNode=root;
    string curr="";
    vector<int>lengths;														// Stores all string's #occurances.
    vector<string> words;													// Stores all strings.
    unordered_map<string,int>reln;											// Tracks reln. b/w referring num. and strings.
    int ids=0;																// Tracks num. of unique strs till now.
    AutocompleteSystem(vector<string> v, vector<int> times) {
        lengths=times;														// Copying the vector values.
        words=v;
        ids=0;
        for(int i=0;i<v.size();i++){										// Pushing all nodes into Trie.
            // cout<<"Inserting word: "<<v[i]<<endl;
            reln[v[i]]=ids;													// Store the reln. b/w ref. num, and string.
            insertWord(v[i],ids++,root);									
            // cout<<"Done Inserting word: "<<v[i]<<endl;
        }
    }
    
    vector<string> input(char c) {
        vector<string>res;
        // cout<<"Curr. char: "<<c<<endl;
        
        if(c=='#'){
            if(curr.length()!=0){											// If non-empty new string obtained.
                if(reln.count(curr)==0){									
                    words.push_back(curr);									// We store the new string in vector.
                    lengths.push_back(1);									// We store the #occurranes in vector.
                    reln[curr]=ids;											// Store reln. b/w string and #occurranes.
                    insertWord(curr,ids++,root);							// inserting string into Trie.
                }
                else lengths[reln[curr]]++;									// If word already occured, then just inc. the count in length vector.
            }
            curr="";														// Setting to base values.
            currNode=root;
            return res;
        }
        curr+=c;
        if(currNode==NULL) return res;										// If currNode is NULL, return empty vector.
        // cout<<"Calling. extractStr fn."<<endl;
        currNode=currNode->m[c];											// Move to child Trie.
        // cout<<"The num. of node: "<<currNode->num<<endl;
        extractStrs(currNode,res);											// Call. fn. to extract hottest Strings.
        // for(auto str: res)
        //     cout<<"Str: "<<str<<endl;
        return res;															// Return top 3 Hottest Strings.
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */