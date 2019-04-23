/*
*
//******************************************************839. Similar String Groups.***********************************************

Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to 
"tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the 
same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at 
least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

Example 1:

Input: ["tars","rats","arts","star"]
Output: 2
Note:

A.length <= 2000
A[i].length <= 1000
A.length * A[i].length <= 20000
All words in A consist of lowercase letters only.
All words in A have the same length and are anagrams of each other.
The judging time limit has been increased for this question.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["tars","rats","arts","star"]

["omv","ovm"]






// Time Complexity: O((n^2)*log(n^2)).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((m^2)*n)*log((m^2)*n)).								// m- leng. of string.
// Space Complexity: O(n).	
// This algorithm is Union-Find based. Here, for each string, we formed m^2 similar strings it can have, and checked if modified string exists
// in given list of strings or not? If exists, we join groups of modified string and curr. string. Since, we are lot of modified strings for
// each string, we are gettting TLE error for last case. 
// Trie facing Memory Limit Exceeding error for 50th of 62nd case and Using Map to track given string gives TLE errors.


// Instead we could have checked each pair of strings in given list and checked whether they are similar are not and joined groups accordingly.
// This is what second algorithm does.









class Solution {
public:
    
    struct Node{
        int index;
        vector<Node*>children;
        
        Node(){
            children=vector<Node*>(26,NULL);
            index=-1;
        }
    };
    
    
    void buildTrie(Node* node, string s, int index){						// Building Trie using given strings.
        int i=0;
        while(i<s.length()){
            if(node->children[s[i]-'a']==NULL) node->children[s[i]-'a']=new Node();
            node=node->children[s[i]-'a'];
            i++;
        }
        node->index=index;
    }
    
    int checkTrie(Node* node, string &s){									// Checks whether given string exists in Trie or not?
        int index=0;
        while(node && index<s.length()){
            if(node->children[s[index]-'a']==NULL) return -1;
            node=node->children[s[index]-'a'];
            index++;
        }
        return node->index;
    }
    
    int getParent(vector<int>&parent, int node){
        if(parent[node]!=node)
            parent[node]=getParent(parent,parent[node]);
        return parent[node];
    }
    
    void unionGroups(vector<int>&parent, int node1, int node2){
        int parA=getParent(parent, node1);
        int parB=getParent(parent, node2);
        if(parA==parB) return; 
        parent[parA]=parB;
        return ;
    }
    
    int numSimilarGroups(vector<string>& v) {
        vector<int>parent(v.size(),0);
        // unordered_map<string,int>m;
        Node* root=new Node();
        for(int i=0;i<v.size();i++){
            // m[v[i]]=i;
            parent[i]=i;
            buildTrie(root, v[i],i);										// Build Trie based on given strings(Easy lookup).
        }
        
        for(int a=0;a<v.size();a++){										// Iter. over each string.
            // cout<<"str: "<<v[a]<<endl;
            Node* node=root;
            for(int i=0;i<v[a].length();i++){								// Creating m^2 similar strings it can potentially have.
                if(node==NULL) break;
                for(int j=i+1;j<v[a].length();j++){
                    swap(v[a][i], v[a][j]);
                    // cout<<"The modified str: "<<v[a]<<endl;
                    // if(m.count(v[a])==1){								// Using map gives TLE eror for last case.
                    //     unionGroups(parent, m[v[a]],a);
                    // }
                    int ind=checkTrie(node,v[a].substr(i));							// If modified string exists, we join groups.
                    if(ind!=-1){
                        unionGroups(parent, ind, a);
                    }
                    swap(v[a][i], v[a][j]);
                }
                node=node->children[v[a][i]-'a'];
            }
        }
        
        int res=0;
        for(int i=0;i<v.size();i++){										// Iter. over strings and get #groups.
            int parA=getParent(parent, i);
            if(parA==i) res++;
        }
        return res;															// Return total #groups.
    }	
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((n^2)*log(n^2)).											// Since, we used compression by depth.
// Space Complexity: O(n).	
// This algorithm is Union-Find based solution. Here, since the #strings in array is less, we check for every pair of strings, if they are 
// similar are not, if they are similar, we join the groups of both strings. In this way, we merge all similar strings into single group.
// At the end of process, we iter. over all strings and get #groups/#group rep. and return the count.











class Solution {
public:
    
    
    int getParent(vector<int>&parent, int node){							// Getting parent of each node.
        if(parent[node]!=node)
            parent[node]=getParent(parent,parent[node]);
        return parent[node];
    }
    
    void unionGroups(vector<int>&parent, int node1, int node2){				// Merging two groups.
        int parA=getParent(parent, node1);
        int parB=getParent(parent, node2);
        if(parA==parB) return; 
        parent[parA]=parB;
        return ;
    }
    
    bool isSimilar(string &s, string &t){									// Checking if two strings are similar(0, 2 diff).
        int diff=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]) diff++;
            if(diff>2) return false;										// If diff>2, then they aren't similar.
        }
        return true;														// It accepts zero, two char diff.
    }
    
    int numSimilarGroups(vector<string>& v) {
        vector<int>parent(v.size(),0);
        for(int i=0;i<v.size();i++) parent[i]=i;							// Init. all nodes.
        
        for(int i=0;i<v.size();i++){										// Checking all possible pairs.
            for(int j=i+1;j<v.size();j++){
                if(isSimilar(v[i], v[j])){									// Checking if two strings are similar are not.
                    // cout<<" matched i: "<<i<<" and j; "<<j<<endl;
                    unionGroups(parent, i,j);								// Merging groups if similar.
                }
            }
        }
        
        int res=0;
        for(int i=0;i<v.size();i++){										// Iter. over all nodes.
            int parA=getParent(parent, i);
            // cout<<"i: "<<i<<" and parent: "<<parA<<endl;
            if(parA==i) res++;												// If group rep. found, inc. the count.
        }
        return res;															// Return the #groups/#group reps found.
    }
};


/*
