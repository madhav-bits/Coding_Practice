/*
*
//****************************************************************207. Course Schedule.*****************************************************

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished 
course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

4
[[1,0],[2,3],[3,2]]

11
[[6,7],[7,8],[8,9],[9,6],[1,2],[1,4],[2,3],[2,4],[4,5]]

4
[[0,1],[1,2],[1,3],[2,0]]


// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).	
// Space Complexity: O(n).	
// This algorithm is modified version of BFS, in each turn we eliminate nodes with zero inDeg(#Nodes pointing to this node). And mark it , so that
// it's not visited once again. And dec. the inDeg of all nodes to which this Node is pointing to. We do it for #Nodes in the graph times. Even 
// after all this iterations, if we still have nodes non-zero inDeg, then this means it has a cycle in it- courses can't be studied.
//************We iterate #Nodes times, as a node can have at most (#Nodes-1) inDeg, so, in case of no cycle, then it has to have zero inDeg by nth
// iter. As, it still doesn't inDeg==0, it indicates that it has cycle involving that node.

//Here, for this question, DFS is performing faster than BFS.



class Solution {
public:
    
    vector<unordered_set<int>> formGraph(int numCourses, vector<pair<int,int>> &v){
        vector<unordered_set<int>> u(numCourses);
        for(int i=0;i<v.size();i++){                    // Points all directed neighbours to a node.
            u[v[i].second].insert(v[i].first);
        }
        return u;
    }
    
    vector<int> calcInDeg(vector<unordered_set<int>> &graph){// Caculates in Degree of all nodes.
        vector<int> v(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto j: graph[i]){
                v[j]++;
            }
        }
        return v;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& v) {
        vector<unordered_set<int>>graph= formGraph(numCourses,v);
        vector<int> inDeg= calcInDeg(graph);
        
        for(int i=0;i<numCourses;i++){
            int j=0;
            for(j=0;j<numCourses;j++){
                if(inDeg[j]==0) break;						// Extracting nodes with zero inDegree.
            }
            if(j==numCourses) return false;					// No, no node with zero inDeg is found, then it indicates that it has a cycle in it.
            inDeg[j]=-1;                                    //Marking, such that this won't be considered next time.
            for(int k:graph[j])								// Dec. the inDeg of all nodes, to which this node is pointing to.
                inDeg[k]--;
        }
        
        return true;
    }
    
};

//************************************************************SOLUTION: 2************************************************************
//***************************************************THIS IS NOT A LEET ACCEPTED SOLUTION.*******************************************
//***************************************************************************************************************************************
// This algortihm is BFS based, looks for occurance of node which had been already visited. Spent almost 5 hours on this.:( worth it.
// But, passed 40/42 cases. As, it is based on BFS, it doesn't differentiate nodes belonging to different paths from the beginning.





class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& v) {
        vector<vector<int>>u(numCourses, vector<int>(0,0));
        map<int, int> unvisited;
        for(int i=0;i<v.size();i++){
            u[v[i].first].push_back(v[i].second);
            unvisited[v[i].first]=1;
            unvisited[v[i].second]=1;
        }
        
        
        map<int, int> visited, once;
        
        while(!unvisited.empty()){
            
            int start=0;
            once.clear();
            auto it=unvisited.begin();
            start=it->first;
            unvisited.erase(start);
            queue<int> q;
            q.push(start);
            visited[start]=1;
            once[start]=1;
            //cout<<"Beginning of outer while with start."<<start<<endl;
            if(u[start].size()==0) continue;
            int num=0;
            while(!q.empty()){                                      //All this is a cluster of nodes.
                cout<<"Beginning of inner while with start."<<q.front()<<endl;
                int curr=q.front();
                q.pop();
                for(int i=0;i<u[curr].size();i++){
                    //num=1;
                    cout<<"The curr. node is; "<<curr<<" and the dependency node is; "<<u[curr][i]<<endl;
                    if(visited.count(u[curr][i])==1 && once.count(u[curr][i])==0)       //Loop doesn't exist.
                        num=1;
                    if(unvisited.count(u[curr][i])==1) unvisited.erase(u[curr][i]);
                    
                    if(once.count(u[curr][i])==0){								// Nodes visited, as part of current cluster. 
                        cout<<"PUshing node is: "<<u[curr][i]<<" and size is: "<<once.size()<<endl;
                        once[u[curr][i]]=1;
                    }
                    else{
                        //cout<<"Removing the node : "<<u[curr][i]<<endl;
                        once.erase(u[curr][i]);
                    }
                    
                    if(visited.count(u[curr][i])==0){							// Nodes visited, as a whole belongs to diff. clusters of nodes.
                        visited[u[curr][i]]=1;
                        q.push(u[curr][i]);
                    }
                    
                    
                }
            }
            //cout<<"Once map size is: "<<once.size()<<endl;
            if(num!=1) return false;                        //There exists loop.
        }
        
        return true;
        
    }
};