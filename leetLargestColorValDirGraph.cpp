/*
*
//********************************************1857. Largest Color Value in a Directed Graph.********************************************

https://leetcode.com/problems/largest-color-value-in-a-directed-graph/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abaca"
[[0,1],[0,2],[2,3],[3,4]]
"a"
[[0,0]]
"abacbaab"
[[1,2],[0,3],[1,4],[0,2],[2,4],[3,6],[1,7],[1,4],[4,3],[5,7],[6,7]]
"g"
[]
"dabc"
[]



// Time Complexity: O(nodes*26+edges*26)=O(nodes+edges).
// Space Complexity: O(nodes*26+edges)=O(nodes+edges).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nodes*26+edges*26)=O(nodes+edges).
// Space Complexity: O(nodes*26+edges)=O(nodes+edges).	
// This algorithm is DFS Topology based. Here, we forms adjaceny list for the graph. We also create a array to track max. #occur of all the colors in all the
// subtrees starting at 'i'. We now run DFS Topology from all unvisited nodes, in the process when we are at 'i', upon visiting each subtree rooted at 'i',
// we collect max. #occur of each of the colors in the subtree, we try to update max. #occur of colors in the subtree starting curr. node using the vals from
// subtrees and inc. the #occur for curr. node's char after iterating all the subtrees. Since, all the max. #occur for all the chars except the one occuring 
// in curr. node is all copied from children/subtrees, we don't have to try to udpate res with them, we try to update res with curr. char's #occur, as it's
// the only char for which max. #occur changed in this step. If we visit a node, which is part of curr. DFS call, we observed a cycle, so we return false,
// based on which we return -1 from the source of DFS call. If no issues observed, we return res/max. #occur of chars in a path after all the DFS calls.







class Solution {
public:
    
    bool getMaxColorValue(vector<vector<int>>&graph, vector<vector<int>>&maxColors, string&s, int node, vector<bool>&visited, vector<bool>&recStack, int&res) {
        visited[node]=true;													// Mark curr. node as visited.
        recStack[node]=true;
        for(int adj:graph[node]) {
            if(recStack[adj]) return false;									// If we revisit node from same DFS call, we observed cycle, so we return false.
            if(visited[adj]==false && !getMaxColorValue(graph, maxColors, s, adj, visited, recStack, res)) return false;// If we observe cycle, return false.
            for(int i=0;i<26;i++) {											// Update max. #occur of each char in the path based on the #occur. in subtrees.
                if(maxColors[adj][i]>maxColors[node][i]) maxColors[node][i]=maxColors[adj][i];
            }
        }
        maxColors[node][s[node]-'a']++;										// Inc. the #occur. for the char in the curr. node.
        if(maxColors[node][s[node]-'a']>res) res=maxColors[node][s[node]-'a'];// Update max. #occur of color in a path based on the #occur. of curr. char.
        recStack[node]=false;												// Mark curr. node as unvisited from DFS call.
        return true;														// No cycle observed, we return true.
    }
    
    int largestPathValue(string s, vector<vector<int>>& edges) {
        int res=1, len=s.length();
        // At every node we store the maxm. #alphabets we can get from the children. DFS Topology works.
        vector<vector<int>>maxColors(len, vector<int>(26, 0));				// Track max. #occur of each color in subtree starting at curr. node.
        vector<bool>visited(len, false), recStack(len, false);
        vector<vector<int>>graph(len);
        for(vector<int>&v:edges) graph[v[0]].push_back(v[1]);				// Forming adjaceny list for the graph.
        for(int i=0;i<len;i++) {											// DFS to cover all paths starting curr. node.
            if(visited[i]) continue;
            if(!getMaxColorValue(graph, maxColors, s, i, visited, recStack, res)) return -1;// If cycle observed, we return -1.
        }
        return res;															// Returning max. #occur of color in a path in the Directed Graph.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nodes*26+edges*26)=O(nodes+edges).
// Space Complexity: O(nodes*26+edges)=O(nodes+edges).	
// This algorithm is BFS Topology based. Here, visit nodes once all it's parent nodes are visited, while a node's direct parents are being visited/processed,
// we try to update max. #occur of chars/colors in path involving child node based on the vals for direct parent node. On visiting we inc. the #occur. for
// that node's char and try to update res with it. If we are able to visit all nodes in the process, we return res else we return -1, as we are not able to 
// visit all nodes because of cycles in the graph. 
// This description is brief since the majority of the logic for this approach is same as the above algorithm.










class Solution {
public:
    int largestPathValue(string s, vector<vector<int>>& edges) {
        int res=1, len=s.length();
        vector<vector<int>>maxColors(len, vector<int>(26, 0));
        vector<vector<int>>graph(len);
        vector<int>inDegree(len, 0);
        for(vector<int>&v:edges) {
            graph[v[0]].push_back(v[1]);
            inDegree[v[1]]++;												// Tracks #direct parents each node has.
        }
        queue<int>q;
        for(int i=0;i<len;i++) {
            if(inDegree[i]==0) q.push(i);									// Start BFS with nodes who don't have any parents.
        }
        
        int visited=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            visited++;														// Tracks #visited nodes.
            if(++maxColors[node][s[node]-'a']>res) res=maxColors[node][s[node]-'a'];
            for(int adj:graph[node]) {									// Iter. over all children and updating their max. #occur of each char in the path.
                for(int i=0;i<26;i++) maxColors[adj][i]=max(maxColors[adj][i], maxColors[node][i]);
                if(--inDegree[adj]==0) q.push(adj);							// As all direct parents are visited, we push node into queue and visit it.
            }
        }
        return (visited<len)?-1:res;										// If cycle found, return -1 else returning max. #occur of a color in a path.
    }
};

