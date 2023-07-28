/*
*
//*******************************************2662. Minimum Cost of a Path With Special Roads.*****************************************

https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1]
[4,5]
[[1,2,3,3,2],[3,4,4,5,1]]
[3,2]
[5,7]
[[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]



// Time Complexity: O(nodes*log(edges)).
// Space Complexity: O(nodes).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nodes*log(edges)).
// Space Complexity: O(nodes).	
// This algorithm is Dijkstra based. This slightly modifies the above algorithm, here we have nodes in the form of spclRoads and edges are the Manhattan dist.
// b/w any two pair of spclRoads. In Dijkstra, when we get a min node from the PQ, we calc. dist of this node to all other nodes and put only those instances 
// which resulted in dec. of min dist. to those nodes, here, when we pop a spclRoad from PQ, we calc. two dist. for each of the spclRoads(sx, sy, ex, ey, cost),
// we calc. manhattan distance from (ex,ey) of PQ's top node to (sx, sy) and add cost, this gives total cost from PQ top node to (ex,ey) via spclRoad and calc.
// direct Manhattan distance from PQ's top node to (ex, ey), we use the min. of the both and if this minm is < min dist till now the other node, we push into 
// PQ. We also push target node as spclRoad into the array for easier processing. If we pop target node from PQ, we return the dist. to the node.



// Manahattan dist. b/w two points via a third point is >= Direct Manhattan distance b/w two points. So, we can skip pushing nodes into PQ where dist. via 
// spclPath>direct Manh. dist to (ex,ey) of other nodes. As it's dist to other nodes when it pops from PQ can be directly calc. from orig. earlier popped node
// from PQ.








class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& nodes) {
        if(start[0]==target[0] && start[1]==target[1]) return 0;
        nodes.push_back({target[0], target[1], target[0], target[1], 0});	// Adding target as a special road in the nodes list.
        vector<int>minCost(nodes.size(), INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0;i<nodes.size();i++) {
            int dist=abs(nodes[i][0]-start[0])+abs(nodes[i][1]-start[1])+nodes[i][4];
            int toCost=abs(abs(nodes[i][2]-start[0])+abs(nodes[i][3]-start[1]));
            minCost[i]=min(dist, toCost);
			// if(dist>toCost) continue;									// If dist via spcl road > Manh. dist to (ex, ey) we can skip this path.
			// minCost[i]=dist;
            // cout<<"i: "<<i<<" and initial minCost: "<<minCost[i]<<endl;
            pq.push({minCost[i], i});
        }
        
        while(!pq.empty()) {
            int dist=pq.top().first, ind=pq.top().second;
            if(ind==nodes.size()-1) return dist;							// If target node observed, we return the min. distance.
            pq.pop();
            if(minCost[ind]<dist) continue;									// Avoid using paths with greater distances.
            // cout<<"curr ind: "<<ind<<" and minCost: "<<dist<<endl;
            int x=nodes[ind][2], y=nodes[ind][3];
            for(int i=0;i<nodes.size();i++) {
                int newDist=abs(nodes[i][0]-x)+abs(nodes[i][1]-y)+nodes[i][4];// Mah. dist to (ex, ey) via special road.
                int newToCost=abs(nodes[i][2]-x)+abs(nodes[i][3]-y);		// Manh. dist. to (ex, ey) of other nodes.
                // int minNewCost=min(newDist, newToCost);
                if(newDist>newToCost || minCost[i]<=dist+newDist) continue;// If dist via spcl road > Manh. dist to (ex, ey) we can skip this path.
                minCost[i]=dist+newDist;									// Updating the minDist to that special road.
                pq.push({minCost[i], i});
                // cout<<"pq pushed i: "<<i<<" and initial minCost: "<<minCost[i]<<endl;
            }
        }
        
        return -1;															// Default terimnating return value.
    }
};

