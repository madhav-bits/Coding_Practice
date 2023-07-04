/*
*
//******************************************************1743. Restore the Array From Adjacent Pairs.******************************************************

https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[2,1],[3,4],[3,2]]
[[4,-2],[1,4],[-3,1]]
[[100000,-100000]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Map based. Here, we first store the edges in an map to make iteration easier. All the nodes occur twice except for the both nodes on ends.
// We iter. over map and pick the node which occured once, that is with a single edge is selected as head. We start our iter. from here, we add this to res,
// move to next node, this has two adj. nodes one of them had been already added to res, we compare the prev. node of curr. node with next node, if they aren't
// same, we make this the next node else we make second adj. node the next node as this would be unvisited, this second adj. node for all nodes except the 
// last node, so we place conditions accordingly.







class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& v) {
        if(v.size()==1) return v[0];
        unordered_map<int, vector<int>>m;
        vector<int>res;
        int head=INT_MIN;
        for(vector<int>&u:v) {												// Storing the edges in the map to form adjacency matrix.
            m[u[0]].push_back(u[1]);
            m[u[1]].push_back(u[0]);
        }
        for(auto it=m.begin();it!=m.end();it++) {
            if(it->second.size()==1) {										// Marking the node with single adj. node as head.
                head=it->first;
                break;
            }
        }
        // unordered_set<int>st;
        while(true) {
			res.push_back(head);											// Adding curr. node to res.
            // st.insert(head);
            // if(st.count(m[head][0])==0) head=m[head][0];
            // else if(m[head].size()>1) head=m[head][1];
            // else break;
            
            if(res.size()==1 ||
               (res.size()>1 && 
               res[res.size()-2]!=m[head][0])) head=m[head][0];				// If first adj. node is unvisited, make it the next node.
            else if(res.size()>1 && 
                    m[head].size()>1 && 
                    res[res.size()-2]!=m[head][1]) head=m[head][1];			// If second adj. node is unvisited, make it the next node.
            else break;
        }
        return res;															// Returning the restored array.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is similar to above one except the part where we add nodes into res array, this is slightly better approach when compared to the above one, as
// few conditions are used, it's easier to read and understand.






class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& v) {
        if(v.size()==1) return v[0];
        unordered_map<int, vector<int>>m;
        vector<int>res;
        int head=INT_MIN;
        for(vector<int>&u:v) {
            m[u[0]].push_back(u[1]);
            m[u[1]].push_back(u[0]);
        }
        for(auto it=m.begin();it!=m.end();it++) {
            if(it->second.size()==1) {
                head=it->first;
                break;
            }
        }
        res.push_back(head);
        res.push_back(m[head][0]);
        // unordered_set<int>st;
        while(res.size()<v.size()+1) {										// We iterate until all nodes had been added to res.
            // res.push_back(head);
            // st.insert(head);
            // if(st.count(m[head][0])==0) head=m[head][0];
            // else if(m[head].size()>1) head=m[head][1];
            // else break;
            
            int visitedAdjNode=res[res.size()-2], tail=res.back();			
            if(m[tail][0]!=visitedAdjNode) res.push_back(m[tail][0]);		// Checking if first adj. node is already visited.
            else res.push_back(m[tail][1]);									// If first node is visited, then second node would be unvisited, so we add to res.
        }
        return res;															// Returning the restored array.
    }
};

