/*
*
//******************************************************802. Find Eventual Safe States.***********************************************

In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal 
(that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a \
natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: 
graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:

graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[[],[2,3],[5],[],[5],[2,3],[]]
[[1,2],[2,3],[5],[],[5],[],[]]
[[],[2,3],[5],[],[5],[2,3],[],[3,7]]
[]
[[1,2],[2,3],[5],[0],[5],[],[]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is DFS. We travel from the start node and travel upto the time, we don't have any other path to follow visit any visited node.
// Once,we visit a already visited node, we mark this entire path is circular. We also stop travelling and mark as ciruclar, if we encounter any
// ciruclar node in any path starting from other node. Thus, we mark all the circular nodes and extract the non ciruclar path forming nodes.

// I had done entirely correct in the first attempt, but the I had passed as parameter, the copy of the graph vector, which took a lot of time to 
// get copied, once I changed it to pass by reference. It got accepted.



class Solution {
public:
    
    unordered_map<int, int> term;									// Marks the node is ciruclar(-1) or non-ciruclar(1).
    bool findTerm(vector<vector<int>> &v, unordered_map<int, int> visited, int node){
        //cout<<"Currently visiting node is: "<<node<<endl;
        if(term[node]==1) return true;       			//***********Test these conditions, prior calling the fn. To reduce exec. time.
        if(term[node]==-1) return false;     			//***********Test these conditions, prior calling the fn. To reduce exec. time.
        
        visited[node]=1;								//Marking the curr. node as visited.
        for(int i=0;i<v[node].size();i++){
            
            if(visited[v[node][i]]!=1){					// If, the next node is unvisited, then travel.
                
                if(!findTerm(v,visited,v[node][i])){	// If the next node is ciruclar, then mark the curr. node also as ciruclar.
                    //cout<<"Non. term. determining node is: "<<v[node][i]<<endl;
                    term[v[node][i]]=-1;				// Marking curr. node as circular.
                    return false;						// Passing the fn. call that next node(here it is curr. node) is circular.
                }
            }
            else{                                       //Visiting a already visited node.
                //cout<<"Non. term. determining node is: "<<v[node][i]<<endl;
                term[v[node][i]]=-1;					// As the next node is circular, we make the current circular.
                return false;							// Passing the fn. call that next node(here it is curr. node) is circular.
            }
            
        }
        term[node]=1;									//Marking the curr. node as non ciruclar.
        //cout<<"Currently term. determined node is: "<<node<<endl;
        return true;									// Passing the fn. call that next node(here it is curr. node) is non-circular.
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        vector<int> res;								// Stores the list of non-circular nodes.
        unordered_map<int, int> visited;				// Stores the visited nodes till that node in the curr. path.
        for(int i=0;i<v.size();i++){
            if(findTerm(v,visited,i)) res.push_back(i);//  Stores the non-circular nodes.
        }
        return res;										// Returning the non-circular nodes.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is DFS. We travel from the start node and travel upto the time, we don't have any other path to follow visit any visited node.
// Once,we visit a already visited node, we mark this entire path is circular. We also stop travelling and mark as ciruclar, if we encounter any
// ciruclar node in any path starting from other node. Thus, we mark all the circular nodes and extract the non ciruclar path forming nodes.

// I had done entirely correct in the first attempt, but the I had passed as parameter, the copy of the graph vector, which took a lot of time to 
// get copied, once I changed it to pass by reference. It got accepted.






class Solution {
public:
    
    bool findTerm(vector<vector<int>> &v, unordered_map<int, int> visited, unordered_map<int, int> &term, int node){
        //cout<<"Currently visiting node is: "<<node<<endl;
        //if(term[node]==1) return true;       //***********Test these conditions, prior calling the fn. To reduce exec. time.
        //if(term[node]==-1) return false;     //***********Test these conditions, prior calling the fn. To reduce exec. time.
        bool ret=true;
        bool ans;
        visited[node]=1;
        for(int i=0;i<v[node].size();i++){
            ans=true;
            if(term[v[node][i]]==1) continue;
            if(term[v[node][i]]==-1) { term[node]=-1; return false;} 
            if(visited[v[node][i]]!=1){
                //visited[v[node][i]]=1;
                ans=findTerm(v,visited, term,v[node][i]);
                if(ans==false){
                    //cout<<"Non. term. determining node is: "<<v[node][i]<<endl;
                    term[v[node][i]]=-1;
                    return false;
                }
                //visited[v[node][i]]=0;
            }
            else{																	//Visiting a already visited node.
                //cout<<"Non. term. determining node is: "<<v[node][i]<<endl;
                term[v[node][i]]=-1;
                return false;
            }
        }
        term[node]=1;
        //cout<<"Currently term. determined node is: "<<node<<endl;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        vector<int> res;
        unordered_map<int, int> visited,term;
        for(int i=0;i<v.size();i++){
            if(term[i]==1 || term[i]==-1) continue;
            //if(term[i]==-1) 
            visited[i]=1;
            findTerm(v,visited,term,i);
            /*
            if(findTerm(v,visited,term,i)){
                term[i]=1;
                cout<<"Currently term. determined node is: "<<i<<endl;
            }
            */
            visited.erase(i);
        }
        for(auto it=term.begin();it!=term.end();it++){
            if(it->second==1) res.push_back(it->first);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

