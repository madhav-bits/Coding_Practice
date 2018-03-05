/*
*
//**********************************************************785. Is Graph Bipartite?.***************************************************

Given a graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph 
has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is 
an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain 
any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.
 

Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]

[[1,3],[0,2],[1,3],[0,2]]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm starts from a node, assigns it a side, and assigns all its adajcent nodes other side. If the adj. node is of same side of curr.
// then return false, push into queue, only those nodes, which are not visited and assign them other side. If, there are no unvisited 
// adj. nodes after few iterations(empty queue). Then push a unvisited node into queue, and assign it any side. The instant, there are no unvisited
// adj. nodes and no unvisited nodes till then, we stop iteration and return true.

class Solution {
public:
    bool isBipartite(vector<vector<int>>& v) {
        map<int, int> m,n;								// m- to assign sides, n- to maintain whether visited status/infact, m can be used.
        /*
        sort(v.begin(), v.end(),[=](vector<int> a, vector<int> b){
            return a[0]<b[0];
        });
        */
        queue<int> q;									// Maintains the unvisited adj. nodes.
        q.push(0);										// Pushing first node to queue.
        m[0]=1;
        for(int i=0;i<v.size();i++) n[i]=1;				// Updating the status to unvisited for all nodes.
        while(!q.empty()){				
            int curr=q.front();							// Curr. scanning node.
            //cout<<"Curr. node is: "<<curr<<endl;
            if(m[curr]==1){								// If the curr. node belongs to a side.
                for(int i=0;i<v[curr].size();i++){		// Adj. nodes scanning.
                    //cout<<"Adj. of node: "<<curr<<" is: "<<v[curr][i]<<" and map value is: "<<m[v[curr][i]]<<endl;
                    if(m[v[curr][i]]==1) return false;	// If adj. node belongs to same side, return false.
                    if(m[v[curr][i]]==0){				// If ad. node is unvisited, assign it other side.
                        m[v[curr][i]]=-1;
                        //cout<<"Pushing elem. is: "<<v[curr][i]<<endl;
                        q.push(v[curr][i]);				// Pushing the unvisited adj. node to queue.
                    }
                }
            }
            if(m[curr]==-1){							// If curr. node belongs to a side.
                for(int i=0;i<v[curr].size();i++){
                    //cout<<"Adj. of node: "<<curr<<" is: "<<v[curr][i]<<" and map value is: "<<m[v[curr][i]]<<endl;
                    if(m[v[curr][i]]==-1) return false;
                    if(m[v[curr][i]]==0){
                        m[v[curr][i]]=1;
                        //cout<<"Pushing elem. is: "<<v[curr][i]<<endl;
                        q.push(v[curr][i]);
                    }
                }
            }
            q.pop();
            n[curr]=0;
            //cout<<"queue size is: "<<q.size()<<endl;
            if(q.empty()){								// If adj. unvisited nodes are not there, pushing the first unvisited node to queue.
                for(auto it=n.begin();it!=n.end();it++){
                    //cout<<"CUrr. node is: "<<it->first<<" and value is; "<<it->second<<endl;
                    if(it->second==1){					// Unvisited node.
                        //cout<<"Node pushed from n map is: "<<it->first<<endl;
                        q.push(it->first);				// Pushing it into queue.
                        m[it->first]=1;					// Assigning it a side.
                        break;
                    }
                }
            }
            
        }
        return true;									// If it passes through all nodes without any issues, then return true.
        
    }
};