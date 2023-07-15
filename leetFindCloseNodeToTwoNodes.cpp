/*
*
//**********************************************2359. Find Closest Node to Given Two Nodes.*******************************************

https://leetcode.com/problems/find-closest-node-to-given-two-nodes/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,2,3,-1]
0
1
[1,2,-1]
0
2
[1,2,1,4,5,3]
0
3
[4,4,8,-1,9,8,4,4,1,1]
5
6



// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is BFS based. Since, we only have two iter. and each of them have only one child at max. we can perform BFS by maintaining two vars and 
// marking that nodes had been visited by node1 by setting those indices with value -2 by -3 for nodes visited by node2. If node1 encounters a node, whose 
// index is set to -3, that means this node had been visited by node2, since both of them had visited, we check if this index is curr. res index as other node
// can also be reaching a node reachable by node1, node2 in the same iter. of BFS thus making both the nodes to be of same max. dist., so we get the min. index
// and return it, if we dont have other node to be a possible common node, our curr. node would be in res and we will return res. We update node1=edges[node1]
// we do the same for node2 too, in case of cycles, if we revisit the node, node1 would change to -2 as this index is set to -2 in prev. iter., thus we
// break out of loops. If other node touches this loop, we return the POC.







class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1==node2) return node1;
        int len=edges.size();
        
        while(node1>=0 || node2>=0) {
            // cout<<"node1: "<<node1<<" and node2: "<<node2<<endl;
            int res=INT_MAX,temp=-1;
            
            if(node1>=0) {													// Node1 curr. iterator.		
                if(edges[node1]==-3 && node1<res) res=node1;				// If curr. is already visited by other node, we update the res with min. node.
                temp=node1;
                node1=edges[node1];											// Moving node1 iterator to next node.
                edges[temp]=-2;												// Marking curr. node as visited by node1.
            }
            if(node2>=0) {													// Node2 curr. iterator.
                if(edges[node2]==-2 && node2<res) res=node2;				// If curr. is already visited by other node, we update the res with min. node.
                temp=node2;
                node2=edges[node2];
                edges[temp]=-3;												// Marking curr. node as visited by node2.
            }
            if(res!=INT_MAX) return res;									// If res is set, we return res.
        }
        return -1;															// If no common node is found.
    }
};

