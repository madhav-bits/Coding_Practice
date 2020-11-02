/*
*
//************************************************1202. Smallest String With Swaps.***********************************************

https://leetcode.com/problems/smallest-string-with-swaps/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked on test cases provided with the question.
"dcab"
[[0,3],[1,2]]
"dcab"
[[0,3],[1,2],[0,2]]
"cba"
[[0,1],[1,2]]



// Time Complexity: O(nlogn).  												// Sorting indices belonging to groups.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************THIS IS A GOOD QUESTION.**************************************************
// Time Complexity: O(nlogn).												// Sorting indices belonging to groups.
// Space Complexity: O(n).	
// This algorithm is Union Find based. Here, the observation is that all the indices which are linked can have their chars swapped at 
// will and smallest string is formed when their chars are arranged in asc. order in the linked indices, this applied to all groups
// formed as per pairs provided. Here, we init a group with each rank-0, themself being parent node. We join them and form groups. 
// We iter. over all indices, calc. parent and collect groups of indices of that parent's group. We iter. over all groups and form
// strings, sort them and update the indices with sorted temp. string thus we lexically small string.








class Solution {
public:
    
    int getParent(vector<int>&parent, int node){							// Calc. parent for the node.
        if(parent[node]!=node) parent[node]=getParent(parent, parent[node]);
        return parent[node];
    }
    
    void joinGroups(vector<int>&parent, vector<int>&ranks, int node1, int node2){// Joing groups based on ranks.
        int parA=getParent(parent, node1);
        int parB=getParent(parent, node2);
        if(parA==parB) return ;
        if(ranks[parA]>=ranks[parB]){
            parent[parB]=parA;
            ranks[parA]+=1;
        }else{
            parent[parA]=parB;
            ranks[parB]+=1;
        }
        return ;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int>ranks(s.length(),0);
        vector<int>parent(s.length(),0);
        for(int i=0;i<s.length();i++) parent[i]=i;
        for(int i=0;i<pairs.size();i++){									// Form groups based on ranks.
            joinGroups(parent, ranks, pairs[i][0], pairs[i][1]);
        }
        unordered_map<int,vector<int>>m;
        for(int i=0;i<s.length();i++){										// Collecting indices belonging to all groups.
            int par=getParent(parent, i);
            m[par].push_back(i);
        }
        string res=s;
        for(auto it=m.begin();it!=m.end();it++){							// Iter. over all groups.
            string temp="";
            for(int i=0;i<it->second.size();i++)							// Iter. over indices in each group.
                temp+=s[it->second[i]];
            sort(temp.begin(), temp.end());									// Sorting chars in each group.
            for(int i=0;i<temp.length();i++)								// Reassigning sorted chars to indices in each group.
                res[it->second[i]]=temp[i];
        }
        return res;															// Returning lexically smallest string after swaps.
    }
};