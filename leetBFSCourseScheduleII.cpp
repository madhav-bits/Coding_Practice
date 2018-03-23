/*
*
//**********************************************************210. Course Schedule II.***************************************************

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken 
after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 

click to show more hints.

Hints:

This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and 
therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,6,7,7]
[]
[1,1,1,1]
[1,1,1,1,2,2,2,3,3]
[1,1,1,1,2,2,2,3,3,4,4,4,4,5,6]
[1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,8,7,8,9,10,1,1,1,1,1]


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
// This is Kahn's Algorithm.
// Space Complexity: O(n).	
// This algorithm is modified version of BFS, in each turn we eliminate nodes with zero inDeg(#Nodes pointing to this node). And mark it , so that
// it's not visited once again. And dec. the inDeg of all nodes to which this Node is pointing to. We do it for #Nodes in the graph times. Even 
// after all this iterations, if we still have nodes non-zero inDeg, then this means it has a cycle in it- courses can't be studied.
//************We iterate #Nodes times, as a node can have at most (#Nodes-1) inDeg, so, in case of no cycle, then it has to have zero inDeg by nth
// iter. As, it still doesn't inDeg==0, it indicates that it has cycle involving that node.

// Whenver we find a node zero inDeg, we push it into the vector to store the seq. of courses to be pursued. If we found there is a cycle in the 
// graph. Then we return null vector. 






class Solution {
public:
    
    vector<unordered_set<int>> formGraph(int numCourses, vector<pair<int, int>>& preq){
        vector<unordered_set<int>> graph(numCourses);
        for(int i=0;i<preq.size();i++){                          // Pushing elem. into vector's array of sets by iterating the preq vector.
            graph[preq[i].second].insert(preq[i].first);		// Points all directed neighbours to a node.
        }
        
        return graph;
    }
    
    vector<int> findInDeg(vector<unordered_set<int>> & graph){	// Caculates in Degree of all nodes.
        vector<int> v(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto node: graph[i]){
                v[node]++;
            }
        }
        return v;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& preq) {
        vector<unordered_set<int>> graph= formGraph(numCourses, preq);
        vector<int> inDeg= findInDeg(graph);
        vector<int> courses;
        
        for(int i=0;i<numCourses;i++){
            int j;
            for(j=0;j<numCourses;j++){
                if(inDeg[j]==0) break;							// Extracting nodes with zero inDegree.
            }
            //cout<<"Outside the for loop with j: "<<j<<endl;
            if(j==numCourses) return vector<int> (0);			// No node with zero inDeg is found, then it indicates that it has a cycle in it.
            for(auto node:graph[j])                             //Accessing elem. of a set.
                inDeg[node]--;									// Dec. the inDeg of all nodes, to which this node is pointing to.
            inDeg[j]=-1;										//Marking, such that this won't be considered next time.
            //cout<<"Currently pushing the node: "<<j<<endl;
            courses.push_back(j);								// Noting the seq. of courses to be pursued.
        }
        
        return courses;											// Returning the all seq. of courses to be pursued.
    }
};