/*
*
//**********************************************************737. Sentence Similarity II.***************************************************

Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences
 are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are 
pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then 
"great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even 
though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to 
words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,3],[0,0,4],[7,6,5]]

["great","acting","skills"]
["fine","drama","talent"]
[["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]



["great"]
["great"]
[]


["great","acting","skills"]
["fine","drama","talent"]
[["great","fine"],["fine","good"],["fine","acting"],["skills","talent"]]


["great","acting","skills","ab"]
["fine","drama","talent","cd"]
[["great","fine"],["fine","good"],["drama","acting"],["skills","talent"]]




// Time Complexity: O(m*#pairs).  
// Space Complexity: O(m+n+#pairs).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*#pairs).(#pairs^2)
// Space Complexity: O(m+n+#pairs).	
// This algorithm is BFS/DFS based. We form graph using the given members of words and the pairs. At each query, we start doing BFS/DFS query from 
// one word(words1[i]), and check for words2[i] in it's all reachable words.



// I thought mapping can be done from any word in words1 to any word in words2 and a single word can be mapped to multiple words in words2 array.
// My approach is bit different here in this algo.



class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> v) {
        if(words1.size()!=words2.size()) return false;
        unordered_map<string,int>m1,m2;										// Tracks #occurances of words in each vector.
        unordered_map<string,vector<string>>pairs;							// Stores the graph of words.
        for(auto pr: v){													// Create a graph.
            pairs[pr.first].push_back(pr.second);
            pairs[pr.second].push_back(pr.first);
        }
        for(auto str: words1){												// Insert words in vectors in graph.
            m1[str]++;
            pairs[str].push_back(str);
        }
        for(auto str: words2){
            m2[str]++;
            pairs[str].push_back(str);
        }
        for(int i=0;i<words1.size();i++){									// Start BFS from all words/nodes in words1 array.
            set<string>s;
            string s1=words1[i];
            // cout<<"CUrr. str: "<<s1<<endl;
            queue<string>q;
            s.insert(s1);
            q.push(s1);
            string curr;
            while(!q.empty()){												// Do a BFS from curr. word/ node.
                curr=q.front();
                // cout<<"Curr. scanning str: "<<curr<<endl;
                if(m2[curr]>0) break;
                q.pop();
                for(auto pr: pairs[curr]){
                    if(s.count(pr)==0){
                      // cout<<"Pushed str: "<<pr<<endl;
                        s.insert(pr);
                        q.push(pr);
                    }
                }
            }
            if(q.empty()) return false;										// If any word from words2 not found, return false.
            // cout<<"The strings s1: "<<s1<<" and "<<curr<<" matched."<<endl;
            m2[curr]--;
            m1[s1]--;
        }
        //for(auto str: words2){												// If any word in words2 not reached, then return false.
        //    if(m2[str]!=0) return false;
        //}
        return true;														// If all mappings occur properly, then return true.
    }
};















//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*#pairs).
// Space Complexity: O(m+n+#pairs).	
// This algorithm is Union-Find based. Here, we do Union of all nodes that can be reached from each other. We iterate through all pairs and 
// form pairs using them. IF the core parent of one elem. in pair doesn't match other's core parent, then we set the parent of second elem's
// coreparent to be coreparent of first elem. This way, we form all unions. Now, we iterate through all words in words1, check if their 
// coreparents match, if not return false. If those words aren't found in Union map(parent), then also return false.







class Solution {
public:
    
    string findParent(unordered_map<string,string>&parent,string src){		// Finds the coreparent of a node.
        while(parent[src]!=src)												// Finds the parent of curr. node.
            src=parent[src];
        return src;
    }
    
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size()) return false;						// If words arrays size is not equal, then return false.
        unordered_map<string,string>parent;									// Union Map(stores node to coreparent rln).
        
        for(auto p: pairs){													// Iterates through all pairs, form unions.
            if(parent.count(p.first)==0)									// If node not in map, make itself it's coreparent.
                parent[p.first]=p.first;
            if(parent.count(p.second)==0)
                parent[p.second]=p.second;
            // cout<<"parent has: "<<p.first<<" and p.second: "<<p.second<<endl;
            parent[findParent(parent,p.second)]=findParent(parent,p.first);// Setting first elem's coreparent to be coreparent of second elem.
        }
        
        
        for(int i=0;i<words1.size();i++){									// Iterating through all words words1 array.
            // cout<<"Curr. word: "<<words1[i]<<" and: "<<words2[i]<<endl;
            if(words1[i]==words2[i]) continue;								// If two words match, escape doing coreparent search.
            if( parent.count(words1[i])==0 || parent.count(words2[i])==0 || (findParent(parent,words1[i])!=findParent(parent,words2[i]))) return false;
        }																	// If any/both elem. not found in Union Map/coreparents not equal.
        return true;														// If all mappings happen properly, reutrn false.
    }
};