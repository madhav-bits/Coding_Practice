/*
*
//******************************************************787. Cheapest Flights Within K Stops.***********************************************
//*****************************************************NEED TO FOLLOW UP WITH BELLMAN FORD.**************************************************
//*****************************************************ALSO WITH IMPROVED DIJKSTRA'S ALGORITHM.**************************************************

There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from 
src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
Note:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6
[[0,1,100],[1,2,100],[2,3,200],[3,1,100],[2,4,500],[4,5,100]]
0
5
4


// Time Complexity: O(n*n*k).  
// Space Complexity: O(n*n*k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*n*k).	
// Space Complexity: O(n*n*k).																	// In case of cycles.
//*****************************************************THIS IS SHORTEST PATH ALGORITHM.**************************************************
//*********************************************I HAD IMPLEMENTED MODIFIED DIJKSTRA'S ALGORITHM.******************************************
// This algorithm is slightly modified version of Dijkstra's Algo. Which extracts min. Cost at every step. If cycles are present in graph,
// it will repeatedly place the cycle elements in queue, until there path is of length>K(Only drawback in this algo). The adjacent 
// nodes are placed in queue, iff they are within stops constraint. The instant we encounter dest within K steps, that's
// the result. If dest is not obtained in K stops, then return -1.



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dest, int K) {
        vector<vector<pair<int,int>>>graph(n);						//Stores the graph.
        for(int i=0;i<v.size();i++) graph[v[i][0]].push_back(make_pair(v[i][1], v[i][2])); 		//Next Stop followed by Dist to next stop.
        int stops=K+1, steps=n;
        vector<vector<int>>m;                          
        m.push_back({0,src,0});						// Pushing source into it-(Cost from src, node, Dist from src).
        while(!m.empty()){
            auto it= min_element(m.begin(), m.end(), [](const auto& x, const auto& y){			// Extracting the min. value from vector.
               return x[0]<y[0]; 
            });
            vector<int> temp;
            temp=*it;
            m.erase(it);                            											// This is probably the costly step. (O(n)).
            //cout<<"Currently visiting node is: "<<temp[1]<<"With dist. from source: "<<temp[0]<<endl;
            if(temp[1]==dest) return temp[0];//result= min(result, temp[0]);					// Dest. is encountered, Return the cost.
            
            for(int i=0;i<graph[temp[1]].size();i++){
                if(temp[2]<=K){																	// If the curr. node is within Less than K stops.
                    //cout<<"Pushing next node is; "<<graph[temp[1]][i].first<<endl;			// Then push the node into queue.
                    m.push_back({temp[0]+graph[temp[1]][i].second, graph[temp[1]][i].first,temp[2]+1 });
                }
            }
            
        }
        return -1;																				// If dest not encountered, return -1.
    }
};