/*
*
//******************************************************2360. Longest Cycle in a Graph.******************************************************

https://leetcode.com/problems/longest-cycle-in-a-graph/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,3,4,2,3]
[2,-1,3,1]
[1,2,4,1,0,1,5,3,9,10,11,12,8,10,13]
[-1,4,-1,2,0,4]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. The approach is slightly modified version of DFS Topological Sort process, we use dist array in place of recStack to keep 
// track of the dist of the nodes from the source of iter. marking that these nodes are part of this round of finding cycle and we use this dist value to 
// calc. the length of the cycle if this node is visited again marking that this cycle is the curr. circle. If we touch nodes whose dist[adj==-1 but 
// visited[adj] is true, that means this node is already visited in earlier DFS calls, as the call didn't reach you from adj. node earlier, we aren't part of 
// it's connected nodes, so we ignore adj. node. Return the length of the cycle returned by the DFS func. call and return it to parent. Thus original DFS
// call gets length of the cycle if exists else -1, which we use to maximize the length of the cycle variable and return it after visiting all the nodes.







class Solution {
public:
    
    int iterateGraph(vector<int>&edges, int node, vector<bool>&visited, vector<int>&dist, int depth) {
        visited[node]=true;
        dist[node]=depth;
        if(edges[node]!=-1 && dist[edges[node]]!=-1) {
            dist[node]=-1;
            return depth-dist[edges[node]]+1;
        }
        if(edges[node]==-1 || visited[edges[node]]) {
            dist[node]=-1;
            return -1;
        }
        int len=iterateGraph(edges, edges[node], visited, dist, depth+1);
        dist[node]=-1;
        return len; 
    }
    
    int longestCycle(vector<int>& edges) {
        vector<bool>visited(edges.size(), false);
        vector<int>recStack(edges.size(), -1);
        int res=-1;
        for(int i=0;i<edges.size();i++) {
            if(visited[i]) continue;
            res=max(res, iterateGraph(edges, i, visited, recStack, 1));
            // cout<<"i: "<<i<<" and res: "<<res<<endl;
        }
        return res;
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This solution is same as the above one except that it only uses visited arry to keep track of the time at which a node had been visited, here we assign 
// the visited times to nodes based on a global var, which doesn't affect us in calc. length of cycle as the nodes from prev. visited nodes in another while 
// loop iter. would have lesser time stamps than the nodes which are visited in this curr. while loop, it won't affect the length of the cycle as each node
// has only one outward edge making it possible to use global var for time stamps otherwise we have to use first solution to address the issue as diff. child
// of a node needs to have same timestamp for us to use them while calc the length of the cycle which is not possible for a global var so we had addressed 
// this using local var in Solution 1.









class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int>visited(edges.size(), -1);
        int res=-1, time=1;
        for(int i=0;i<edges.size();i++) {
            if(visited[i]!=-1) continue;
            int node=i, start=time;
            
            while(node!=-1 && visited[node]==-1) {							// Visiting unvisited nodes in curr. iter.
                visited[node]=time++;										// Assigning the time stamp to curr. node.
                node=edges[node];											// Moving to next node.
            }
            
            if(node!=-1 && visited[node]>=start) res=max(res, time-visited[node]);// If revisited node belongs to same while loop, we calc. len of cycle.
        }
        
        
        return res;															// Returning the max. length of the cycle.
    }
};











//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// This solution is BFS based, this is BFS version of Topological Sort. Here, we use topological sorting to cover all nodes which aren't part of any cycles.
// Later, we start DFS iterations from those nodes which haven't been visited earlier as they were part of cycles, as each node has only one outward edge it
// can be part of only at max one cycle, now we count #nodes in each cycle and try to maximize the cycle length and return it at the end of iter.









class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int>inwardCount(edges.size(), 0);
        int res=-1, time=1;
        for(int&num:edges) {
            if(num!=-1) inwardCount[num]++;									// Counting #inward edges for a node.
        }
        queue<int>q;
        for(int i=0;i<edges.size();i++)
            if(inwardCount[i]==0) q.push(i);								// Collecting nodes with zero inward edges.
        
        while(!q.empty()) {													// Covering all nodes which aren't part of any cycles.
            int curr=q.front();
            q.pop();
            curr=edges[curr];
            if(curr!=-1) {
                if(--inwardCount[curr]==0) q.push(curr);
            }
        }
        
        for(int i=0;i<edges.size();i++) {									// Covering all nodes which are part of cycles.
            if(inwardCount[i]==0) continue;
            int curr=i, cnt=0;
            while(inwardCount[curr]!=0) {									// Covering a cycle.
                inwardCount[curr]=0;
                cnt++;														// Tracking #nodes in the cycle.
                curr=edges[curr];
            }
            if(cnt>res) res=cnt;											// Tracking the max. #nodes in a cycle.
        }
        
        return res;															// Returning the max. length/nodes of the cycle.
    }
};


