/*
*
//******************************************************847. Shortest Path Visiting All Nodes.***********************************************

An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and 
you may reuse edges.

 

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Note:

1 <= graph.length <= 12
0 <= graph[i].length < graph.length




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[]]
[[1],[0,2,4],[1,3,4],[2],[1,2]]



// Time Complexity: O(2^nodes*nodes).  
// Space Complexity: O(2^nodes*nodes).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^nodes*nodes).
// Space Complexity: O(2^nodes*nodes).	
// This algorithm is Breadth First Search based. We strat iterations from all nodes, we track the visited nodes in the form of bitmask(3 indicates
// index-0,1 had been visited). As, same nodes and paths can be traversed multiple times, we add a extra factor to decrese the scrutiny, like
// whenever we get a pair (whose path till now, next traversing node) had been already in the set, then won't push that pair into queue. If we 
// get a pair( path visited till now, next visiting node) are not present in  set, we push it into queue.



// This is BFS form all nodes, return the path first reaching all nodes.




class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==0 ) return 0;										// If empty graph is given, return 0.
        int length=graph.size();
        int fin=(1<<length)-1;
        // cout<<"The target is: "<<bitset<32>(fin)<<endl;
        queue<pair<int,int>>q;												// Stores the next visiting pair of path travelled, nextNode.
        set<pair<int,int>> st;												// Stores the visited pair of path travelled, nextNode..
        for(int i=0;i<length;i++){
            if(graph[i].size()==0) continue;
            int temp=1<<i;
            // cout<<"pushing the temp value: "<<bitset<32>(temp)<<endl;
            st.insert(make_pair(temp,i));									// Pushing into queue to be visited and set as visited.
            q.push(make_pair(temp,i));
        }
        
        int res=0;
        while(!q.empty()){
            res++;															// Inc. the count of path, as we are working on a edge now.
            // cout<<"Inside the queue with dist: "<<res<<endl;
            int len=q.size();
            for(int i=0;i<len;i++){
                int mask=q.front().first;									// Path travelled till now.
                int curr=q.front().second;									// Curr. node.
                // cout<<"Extracted mask: "<<bitset<32>(mask)<<endl;
                q.pop();
                for(int i=0;i<graph[curr].size();i++){						// Scanning all neighbors.
                    int nextMask=1<<graph[curr][i];
                    // cout<<"Curr. scanning val: "<< bitset<32>(nextMask)<<" with mask: "<<bitset<32>(mask)<<endl;
                    if((mask| nextMask)==fin) return res;					// If travelling nextNode makes complete tour, then return dist.
                    // cout<<"the match is: "<<bitset<32>(mask&nextMask)<<endl;
                    pair<int,int> nextPair= make_pair(mask|nextMask,graph[curr][i]);
                    if(st.count(nextPair)==0){                     			// If next pair not in set, then push into queue, set.
                        // cout<<"Pushing into queue with val: "<<bitset<32>(mask|nextMask)<<endl;
                        st.insert(nextPair);								// Pushing nextPair into set, queue.
                        q.push(nextPair);
                    }
                }
            }
        }
        
        return res;															// This handles a single node with no edges.
        
    }
};