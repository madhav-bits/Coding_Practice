/*
*
//**********************************************************269. Alien Dictionary.***************************************************

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of 
non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters 
in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["zy","zx"]

["ab","adc"]


["wrt","wrf","er","ett","rftt"]




// Time Complexity: O(Vertices^2*Edges).									// Not to sure, about this.
// Space Complexity: O(Edges).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Vertices^2*Edges). Can be improved to O(V+E).
// Space Complexity: O(Edges).	
// This algorithm is Topological Sort+BFS based. In the first iteration, we form a graph using HashMap and set, which has a Char as it's key,
// and all the chars prior to that char in values. We can know precednce by comparing two adj. strs, the ptr. of their difference is where we 
// can get the precedence. In the second iteration, I extract all chars with zero, preceeding chars to be extracted and push them into queue.
// Then we do a BFS by extracting chars with zero prece. elem. to be extracted, append it to final str and  remove it from the preceeding 
// list of chars if any. If those chars have become zero preceding chars, then push them into queue. After the whole iteration, if there are still
// chars, then those chars are in a cycle. So, we can't form a sequence of chars, so return "".


// This algo. can be optimized execution wise, by taking another vector to store inDegrees of chars, making it O(V+E).





class Solution {
public:
    string alienOrder(vector<string>& v) {
        string res;
        if(v.size()==0) return res;
        unordered_map<char,unordered_set<char>>m;          					// Values are chars prior to key->char.
        for(int i=0;i<v.size();i++){
            int j=0,k=0;
            if(i>0){
                while(j<v[i-1].length() && k<v[i].length()){
                    if(v[i-1][j]!=v[i][k]) break;
                    j++;k++;
                }
                if(j<v[i-1].length() && k<v[i].length()){					// If diff. char found, then push preceeding char into set.
                    if(m[v[i-1][j]].count(v[i][k])==1) return "";			// If dup. edge found, return "".
                    // cout<<"Into set of: "<<v[i][k]<<"pushing: "<<v[i-1][j]<<endl;
                    m[v[i][k]].insert(v[i-1][j]);							
                }
            }
            for(int j=0;j<v[i].size();j++){									// Forming empty preceeding chars sets to chars in curr. str.
                m[v[i][j]];
            }
                
        }
        
        queue<char>q;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second.size()==0){										// Extracting chars. with zero preceding chars.
                // cout<<"Pushing char: "<<it->first<<endl;
                q.push(it->first);
            } 
        }
        
        while(!q.empty()){
            char curr=q.front();											// Extracting chars with zero preceding chars.
            // cout<<"Curr.char: "<<curr<<endl;
            m.erase(curr);
            res+=curr;														// Adding it to result str.
            q.pop();
            for(auto it=m.begin();it!=m.end();it++){						// Iterate all nodes, remove from set of chars if present.
                if(it->second.count(curr)==1){
                    it->second.erase(curr);
                    if(it->second.size()==0) q.push(it->first);				// If, set length =0, then push that char into queue.
                }
            }
            
        }
        for(auto it=m.begin();it!=m.end();it++){							// If still there are chars with set size>1, then they form a cycle.
            if(it->second.size()>0) return "";								// As sequence of chars can't be formed, return "".
        }
        return res;															// Return the sequence of chars formed.
    }
};