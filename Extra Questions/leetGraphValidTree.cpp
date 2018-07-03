/*
*
//************************************************************261. Graph Valid Tree.*****************************************************

Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these 
edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not 
appear together in edges.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
[[0,1], [3,2]]


5
[[0,1],[0,4],[1,4],[2,3]]




// Time Complexity: O(Elogv).  													// Not sure about time complexities of 1/3 algos.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Elogv).
// Space Complexity: O(n).	
// This algorithm is BFS based, we first form a map which stores bi directional keys. We start iterating the array, at each step, we extract
// adj. nodes and push them into queue,if they are unvisited yet. We remove all this dup. nodes from the other end of the edge's node. When we 
// encounter a dup. node, return false.


// A trick is that if edges!=n-1, then it can be lesser edges(all nodes won't be connected) or higher edges(dup. exists for sure).








class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& v) {
        if(v.size()!=n-1) return false;                      				//All the nodes won't be connected.
        unordered_map<int,set<int>>edges;
        for(int i=0;i<v.size();i++){										// Forming two sided connections.
            edges[v[i].first].insert(v[i].second);
            edges[v[i].second].insert(v[i].first);
        }
        
        unordered_map<int,int>visited;
        for(int i=0;i<v.size();i++){
            if(visited.count(v[i].first)) continue;
            // cout<<"CUrr. index: "<<i<<endl;
            queue<int>q;
            q.push(v[i].first);												// Start from the unvisited node. of tree.
            while(!q.empty()){
                int curr=q.front();
                // cout<<"Curr. scanned node: "<<curr<<endl;
                // if(visited.count(curr)==1) return false;
                q.pop();
                visited[curr]=1;											// Marking curr. node as visited.
                for(auto j=edges[curr].begin();j!=edges[curr].end();j++){
                    
                    if(visited.count(*j)) return false;						// If trying to push already visited node, return false.
                    else q.push(*j);
                    edges[*j].erase(curr);									// Avoids using duplicate edges.
                }
            }    
        }
        return true;
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).													// Not so sure complexities.
// Space Complexity: O(n).	
// This algorithm is Union-Find based. We set deafult core parents to all nodes. We iterate the given array, for each edge I am making the parent
// of both of them as same, such that all the connected would have same core-parent. If, we encounter a scenario, where both ones are from the
// same group(same core parent), then return false. If, no issues till last iteration, return false.






class Solution {
public:
    int findParent(int i,vector<int>&parent){
        // cout<<"Inside fn. with node: "<<i<<endl;
        while(parent[i]!=i)
            i=parent[i];
        
        return i;
    }
    
    
    bool validTree(int n, vector<pair<int, int>>& v) {
		if(v.size()!=n-1) return false;
        vector<int>parent(n,0);
        for( int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<v.size();i++){
            int parL=findParent(v[i].first, parent);						// Extracing core parent of first node.
            int parR=findParent(v[i].second, parent);						// Extracing core parent of second node.
            // cout<<"Curr. node: "<<v[i].first<<" second node: "<<v[i].second<<endl;
            // cout<<"Parents are: "<<parL<<" second node: "<<parR<<endl;
            if(parL==parR) return false;									// If they belong to same group, return false.
            parent[parL]=parR;												// Assigning core parent of Right as parent of Left's coreParent.
            // cout<<"Updating parent of L: "<<parL<<" to: "<<parR<<endl<<endl;
        }
        //int par=findParent(0, parent);
        //for(int i=1;i<n;i++){
        //    int curr=findParent(i,parent);
        //    if(curr!=par) return false;
        //}
		
        return true;														// If no issues arise, return true.
    }
};












//************************************************************Solution 3:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(Eogv).
// Space Complexity: O(n).	
// This algo. is DFS based. We form a map with bidirectional edges. Next we start DFs from node-"0", with that hope that, the tree being 
// conencted, we expect to reach all nodes from here. AT each step of DFS, we go into recursive for only those nodes, which were unvisited till
// then. If visited, we take an exception for prev node from which we travelled here). If we get any other node, then return true from the fn.
// indicating that cycle exists.
// In the second iteration, we check whether all nodes had been reached or not, if not return false, else return true.









class Solution {
public:
    
    bool findCycle(int curr, int prev, unordered_map<int,int>&visited, vector<vector<int>>&edges){	// Find Cycles.
        visited[curr]=1;													// Marking curr. as visited.
        for(auto node:edges[curr]){											// Iterating through adj. nodes.
            if(!visited[node]){												// If a adj. node is un-visited.
                if(findCycle(node, curr, visited,edges)) return true;		// GO for a recursive call, to traverse the tree
            }
            else if(node!=prev){											// If pre-visited node is non-parent(prev), then return true.
                return true;												// Else, take an exception.
            }
        }
        return false;														// If no issue arises, then return no cycle were observed(false).
    }
    
    bool validTree(int n, vector<pair<int, int>>& v) {
        if(v.size()!=n-1) return false;                     				//All the nodes won't be connected.
        vector<vector<int>>edges(n);		
        unordered_map<int,int>visited;										// Tracks visted nodes till now.
        for(int i=0;i<v.size();i++){										// Forming bidirectional edges.
            edges[v[i].first].push_back(v[i].second);
            edges[v[i].second].push_back(v[i].first);
        }
        
        if(findCycle(0,-1,visited,edges)) return false;						// Calling fn. to detect cycle.
        
        for(int i=0;i<n;i++){												// Checking for unvisited nodes.
            if(visited[i]==false) return false;
        }
        return true;														// If no issues exist, return true.
    }
};